/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dma_chn_write_ev_flags_lib.c
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
 * $Id: $
 * $Name:  $
 *
 ********************************************************************/
#include <peripheral/dma.h>

#include "_dma_include.h"


#ifdef _DMA_CHANNELS


/*********************************************************************
 * Function:        void DmaChnWriteEvFlags(DmaChannel chn, DmaEvFlags eFlags)
 *
 * PreCondition:    chn	- valid DMA channel
 *
 * Input:			chn		- DMA channel number
 * 					eFlags	- event flags with the following significance:
 * 								- DMA_EV_ERR: address error event
 * 								- DMA_EV_ABORT: transfer abort event
 * 								- DMA_EV_CELL_DONE: cell transfer complete event
 * 								- DMA_EV_BLOCK_DONE: block transfer complete event
 * 								- DMA_EV_DST_HALF: destination half event
 * 								- DMA_EV_DST_FULL: destination full event
 * 								- DMA_EV_SRC_HALF: source half event
 * 								- DMA_EV_SRC_FULL: source full event
 * 								- DMA_EV_ALL_EVNTS: all of the above flags
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function writes the event flags for the selected DMA channel.
 * 					The channel event flags are forced to the eFlags value.
 *
 * Note:            This is intended as a channel test function.
 ********************************************************************/
void DmaChnWriteEvFlags(DmaChannel chn, DmaEvFlags eFlags)
{
	(_DmaMapTbl+chn)->intr.w=(eFlags<<__DCHxINT_MASK_(CHERIF_POSITION));		// set the corresponding bits
}



#endif	// _DMA_CHANNELS

