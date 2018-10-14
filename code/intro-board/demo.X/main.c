#include "drivers.h"

void loseSomeTime(long cptMax)
{
	long cpt;
	for(cpt = 0; cpt<cptMax; cpt++){  }
}

void ex01(void)
{
    setLeds(0xaa);
}

void ex02(void)
{
    char leds = 0x55;
    setLeds(leds);
}

void ex03(void)
{
    char leds = 1;
    char i = 1;

    while(i<4){
        i = i + 1;
        leds = leds*i;
    }
    setLeds(leds);
}

void ex04(void)
{
    char leds = 1;
    char i;

    for(i=1;i<=4;i=i+1){
            leds = leds*i;
    }
    setLeds(leds);
}

void ex05(void){
    char leds = 0xaa;

    while(1){
            leds = leds^0xff;
            setLeds(leds);
    }
}

void ex06(void){
    char leds = 0;
    long cpt;

    leds = 0;
    while(1){
            leds = leds^0xf0;
            setLeds(leds);
            for(cpt = 0; cpt<10000; cpt++)
            {
            }
    }
}

void ex07(void){
    char leds = 0;
    long cpt;

    leds = 0;
    while(1){
        leds = leds^0xF0;
        setLeds(leds);
        loseSomeTime(1000);
    }
}

void ex08(void){
    unsigned char voltage;

    while(1){
        voltage = getVoltage();
        setLeds(voltage);
    }
}

void ex09(void){
    char leds = 0;
    short voltage;

    while(1){
            voltage  = getVoltage();
            loseSomeTime( (long) voltage*16);
            leds ^= 0xff;
            setLeds(leds);
    }
}

void ex10(void){
    char leds = 0; 
    short voltage; 

    leds = 0;
    while(1){
        loseSomeTime((long)getVoltage()*16);
        leds ^= 0xff;
        setLeds(leds);
    }
}

void ex11(void){
    unsigned char voltage;

    while(1)
    {
        voltage = getVoltage();
        while(!getButton()){
            setLeds(0xff);
        }
        setLeds(0);
    }
}

void ex12(void){
    while(1){
        if(getButton()){
            setLeds(0xff);
            loseSomeTime( 40 );
            setLeds(0x00);
            loseSomeTime( 10 );  }

        else{
            setLeds(0xff);
            loseSomeTime( 10 );
            setLeds(0x00);
            loseSomeTime( 40 );  }
    }
}

void ex13(void){
    char leds;
    while(1){
        leds = 'G';
        setLeds(leds);
    }
}

void ex14(void){
    signed char i;
    unsigned char table[8]={0b10000000, \
           0b11000000, 0b11100000, 0b11110000, \
           0b11111000, 0b11111100, 0b11111110,\
           0b11111111};
    setLeds(0);
    while(1){
        for (i=0; i<8; i++){
            loseSomeTime((long)getVoltage()*10);
            setLeds(table[i]);
        }
    }
}

void main (void)
{
    // microcontroler configuration
    init();

    ex14(); // Change it from ex01 to ex14
}

