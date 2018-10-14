
#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#include "plib.h"

#include "PmodIR_Range.h"



#ifdef IR_RANGE_CONNECTED_TO_JJ1
    #define irAnalogIn 0
#endif
#ifdef IR_RANGE_CONNECTED_TO_JJ2
    #define irAnalogIn 4
#endif
#ifdef IR_RANGE_CONNECTED_TO_JB2
    #define irAnalogIn 15
#endif



void initIR_range(){
    initAnalogInputs(1<<irAnalogIn);
}

unsigned short getIR_range(){ 
    return ReadADC10(irAnalogIn);
}