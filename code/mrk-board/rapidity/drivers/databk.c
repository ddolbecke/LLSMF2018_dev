#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#include "plib.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "databk.h"


unsigned short dataTable[DATALENGTH][DATAWIDTH];
unsigned short pointer;




void initDatabk(void){
    initDelay();
    OpenUART1(UART_EN | UART_NO_PAR_8BIT | UART_1STOPBIT,UART_TX_PIN_LOW| UART_TX_ENABLE,10);
    pointer=0;
}
void dataStore(short* variables){
    char i;
    for (i=0;i<DATAWIDTH;i++){
      dataTable[pointer][i]=variables[i];
    }
    pointer++;
}
void dataRecovery(void){
    char i;
    char myString[0x50] ;
    for (i=0;i<DATALENGTH;i++){
        sprintf(myString, "%d,%d,%d\n",dataTable[i][0],dataTable[i][1],dataTable[i][2]);
        putsUART1(myString);
        DelayMs(10);
    }
    sprintf(myString, "fini\n");
    putsUART1(myString);
        
}



