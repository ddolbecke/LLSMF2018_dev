/* 
 * File:   main.c
 * Author: Dimitri
 *
 * Created on October 6, 2015, 1:54 PM
 */

/* ------------------------------------------------------------ */
/*				main header     								*/
/* ------------------------------------------------------------ */
#include "main.h"
#include <stdio.h>
/* ------------------------------------------------------------ */
/*				peripheral modules								*/
/* ------------------------------------------------------------ */
#include "delay.h"
#include "PmodCLP.h"
#include "analogInputs.h"
#include "interrupts.h"

/* ------------------------------------------------------------ */
/*				global variables								*/
/* ------------------------------------------------------------ */
char cs=0, s=0, min=0, btn1released=1, start;

/* ------------------------------------------------------------ */
/*				   functions    								*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*				main function     								*/
/* ------------------------------------------------------------ */
void main (void)
{   
    char txt[16];
    
    initIO();
    initAnalogInputs(1);
    initLCD();
    
    initTimer1(12500, T1_PS_1_8); // 100 interrupts per second
    initTimer2(625, T2_PS_1_16);  // 1000 interrupts per second 
    timer1InterruptEnable();
    timer2InterruptEnable();

    while(1){
        sprintf(txt," %02d:%02d.%02d",min,s,cs);
        writeLine(txt, 1);
        setLeds(s);

    }
}

/* ------------------------------------------------------------ */
/*				interrupts functions     	     				*/
/* ------------------------------------------------------------ */
void timer1Interrupt(void){
    if(start)
        cs++; // centiseconds count
    if(cs>99){
        cs = 0;
        s++; // seconds count
    }
    if(s>59){
        s = 0;
        min++; // minutes count
    }
}

void timer2Interrupt(void){
    if( getButton1() && btn1released){
        btn1released = 0;
        start = !start;
    }
    if( !getButton1() ){
        btn1released = 1;
    }       
    if(getButton2()){
       cs = 0;
       s = 0;
       min = 0;
       start = 0;
    }
}
