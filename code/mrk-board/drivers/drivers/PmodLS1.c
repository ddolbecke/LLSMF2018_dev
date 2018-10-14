#include "PmodLS1.h"



#ifdef IR_PROX_CONNECTED_TO_JC2
#define IR_PROX_TRIS0 TRISGbits.TRISG0
#define IR_PROX_TRIS1 TRISGbits.TRISG1
#define IR_PROX_TRIS2 TRISFbits.TRISF0
#define IR_PROX_TRIS3 TRISFbits.TRISF1

#define IR_PROX_PORT0 PORTGbits.RG0
#define IR_PROX_PORT1 PORTGbits.RG1
#define IR_PROX_PORT2 PORTFbits.RF0
#define IR_PROX_PORT3 PORTFbits.RF1
#endif


#ifdef IR_PROX_CONNECTED_TO_JJ1
#define IR_PROX_TRIS0 TRISBbits.TRISB0
#define IR_PROX_TRIS1 TRISBbits.TRISB1
#define IR_PROX_TRIS2 TRISBbits.TRISB2
#define IR_PROX_TRIS3 TRISBbits.TRISB3

#define IR_PROX_PORT0 PORTBbits.RB0
#define IR_PROX_PORT1 PORTBbits.RB1
#define IR_PROX_PORT2 PORTBbits.RB2
#define IR_PROX_PORT3 PORTBbits.RB3
#endif
#ifdef IR_PROX_CONNECTED_TO_JJ2
#define IR_PROX_TRIS0 TRISBbits.TRISB4
#define IR_PROX_TRIS1 TRISBbits.TRISB5
#define IR_PROX_TRIS2 TRISBbits.TRISB8
#define IR_PROX_TRIS3 TRISBbits.TRISB9

#define IR_PROX_PORT0 PORTBbits.RB4
#define IR_PROX_PORT1 PORTBbits.RB5
#define IR_PROX_PORT2 PORTBbits.RB8
#define IR_PROX_PORT3 PORTBbits.RB9
#endif
#ifdef IR_PROX_CONNECTED_TO_JA1
#define IR_PROX_TRIS0 TRISEbits.TRISE0
#define IR_PROX_TRIS1 TRISEbits.TRISE1
#define IR_PROX_TRIS2 TRISEbits.TRISE2
#define IR_PROX_TRIS3 TRISEbits.TRISE3

#define IR_PROX_PORT0 PORTEbits.RE0
#define IR_PROX_PORT1 PORTEbits.RE1
#define IR_PROX_PORT2 PORTEbits.RE2
#define IR_PROX_PORT3 PORTEbits.RE3
#endif
#ifdef IR_PROX_CONNECTED_TO_JA2
#define IR_PROX_TRIS0 TRISEbits.TRISE4
#define IR_PROX_TRIS1 TRISEbits.TRISE5
#define IR_PROX_TRIS2 TRISEbits.TRISE6
#define IR_PROX_TRIS3 TRISEbits.TRISE7

#define IR_PROX_PORT0 PORTEbits.RE4
#define IR_PROX_PORT1 PORTEbits.RE5
#define IR_PROX_PORT2 PORTEbits.RE6
#define IR_PROX_PORT3 PORTEbits.RE7
#endif
#ifdef IR_PROX_CONNECTED_TO_JD1
#define IR_PROX_TRIS0 TRISDbits.TRISD7
#define IR_PROX_TRIS1 TRISDbits.TRISD1
#define IR_PROX_TRIS2 TRISDbits.TRISD9
#define IR_PROX_TRIS3 TRISCbits.TRISC1

#define IR_PROX_PORT0 PORTDbits.RD7
#define IR_PROX_PORT1 PORTDbits.RD1
#define IR_PROX_PORT2 PORTDbits.RD9
#define IR_PROX_PORT3 PORTCbits.RC1
#endif
#ifdef IR_PROX_CONNECTED_TO_JE1
#define IR_PROX_TRIS0 TRISDbits.TRISD14
#define IR_PROX_TRIS1 TRISFbits.TRISF8
#define IR_PROX_TRIS2 TRISFbits.TRISF2
#define IR_PROX_TRIS3 TRISDbits.TRISD15

#define IR_PROX_PORT0 PORTDbits.RD14
#define IR_PROX_PORT1 PORTFbits.RF8
#define IR_PROX_PORT2 PORTFbits.RF2
#define IR_PROX_PORT3 PORTDbits.RD15
#endif





void initLS1() {
    IR_PROX_TRIS0 = 1;
    IR_PROX_TRIS1 = 1;
    IR_PROX_TRIS2 = 1;
    IR_PROX_TRIS3 = 1;
}
unsigned char getLS1_1() {
    return IR_PROX_PORT0;
}
unsigned char getLS1_2() {
    return IR_PROX_PORT1;
}
unsigned char getLS1_3() {
    return IR_PROX_PORT2;
}
unsigned char getLS1_4() {
    return IR_PROX_PORT3;
}
