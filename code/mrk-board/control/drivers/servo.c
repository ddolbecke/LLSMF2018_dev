#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define _SUPPRESS_PLIB_WARNING 1

#include <xc.h>
#include "servo.h"
#include <p32xxxx.h>
#include <plib.h>
#include "interrupts.h"

void setServoAngle(unsigned short angle, unsigned short servoPos)
{
    switch (servoPos)
    {
        case 1:
            servo_angle1 = angle;
            break;
        case 2:
            servo_angle2 = angle;
            break;
        case 3:
            servo_angle3 = angle;
            break;
        case 4:
            servo_angle4 = angle;
            break;
        case 5:
            servo_angle5 = angle;
            break;
        case 6:
            servo_angle6 = angle;
            break;
        case 7:
            servo_angle7 = angle;
            break;
        case 8:
            servo_angle8 = angle;
            break;
    }
    
}

void initServo() {
    enable10usInterrupts();
    
    #ifdef SERVO_CONNECTED_TO_S1
        TRISGbits.TRISG12 = 0;	// S1-JC1-RG12 (selected by default)
    #endif
    #ifdef SERVO_CONNECTED_TO_S2
        TRISGbits.TRISG13 = 0;	// S2-JC2-RG13
    #endif
    #ifdef SERVO_CONNECTED_TO_S3
        TRISGbits.TRISG14 = 0;	// S3-JC3-RG14
    #endif
    #ifdef SERVO_CONNECTED_TO_S4
        TRISGbits.TRISG15 = 0;	// S4-JC4-RG15
    #endif
    #ifdef SERVO_CONNECTED_TO_S5
        TRISGbits.TRISG0 = 0;	// S5-JC7-RG00
    #endif
    #ifdef SERVO_CONNECTED_TO_S6
        TRISGbits.TRISG1 = 0;	// S6-JC8-RG01
    #endif
    #ifdef SERVO_CONNECTED_TO_S7
        TRISFbits.TRISF0 = 0;	// S7-JC9-RF00
    #endif
    #ifdef SERVO_CONNECTED_TO_S8
        TRISFbits.TRISF1 = 0;	// S8-JC10-RF1
    #endif

    servo_count = 0;		    //
    servo_angle1 = 0;		    // from 0 to 180 (750us to 2550us)
    servo_angle2 = 0;
    servo_angle3 = 0;
    servo_angle4 = 0;
    servo_angle5 = 0;
    servo_angle6 = 0;
    servo_angle7 = 0;
    servo_angle8 = 0;
}


void servo10usRoutine(void)
{
    servo_count++;
    
    if (servo_angle1 > 179)
        servo_angle1 = 179;
    if (servo_angle2 > 179)
        servo_angle2 = 179;
    if (servo_angle3 > 179)
        servo_angle3 = 179;
    if (servo_angle4 > 179)
        servo_angle4 = 179;
    if (servo_angle5 > 179)
        servo_angle5 = 179;
    if (servo_angle6 > 179)
        servo_angle6 = 179;
    if (servo_angle7 > 179)
        servo_angle7 = 179;
    if (servo_angle8 > 179)
        servo_angle8 = 179;
    
    #ifdef SERVO_CONNECTED_TO_S1
        LATGbits.LATG12 = servo_count < (servo_angle1 + 75); // min.750us;max.2550us (10us per degree)	// S1-JC1-RG12 (selected by default)
       #endif
    #ifdef SERVO_CONNECTED_TO_S2
        LATGbits.LATG13 = servo_count < (servo_angle2 + 75);	// S2-JC2-RG13
        #endif
    #ifdef SERVO_CONNECTED_TO_S3
        LATGbits.LATG14 = servo_count < (servo_angle3 + 75);	// S3-JC3-RG14
        #endif
    #ifdef SERVO_CONNECTED_TO_S4
        LATGbits.LATG15 = servo_count < (servo_angle4 + 75);	// S4-JC4-RG15
        #endif
    #ifdef SERVO_CONNECTED_TO_S5
        LATGbits.LATG0 = servo_count < (servo_angle5 + 75);	// S5-JC7-RG00
        #endif
    #ifdef SERVO_CONNECTED_TO_S6
        LATGbits.LATG1 = servo_count < (servo_angle6 + 75);	// S6-JC8-RG01
        #endif
    #ifdef SERVO_CONNECTED_TO_S7
        LATFbits.LATF0 = servo_count < (servo_angle7 + 75);	// S7-JC9-RF00
        #endif
    #ifdef SERVO_CONNECTED_TO_S8
        LATFbits.LATF1 = servo_count < (servo_angle8 + 75);	// S8-JC10-RF1
    #endif

    if (servo_count >= SERVO_PERIOD)
        servo_count = 0;
}

