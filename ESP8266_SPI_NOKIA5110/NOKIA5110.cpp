/*
* NOKIA5110.c
*
* Created: 2018-10-05 오후 8:39:25
*  Author: kiki
*/

#include <SPI.h>

#include "NOKIA5110.h"
#include "FONT_IMAGE.h"

#define SPI_SS				15
#define N5110_DC			2
#define N5110_RESET			4

NOKIA5110Class NOKIA5110;

NOKIA5110Class::NOKIA5110Class()
{
	CurrentFont = SmallFont;
}

bool NOKIA5110Class::Write(uint8_t data, uint8_t mode)
{
	/* slave select */
	digitalWrite(SPI_SS, LOW);

	/* select mode */
	if(mode == N5110_CMD)
	{
		digitalWrite(N5110_DC, LOW);
	}
	else if(mode == N5110_DATA)
	{
		digitalWrite(N5110_DC, HIGH);
	}
	else
	{
		digitalWrite(SPI_SS, HIGH);
		return false;
	}

	/* transfer data */
	SPI.transfer(data);

	/* slave deselect */
	digitalWrite(SPI_SS, HIGH);

	return true;
}

bool NOKIA5110Class::Init()
{
	/* Initialize SPI features */
	SPI.begin();
	SPI.beginTransaction(SPISettings(4000000, MSBFIRST, SPI_MODE0));

	/* Set pin mode for DC & RESET */
	pinMode(N5110_DC, OUTPUT);
	pinMode(N5110_RESET, OUTPUT);

	/* Initialize & Configure NOKIA 5110 */
	Reset();
	if(!Write(PCD8544_CMD_FUNCTIONSET | PCD8544_BIT_EXTENDED, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_SETVOP | PCD8544_DEFAULT_CONTRAST, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_SETTEMP | PCD8544_DEFAULT_TEMP, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_SETBIAS | PCD8544_DEFAULT_BIAS, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_FUNCTIONSET, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_DISPLAYCONTROL | PCD8544_BIT_DISPLAYNORMAL, N5110_CMD)) return false;

	return true;
}

void NOKIA5110Class::Reset()
{
	digitalWrite(N5110_RESET, LOW);
	delay(100);
	digitalWrite(N5110_RESET, HIGH);
}

bool NOKIA5110Class::SetContrast(uint8_t contrast)
{
	/* Max Contrast */
	if(contrast > 0x7F) contrast = 0x7F;

	if(!Write(PCD8544_CMD_FUNCTIONSET | PCD8544_BIT_EXTENDED, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_SETVOP | contrast, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_FUNCTIONSET, N5110_CMD)) return false;

	return true;
}

bool NOKIA5110Class::InvertDisplay(bool invert)
{
	if(invert)
	{
		if(!Write(PCD8544_CMD_DISPLAYCONTROL | PCD8544_BIT_DISPLAYINVERTED, N5110_CMD)) return false;
	}
	else
	{
		if(!Write(PCD8544_CMD_DISPLAYCONTROL | PCD8544_BIT_DISPLAYNORMAL, N5110_CMD)) return false;
	}

	return true;
}

bool NOKIA5110Class::Update()
{
	/* Move to (0,0) position */
	if(!Write(PCD8544_CMD_SETXADDR, N5110_CMD)) return false;
	if(!Write(PCD8544_CMD_SETYADDR, N5110_CMD)) return false;

	for(int i = 0; i < N5110_PIXEL; i++)
	{
		if(!Write(FrameBuffer[i], N5110_DATA)) return false;
	}

	return true;
}

void NOKIA5110Class::Clear()
{
	for(int i = 0; i < N5110_PIXEL; i++)
	{
		FrameBuffer[i] = 0x00;
	}
}

void NOKIA5110Class::Fill()
{
	for(int i = 0; i < N5110_PIXEL; i++)
	{
		FrameBuffer[i] = 0xFF;
	}
}

void NOKIA5110Class::SetPixel(uint8_t x, uint8_t y, bool set)
{
	uint16_t by;
	uint8_t  bi;

	if(x >= N5110_MAX_WIDTH || y >= N5110_MAX_HEIGHT) return;

	by = (y / 8) * N5110_MAX_WIDTH + x;
	bi = y % 8;

	if(set)
	{
		FrameBuffer[by] |= (1 << bi);
	}
	else
	{
		FrameBuffer[by] &= ~(1 << bi);
	}
}

