/************************************************************************/
/*																		*/
/*	delay.h	--	Interface Declarations for delay.c						*/
/*																		*/
/************************************************************************/
/*	Author:		Dimitri                                                 */
/************************************************************************/
/*  File Description:													*/
/*																		*/
/*																		*/
/************************************************************************/


#if !defined(DELAY_INC)
#define	DELAY_INC

/* ------------------------------------------------------------ */
/*					Miscellaneous Declarations					*/
/* ------------------------------------------------------------ */


#define	cntMsDelay	625			//timer 5 delay for 1ms : (10MHz/16)*(1ms)=625 


/* ------------------------------------------------------------ */
/*					General Type Declarations					*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */
/*					Object Class Declarations					*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */
/*					Variable Declarations						*/
/* ------------------------------------------------------------ */



/* ------------------------------------------------------------ */
/*					Procedure Declarations						*/
/* ------------------------------------------------------------ */

void	initDelay();
void	DelayMs(int cms);
void    DelayUs(short tusDelay );
void    delay1msRoutine();
/* ------------------------------------------------------------ */

#endif

/************************************************************************/
