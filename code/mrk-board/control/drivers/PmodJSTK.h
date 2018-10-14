#ifndef JSTK_H
#define	JSTK_H






void initJSTK(void); 
void jstkSetLeds(unsigned char ledSt);
// only LD1 works

unsigned short jstkGetX();
// get jstk X postion

unsigned short jstkGetY();
// get jstk Y postion

unsigned char jstkGetBtn();
// return btn position on the 3 first bits (btn2, b)
void jstkGetAll(unsigned char leds, unsigned char *recv);




#endif	/* ACCELEROMETER_H */