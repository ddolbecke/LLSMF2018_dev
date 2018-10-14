#include "drivers.h"
#include "pic18f45k20.h"

void init(void){
    TRISD = 0;
    INTCON2bits.RBPU = 0;	// enable PORTB internal pullups
    WPUBbits.WPUB0 = 1;		// enable pull up on RB0
    ANSELH = 0x00;              // AN8-12 are digital inputs (AN12 on RB0)
    TRISBbits.TRISB0 = 1;       // PORTB bit 0 (connected to switch) is input (1)
    ADC_Init();
}


void interruptEnable(void){
    // Set up global interrupts
    RCONbits.IPEN = 1;          // Enable priority levels on interrupts
    INTCONbits.GIEL = 1;        // Low priority interrupts allowed
    INTCONbits.GIEH = 1;        // Interrupting enabled.

}
void interruptDisable(void){
    INTCONbits.GIE = 0;
}

void buttonInterruptEnable(void){
    INTCON2bits.INTEDG0 = 0;    // interrupt on falling edge of INT0 (switch pressed)
    INTCONbits.INT0IF = 0;      // ensure flag is cleared
    INTCONbits.INT0IE = 1;      // enable INT0 interrupt
}
void buttonInterruptDisable(void){
    INTCONbits.INT0IE = 0;
}

void clearButtonInterruptRequest(void){
    INTCONbits.INT0IF = 0;
}

void timerInterruptEnable(void){

    INTCONbits.PEIE = 1; // enable peripheral interrupts (like timer interrupts)
    INTCONbits.T0IF = 0;
    INTCONbits.T0IE = 1;
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

void setLeds(char x){
    LATD = x;
}

void loadTimer(unsigned short data){
    TMR0H = data>>8;    // Write upper byte first
    TMR0L = data & 0x00FF;

}

unsigned char getVoltage(void)
{
    return ADC_Convert();
}

char getButton(void){
    return !PORTBbits.RB0;
}


void ADC_Init(void)
{ // initialize the Analog-To-Digital converter.
    // First, we need to make sure the AN0 pin is enabled as an analog input
    // as the demo board potentiometer is connected to RA0/AN0
    // Don't forget that RB0/AN12 must be digital!
	ANSEL = 0;	//turn off all other analog inputs
	ANSELH = 0;
 	ANSELbits.ANS0 = 1;	// turn on RA0 analog

    // Sets bits VCFG1 and VCFG0 in ADCON1 so the ADC voltage reference is VSS to VDD

    ADCON1 = 0;

    // The ADC clock must as short as possible but still greater than the
    // minimum TAD time, datasheet parameter 130.  At the time this lesson was
    // written TAD minimum for the PIC18F45K20 is 1.4us.
    // At 1MHz clock, selecting ADCS = FOSC/2 = 500kHz.  One clock period
    // 1 / 500kHz = 2us, which greater than minimum required 1.4us.
    // So ADCON2 bits ADCS2-0 = 000
    //
    // The ACQT aquisition time should take into accound the internal aquisition
    // time TACQ of the ADC, datasheet paramter 130, and the settling time of
    // of the application circuit connected to the ADC pin.  Since the actual
    // settling time of the RC circuit with the demo board potentiometer is very
    // long but accuracy is not very important to this demo, we'll set ACQT2-0 to
    // 20TAD = 111
    //
    // ADFM = 0 so we can easily read the 8 Most Significant bits from the ADRESH
    // Special Function Register
    ADCON2 = 0b00111000;

    // Select channel 0 (AN0) to read the potentiometer voltage and turn on ADC
    ADCON0 = 0b00000001;
}

unsigned char ADC_Convert(void)
{ // start an ADC conversion and return the 8 most-significant bits of the result
    ADCON0bits.GO_DONE = 1;             // start conversion
    while (ADCON0bits.GO_DONE == 1);    // wait for it to complete
    return ADRESH;                      // return high byte of result
}


// function that check if the button interrupt was requested
char isButtonInterruptRequested(){return INTCONbits.INT0IF;}

// function that check if the timer interrupt was requested
char isTimerInterruptRequested(){return INTCONbits.T0IF;}
