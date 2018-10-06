/*
 * NOKIA5110.h
 *
 * Created: 2018-10-05 오후 8:39:05
 *  Author: kiki
 */

#ifndef __NOKIA5110_H_
#define __NOKIA5110_H_

#define N5110_CMD						0
#define N5110_DATA						1
#define N5110_MAX_WIDTH					84
#define N5110_MAX_HEIGHT				48
#define N5110_PIXEL						504

#define PCD8544_BIT_POWERDOWN			0x04
#define PCD8544_BIT_ENTRYMODE			0x02
#define PCD8544_BIT_EXTENDED			0x01
#define PCD8544_BIT_DISPLAYBLANK		0x00
#define PCD8544_BIT_DISPLAYNORMAL		0x04
#define PCD8544_BIT_DISPLAYALLON		0x01
#define PCD8544_BIT_DISPLAYINVERTED		0x05

#define PCD8544_CMD_FUNCTIONSET			0x20
#define PCD8544_CMD_DISPLAYCONTROL		0x08
#define PCD8544_CMD_SETYADDR			0x40
#define PCD8544_CMD_SETXADDR			0x80
#define PCD8544_CMD_SETTEMP				0x04
#define PCD8544_CMD_SETBIAS				0x10
#define PCD8544_CMD_SETVOP				0x80

#define PCD8544_DEFAULT_BIAS			0x03
#define PCD8544_DEFAULT_TEMP			0x03
#define PCD8544_DEFAULT_CONTRAST		0x37


class NOKIA5110Class
{
public:
	NOKIA5110Class();
	bool Init(void);
	void Reset(void);
	bool SetContrast(uint8_t contrast);
	bool InvertDisplay(bool invert);
	bool Update(void);
	void Clear(void);
	void Fill(void);
	void SetPixel(uint8_t x, uint8_t y, bool set);
	void SetFont(const uint8_t * font);
	void PrintChar(uint8_t x, uint8_t y, char ch, bool set);
	void PrintStr(uint8_t x, uint8_t y, char *str, bool set);
	void DrawHLine(uint8_t x, uint8_t y, uint8_t length, bool set);
	void DrawVLine(uint8_t x, uint8_t y, uint8_t length, bool set);
	void DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool set);
	void DrawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool set, bool fill);
	void DrawRoundRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool set, bool fill);
	void DrawCircle(uint8_t x, uint8_t y, uint8_t radius, bool set, bool fill);
	void DrawBitmap(uint8_t x, uint8_t y, uint8_t * bitmap, uint8_t width, uint8_t height);

private:
	bool Write(uint8_t data, uint8_t mode);
	uint8_t FrameBuffer[N5110_PIXEL];
	const uint8_t *CurrentFont;
};

extern NOKIA5110Class NOKIA5110;

#endif /* NOKIA5110_H_ */
