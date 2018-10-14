/* 
 * File:   alphanum_screen.h
 * Author: Simon
 *
 * Created on 4 novembre 2015, 13:01
 */

#ifndef PMOD_LS1_H
#define	PMOD_LS1_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
#define IR_PROX_CONNECTED_TO_JE1
    // possible connections :  JJ1, JJ2, JA1, JA2, JD1

// Initializes  the module
void initLS1();

// get Sensors values, 1 bit per senor

unsigned char getLS1_1();
unsigned char getLS1_2();
unsigned char getLS1_3();
unsigned char getLS1_4();    

#ifdef	__cplusplus
}
#endif

#endif	/* ALPHANUM_SCREEN_H */

