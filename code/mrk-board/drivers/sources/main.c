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
#include "acl.h"

/* ------------------------------------------------------------ */
/*				global variables								*/
/* ------------------------------------------------------------ */

long angle1, angle2, angle3, angle4, motorSelect=1;
unsigned short ax,ay,az;
char button1=0, button2=0, button1_old=0, button2_old=0;
char button1Change=0, button2Change=0;
char txt[17];

/* ------------------------------------------------------------ */
/*				   functions    								*/
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*				main function     								*/
/* ------------------------------------------------------------ */
void main (void)
{   
    

    initIO();
    initBuzzer();
    initServo();
    //setLeds(0xa);
    //initDelay();
    //initSonar();
    initAnalogInputs(1);
    initLCD();
    //initIR_range();
    //initLS1();
    //initMotors();
    initTimer1(6250, T1_PS_1_64); // 10 interrupts per second

    timer1InterruptEnable();
    while(1){
        //sprintf(txt, "%3d %3d %3d %3d ",angle1, angle2, angle3, angle4);
        sprintf(txt, "%4d  %4d  %4d",ax, ay, az);
        writeLine(txt,0);
        sprintf(txt, "%3d             ",motorSelect);
        writeLine(txt,1);
        
    }
}


/* ------------------------------------------------------------ */
/*				interrupts functions     	     				*/
/* ------------------------------------------------------------ */


void timer1Interrupt(void)
{
    
    button1 = getButton1(); // get new button state
    button2 = getButton2();
    button1Change = button1 - button1_old;
    button2Change = button2 - button2_old;
    button1_old = button1;  // store current button state for next interrupt
    button2_old = button2;
    
    
    
    // on push (button1)
    // =================
    // we select servo motor with button 1 
    if(button1Change == 1){ 
        motorSelect+=1;
        if (motorSelect>4)
            motorSelect=1;
        
    
    }
    // on release (button2)
    // ====================
    // we assign new servo angle on button 2 release
    if(button2Change == -1){
        setServo1Angle(angle1);
        setServo2Angle(angle2);
        setServo3Angle(angle3);
        setServo4Angle(angle4);
    
    }
    
    // on every timer1 interrupt
    // =========================    
    switch(motorSelect){
        case 1: 
            angle1 = readADC(0)*180/1023;
            break;
        case 2: 
            angle2 = readADC(0)*180/1023;
            break;
        case 3: 
            angle3 = readADC(0)*180/1023;
            break;
        case 4: 
            angle4 = readADC(0)*180/1023;
            break;
    }    


}