#include <p32xxxx.h>
#include "analogInputs.h"

static short param4=0;

void initAnalogInputs(short analogInputs){
    
    CloseADC10();// ensure the ADC is off before setting the configuration
    #define PARAM1  ADC_MODULE_ON | ADC_FORMAT_INTG | ADC_CLK_AUTO | ADC_AUTO_SAMPLING_ON | ADC_SAMP_ON
    #define PARAM2  ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_ON | ADC_SAMPLES_PER_INT_16 | ADC_ALT_BUF_ON | ADC_ALT_INPUT_OFF
    #define PARAM3  ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_12
    #define PARAM5  0
        
    param4  |=  analogInputs;
    OpenADC10( PARAM1, PARAM2, PARAM3, param4, PARAM5 );
    // Now enable the ADC logic
    EnableADC10();
    
}

unsigned short readADC(char num){
    return ReadADC10(num);
}