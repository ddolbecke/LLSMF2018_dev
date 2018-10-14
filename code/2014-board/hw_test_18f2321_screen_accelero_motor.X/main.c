#include "drivers.h"
#include "lcd.h"
#include "adc.h"
#include <stdio.h>

unsigned char acceleration[17]   = "                ";
unsigned char countStr[17]   = "                ";
unsigned short ax=0;
unsigned char count = 0;
unsigned char out = 0x01;

void main (void)
{

    init();
    lcd_init();
    adc_init();
    interruptEnable();
    sensorInterruptEnable(); // high priority
    buttonInterruptEnable(0); // high priority
    LATC=0;
    TRISC = 0;
    while(1) {
       ax = getAxy();
       sprintf(acceleration, "ax= %4d        ", ax);
       sprintf(countStr,     "count= %4d     ", count);
       lcd_write(acceleration,1);
       lcd_write(countStr,2);
       setLedG(out);
       setLedR(!out);
       
       
    }
}


void interrupt hpInterrupt(void)
{
    count++;
    clearSensorInterruptRequest();
    
}


void interrupt low_priority lpInterrupt(void)
{
    out ^= 1;
    LATCbits.LATC0 = out;
    clearButtonInterruptRequest();
}
