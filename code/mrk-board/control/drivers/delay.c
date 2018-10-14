/************************************************************************/
/*																		*/
/*	delay.c	--	Time Delay Functions									*/
/*																		*/
/************************************************************************/
/*	Author: 	Dimitri                                                 */
/************************************************************************/
/*  Module Description: 												*/
/*																		*/
/*																		*/
/************************************************************************/


#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1

/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */

#include <p32xxxx.h>
#include <plib.h>
#include "interrupts.h"
#include "delay.h"

/* ------------------------------------------------------------ */
/*				Local Type Definitions							*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				Global Variables								*/
/* ------------------------------------------------------------ */

unsigned long msCount;
/* ------------------------------------------------------------ */
/*				Local Variables									*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				Forward Declarations							*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				Procedure Definitions							*/
/* ------------------------------------------------------------ */
/***	DelayInit
**
**	Parameters:
**		none
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Initialized the hardware for use by delay functions. This
**		initializes Timer 1 to count at 10Mhz.
*/

void initDelay(){
    enable1msInterrupts();
}

/* ------------------------------------------------------------ */
/***	DelayMs
**
**	Parameters:
**		dms		- delay in ms
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Delay the requested number of milliseconds. Uses Timer5.
*/

void DelayMs(int dms){
    unsigned long till;
    till=dms+msCount;
	while(msCount<till);
}		

/* ------------------------------------------------------------ */
/***	ProcName
**
**	Parameters:
**
**	Return Value:
**
**	Errors:
**
**	Description:
**
*/

/* ------------------------------------------------------------ */


void DelayUs( short tusDelay )
{
	tusDelay -= 2;
	
    while ( 0 < tusDelay )
    {
        tusDelay--;
    }   // end while
}

/************************************************************************/


void delay1msRoutine(){
    msCount++;
}