/* 
 * File:   ssd.h
 * Author: Simon
 *
 * Created on 6 novembre 2015, 13:50
 */

#ifndef SSD_H
#define	SSD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

#define SSD_CONNECTED_TO_JC1_JD1

#define SSD_BLANK  0b0000000
#define SSD_CHAR_0 0b0111111
#define SSD_CHAR_1 0b0000110
#define SSD_CHAR_2 0b1011011
#define SSD_CHAR_3 0b1001111
#define SSD_CHAR_4 0b1100110
#define SSD_CHAR_5 0b1101101
#define SSD_CHAR_6 0b1111101
#define SSD_CHAR_7 0b0000111
#define SSD_CHAR_8 0b1111111
#define SSD_CHAR_9 0b1011111

// Initializes the seven-segment display
void initSSD();

// Sets the seven-segments. 
// 'segments' is a 7-bit number which every bit corresponds to one segment
// 'figure' is the digit to display
// Note : displaying both numbers is only possible through time multiplexing,
// which means to very quickly (< 10ms) switch between the two numbers
void setSSD(unsigned char segments, unsigned char figure);

#ifdef	__cplusplus
}
#endif

#endif	/* SSD_H */

