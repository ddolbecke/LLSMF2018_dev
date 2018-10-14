
#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#include "plib.h"

#include "PmodIR_Range.h"



#ifdef IR_RANGE_CONNECTED_TO_JJ1
    #define irAnalogIn 0xf // AN0, AN1, AN2, AN3
    // to do
#endif
#ifdef IR_RANGE_CONNECTED_TO_JJ2 // AN4, AN5, AN8, AN9
    #define irAnalogIn 0b1100110000
    #define irAnalogIn1 4
    #define irAnalogIn2 5
    #define irAnalogIn3 8
    #define irAnalogIn4 9
#endif
#ifdef IR_RANGE_CONNECTED_TO_JB2
    #define irAnalogIn 0b10000000
    // to do
#endif



void initIR_range(){
    initAnalogInputs(irAnalogIn);
}

unsigned short getIR_range1(){ 
    return ReadADC10(irAnalogIn1);
}

unsigned short getIR_range2(){ 
    return ReadADC10(irAnalogIn2);
}

unsigned short getIR_range3(){ 
    return ReadADC10(irAnalogIn3);
}

unsigned short getIR_range4(){ 
    return ReadADC10(irAnalogIn4);
}
