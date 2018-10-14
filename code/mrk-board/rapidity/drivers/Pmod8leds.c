#include "Pmod8leds.h"

#ifdef LEDS_CONNECTED_TO_JA
#define LED_TRIS0 TRISEbits.TRISE0
#define LED_TRIS1 TRISEbits.TRISE1
#define LED_TRIS2 TRISEbits.TRISE2
#define LED_TRIS3 TRISEbits.TRISE3
#define LED_TRIS4 TRISEbits.TRISE4
#define LED_TRIS5 TRISEbits.TRISE5
#define LED_TRIS6 TRISEbits.TRISE6
#define LED_TRIS7 TRISEbits.TRISE7

#define LED_LAT0 LATEbits.LATE0
#define LED_LAT1 LATEbits.LATE1
#define LED_LAT2 LATEbits.LATE2
#define LED_LAT3 LATEbits.LATE3
#define LED_LAT4 LATEbits.LATE4
#define LED_LAT5 LATEbits.LATE5
#define LED_LAT6 LATEbits.LATE6
#define LED_LAT7 LATEbits.LATE7
#endif
#ifdef LEDS_CONNECTED_TO_JB
#define LED_TRIS0 TRISGbits.TRISG9
#define LED_TRIS1 TRISGbits.TRISG8
#define LED_TRIS2 TRISGbits.TRISG7
#define LED_TRIS3 TRISGbits.TRISG6
#define LED_TRIS4 TRISBbits.TRISB15
#define LED_TRIS5 TRISDbits.TRISD5
#define LED_TRIS6 TRISDbits.TRISD4
#define LED_TRIS7 TRISBbits.TRISB14

#define LED_LAT0 LATGbits.LATG9
#define LED_LAT1 LATGbits.LATG8
#define LED_LAT2 LATGbits.LATG7
#define LED_LAT3 LATGbits.LATG6
#define LED_LAT4 LATBbits.LATB15
#define LED_LAT5 LATDbits.LATD5
#define LED_LAT6 LATDbits.LATD4
#define LED_LAT7 LATBbits.LATB14
#endif
#ifdef LEDS_CONNECTED_TO_JC
#define LED_TRIS0 TRISGbits.TRISG12
#define LED_TRIS1 TRISGbits.TRISG13
#define LED_TRIS2 TRISGbits.TRISG14
#define LED_TRIS3 TRISGbits.TRISG15
#define LED_TRIS4 TRISGbits.TRISG0
#define LED_TRIS5 TRISGbits.TRISG1
#define LED_TRIS6 TRISFbits.TRISF0
#define LED_TRIS7 TRISFbits.TRISF1

#define LED_LAT0 LATGbits.LATG12
#define LED_LAT1 LATGbits.LATG13
#define LED_LAT2 LATGbits.LATG14
#define LED_LAT3 LATGbits.LATG15
#define LED_LAT4 LATGbits.LATG0
#define LED_LAT5 LATGbits.LATG1
#define LED_LAT6 LATFbits.LATF0
#define LED_LAT7 LATFbits.LATF1
#endif
#ifdef LEDS_CONNECTED_TO_JD
#define LED_TRIS0 TRISDbits.TRISD7
#define LED_TRIS1 TRISDbits.TRISD1
#define LED_TRIS2 TRISDbits.TRISD9
#define LED_TRIS3 TRISCbits.TRISC1
#define LED_TRIS4 TRISDbits.TRISD6
#define LED_TRIS5 TRISDbits.TRISD2
#define LED_TRIS6 TRISDbits.TRISD10
#define LED_TRIS7 TRISCbits.TRISC2

#define LED_LAT0 LATGbits.LATG12
#define LED_LAT1 LATGbits.LATG13
#define LED_LAT2 LATGbits.LATG14
#define LED_LAT3 LATGbits.LATG15
#define LED_LAT4 LATGbits.LATG0
#define LED_LAT5 LATGbits.LATG1
#define LED_LAT6 LATFbits.LATF0
#define LED_LAT7 LATFbits.LATF1
#endif
#ifdef LEDS_CONNECTED_TO_JE
#define LED_TRIS0 TRISDbits.TRISD14
#define LED_TRIS1 TRISFbits.TRISF8
#define LED_TRIS2 TRISFbits.TRISF2
#define LED_TRIS3 TRISDbits.TRISD15
#define LED_TRIS4 TRISEbits.TRISE9
#define LED_TRIS5 TRISDbits.TRISD3
#define LED_TRIS6 TRISDbits.TRISD11
#define LED_TRIS7 TRISCbits.TRISC3

