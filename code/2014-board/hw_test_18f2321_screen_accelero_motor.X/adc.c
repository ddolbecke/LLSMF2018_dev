#include "adc.h"
#include "drivers.h"

void adc_init(void) {
    ADCON0bits.CHS = 0b1000;    // AN08 input

    ADCON0bits.ADON = 1;

    ADCON1bits.VCFG1 = 0;
    ADCON1bits.VCFG0 = 0;

    ADCON1bits.PCFG = 0b0110; // AN8 is analog but not the 12 (sensor)

    ADCON2bits.ADFM = 1;

    ADCON2bits.ACQT = 0b111;
    ADCON2bits.ADCS = 0b000;
}

unsigned short getAz(void) {
    ADCON0bits.CHS = 0b1100;    // AN12 input
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE);
    return (unsigned short) ((ADRESH&0x03)<<8) | (ADRESL & 0xFF);
}

unsigned short getAxy(void) {
    ADCON0bits.CHS = 0b1000;    // AN08 input
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE);
    return (unsigned short) ((ADRESH&0x03)<<8) | (ADRESL & 0xFF);
}

