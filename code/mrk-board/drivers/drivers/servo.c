#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define _SUPPRESS_PLIB_WARNING 1

#include <xc.h>
#include "servo.h"
#include <p32xxxx.h>
#include <plib.h>
#include "interrupts.h"

void setServoAngle(unsigned short angle) {
    servo_angle = angle;
}
intCount = 0;
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
    servo_angle = 0;		    // from 0 to 180 (750us to 2550us)
}

void setServoEnable(unsigned char enable) {
#ifdef SERVO_CONNECTED_TO_S1
    LATGbits.LATG12 = enable;	// S1-JC1-RG12 (selected by default)
   #endif
#ifdef SERVO_CONNECTED_TO_S2
    LATGbits.LATG13 = enable;	// S2-JC2-RG13
    #endif
#ifdef SERVO_CONNECTED_TO_S3
    LATGbits.LATG14 = enable;	// S3-JC3-RG14
    #endif
#ifdef SERVO_CONNECTED_TO_S4
    LATGbits.LATG15 = enable;	// S4-JC4-RG15
    #endif
#ifdef SERVO_CONNECTED_TO_S5
    LATGbits.LATG0 = enable;	// S5-JC7-RG00
    #endif
#ifdef SERVO_CONNECTED_TO_S6
    LATGbits.LATG1 = enable;	// S6-JC8-RG01
    #endif
#ifdef SERVO_CONNECTED_TO_S7
    LATFbits.LATF0 = enable;	// S7-JC9-RF00
    #endif
#ifdef SERVO_CONNECTED_TO_S8
    LATFbits.LATF1 = enable;	// S8-JC10-RF1
#endif
}


void servo10usRoutine(void){
    unsigned short servo_angle_norm;  
    servo_count++;
    if (servo_angle > 180)
        servo_angle_norm = 180;
    else
        servo_angle_norm = servo_angle;
    
    setServoEnable(servo_count < (servo_angle_norm + 75)); // min.750us;max.2550us (10us per degree)
    if (servo_count == SERVO_PERIOD) {
	servo_count = 0;
    } 
}

