/*
 * File:   drivers.h
 * Author: Dimitri de Smet and Simon Hubert
 *
 * Main header file containing the drivers for the Demo board used in the
 * electronic part of the LSMF2018 project.
 *
 * Created on October 7, 2013, 1:52 PM
 */

#ifndef DRIVERS_H
#define	DRIVERS_H

// CONFIGURATION BITS
#pragma config FOSC = INTIO67
#pragma config WDTEN = OFF, LVP = OFF, MCLRE = OFF

// INCLUDES
#include "p18f45k20.h"

/*
 * init
 * Initializes the microcontroller for the purposes of the project LSMF2018
 * Input parameters : none
 * Output parameters : none
 */
void init(void);

/*
 * setLeds
 * Puts the binary value of the input char argument on the 8 leds of the board
 * Input param : the binary representation of the leds to display
 */
void setLeds(unsigned char);

/*
 * getVoltage
 * Returns a 8-bit value corresponding to the voltage seen at the output of the
 * potentiometer, in a dynamic range from 0 to 5V.
 * Input param : none
 * Output param : an unsigned char representation of the voltage output by the potentiometer
 */
unsigned char getVoltage(void);

/*
 * getButton
 * Returns the state of the button on the Demo board
 * Input param : none
 * Output param : 0x01 if the button is released ; 0x00 if the button is pressed
 */
char getButton(void);

/*
 * initADC
 * initializes the Analog-to-digital converter
 * Input param : none
 * Output param : none
 */
void initADC(void);

/*
 * getADC
 * initializes the Analog-to-digital converter
 * Input param : none
 * Output param : an unsigned char representation of the voltage at the input of the ADC
 */
unsigned char getADC(void);

#endif	/* DRIVERS_H */

