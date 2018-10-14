#ifndef ACCELEROMETER_H
#define	ACCELEROMETER_H



#define ACC1_CONNECTED_TO_JJ1


void initAcc1(void); 
void initAcc2(void);


unsigned short getA1xy();
unsigned short getA1z();

unsigned short getA2x();
unsigned short getA2y();
unsigned short getA2z();


void spiWriteByte(char address, char data);
unsigned char spiReadByte(char address);


#endif	/* ACCELEROMETER_H */