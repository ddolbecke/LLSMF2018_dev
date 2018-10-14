#include "drivers.h"

void lowSpeedInterrupt(void);
void highSpeedInterrupt(void);
void setLedx(char x);
void resetLedx(char x);

unsigned char leds = 0;
long interruptCount = 0;
char lowSpeedInterruptCount = 0;
char first = 2;
char second = 1;
char third = 0;
char direction = 1; // 0: down; 1: up

void main (void)
{
    unsigned char m = 0xF;
    init();
    interruptEnable();
    buttonInterruptEnable();
    initTimer(0b010,0);
    timerInterruptEnable();
    //leds = 0xff;
    loadTimer(65535);
    while(1){

        setLeds(leds);
    }
}

void interrupt buttonInterrupt(void)
{
    leds=0x00;
    clearButtonInterruptRequest();
    
}

void interrupt low_priority timerInterrupt(void)
{
    interruptCount++;
    if(interruptCount>10){
        interruptCount=1;
        lowSpeedInterrupt();
    }
    highSpeedInterrupt();
    clearTimerInterruptRequest(); 
}

void lowSpeedInterrupt(void){
    lowSpeedInterruptCount++;
    if (lowSpeedInterruptCount>4){
        lowSpeedInterruptCount=0;

        third = second;
        second = first;

        if (direction){
            first++;
            if (first==7)
              direction = 0;
        }
        else{
            first--;
            if (first==0)
                direction = 1;

        }
    }

}

void highSpeedInterrupt(void){
    loadTimer(65500);
    if(interruptCount==1){
        setLedx(first);
        setLedx(second);
        setLedx(third);
    }
    if(interruptCount==2){
        resetLedx(third);
    }
    if(interruptCount==4){
        resetLedx(second);
    }

}

void setLedx(char x){
    unsigned char mask = 0x01;
    mask = mask<<x;
    leds |= mask;
}

void resetLedx(char x){
    unsigned char mask = 0x01;
    mask = ~(mask<<x);
    leds &= mask;
}


