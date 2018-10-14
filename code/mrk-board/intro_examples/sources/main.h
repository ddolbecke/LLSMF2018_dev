/* 
 * File:   main.h
 * Author: Dimitri
 *
 * Created on October 16, 2015, 10:27 AM
 */

#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1

#ifndef MAIN_H
#define	MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>

#include <plib.h>
#include <xc.h>

#include "interrupts.h"
#include "mx4.h"
#include "ClpLib.h"

// oscillator conf. 
// CPU 80Mh
// Periph. 10 MHz (checked)


// DEVCFG2


#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config UPLLIDIV = DIV_12        // USB PLL Input Divider (12x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 1)
#pragma config FWDTEN = OFF             // Disable Watchdog


#pragma config FNOSC = PRIPLL
#pragma config POSCMOD = EC


#pragma config FPBDIV = DIV_8 //DIV_8 =>10MHz 

#endif	/* MAIN_H */

