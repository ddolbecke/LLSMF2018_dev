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
 * potentiometer, in a dynamic range of 0 to 5V.
 * Input param : none
 * Output param : an unsigned char representation of the output voltage
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
 * ADC_Init
 * Initialize ADC module
 * Input param : none
 * Output param : none
 *
 */
void ADC_Init(void);

/*
 * ADC_Convert
 * Start an ADC conversion, wait for the result and return it
 * Input param : none
 * Output param : result of the 8 bits conversion
 */
unsigned char ADC_Convert(void);

/*
 * interruptEnable
 * Enable interrupts Globally
 * Input param : none
 * Output param : none
 */
void interruptEnable(void);
/*
 * interruptDisable
 * Disable interrupts Globally
 * Input param : none
 * Output param : none
 */
void interruptDisable(void);

/*
 * buttonInterruptEnable
 * Enable button interrupts
 * Input param : none
 * Output param : none
 */
void buttonInterruptEnable(void);
/*
 * buttonInterruptDisable
 * Disable button interrupts
 * Input param : none
 * Output param : none
 */
void buttonInterruptDisable(void);
/*
 * clearButtonInterruptRequest
 * Clear button interrupt request. This function
 * is required to leave the button interrupt routine
 * Input param : none
 * Output param : none
 */
void clearButtonInterruptRequest(void);
/*
 * initTimer
 * Initialize the timer module.
 * Input param :
 *      prescaler   :   used to divide the clock frequency = make it
 *                      slower
 *      priority    :   0 -> low priority interrupt
 *                      1 -> high priority interrupt
 * Output param : none
 */
void initTimer(unsigned char prescaler, unsigned char priority);
/*
 * loadTimer
 * Change the timer value to a specific value.
 * Input param : 16 bits value to be stored
 * Output param : none
 */
void loadTimer(unsigned short data);
/*
 * TimerInterruptEnable
 * Enable timer interrupts
 * Input param : none
 * Output param : none
 */
void timerInterruptEnable(void);
/*
 * TimerInterruptDisable
 * Disable timer interrupts
 * Input param : none
 * Output param : none
 */
void timerInterruptDisable(void);
/*
 * clearTimerInterruptRequest
 * Clear Timer interrupt request. This function
 * is required to be called to leave the timer interrupt routine
 * Input param : none
 * Output param : none
 */
void clearTimerInterruptRequest(void);

// function that check if the button interrupt was requested
char isButtonInterruptRequested(void);

// function that check if the timer interrupt was requested
char isTimerInterruptRequested(void);
#endif	/* DRIVERS_H */

