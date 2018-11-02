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
#include "PmodKYPD.h"
#include "uart.h"

/* ------------------------------------------------------------ */
/*				global variables								*/
/* ------------------------------------------------------------ */
/*char cs=0, s=0, min=0, btn1released=1, start;
unsigned short d1,d2,d3,d4;
char button1Released = 1, keyReleased=1, newKey=0;
char distType = 0;
char col, row, rows,x=0, key;
char txt[17];
// key (row, col)
char keys[4][4] = { { '0', 'F', 'E', 'D' }, { '7', '8', '9', 'C' } , { '4', '5', '6', 'B' }, { '1', '2', '3', 'A' } }; 
 */
int count = 0;

/* ------------------------------------------------------------ */
/*				   functions    								*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*				main function     								*/
/* ------------------------------------------------------------ */
void main (void)
{   
    
    initIO();
   // initBuzzer();
    initUart();
    //initDelay();
    //initSonar();
    //initAnalogInputs(1);
   // initLCD();
    //initIR_range();
    //initLS1();
    //initMotors();
    
    initTimer1(625, T1_PS_1_1);     
    timer1InterruptEnable();
    char data[0x50] = "" ;
    
    while(1){
        
        
        
        count++;
        count = count % 20;
        sprintf(data,"%d \r\n", count);
        sendVariables(data);

    }
}


/* ------------------------------------------------------------ */
/*				interrupts functions     	     				*/
/* ------------------------------------------------------------ */


void timer1Interrupt(void)
{
 
    
    
}