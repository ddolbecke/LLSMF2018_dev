
#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1

#include "PmodMIC3.h"
#include "plib.h"

int global_data;

void initMIC3(void) {
    TRISGbits.TRISG9 = 0;
    LATGbits.LATG9 = 1;
    
    OpenSPI2(FRAME_ENABLE_OFF|FRAME_SYNC_OUTPUT|SPI_MODE8_ON|MASTER_ENABLE_ON|
            SLAVE_ENABLE_ON, SPI_ENABLE);
    
    SPI2BRG = 50;
    
    DisableIntSPI2;
}

int readMIC3(void) {   
    if (SPI1STATbits.SPIRBF){   // If our receive buffer is full
        unsigned int temp = (unsigned int)SPI2BUF;}   // Empty it...
         
    LATGbits.LATG9 = 0;
    // Get the MSB
    SPI2BUF = 0;      // Send dummy data
    while (!SPI2STATbits.SPIRBF) {}; // Wait for our data
    unsigned int byte1 = (unsigned int)SPI2BUF;    // grab the returned data
    // Get the LSB
    SPI2BUF = 0;      // Send dummy data
    while (!SPI2STATbits.SPIRBF) {}; // Wait for our data
    unsigned int byte2 = (unsigned int)SPI2BUF;    // grab the returned data
    LATGbits.LATG9 = 1;
    
    unsigned int val = 256*byte1 + byte2;
    int res = (int) val;
    
    res -= 2048;
    
    return res;
}

unsigned int abs_int(int val){
    return (unsigned int) (val>0 ? val : -val);
}

unsigned int readVolume(void){
    int i=0, res=0, samples=100;
    
    for (i=0 ; i<samples ; i++){
        res += (unsigned int) ((float) abs_int(readMIC3())/ (float)samples);
    }
    
    return res;
}

void closeMIC3(void) {
    CloseSPI2();
}