void NOKIA5110Class::SetFont(const uint8_t * font)
{
	CurrentFont = font;
}

void NOKIA5110Class::PrintChar(uint8_t x, uint8_t y, char ch, bool set)
{
	uint8_t f_width  = pgm_read_byte(&CurrentFont[0]);
	uint8_t f_height = pgm_read_byte(&CurrentFont[1]);
	uint8_t f_offset = pgm_read_byte(&CurrentFont[2]);

	if((f_height % 8) == 0)
	{
		uint16_t f_index = (ch - f_offset) * (f_width * f_height / 8) + FONT_HEADER_SIZE;
		for(int row = 0; row < f_height / 8; row++)
		{
			for(int cx = 0; cx < f_width; cx++)
			{
				for(int bi = 0; bi < 8; bi++)
				{
					uint8_t cbyte = pgm_read_byte(&CurrentFont[f_index + cx + (row * f_width)]);
					if((cbyte & (1 << bi)) != 0)
					{
						SetPixel(x + cx, y + row * 8 + bi, set);
					}
					else
					{
						SetPixel(x + cx, y + row * 8 + bi, !set);
					}
				}
			}
		}
	}
	else
	{
		uint16_t f_index = (ch - f_offset) * (f_width * f_height / 8) + FONT_HEADER_SIZE;
		uint8_t cbyte = pgm_read_byte(&CurrentFont[f_index]);
		int8_t bi = 7;

		for(int cx = 0; cx < f_width; cx++)
		{
			for(int cy = 0; cy < f_height; cy++)
			{
				if((cbyte & (1 << bi)) != 0)
				{
					SetPixel(x+cx, y+cy, set);
				}
				else
				{
					SetPixel(x+cx, y+cy, !set);
				}

				bi--;

				if(bi < 0)
				{
					bi = 7;
					f_index++;
					cbyte = pgm_read_byte(&CurrentFont[f_index]);
				}
			}
		}
	}
}

void NOKIA5110Class::PrintStr(uint8_t x, uint8_t y, char *str, bool set)
{
	uint8_t f_width  = pgm_read_byte(&CurrentFont[0]);
	uint8_t length = strlen(str);

	for(int i = 0; i < length; i++)
	{
		PrintChar(x + (i * f_width), y, *str++, set);
	}
}

void NOKIA5110Class::DrawHLine(uint8_t x, uint8_t y, uint8_t length, bool set)
{
	for(int cx = 0; cx < length; cx++)
	{
		SetPixel(x+cx, y, set);
	}
}

void NOKIA5110Class::DrawVLine(uint8_t x, uint8_t y, uint8_t length, bool set)
{
	for(int cy = 0; cy < length; cy++)
	{
		SetPixel(x, y+cy, set);
	}
}

void NOKIA5110Class::DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool set)
{
	uint8_t tmp;
	float delta, tx, ty;

	if(x1 > x2)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;

		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	if(y1 > y2)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;

		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	if(y1 == y2)
	{
		if(x1 > x2)
		{
			tmp = x1;
			x1 = x2;
			x2 = tmp;
		}

		DrawHLine(x1, y1, x2-x1, set);
	}
	else if(x1 == x2)
	{
		if(y1 > y2)
		{
			tmp = y1;
			y1 = y2;
			y2 = tmp;
		}

		DrawVLine(x1, y1, y2-y1, set);
	}
	else if (abs(x2-x1)>abs(y2-y1))
	{
		delta = (float)((float)(y2-y1)/(float)(x2-x1));
		ty = (float)y1;
		if (x1 > x2)
		{
			for (int8_t i = x1; i >= x2; i--)
			{
				SetPixel(i, (uint8_t)(ty+0.5), set);
				ty = ty-delta;
			}
		}
		else
		{
			for (uint8_t i = x1; i <= x2; i++)
			{
				SetPixel(i, (uint8_t)(ty+0.5), set);
				ty = ty+delta;
			}
		}
	}
	else
	{
		delta = (float)((float)(x2-x1)/(float)(y2-y1));
		tx = (float)x1;
		if(y1 > y2)
		{
			for(int i = y2+1; i > y1; i--)
			{
				SetPixel((uint8_t)(tx+0.5), i, set);
				tx = tx+delta;
			}
		}
		else
		{
			for (int i = y1; i < y2+1; i++)
			{
				SetPixel((uint8_t)(tx+0.5), i, set);
				tx=tx+delta;
			}
		}
	}
}

