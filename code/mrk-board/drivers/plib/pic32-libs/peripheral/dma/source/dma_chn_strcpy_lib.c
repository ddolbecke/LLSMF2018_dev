/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_strcpy_lib.c
 * Dependencies:	Dma.h
 *
 * Processor:       PIC32
 *
 * Compiler:        MPLAB XC32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PIC32/PIC24F Microcontroller is intended
 * and supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip PIC32/PIC24F Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * $Id:$
 * $Name:  $
 *
 ********************************************************************/
#include <peripheral/dma.h>

#include "_dma_include.h"


#ifdef _DMA_CHANNELS


/*********************************************************************
 * Function:        DmaTxferRes DmaChnStrcpy(char* s1, const char* s2, DmaChannel chn, DmaChannelPri chPri)
 *
 * PreCondition:    chn		- a valid DMA channel
 * 					s1, s2	- valid memory pointers
 *
 * Input:			s1		- destination pointer
 * 					s2		- source pointer
 * 					chn		- the DMA channel to perform the transfer
 * 					chPri	- the desired channel priority
 * 
 * Output:          DMA_TXFER_OK if the transfer ended normally,
 * 					an DmaTxferRes error code  otherwise
 *
 * Side Effects:    None
 *
 * Overview:		The function configures a DMA channel for a fast memory transfer.
 * 			Then it copies one zero terminated string from source to destination.
 *
 *
 * Note:            - If the CRC is attached to the submitted channel, the CRC append mode will be turned off.
 *				This way, the transfer will occur correctly together with CRC calculation.
 *			- The channel will support transfers of up to max size bytes.
 *			- The start and abort Irqs will be disabled and the channel event enable flags are disabled.
 *			- Multiple channels could be opened to perform fast memory transfers, if necessary.
 *
 *
 ********************************************************************/
DmaTxferRes DmaChnStrcpy(char* s1, const char* s2, DmaChannel chn, DmaChannelPri chPri)
{
	register volatile _DmaRegMap*	pReg=_DmaMapTbl+chn;

	__DCRCCONbits_t crcCon;

	_DmaChnInitOp(pReg);		// DMA controller on, abort previous operation

	crcCon.w=DCRCCON;				// read current control word
	if(crcCon.CRCCH==chn)
	{
		DCRCCONCLR=_DCRCCON_CRCAPP_MASK;			// clear append mode
	}

	pReg->con.w=chPri;	// not enabled, +CHPRI
	pReg->econClr=(__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK));		// disable start and abort irqs
	pReg->econSet=__DCHxECON_MASK_(PATEN_MASK);	// patern enable
	
	pReg->intrClr=__DCHxINT_MASK_(w_MASK);	// disable events, clear existing flags
	pReg->dat=0x0;					// end for strcpy


	pReg->ssa=_VirtToPhys(s2);		// set src address
	pReg->dsa=_VirtToPhys(s1);		// set dst address

	pReg->ssiz=pReg->dsiz=pReg->csiz=0x0;	// size is max

	return DmaChnStartTxfer(chn, DMA_WAIT_BLOCK, 0);
}


#endif	// _DMA_CHANNELS

