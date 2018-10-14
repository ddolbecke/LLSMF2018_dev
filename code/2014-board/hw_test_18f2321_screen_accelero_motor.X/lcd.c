#include "drivers.h"
#include "delays.h"
#include "lcd.h"

#define CMD_DLY 5

void lcd_putcmd(unsigned char c)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_D = c;
	LCD_E = 1;
	LCD_E = 0;
}

void lcd_putcmd4b(unsigned char c)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_D = (LCD_D & 0x0f) | (c & 0xf0);
	LCD_E = 1;
	LCD_E = 0;
	Delay1KTCYx(CMD_DLY);
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_D = (LCD_D & 0x0f) | ((c << 4) & 0xf0);
	LCD_E = 1;
	LCD_E = 0;
}

void lcd_init() {
	//Initiation des pins I/0
	TRISC = 0b00000000;
        TRISAbits.TRISA2 = 0;
	TRISAbits.TRISA3 = 0;
        TRISAbits.TRISA4 = 0;
        LCD_D = 0;
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_E = 0;

	// Initialisation
	Delay1KTCYx(15);
	lcd_putcmd(0x30);
	Delay1KTCYx(5);
	lcd_putcmd(0x30);
	Delay1KTCYx(5);
	lcd_putcmd(0x30);
	Delay1KTCYx(5);
	lcd_putcmd(0x20);	// 8-bit interface
	Delay1KTCYx(5);

	lcd_putcmd4b(0x28);	// 2 lines, 5x7 font
	Delay1KTCYx(5);
	lcd_putcmd4b(0x08);
	Delay1KTCYx(5);
	lcd_putcmd4b(0x06);
	Delay1KTCYx(5);
	lcd_putcmd4b(0x01);
	Delay1KTCYx(5);
	lcd_putcmd4b(0x0c);
	Delay1KTCYx(5);
}


void lcd_putchar4b(unsigned char c)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_D = (LCD_D & 0x0f) | (c & 0xf0);
	LCD_E = 1;
	LCD_E = 0;
	LCD_RS = 0;
	Delay1KTCYx(1);
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_D = (LCD_D & 0x0f) | ((c << 4) & 0xf0);
	LCD_E = 1;
	LCD_E = 0;
	LCD_RS = 0;
	Delay1KTCYx(1);
}

void lcd_putchar(unsigned char c)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_D = c;
	LCD_E = 1;
	LCD_E = 0;
	LCD_RS = 0;
	Delay1KTCYx(1);
}

void lcd_clear()
{
	lcd_putcmd4b(0x01);
	Delay1KTCYx(5);
}

void lcd_write(char* c, char line)
{
	char i = 0;
	if(line==1) {
		lcd_putcmd4b(0x02);
	} else {
		lcd_putcmd4b(0xC0);
	}

	Delay1KTCYx(1);

	for(i=0; i<16; i++){
		lcd_putchar4b(*(c+i));
	}
}

