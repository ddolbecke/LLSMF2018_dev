#ifndef LCD_H
#define LCD_H

#define LCD_D		LATC
#define LCD_RS 		LATAbits.LATA2
#define LCD_RW 		LATAbits.LATA3
#define LCD_E		LATAbits.LATA4

/*
 * lcd_init
 * Initializes the LCD screen
 * Input param : none
 */
void lcd_init(void);

/*
 * lcd_clear
 * Clears the entire LCD screen
 * Input param : none
 */
void lcd_clear(void);

/*
 * lcd_write
 * Writes 16 characters on the LCD screen
 * Input params :
 *  - c : array of 16 unsigned char to display.
 *  - line : number of the line to write on. (1 or 2)
 */
void lcd_write(char* c, char line);


// -----------------------------------------------------------------------------
// The following functions are defined only for the programmers.
// For advanced users only...
void lcd_putcmd(unsigned char c);
void lcd_putchar(unsigned char c);
void lcd_post3(void);

#endif
 