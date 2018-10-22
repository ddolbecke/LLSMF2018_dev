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
int buzz = 0;
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
    //setLeds(0xa);
    //initDelay();
    //initSonar();
    //initAnalogInputs(1);
   // initLCD();
    //initIR_range();
    //initLS1();
    //initMotors();
    
    initTimer1(625, T1_PS_1_8); // 100 interrupts per second

    timer1InterruptEnable();
    while(1){
       /* if(newKey)
            txt[x] = key;

        writeLine(txt, 1);
        */
        
    }
}


/* ------------------------------------------------------------ */
/*				interrupts functions     	     				*/
/* ------------------------------------------------------------ */


void timer1Interrupt(void)
{
    if(getButton1()){
        if(buzz == 0){
            buzz = 1;
            setBuzzer3(0b1);
        }
        else{
            buzz = 0;
            setBuzzer3(0b00);
        }
    }
   /* rows = keypad_readRows();
    setLeds(rows);
    
    if(rows != 0xf){
        for(row=0; row<4;row++){
            if( ((rows>>row) & 0b0001) == 0 ){
                key = keys[row][col];
                 
                newKey = 1;
                keyReleased = 0;
            }     
        }  
    }
        
 
    
    col+=1;
    if(col>3){
        col = 0;
        if( (keyReleased==1) && (newKey) ){
            x+=1;
            newKey = 0;
            if(x>15)
                x = 0;
        }
        keyReleased = 1;
       
    }
       
    keypad_setCols((1<<col)^0xF);

    
    
    if(button1Released && getButton1()){
        button1Released = 0;   
        x -=1;
        if(x<0)
            x=15;
        txt[x] = ' ';
    }
    if(!getButton1()){
        button1Released = 1;
    }
    
    */
    
}