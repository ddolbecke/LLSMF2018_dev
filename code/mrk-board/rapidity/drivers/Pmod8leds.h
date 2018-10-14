/* 
 * File:   8leds.h
 * Author: Simon
 *
 * Created on 6 novembre 2015, 12:17
 */

#ifndef H8LEDS_H
#define	H8LEDS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

    // Change this to let the program know where you are connected
#define LEDS_CONNECTED_TO_JE

    // Initializes the Pmod 8 LED
void init8Leds();

// Writes the 8 LEDs at once
void set8Leds(unsigned char leds);

// Writes every LED independently
void set8Leds0(unsigned char led);
void set8Leds1(unsigned char led);
void set8Leds2(unsigned char led);
void set8Leds3(unsigned char led);
void set8Leds4(unsigned char led);
void set8Leds5(unsigned char led);
void set8Leds6(unsigned char led);
void set8Leds7(unsigned char led);


#ifdef	__cplusplus
}
#endif

#endif	/* H8LEDS_H */

