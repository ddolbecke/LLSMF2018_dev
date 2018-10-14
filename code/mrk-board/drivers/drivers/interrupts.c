/* 
 * File:   interrupts.c
 * Authors: Dimitri
 *
 * Created on October 16, 2015, 9:53 AM
 * 
 */



/* 
  Total of 5 timers
 Oscillator 10 MHz
 */

#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "servo.h"
#include "scope.h"
#include "delay.h"
#include "motors.h"

extern volatile unsigned int t2CountIC2, t2CountIC3;

void initTimer1(unsigned long period, char ps){
    //static_assert(ps==T1_PS_1_256,'lj');
    INTEnableInterrupts();
    // timer1 init
    ConfigIntTimer1(T1_INT_OFF | T1_INT_PRIOR_7 | T1_INT_SUB_PRIOR_0);
    OpenTimer1(T1_ON|ps|T1_SOURCE_INT,period);  //config, period (16 bits))
}

void initTimer2(unsigned long period, char ps){
    INTEnableInterrupts();
    // timer2 init
    ConfigIntTimer2(T2_INT_OFF | T2_INT_PRIOR_7 | T2_INT_SUB_PRIOR_0);
    OpenTimer2(T2_ON|ps| T2_32BIT_MODE_OFF |T2_SOURCE_INT,period);  //config, period (32 bits))
}

void initTimer3(unsigned short period, char ps){
    INTEnableInterrupts();
    // timer2 init
    ConfigIntTimer3(T3_INT_OFF | T3_INT_PRIOR_7 | T3_INT_SUB_PRIOR_0);
    OpenTimer3(T3_ON|ps|T3_SOURCE_INT,period);  
}

void timer1InterruptEnable(void){
    INTEnable(INT_T1,1);  // source, enable/disable
}

void timer2InterruptEnable(void){
    INTEnable(INT_T2,1);  // source, enable/disable
}

void timer3InterruptEnable(void){
    INTEnable(INT_T3,1);  // source, enable/disable
}


void timer1InterruptDisable(void){
    INTEnable(INT_T1,0);  // source, enable/disable
}

void timer2InterruptDisable(void){
    INTEnable(INT_T2,0);  // source, enable/disable
}

void timer3InterruptDisable(void){
    INTEnable(INT_T3,0);  // source, enable/disable
}

void motor1SensorsInterruptEnable(void) {
    /*
    //INTEnable(INT_CN, 1);
    ConfigIntCN(CHANGE_INT_PRI_6 | CHANGE_INT_ON);
    CNCONbits.ON = 1;		// Enables Change Notice
    CNCONbits.SIDL = 1;		// Idle stops CN
    CNENbits.CNEN9 = 1;		// Enables Change notice on pin CN9
    CNPUEbits.CNPUE9 = 0;	// Disable weak pull-up on pin CN9*/
    mCNOpen(CN_ON | CN_IDLE_CON, CN9_ENABLE, CN_PULLUP_DISABLE_ALL);
    mPORTGRead();	// Clear mismatch condition
    ConfigIntCN(CHANGE_INT_ON | CHANGE_INT_PRI_6);
}
void motor2SensorsInterruptEnable(void) {
    mCNClearIntFlag();
    mCNIntEnable(1);		// Activate CN interrupts
    CNCONbits.ON = 1;		// Enables Change Notice
    CNCONbits.SIDL = 1;		// Idle stops CN
    CNENbits.CNEN13 = 1;	// Enables Change notice on pin CN13
    CNPUEbits.CNPUE13 = 0;	// Disable weak pull-up on pin CN13
}

void clearTimer1InterruptRequest(void){
    mT1ClearIntFlag(); 
}
void clearTimer2InterruptRequest(void){
    mT2ClearIntFlag(); 
   
}

void clearTimer3InterruptRequest(void){
    mT3ClearIntFlag(); 
}

void motor1SensorsInterruptDisable(void) {
    CNENbits.CNEN9 = 0;		// Disables Change notice on pin CN9
}
void motor2SensorsInterruptDisable(void) {
    CNENbits.CNEN13 = 0;		// Disables Change notice on pin CN13
}

void enable10usInterrupts(void){
    // timer 4 enable
    INTEnableInterrupts();
    // timer4 init
    ConfigIntTimer4(T4_INT_OFF | T4_INT_PRIOR_7 | T4_INT_SUB_PRIOR_0);
    OpenTimer4(T4_ON|T4_PS_1_1|T4_SOURCE_INT,100);  //config, period (16 bits))
    INTEnable(INT_T4,1);  // source, enable/disable
}

void enable1msInterrupts(void){
    
    INTEnableInterrupts();
    ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_7 | T5_INT_SUB_PRIOR_3);
    #define TCFG T5_ON|T5_SOURCE_INT|T5_PS_1_16 
    OpenTimer5(TCFG, 625 );  
    //INTEnable(INT_T5,1);  // source, enable/disable
}

void __ISR(_TIMER_1_VECTOR, IPL7AUTO) intTimer1(void) {
    //static unsigned long t4intCount;   
    //t4intCount++;
    timer1Interrupt();
    clearTimer1InterruptRequest();
}

void __ISR(_TIMER_2_VECTOR, IPL7AUTO) intTimer2(void) {
    //static unsigned long t4intCount;   
    //t4intCount++;
    speedTimerInterrupt(); 
    clearTimer2InterruptRequest();
}

void __ISR(_TIMER_3_VECTOR, IPL7AUTO) intTimer3(void) {
    timer3Interrupt();
    clearTimer3InterruptRequest();
}

void __ISR(_TIMER_4_VECTOR, IPL7AUTO) timer4_10usInterrupt(void) {
    //static unsigned long t4intCount;   
    //t4intCount++;
    servo10usRoutine();
    mT4ClearIntFlag();
}


void __ISR(_TIMER_5_VECTOR, IPL7AUTO) timer5_1msInterrupt(void) {
    static unsigned long t5intCount;
//    t5intCount++;
//    delay1msRoutine();
//    if(t5intCount>=100){
//        t5intCount=0;
//        scopeRoutine(); //10Hz
//    }   
    mT5ClearIntFlag();
}


