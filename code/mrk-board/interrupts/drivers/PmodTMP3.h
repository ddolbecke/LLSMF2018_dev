/* 
 * File:   temp.h
 * Author: Dimitri
 * PmodTemp3 connected to I2C #2 port
 * Created on 16 octobre 2015, 12:32
 */



#ifndef TEMP_H
#define	TEMP_H

#ifdef	__cplusplus
extern "C" {
#endif


void initTemp();  // Initialize the temperature module


short getTemp(); 
// Returns the temperature in degrees multiplied by 16 (signed). 

#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_H */

