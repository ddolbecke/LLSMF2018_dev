#include "PmodSSD.h"

#ifdef SSD_CONNECTED_TO_JJ1_JH1
#define SSD_TRIS0	TRISFbits.TRISF12
#define SSD_TRIS1	TRISFbits.TRISF5
#define SSD_TRIS2	TRISFbits.TRISF4
#define SSD_TRIS3	TRISFbits.TRISF13
#define SSD_TRIS4	TRISBbits.TRISB0
#define SSD_TRIS5	TRISBbits.TRISB1
#define SSD_TRIS6	TRISBbits.TRISB2
#define SSD_TRISCAT	TRISBbits.TRISB3

#define SSD_LAT0	LATFbits.LATF12
#define SSD_LAT1	LATFbits.LATF5
#define SSD_LAT2	LATFbits.LATF4
#define SSD_LAT3	LATFbits.LATF13
#define SSD_LAT4	LATBbits.LATB0
#define SSD_LAT5	LATBbits.LATB1
#define SSD_LAT6	LATBbits.LATB2
#define SSD_LATCAT	LATBbits.LATB3
#endif
#ifdef SSD_CONNECTED_TO_JJ2_JH2
#define SSD_TRIS0	TRISEbits.TRISE8
#define SSD_TRIS1	TRISDbits.TRISD0
#define SSD_TRIS2	TRISDbits.TRISD8
#define SSD_TRIS3	TRISDbits.TRISD13
#define SSD_TRIS4	TRISBbits.TRISB4
#define SSD_TRIS5	TRISBbits.TRISB5
#define SSD_TRIS6	TRISBbits.TRISB6
#define SSD_TRISCAT	TRISBbits.TRISB7

#define SSD_LAT0	LATEbits.LATE8
#define SSD_LAT1	LATDbits.LATD0
#define SSD_LAT2	LATDbits.LATD8
#define SSD_LAT3	LATDbits.LATD13
#define SSD_LAT4	LATBbits.LATB4
#define SSD_LAT5	LATBbits.LATB5
#define SSD_LAT6	LATBbits.LATB6
#define SSD_LATCAT	LATBbits.LATB7
#endif
#ifdef SSD_CONNECTED_TO_JC2_JD2
#define SSD_TRIS0	TRISGbits.TRISG0
#define SSD_TRIS1	TRISGbits.TRISG1
#define SSD_TRIS2	TRISFbits.TRISF0
#define SSD_TRIS3	TRISFbits.TRISF1
#define SSD_TRIS4	TRISDbits.TRISD6
#define SSD_TRIS5	TRISDbits.TRISD2
#define SSD_TRIS6	TRISDbits.TRISD10
#define SSD_TRISCAT	TRISCbits.TRISC2

#define SSD_LAT0	LATGbits.LATG0
#define SSD_LAT1	LATGbits.LATG1
#define SSD_LAT2	LATFbits.LATF0
#define SSD_LAT3	LATFbits.LATF1
#define SSD_LAT4	LATDbits.LATD6
#define SSD_LAT5	LATDbits.LATD2
#define SSD_LAT6	LATDbits.LATD10
#define SSD_LATCAT	LATCbits.LATC2
#endif
#ifdef SSD_CONNECTED_TO_JC1_JD1
#define SSD_TRIS0	TRISGbits.TRISG12
#define SSD_TRIS1	TRISGbits.TRISG13
#define SSD_TRIS2	TRISGbits.TRISG14
#define SSD_TRIS3	TRISGbits.TRISG15
#define SSD_TRIS4	TRISDbits.TRISD7
#define SSD_TRIS5	TRISDbits.TRISD1
#define SSD_TRIS6	TRISDbits.TRISD9
#define SSD_TRISCAT	TRISCbits.TRISC1

#define SSD_LAT0	LATGbits.LATG12
#define SSD_LAT1	LATGbits.LATG13
#define SSD_LAT2	LATGbits.LATG14
#define SSD_LAT3	LATGbits.LATG15
#define SSD_LAT4	LATDbits.LATD7
#define SSD_LAT5	LATDbits.LATD1
#define SSD_LAT6	LATDbits.LATD9
#define SSD_LATCAT	LATCbits.LATC1
#endif

void initSSD() {
    SSD_TRIS0 = 0;
    SSD_TRIS1 = 0;
    SSD_TRIS2 = 0;
    SSD_TRIS3 = 0;
    SSD_TRIS4 = 0;
    SSD_TRIS5 = 0;
    SSD_TRIS6 = 0;
    SSD_TRISCAT = 0;
}

void setSSD(unsigned char segments, unsigned char figure) {
    SSD_LATCAT = figure & 0x01;
    SSD_LAT0 = segments & 0b00000001;
    SSD_LAT1 = (segments & 0b00000010) >> 1;
    SSD_LAT2 = (segments & 0b00000100) >> 2;
    SSD_LAT3 = (segments & 0b00001000) >> 3;
    SSD_LAT4 = (segments & 0b00010000) >> 4;
    SSD_LAT5 = (segments & 0b00100000) >> 5;
    SSD_LAT6 = (segments & 0b01000000) >> 6;
}
