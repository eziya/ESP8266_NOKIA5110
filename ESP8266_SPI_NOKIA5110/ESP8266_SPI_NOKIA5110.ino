#include "Arduino.h"
#include "NOKIA5110.h"
#include "FONT_IMAGE.h"

#define DELAY	2000

void setup()
{
	Serial.begin(115200);

	/* Initialize NOKIA 5110 */
	if(!NOKIA5110.Init())
	{
		Serial.println("Initialize NOKIA 5110 Failed");
	}
	else
	{
		Serial.println("Initialize NOKIA 5110 OK");
	}
}

void loop()
{
	/* Small Font Testing */
	NOKIA5110.Clear();
	NOKIA5110.SetFont(SmallFont);
	NOKIA5110.PrintStr(N5110_MAX_WIDTH/2-(4.5*6), N5110_MAX_HEIGHT/2 - 4, (char*)"NOKIA5110", true);
	NOKIA5110.Update();
	delay(DELAY);

	/* Tiny Font Testing */
	NOKIA5110.Clear();
	NOKIA5110.SetFont(TinyFont);
	NOKIA5110.PrintStr(N5110_MAX_WIDTH/2-(4.5*4), N5110_MAX_HEIGHT/2 - 3, (char*)"NOKIA5110", true);
	NOKIA5110.Update();
	delay(DELAY);

	/* Medium Number Testing */
	NOKIA5110.Clear();
	NOKIA5110.SetFont(MediumNumbers);
	NOKIA5110.PrintStr(N5110_MAX_WIDTH/2-(2.5*12), N5110_MAX_HEIGHT/2 - 8, (char*)"99-99", true);
	NOKIA5110.Update();
	delay(DELAY);

	/* Big Number Testing */
	NOKIA5110.Clear();
	NOKIA5110.SetFont(BigNumbers);
	NOKIA5110.PrintStr(N5110_MAX_WIDTH/2-(2.5*14), N5110_MAX_HEIGHT/2 - 12, (char*)"99-99", true);
	NOKIA5110.Update();
	delay(DELAY);

	/* Invert Display Testing */
	NOKIA5110.Clear();
	NOKIA5110.SetFont(SmallFont);
	NOKIA5110.PrintStr(N5110_MAX_WIDTH/2-(4.5*6), N5110_MAX_HEIGHT/2 - 4, (char*)"NOKIA5110", true);
	NOKIA5110.Update();
	delay(DELAY);

	NOKIA5110.InvertDisplay(true);
	delay(DELAY);
	NOKIA5110.InvertDisplay(false);
	delay(DELAY);

	/* Draw Line Testing */
	NOKIA5110.DrawHLine(0, N5110_MAX_HEIGHT/2 - 8, N5110_MAX_WIDTH, true);
	NOKIA5110.DrawHLine(0, N5110_MAX_HEIGHT/2 + 8, N5110_MAX_WIDTH, true);
	NOKIA5110.DrawVLine(0, N5110_MAX_HEIGHT/2 - 8, 16, true);
	NOKIA5110.DrawVLine(N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT/2 - 8, 16, true);
	NOKIA5110.Update();
	delay(DELAY);

	/* Draw Rectangle Testing */
	NOKIA5110.DrawRect(0, N5110_MAX_HEIGHT/2 - 8, N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT/2 + 8, false, false);
	NOKIA5110.Update();
	delay(DELAY);

	NOKIA5110.Clear();
	NOKIA5110.Update();

	/* Draw Line Testing */
	for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
	{
		NOKIA5110.DrawLine(0, 0, i, N5110_MAX_HEIGHT-1, true);
	}
	NOKIA5110.Update();
	delay(DELAY);

	NOKIA5110.Clear();
	for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
	{
		NOKIA5110.DrawLine(0, N5110_MAX_HEIGHT-1, i, 0, true);
	}
	NOKIA5110.Update();
	delay(DELAY);

	NOKIA5110.Clear();
	for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
	{
		NOKIA5110.DrawLine(N5110_MAX_WIDTH-1, 0, i, N5110_MAX_HEIGHT-1, true);
	}
	NOKIA5110.Update();
	delay(DELAY);

	NOKIA5110.Clear();
	for(int i = 0; i < N5110_MAX_WIDTH; i=i+5)
	{
		NOKIA5110.DrawLine(N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT-1, i, 0, true);
	}
	NOKIA5110.Update();
	delay(DELAY);

	/* Draw Rectangle Testing */
	NOKIA5110.Clear();
	for(int i = 0; i < N5110_MAX_HEIGHT/2; i=i+2)
	{
		NOKIA5110.DrawRect(N5110_MAX_WIDTH/2-1.7*i,N5110_MAX_HEIGHT/2-1-i,N5110_MAX_WIDTH/2+1.7*i,N5110_MAX_HEIGHT/2+i, true, false);
		NOKIA5110.Update();
	}
	delay(DELAY);

	NOKIA5110.DrawRect(0, 0, N5110_MAX_WIDTH-1, N5110_MAX_HEIGHT-1, true, true);
	NOKIA5110.Update();
	delay(DELAY);

	/* Draw Circle Testing */
	NOKIA5110.Clear();
	for(int i = 0; i < N5110_MAX_HEIGHT/2; i=i+2)
	{
		NOKIA5110.DrawCircle(N5110_MAX_WIDTH/2-1,N5110_MAX_HEIGHT/2-1, i, true, false);
		NOKIA5110.Update();
	}
	delay(DELAY);

	NOKIA5110.DrawCircle(N5110_MAX_WIDTH/2-1,N5110_MAX_HEIGHT/2-1, N5110_MAX_HEIGHT/2-1, true, true);
	NOKIA5110.Update();
	delay(DELAY);

	NOKIA5110.PrintStr(15, N5110_MAX_HEIGHT/2 - 4, (char*)"NOKIA5110", false);
	NOKIA5110.Update();
	delay(DELAY);

	/* Draw Bitmap Testing */
	NOKIA5110.Clear();
	NOKIA5110.DrawBitmap(0, 0, (uint8_t*)Bitmap, N5110_MAX_WIDTH, N5110_MAX_HEIGHT);
	NOKIA5110.Update();
	delay(DELAY);
}
