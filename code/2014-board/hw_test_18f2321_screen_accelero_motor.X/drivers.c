#include "drivers.h"

void init(void){
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    INTCON2bits.RBPU = 0;		// enable PORTB internal pullups
    TRISBbits.TRISB0 = 1;       // PORTB bit 0 (connected to switch) is input (1)
}

void interruptEnable(void){
    // Set up global interrupts
    RCONbits.IPEN = 1;          // Enable priority levels on interrupts
    INTCONbits.GIEL = 1;        // Low priority interrupts allowed
    INTCONbits.GIEH = 1;        // Interrupting enabled
}

void interruptDisable(void){
    INTCONbits.GIE = 0;
}

void loadTimer(unsigned short data){
    TMR0H = data>>8;    // Write upper byte first
    TMR0L = data & 0x00FF;
}

void buttonInterruptEnable(char priority){
    INTCON2bits.INTEDG1 = 0;    // interrupt on falling edge of INT0 (switch pressed)
    INTCON3bits.INT1IF = 0;      // ensure flag is cleared
    INTCON3bits.INT1IE = 1;      // enable INT0 interrupt
    INTCON3bits.INT1IP = priority;
}

void buttonInterruptDisable(void){
    INTCON3bits.INT1IE = 0;
}

void clearButtonInterruptRequest(void){
    INTCON3bits.INT1IF = 0;
}

void timerInterruptEnable(void){
    INTCONbits.PEIE = 1; // enable peripheral interrupts (like timer interrupts)
    INTCONbits.T0IF = 0; // get interrupted imediatly
    INTCONbits.T0IE = 1;
    TMR0H = 0;                      // always write upper byte first
    TMR0L = 0;
}

void timerInterruptDisable(void){
    INTCONbits.T0IE = 0;
}

void clearTimerInterruptRequest(void){
    INTCONbits.T0IF = 0;
}

void initTimer(unsigned char prescaler, unsigned char priority){
    T0CON = 0b10000000 | prescaler;
    INTCON2bits.TMR0IP = priority;
    if(priority)
        RCONbits.IPEN = 1;
}

void setLedG(char x){
    LATAbits.LA0 = x;
}

void setLedR(char x){
    LATAbits.LA1 = x;
}

char getButton(void){
    return !PORTBbits.RB1;
}

void clearSensorInterruptRequest(void){
    INTCONbits.INT0IF = 0;
}

void sensorInterruptEnable(void){
    INTCONbits.INT0IE = 1;
}

void sensorInterruptDisable(void){
    INTCONbits.INT0IE = 0;
}

