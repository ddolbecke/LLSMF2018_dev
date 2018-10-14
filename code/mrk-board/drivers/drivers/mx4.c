/*
 * File:   io.c
 * Author: Dimitri
 *
 * Created on October 16, 2015, 9:45 AM
 */


#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define _SUPPRESS_PLIB_WARNING 1
#include <p32xxxx.h>
#include "mx4.h"

void initIO(void){
    AD1PCFG = 0xFFFF;  // All pins as digital
    CNEN = 0x0000;
    // initialize leds pins (RB10-13)
    TRISB &= 0xC3FF;
    
    //PORTSetPinsDigitalOut(IOPORT_B, BIT_10 | BIT_11 |BIT_12 |BIT_13 );
    
    // initialize button pins
    TRISAbits.TRISA6=1;
    TRISAbits.TRISA7=1;
    //PORTSetPinsDigitalIn(IOPORT_A, BIT_6 | BIT_7);
    
    
    // an address per source
    INTEnableSystemMultiVectoredInt();

    
}


char getButton1(void){
    return PORTAbits.RA6;
}
char getButton2(void){
    return PORTAbits.RA7;
}

void setLeds(char leds){
    LATB = (LATB & 0xFFFFC3FF) | leds<<10 ;
}


