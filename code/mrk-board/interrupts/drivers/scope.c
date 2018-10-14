
// *****************************************************************************

/* 
 * File: scope.c  
 * Author: Dimitri
 * Comments:
 * Revision history: 
 */

// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************


#include <stdio.h> // required for sprintf, ...

#include "scope.h"



// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

char scopeUsed = 0; // by default we don't use the scope

// *****************************************************************************
// *****************************************************************************
// Section: User Functions
// *****************************************************************************
// *****************************************************************************

// Comment a function definition and leverage automatic documentation 
/**
  <p><b>Function: void initScope(void)</b></p>

  <p><b>Summary: Calling this function allows sending variable via usart</b></p>

  <p><b>Description:</b></p>

  <p><b>Remarks:</b></p>
 */
void initScope(){
    enable1msInterrupts();
    OpenUART1(UART_EN | UART_NO_PAR_8BIT | UART_1STOPBIT,UART_TX_PIN_LOW| UART_TX_ENABLE,10);
    scopeUsed=1;
}

void sendVariables(long* data){
    char myString[0x50] ;
    sprintf(myString, "%d,%d,%d,%d,%d,%d\n\r",data[0],data[1],data[2],data[3],data[4],data[5]);
    putsUART1(myString);
}

void scopeRoutine(){
    if(scopeUsed)
        sendVariables(scopeVariables);
}

