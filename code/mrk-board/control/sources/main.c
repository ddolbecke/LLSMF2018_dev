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
#include "PmodIR_Range.h"

/* ------------------------------------------------------------ */
/*				global variables								*/
/* ------------------------------------------------------------ */
char cs=0, s=0, min=0, btn1released=1, start;
unsigned short d1,d2,d3,d4;

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
    initDelay();
    //initAnalogInputs(1);
    initLCD();
    initIR_range();
    initPmodLS1();

    //initTimer1(12500, T1_PS_1_8); // 100 interrupts per second
    //initTimer2(625, T2_PS_1_16);  // 1000 interrupts per second 
    //timer1InterruptEnable();
    //timer2InterruptEnable();

    while(1){
        sprintf(txt,"d1 %4d, d2 %4d",getIR_range1(),getIR_range2());
        writeLine(txt, 0);
        sprintf(txt,"d2 %4d, d4 %4d",getIR_range3(),getIR_range4());
        writeLine(txt, 1);
        DelayMs(200);
        setLeds(getLS1_1()+getLS1_2()*2+getLS1_3()*4+getLS1_4()*8);
    }
}


/* ------------------------------------------------------------ */
/*				interrupts functions     	     				*/
/* ------------------------------------------------------------ */
void timer1Interrupt(void)
{
    
}

// 5 ms interrupt
void t5msInterrupt(void)
{
    
}
