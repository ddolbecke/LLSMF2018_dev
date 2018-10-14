
#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#include "plib.h"

#include "PmodMAXSONAR.h"



#ifdef SONAR_CONNECTED_TO_JJ1
    #define sonarAnalogIn 0
#endif
#ifdef SONAR_CONNECTED_TO_JJ2
    #define sonarAnalogIn 4
#endif
#ifdef SONAR_CONNECTED_TO_JB2
    #define sonarAnalogIn 15
#endif



void initSonar(){
    initAnalogInputs(1<<sonarAnalogIn);
}

unsigned short getDistance(){ 
    return ReadADC10(sonarAnalogIn);
}