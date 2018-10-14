#include "drivers.h"

unsigned char leds = 0;

void main (void)
{
    
    init();
    interruptEnable();
    buttonInterruptEnable();
    initTimer(0b011,0);
    timerInterruptEnable();
    loadTimer(62500);
    while(1){
        setLeds(leds);
    }
}

void interrupt buttonInterrupt(void)
{
    leds=0;
    clearButtonInterruptRequest();    
}

void interrupt low_priority timerInterrupt(void)
{
    leds++;
    loadTimer(62500);
    clearTimerInterruptRequest();
}

