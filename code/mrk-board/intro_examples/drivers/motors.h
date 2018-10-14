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





#ifdef	__cplusplus
}
#endif

#endif	/* MOTORS_H */

