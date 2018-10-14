/* 
 * File:   main.c
 * Author: Dimitri
 *
 * Created on October 15, 2017, 09:01 PM
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
char state;
short t, reaction_time;

/* ------------------------------------------------------------ */
/*				   functions    								*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*				main function     								*/
/* ------------------------------------------------------------ */
void main (void)
{   
    char txt[17];
    
    initIO();
    initLCD();
    initTimer2(625, T2_PS_1_16);    // 1000 interrupts per second   
    timer2InterruptEnable();
    
    state = 0;
    setLeds(0);
    
    while(1){
        switch(state){
            case 0:
                writeLine("push button 1",0);
                break;
            case 1:
                writeLine("             ", 0);
                break;
            case 3:
                writeLine("It took you", 0);
                sprintf(txt,"%5d ms",reaction_time);
                writeLine(txt, 1);
                break;
            case 4:
                writeLine("too fast", 0);
                break;
        }




    }
}

/* ------------------------------------------------------------ */
/*				interrupts functions     	     				*/
/* ------------------------------------------------------------ */
void timer1Interrupt(void){ //next state logic

}

void timer2Interrupt(void){ // time computation
    switch(state){
        case 0:
            t+=100; // increase delay time per 100 ms
            if(t>=5000)  // range [2, 5] seconds
                t = 2000;
            if(getButton1()){
                state=1;
                setLeds(0xf);
            }
            break;
        case 1:
            t--;
            if(t==0){
                state=2;
                setLeds(0);
                
            }
            if(getButton2())
                    state=4;
            break;
        case 2:
            t++;
            if(getButton2()){
                state=3;
                reaction_time = t;
            }     
            break;
        case 3:
            t+=100; // increase challenge time per 100 ms
            if(t>=5000)
                t = 2000;
            if(getButton1()){
                state=1;
                setLeds(0xf);
            }
            break;
        case 4:
            t+=100; // increase challenge time per 100 ms
            if(t>=5000)
                t = 2000;
            if(getButton1()){
                state=1;
                setLeds(0xf);
            }
            break;
    }
}