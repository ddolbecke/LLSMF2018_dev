#include "drivers.h"

unsigned char leds = 0xaa;

void main (void)
{
    //unsigned char m = 0xF;
    init();
    //interruptEnable();
    //buttonInterruptEnable();
    //initTimer(0b011,0);
    //timerInterruptEnable();
    //loadTimer(62500);
    leds=0xaa;
    while(1){
        setLeds(leds);
    }
}

void interrupt buttonInterrupt(void)
{
    //leds^=0xff;
    clearButtonInterruptRequest();
    
}

void interrupt low_priority timerInterrupt(void)
{
    //leds++;
    //loadTimer(62500);
    clearTimerInterruptRequest();
}

