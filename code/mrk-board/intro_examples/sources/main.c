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

/* ------------------------------------------------------------ */
/*				global variables								*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				   functions    								*/
/* ------------------------------------------------------------ */
void loseSomeTime(long cptMax)
{
	long cpt;
	for(cpt = 0; cpt<cptMax; cpt++){  }
}

void ex01(void)
{
    initIO();
    setLeds(0xa);
}

void ex02(void)
{
    initIO();
    if(getButton1())
        setLeds( 0b0011 );
    else
        setLeds( 0b1100 );  
}

void ex03(void)
{
    initIO();
    while(1){
        if(getButton1())
            setLeds( 0b0011 );
        else
            setLeds( getButton2() );
    }
}

void ex04(void)
{
    char evenBits = 0x0a;
    char oddBits = 0x05;
    
    initIO();
    while(1){
        if( getButton1() && getButton2() )
            setLeds(evenBits);
        else
            setLeds(oddBits);
    }
}


void ex05(void){
    char leds = 0xa;

    initIO();
    while(1){
            leds = leds^0x3;
            setLeds(leds);
    }
}

void ex06(void){
    char leds = 0b1010;
    long cpt;

    initIO();

    while(1){
            leds = leds^0b0011;
            setLeds(leds);
            for(cpt = 0; cpt<200000; cpt++)
            {
            }
    }
}

void ex07(void){
    char leds = 0;
    initIO();
    while(1){
        leds = leds^0xf;
        setLeds(leds);
        loseSomeTime(200000);
    }
}
void ex08(void){
    char leds = 0;
    
    initIO();
    initDelay();
    leds = 0;
    while(1){
        leds = leds^0xf;
        setLeds(leds);
        DelayMs(300);
    }
}

void ex09(void){
    unsigned short adc;
    initIO();
    initAnalogInputs(0x01);

    while(1){
        adc = readADC(0);
        setLeds(adc/64);
    }
}


void ex10(void)
{
    char strA[16] = "   LLSMF2018    ";
    char strB[16] = "    Demo code   ";
    
    initIO();
    initLCD();
    writeLine(strA, 0);
    writeLine(strB, 1);
}

void ex11(void){
    unsigned short adc;
    char txt[16];
    initIO();
    initAnalogInputs(0x01);
    initLCD();
    while(1){
        adc = readADC(0);
        setLeds(adc/64);
        sprintf(txt,"ADC : %4d        ", adc);
        writeLine(txt,0);
        sprintf(txt,"  U =  %1.1f Volts ", (float) adc/1023*3.3);
        writeLine(txt,1);
    }
}


void ex12(void){
    char leds = 0;
    short adc;
    initIO();
    initDelay();
    initAnalogInputs(1);
    while(1){
            DelayMs( readADC(0) );
            leds ^= 0xf;
            setLeds(leds);
    }
}

void ex13(void){
    initIO(); initDelay();
    while(1){
        if(getButton2()){
            setLeds(0xff);
            DelayUs( 40 );
            setLeds(0x00);
            DelayUs( 10 );  }
        else{
            setLeds(0xff);
            DelayUs( 10 );
            setLeds(0x00);
            DelayUs( 40 );  }
    }
}

void ex14(void){
    initIO();
    initDelay();
    initAnalogInputs(1);
    
    while(1){
            setLeds(0xf);
            DelayUs( (long)(readADC(0)) );
            setLeds(0x0);
            DelayUs( 1023-(long)(readADC(0)) );  
    }
}

void ex15(void){
    char leds;
    initIO();
    while(1){
        leds = 'G';
        setLeds(leds+1);
    }
}

void ex16(void){
    signed char i;
    unsigned char table[5]={0b0000, \
           0b1000, 0b1100, 0b1110, \
           0b1111};
    
    initIO();
    initDelay();
    initAnalogInputs(1);

    setLeds(0);
    while(1){
        for (i=0; i<5; i++){
            DelayMs(readADC(0)+100 );
            setLeds(table[i]);
        }
    }
}

void ex17(void){
    long a =0 , b = 0, c = 0, d = 0, op = 0;
    char selector=0;
    char formula[16], results[16];
    
    initIO();
    initDelay();
    initAnalogInputs(1);
    initLCD();

    while(1){
        setLeds(selector);
        if(getButton2()){
            selector++;
            if(selector>2)
                selector = 0;
            DelayMs(500);
        }
        switch(selector){
            case 0 : 
                a = (long) readADC(0);break;
            case 1 : 
                b = (long) readADC(0);break;
            case 2 : 
                c = (long) readADC(0);break;       
        }
        
        if( b < 300){
            op = '+';
            d = a+c;}
        else if(b < 600){
            op = '-';
            d = a-c;}
        else{
            op = '*';
            d = a*c;}       
        sprintf(formula," %4d  %c  %4d  ",a,op,c);
        sprintf(results," = %7d", d);
        writeLine(formula,0);
        writeLine(results,1);    
    }   
}


/* ------------------------------------------------------------ */
/*				main function     								*/
/* ------------------------------------------------------------ */
void main (void)
{   

    ex17();
}

