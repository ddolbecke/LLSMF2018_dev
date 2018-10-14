/* 
 * File:   alphanum_screen.h
 * Author: Simon
 *
 * Created on 4 novembre 2015, 13:01
 */

#ifndef ALPHANUM_SCREEN_H
#define	ALPHANUM_SCREEN_H

#ifdef	__cplusplus
extern "C" {
#endif

#define LCD_CONNECTED_TO_JA_JB

    // Initializes  the alphanumeric LCD screen
void initLCD();

// Writes the character string to the line specified (0 or 1)
void writeLine(char * string, char line);

// Clears the alphanumeric screen
void clearScreen();

// Shifts the whole to the right (right=1) or left (right=0)
void shiftScreen(unsigned char right);
    

#ifdef	__cplusplus
}
#endif

#endif	/* ALPHANUM_SCREEN_H */

