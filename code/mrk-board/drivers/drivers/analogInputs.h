/* 
 * File:   analogInputs.h
 * Author: dimitri
 *
 * Created on November 27, 2015, 1:17 PM
 */

#ifndef ANALOGINPUTS_H
#define	ANALOGINPUTS_H

#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1

#include "plib.h"


void initAnalogInputs(short analogInputs); 
// analogInputs : 16 bits, each bit can be set to enable the corresponding analog input

unsigned short readADC(char num);

#endif	/* ANALOGINPUTS_H */

