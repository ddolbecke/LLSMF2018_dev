/* 
 * File:   btn.h
 * Author: Simon
 *
 * Created on 6 novembre 2015, 12:37
 */

#ifndef BTN_H
#define	BTN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>

#define BTN_CONNECTED_TO_JA2

    // initalizes the BTN module
    void initBTN();

    // Gets the state of every button independantly (1 if pressend, 0 if not)
    unsigned char getBTN0();
    unsigned char getBTN1();
    unsigned char getBTN2();
    unsigned char getBTN3();

#ifdef	__cplusplus
}
#endif

#endif	/* BTN_H */

