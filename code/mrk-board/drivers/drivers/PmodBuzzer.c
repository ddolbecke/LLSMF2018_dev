#include "PmodBuzzer.h"


#ifdef BUZZER_CONNECTED_TO_JE1
#define BUZZER_TRIS0 TRISDbits.TRISD14
#define BUZZER_TRIS1 TRISFbits.TRISF8
#define BUZZER_TRIS2 TRISFbits.TRISF2
#define BUZZER_TRIS3 TRISDbits.TRISD15


#define BUZZER_LAT0 LATDbits.LATD14
#define BUZZER_LAT1 LATFbits.LATF8
#define BUZZER_LAT2 LATFbits.LATF2
#define BUZZER_LAT3 LATDbits.LATD15

#endif

void initBuzzer() {
    BUZZER_TRIS0 = 0;
    BUZZER_TRIS1 = 0;
    BUZZER_TRIS2 = 0;
    BUZZER_TRIS3 = 0;
}

void setBuzzer(unsigned char buzz) {
    BUZZER_LAT0 = buzz & 0b0001;
    BUZZER_LAT1 = (buzz & 0b0010) >> 1;
    BUZZER_LAT2 = (buzz & 0b0100) >> 2;
    BUZZER_LAT3 = (buzz & 0b1000) >> 3;
}
void setBuzzer0(unsigned char buzz) {
    BUZZER_LAT0 = buzz;
}
void setBuzzer1(unsigned char buzz) {
    BUZZER_LAT1 = buzz;
}
void setBuzzer2(unsigned char buzz) {
    BUZZER_LAT2 = buzz;
}
void setBuzzer3(unsigned char buzz) {
    BUZZER_LAT3 = buzz;
}

