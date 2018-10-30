/* 
 * File:   PmodKYPD.h
 * Author: dim
 *
 * Created on October 13, 2018, 12:07 PM
 */

#ifndef PMODKYPD_H
#define	PMODKYPD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

#define IR_PROX_CONNECTED_TO_JH

void keypad_init(void);
void keypad_setRows(char rows);
void keypad_setCols(char cols);
char keypad_readRows(void);
char keypad_readCols(void);

    
    
    
    


#ifdef	__cplusplus
}
#endif

#endif	/* PMODKYPD_H */

