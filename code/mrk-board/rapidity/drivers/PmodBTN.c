#include "PmodBTN.h"

#ifdef BTN_CONNECTED_TO_JJ1
#define BTN_TRIS0 TRISBbits.TRISB0
#define BTN_TRIS1 TRISBbits.TRISB1
#define BTN_TRIS2 TRISBbits.TRISB2
#define BTN_TRIS3 TRISBbits.TRISB3

#define BTN_PORT0 PORTBbits.RB0
#define BTN_PORT1 PORTBbits.RB1
#define BTN_PORT2 PORTBbits.RB2
#define BTN_PORT3 PORTBbits.RB3
#endif
#ifdef BTN_CONNECTED_TO_JJ2
#define BTN_TRIS0 TRISBbits.TRISB4
#define BTN_TRIS1 TRISBbits.TRISB5
#define BTN_TRIS2 TRISBbits.TRISB8
#define BTN_TRIS3 TRISBbits.TRISB9

#define BTN_PORT0 PORTBbits.RB4
#define BTN_PORT1 PORTBbits.RB5
#define BTN_PORT2 PORTBbits.RB8
#define BTN_PORT3 PORTBbits.RB9
#endif
#ifdef BTN_CONNECTED_TO_JA1
#define BTN_TRIS0 TRISEbits.TRISE0
#define BTN_TRIS1 TRISEbits.TRISE1
#define BTN_TRIS2 TRISEbits.TRISE2
#define BTN_TRIS3 TRISEbits.TRISE3

#define BTN_PORT0 PORTEbits.RE0
#define BTN_PORT1 PORTEbits.RE1
#define BTN_PORT2 PORTEbits.RE2
#define BTN_PORT3 PORTEbits.RE3
#endif
#ifdef BTN_CONNECTED_TO_JA2
#define BTN_TRIS0 TRISEbits.TRISE4
#define BTN_TRIS1 TRISEbits.TRISE5
#define BTN_TRIS2 TRISEbits.TRISE6
#define BTN_TRIS3 TRISEbits.TRISE7

#define BTN_PORT0 PORTEbits.RE4
#define BTN_PORT1 PORTEbits.RE5
#define BTN_PORT2 PORTEbits.RE6
#define BTN_PORT3 PORTEbits.RE7
#endif

void initBTN() {
    BTN_TRIS0 = 1;
    BTN_TRIS1 = 1;
    BTN_TRIS2 = 1;
    BTN_TRIS3 = 1;
}
unsigned char getBTN0() {
    return BTN_PORT0;
}
unsigned char getBTN1() {
    return BTN_PORT1;
}
unsigned char getBTN2() {
    return BTN_PORT2;
}
unsigned char getBTN3() {
    return BTN_PORT3;
}
