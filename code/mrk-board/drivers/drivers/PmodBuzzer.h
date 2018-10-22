/* 
 * File:   PmodBuzzer.h
 * Author: Jean & Thomas
 *
 * Created on 19 October 2018
 */

#ifndef BUZZER_H
#define	BUZZER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

    // Change this to let the program know where you are connected
#define BUZZER_CONNECTED_TO_JE1

    // Initializes the Pmod 8 LED
void initBuzzer();

// Writes the 8 LEDs at once
void setBuzzer(unsigned char buzz);

// Writes every LED independently
void setBuzzer0(unsigned char buzz);
void setBuzzer1(unsigned char buzz);
void setBuzzer2(unsigned char buzz);
void setBuzzer3(unsigned char buzz);



#ifdef	__cplusplus
}
#endif

#endif	/* H8LEDS_H */

