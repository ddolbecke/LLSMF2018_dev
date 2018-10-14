/* 
 * File:   interrupts.h
 * Authors: Dimitri & Simon
 *
 * Created on October 16, 2015, 9:53 AM
 */

#ifndef INTERRUPTS_H
#define	INTERRUPTS_H


//void __ISR(_TIMER_1_VECTOR, ipl7) Timer1Handler(void);

//void __ISR(_TIMER_2_VECTOR, ipl6) Timer2Handler(void);

// Timers

void initTimer1(unsigned long period, char ps);
// Initialize timer1 to generate periodic interrupts of f=10e6/(ps*period)
// period range : [0 65535]
// ps (prescaler) possible values : 
//              T1_PS_1_256,    T1_PS_1_64,
//              T1_PS_1_8,      T1_PS_1_1


void initTimer2(unsigned long period, char ps);
// Initialize timer2 to generate periodic interrupts of f=10e6/(ps*period)
// period range : [0 65535]
// ps (prescaler) possible values : 
//             T2_PS_1_256, T2_PS_1_64, T2_PS_1_32, 
//             T2_PS_1_16,  T2_PS_1_8,  T2_PS_1_4,
//             T2_PS_1_2,  T2_PS_1_1


void initTimer3(unsigned short period, char ps);
// Initialize timer2 to generate periodic interrupts of f=10e6/(ps*period)
// period range : [0 65535]
// ps (prescaler) possible values : 
//             T3_PS_1_256, T3_PS_1_64, T3_PS_1_32, 
//             T3_PS_1_16,  T3_PS_1_8,  T3_PS_1_4,
//             T3_PS_1_2,  T3_PS_1_1

void enable10usInterrupts(void); // Timer 4 interrupts
void enable1msInterrupts(void);  // Timer 5 interrupts
void timer1InterruptEnable(void);
void timer2InterruptEnable(void);
void timer3InterruptEnable(void);
void timer1InterruptDisable(void);
void timer2InterruptDisable(void);
void timer3InterruptDisable(void);
void clearTimer1InterruptRequest(void);
void clearTimer2InterruptRequest(void);
void clearTimer3InterruptRequest(void);

// Interrupt routines
void timer1Interrupt(void);
void timer2Interrupt(void);
void timer3Interrupt(void);
void timer4_10usInterrupt(void);
void timer5_1msInterrupt(void);


// Motors
void motor1SensorsInterruptEnable(void);
void motor2SensorsInterruptEnable(void);
void motor1SensorsInterruptDisable(void);
void motor2SensorsInterruptDisable(void);
void motorSensorsInterrupt(void);

#endif	/* INTERRUPTS_H */