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

#define SERVO_CONNECTED_TO_S1
#define SERVO_CONNECTED_TO_S2
#define SERVO_CONNECTED_TO_S3
#define SERVO_CONNECTED_TO_S4

#define SERVO_PERIOD 2000   // 100kHz timer (.1us), 20ms period
static unsigned short servo_count;		    //
static unsigned short servo_angle1, servo_angle2, servo_angle3, servo_angle4,
        servo_angle5, servo_angle6, servo_angle7, servo_angle8;		    // from 0 to 180 (750us to 2550us)

// Initializes the servomotor
void initServo();

// Sets the servo to the corresponding angle (in degrees, from 0 to 180)
void setServoAngle(unsigned short angle, unsigned short servoPos);

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */

