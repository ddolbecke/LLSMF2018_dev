#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define _SUPPRESS_PLIB_WARNING 1

#include <xc.h>
#include "servo.h"
#include <p32xxxx.h>
#include <plib.h>
#include "interrupts.h"

void setServo1Angle(unsigned short angle) {
    servo1_angle = angle;
}

void setServo2Angle(unsigned short angle) {
    servo2_angle = angle;
}

void setServo3Angle(unsigned short angle) {
    servo3_angle = angle;
}

void setServo4Angle(unsigned short angle) {
    servo4_angle = angle;
}

void initServo() {
    enable10usInterrupts();

    TRISGbits.TRISG12 = 0;	// S1-JC1-RG12 (selected by default)
    TRISGbits.TRISG13 = 0;	// S2-JC2-RG13
    TRISGbits.TRISG14 = 0;	// S3-JC3-RG14
    TRISGbits.TRISG15 = 0;	// S4-JC4-RG15

    servo_count = 0;		    //
    servo1_angle = 0;		    // from 0 to 180 (750us to 2550us)
    servo2_angle = 0;		    // from 0 to 180 (750us to 2550us)
    servo3_angle = 0;		    // from 0 to 180 (750us to 2550us)
    servo4_angle = 0;		    // from 0 to 180 (750us to 2550us)
}

void setServo1Enable(unsigned char enable) {
    LATGbits.LATG12 = enable;	// S1-JC1-RG12 (selected by default)
}

void setServo2Enable(unsigned char enable) {
    LATGbits.LATG13 = enable;	// S2-JC2-RG13
}

void setServo3Enable(unsigned char enable) {
    LATGbits.LATG14 = enable;	// S3-JC3-RG1
}

void setServo4Enable(unsigned char enable) {
    LATGbits.LATG15 = enable;	// S4-JC4-RG15
}


void servo10usRoutine(void){
    unsigned short servo1_angle_norm;
    
    servo_count++;
    if (servo1_angle > 180)
        servo1_angle = 180;
    if (servo2_angle > 180)
        servo2_angle = 180;
    if (servo3_angle > 180)
        servo3_angle = 180;
    if (servo4_angle > 180)
        servo4_angle = 180;
    
    setServo1Enable(servo_count < (servo1_angle + 75)); // min.750us;max.2550us (10us per degree)
    setServo2Enable(servo_count < (servo2_angle + 75)); // min.750us;max.2550us (10us per degree)
    setServo3Enable(servo_count < (servo3_angle + 75)); // min.750us;max.2550us (10us per degree)
    setServo4Enable(servo_count < (servo4_angle + 75)); // min.750us;max.2550us (10us per degree)
    
    if (servo_count == SERVO_PERIOD) {
        servo_count = 0;
    } 
}