#define LED_LAT0 LATDbits.LATD14
#define LED_LAT1 LATFbits.LATF8
#define LED_LAT2 LATFbits.LATF2
#define LED_LAT3 LATDbits.LATD15
#define LED_LAT4 LATEbits.LATE9
#define LED_LAT5 LATDbits.LATD3
#define LED_LAT6 LATDbits.LATD11
#define LED_LAT7 LATCbits.LATC3
#endif
#ifdef LEDS_CONNECTED_TO_JF
#define LED_TRIS0 TRISAbits.TRISA14
#define LED_TRIS1 TRISAbits.TRISA15
#define LED_TRIS2 TRISAbits.TRISA6
#define LED_TRIS3 TRISAbits.TRISA7
#define LED_TRIS4 TRISAbits.TRISA0
#define LED_TRIS5 TRISAbits.TRISA1
#define LED_TRIS6 TRISAbits.TRISA4
#define LED_TRIS7 TRISAbits.TRISA5

#define LED_LAT0 LATAbits.LATA14
#define LED_LAT1 LATAbits.LATA15
#define LED_LAT2 LATAbits.LATA6
#define LED_LAT3 LATAbits.LATA7
#define LED_LAT4 LATAbits.LATA0
#define LED_LAT5 LATAbits.LATA1
#define LED_LAT6 LATAbits.LATA4
#define LED_LAT7 LATAbits.LATA5
#endif
#ifdef LEDS_CONNECTED_TO_JH
#define LED_TRIS0 TRISFbits.TRISF12
#define LED_TRIS1 TRISFbits.TRISF5
#define LED_TRIS2 TRISFbits.TRISF4
#define LED_TRIS3 TRISFbits.TRISF13
#define LED_TRIS4 TRISEbits.TRISE8
#define LED_TRIS5 TRISDbits.TRISD0
#define LED_TRIS6 TRISDbits.TRISD8
#define LED_TRIS7 TRISDbits.TRISD13

#define LED_LAT0 LATFbits.LATF12
#define LED_LAT1 LATFbits.LATF5
#define LED_LAT2 LATFbits.LATF4
#define LED_LAT3 LATFbits.LATF13
#define LED_LAT4 LATEbits.LATE8
#define LED_LAT5 LATDbits.LATD0
#define LED_LAT6 LATDbits.LATD8
#define LED_LAT7 LATDbits.LATD13
#endif
#ifdef LEDS_CONNECTED_TO_JK
#define LED_TRIS0 TRISBbits.TRISB10
#define LED_TRIS1 TRISBbits.TRISB11
#define LED_TRIS2 TRISBbits.TRISB12
#define LED_TRIS3 TRISBbits.TRISB13
#define LED_TRIS4 TRISAbits.TRISA9
#define LED_TRIS5 TRISAbits.TRISA10
#define LED_TRIS6 TRISDbits.TRISD12
#define LED_TRIS7 TRISCbits.TRISC4

#define LED_LAT0 LATBbits.LATB10
#define LED_LAT1 LATBbits.LATB11
#define LED_LAT2 LATBbits.LATB12
#define LED_LAT3 LATBbits.LATB13
#define LED_LAT4 LATAbits.LATA9
#define LED_LAT5 LATAbits.LATA10
#define LED_LAT6 LATDbits.LATD12
#define LED_LAT7 LATCbits.LATC4
#endif


void init8Leds() {
    LED_TRIS0 = 0;
    LED_TRIS1 = 0;
    LED_TRIS2 = 0;
    LED_TRIS3 = 0;
    LED_TRIS4 = 0;
    LED_TRIS5 = 0;
    LED_TRIS6 = 0;
    LED_TRIS7 = 0;
}

void set8Leds(unsigned char leds) {
    LED_LAT0 = leds & 0b00000001;
    LED_LAT1 = (leds & 0b00000010) >> 1;
    LED_LAT2 = (leds & 0b00000100) >> 2;
    LED_LAT3 = (leds & 0b00001000) >> 3;
    LED_LAT4 = (leds & 0b00010000) >> 4;
    LED_LAT5 = (leds & 0b00100000) >> 5;
    LED_LAT6 = (leds & 0b01000000) >> 6;
    LED_LAT7 = (leds & 0b10000000) >> 7;
}
void set8Leds0(unsigned char led) {
    LED_LAT0 = led;
}
void set8Leds1(unsigned char led) {
    LED_LAT1 = led;
}
void set8Leds2(unsigned char led) {
    LED_LAT2 = led;
}
void set8Leds3(unsigned char led) {
    LED_LAT3 = led;
}
void set8Leds4(unsigned char led) {
    LED_LAT4 = led;
}
void set8Leds5(unsigned char led) {
    LED_LAT5 = led;
}
void set8Leds6(unsigned char led) {
    LED_LAT6 = led;
}
void set8Leds7(unsigned char led) {
    LED_LAT7 = led;
}