void NOKIA5110Class::DrawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool set, bool fill)
{
	uint8_t tmp;

	/* Swap position to make x2 and y2 are bigger than x1 and y1 */
	if(x2 < x1)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	if(y2 < y1)
	{
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	if(fill)
	{
		for(int i = x1; i <= x2; i++)
		{
			for(int j = y1; j <= y2; j++)
			{
				SetPixel(i, j, set);
			}
		}
	}
	else
	{
		DrawHLine(x1, y1, x2-x1, set);
		DrawHLine(x1, y2, x2-x1, set);
		DrawVLine(x1, y1, y2-y1, set);
		DrawVLine(x2, y1, y2-y1, set);
	}
}

void NOKIA5110Class::DrawRoundRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool set, bool fill)
{
	uint8_t tmp;

	/* Swap position to make x2 and y2 are bigger than x1 and y1 */
	if(x2 < x1)
	{
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}

	if(y2 < y1)
	{
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	/* Too small to make rounded rectangle */
	if((x2-x1 <= 4) || (y2-y1) <= 4) return;

	if(fill)
	{
		for(int i = x1; i <= x2; i++)
		{
			for(int j = y1; j <= y2; j++)
			{
				/* Rounds four corners of rectangle */
				if( (i== x1 && j == y1) || (i == x1 && j == y1+1) || (i == x1+1 && j == y1 ) ||
				(i== x1 && j == y2) || (i == x1 && j == y2-1) || (i == x1+1 && j == y2 ) ||
				(i== x2 && j == y1) || (i == x2 && j == y1+1) || (i == x2-1 && j == y1 ) ||
				(i== x2 && j == y2) || (i == x2 && j == y2-1) || (i == x2-1 && j == y2 ) )
				{
					SetPixel(i, j, !set);
				}
				else
				{
					SetPixel(i, j, set);
				}
			}
		}
	}
	else
	{
		SetPixel(x1+1, y1+1, set);
		SetPixel(x2-1, y1+1, set);
		SetPixel(x1+1, y2-1, set);
		SetPixel(x2-1, y2-1, set);

		DrawHLine(x1+2, y1, x2-x1-3, set);
		DrawHLine(x1+2, y2, x2-x1-3, set);
		DrawVLine(x1, y1+2, y2-y1-3, set);
		DrawVLine(x2, y1+2, y2-y1-3, set);
	}
}

void NOKIA5110Class::DrawCircle(uint8_t x, uint8_t y, uint8_t radius, bool set, bool fill)
{
	int8_t a = 0;
	int8_t b = radius;
	int8_t p = 1 - radius;

	do
	{
		if(fill)
		{
			DrawLine(x-a, y+b, x+a, y+b, set);
			DrawLine(x-a, y-b, x+a, y-b, set);
			DrawLine(x-b, y+a, x+b, y+a, set);
			DrawLine(x-b, y-a, x+b, y-a, set);
		}
		else
		{
			SetPixel(x+a, y+b, set);
			SetPixel(x-a, y+b, set);
			SetPixel(x+a, y-b, set);
			SetPixel(x-a, y-b, set);
			SetPixel(x+b, y+a, set);
			SetPixel(x-b, y+a, set);
			SetPixel(x+b, y-a, set);
			SetPixel(x-b, y-a, set);
		}

		if(p < 0)
		{
			p += (3 + 2*a);
			a++;
		}
		else
		{
			p += (5 + 2*(a-b));
			a++;
			b--;
		}
	} while(a <=b);
}

void NOKIA5110Class::DrawBitmap(uint8_t x, uint8_t y, uint8_t * bitmap, uint8_t width, uint8_t height)
{
	uint8_t bit, data;

	for (int cy=0; cy < height; cy++)
	{
		bit= cy % 8;
		for(int cx=0; cx < width; cx++)
		{
			data = pgm_read_byte(&bitmap[cx+(cy/8*width)]);
			if ((data & (1<<bit)))
			{
				SetPixel(x+cx, y+cy, 1);
			}
			else
			{
				SetPixel(x+cx, y+cy, 0);
			}
		}
	}
}
