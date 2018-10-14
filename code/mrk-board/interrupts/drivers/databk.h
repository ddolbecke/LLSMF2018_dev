/* 
 * File:   databk.h
 * Author: dimitri
 *
 * Created on December 2, 2015, 4:59 PM
 */

#ifndef DATABK_H
#define	DATABK_H

#define DATALENGTH 30
#define DATAWIDTH  3


void initDatabk(void);
void dataStore(short* variables);
void dataRecovery(void);
#endif	/* DATABK_H */

