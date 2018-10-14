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
#pragma config OSC = XT
#pragma config WDT = OFF, LVP = OFF, MCLRE = OFF
#pragma config PBADEN = DIG

// INCLUDES
#include "p18f2321.h"

/*
 * init
 * Initializes the microcontroller for the purposes of the project LSMF2018
 * Input parameters : none
 * Output parameters : none
 */
void init(void);

/*
 * setLedR
 * Controls the RED LED
 * Input param : A logical value representing the on/off state of the LED
 */
void setLedR(unsigned char);

/*
 * setLedG
 * Controls the GREEN LED
 * Input param : A logical value representing the on/off state of the LED
 */
void setLedG(unsigned char);

/*
 * getButton
 * Returns the state of the button on the Demo board
 * Input param : none
 * Output param : 0x01 if the button is released ; 0x00 if the button is pressed
 */
char getButton(void);

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
 * Input param : priority (1:hp, 0:lp)
 * Output param : none
 */
void buttonInterruptEnable(char priority);

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

void clearSensorInterruptRequest(void);

void sensorInterruptEnable(void);

void sensorInterruptDisable(void);

#endif	/* DRIVERS_H */

