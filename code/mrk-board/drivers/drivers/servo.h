/* 
 * File:   servo.h
 * Author: Simon
 *
 * Created on 6 novembre 2015, 12:25
 */

#ifndef SERVO_H
#define	SERVO_H

#ifdef	__cplusplus
extern "C" {
#endif


#define SERVO_PERIOD 2000   // 100kHz timer (.1us), 20ms period
static unsigned short servo_count;		    //
static unsigned short servo1_angle;		    // from 0 to 180 (750us to 2550us)
static unsigned short servo2_angle;		    // from 0 to 180 (750us to 2550us)
static unsigned short servo3_angle;		    // from 0 to 180 (750us to 2550us)
static unsigned short servo4_angle;		    // from 0 to 180 (750us to 2550us)

// Initializes the servomotor
void initServo();

// Sets the servo to the corresponding angle (in degrees, from 0 to 180)
void setServoAngle(unsigned short angle);

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

