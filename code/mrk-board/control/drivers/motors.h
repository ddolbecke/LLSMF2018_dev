/* 
 * File:   motors.h
 * Author: Simon
 *
 * Created on 16 octobre 2015, 12:32
 */

#ifndef MOTORS_H
#define	MOTORS_H

#ifdef	__cplusplus
extern "C" {
#endif

// Change the name of the connector where the servo is connected
#define MOTORS_CONNECTED_TO_JD // JB, JC or JD

/* Initializes the PWM module with a frequency of a frequency of 1 kHz (OC2 and OC3).
 */
void initPWM(void);

void timer3Interrupt(void);

/* Set de PWM duty cycle (min=0, max=10000)
 * PARAMETERS
 * DC1  Duty cycle (OC2)
 * DC2  Duty cycle (OC3)
 */
void setPWMDC(unsigned int DC1, unsigned int DC2);

/* Disable the PWM module.
 */
void disablePWM(void);

/*
 * Function initMotors
 * Description : Initialized the motors to work with the board. Be careful to 
 * select the proper connector from the MOTORS_CONNECTED_TO_XX define above.
 */
void initMotors();

/*
 * Functions setMotorXDirection
 * Description : Sets the direction of motor X. "direction" is a binary value.
 */
void setMotor1Direction(unsigned short direction);
void setMotor2Direction(unsigned short direction);

/*
 * Functions setMotorXEnable
 * Description : Makes the motor X turn. "enable" is a binary value.
 */
void setMotor1Enable(unsigned short enable);
void setMotor2Enable(unsigned short enable);

/*
 * Functions getMotorXSensorY
 * Description : gets the binary value relative to the Y's sensor of motor X.
 * The speed and direction of each motor can be determined by observing the
 * sequence returned by both sensors.
 */
unsigned short getMotor1SensorA(void);
unsigned short getMotor1SensorB(void);
unsigned short getMotor2SensorA(void);
unsigned short getMotor2SensorB(void);


unsigned int getMotor1RevTime(void);;
unsigned int getMotor2RevTime(void);


void speedTimerInterrupt(void);


#ifdef	__cplusplus
}
#endif

#endif	/* MOTORS_H */

