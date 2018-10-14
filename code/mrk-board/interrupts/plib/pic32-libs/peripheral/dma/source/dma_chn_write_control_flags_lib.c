/*********************************************************************
 *
 *                  DMA API implementation file
 *
 *********************************************************************
 * FileName:        dam_chn_write_control_flags_lib.c
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
 * Function:        void DmaChnWriteControlFlags(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
 *
 * PreCondition:    chn	- valid DMA channel
 *
 * Input:			chn			- DMA channel number
 * 					dmaChnCtrl	- 	either a DmaChnCtrl structure field, carrying the following info:
 * 										- chPri: channel priority 0-3
 * 										- autoEn: enable/disable the automatic mode
 * 										- chainEn: enable/disable channel chaining
 * 										- detectEn: enable/disable events detection when channel disabled
 * 										- chEn: enable/disable channel functionality
 * 										- chainDir:	chain direction: chain to lower(1)/higher(0),pri channel
 * 									or any of the DmaChnCtrlFlags flags:
 * 										DMA_CTL_PRI(pri)|DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN|DMA_CTL_DET_EN|DMA_CTL_CHN_EN|DMA_CTL_CHAIN_DIR
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:		The function enables/disables the selected DMA channel and also sets
 * 					the channel priority, chaining mode and auto mode and events detection.
 *
 * Note:            None.
 *
 * Example:			either:
 * 						DmaChnWriteControlFlags(3, DMA_CTL_PRI(DMA_CHN_PRI2)|DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN);
 * 					or:
 * 						DmaChnCtrl chCtrl; chCtrl.w=0; chCtrl.chPri=DMA_CHN_PRI2; chCtrl.autoEn=1; chCtrl.chainEn=1;
 * 						DmaChnWriteControlFlags(3, chCtrl.w);
 *
 ********************************************************************/
void DmaChnWriteControlFlags(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
{
	(_DmaMapTbl+chn)->con.w=dmaChnCtrl;		// set the control register fields
}


#endif	// _DMA_CHANNELS

