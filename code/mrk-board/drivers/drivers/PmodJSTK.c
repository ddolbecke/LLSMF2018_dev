#include "PmodJSTK.h"
#include "delay.h"


#define _SUPPRESS_PLIB_WARNING 1
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#include "plib.h"

// acl1 I2C address
#define SLAVE_ADDRESS 0x1D

/*
*  Analog accelerometer 
JJ_1 (top)      JJ-01,JJ-JJ-04    AN0,  AN3
JJ_2 (bottom)   JJ-07,JJ1-10      AN4,  AN9
JK_1 (top)      JK-01,JK-04       AN10, AN13 (also connected to leds)
JB_2 (bottom)   JB-07,JB-10       AN15, AN14 : RB15, RB14
 */


 
// Test with PmodACL2

  
#define SPI_CS_PORT IOPORT_G
#define SPI_CS_PIN  BIT_9

#define CS_LOW() PORTClearBits(SPI_CS_PORT, SPI_CS_PIN)
#define CS_HIGH() PORTSetBits(SPI_CS_PORT, SPI_CS_PIN)


void initJSTK(void){
    initDelay();

    // Make the Data/Command select, Reset, and SPI CS pins be outputs.
	
    
#define prtSelect	IOPORT_G
#define	prtDataCmd	IOPORT_B
#define	prtReset	IOPORT_D
#define	prtVbatCtrl IOPORT_D
#define	prtVddCtrl	IOPORT_B

#define bitSelect	BIT_9
#define bitDataCmd	BIT_15
#define	bitReset	BIT_5
#define	bitVbatCtrl	BIT_4
#define	bitVddCtrl	BIT_14
    
	PORTSetBits(prtDataCmd, bitDataCmd);
	PORTSetPinsDigitalOut(prtDataCmd, bitDataCmd);		//Data/Command# select
	PORTSetBits(prtReset, bitReset);
	PORTSetPinsDigitalOut(prtReset, bitReset);
	PORTSetBits(prtSelect, bitSelect);
	PORTSetPinsDigitalOut(prtSelect, bitSelect);
    
    CS_HIGH();
    
 

   
	SPI2CON = 0;
	SPI2BRG = 4;				//8Mhz, with 80Mhz PB clock
	
	SPI2CONbits.CKP = 0;
    SPI2CONbits.CKE = 1;
    SPI2CONbits.SMP = 1;
	SPI2CONbits.MSTEN = 1;
	SPI2CONbits.ON = 1;

    //OpenSPI2(ENABLE_SDO_PIN|SPI_MODE8_ON|SPI_SMP_OFF|SPI_CKE_OFF|CLK_POL_ACTIVE_HIGH);
    #define CONFIG1 SPICON_MSTEN | SPICON_CKE // master mode           
    #define CONFIG2 SPI_OPEN_MSTEN | SPI_OPEN_SMP_END | SPI_OPEN_CKE_REV | SPI_OPEN_MODE8 |SPICON_ON // master mode  
    #define CONFIG3 SPI_OPEN_MSTEN | SPI_OPEN_SMP_END | SPI_OPEN_CKP_HIGH | SPI_OPEN_CKE_REV | SPI_OPEN_MODE8 |SPICON_ON // master mode  

    
   
    //SpiChnOpen(2,CONFIG2,2);
    //SPI2CON = BIT_23 | BIT_15 | BIT_9 | BIT_8 | BIT_5;
    
    //SPI2STAT =
    IEC1bits.SPI2EIE=0;
    IEC1bits.SPI2RXIE=0;
    IEC1bits.SPI2TXIE=0;
    
    //spiWriteByte(0x2D,0x02);
    
}

void jstkGetAll(unsigned char ledSt, unsigned char *recv)
{
//	spiCon.setSelect(LOW);
    CS_LOW();
	DelayUs(10);
	SpiChnPutC(2,ledSt);
    while (SPI2STATbits.SPIRBF == 0);
    *recv++ =SPI2BUF;
	
    DelayUs(10);
	SpiChnPutC(2,0);
    while (SPI2STATbits.SPIRBF == 0);
    *recv++ =SPI2BUF;
    
	DelayUs(10);
	SpiChnPutC(2,0);
    while (SPI2STATbits.SPIRBF == 0);
    *recv++ =SPI2BUF;
    
	DelayUs(10);
	SpiChnPutC(2,0);
    while (SPI2STATbits.SPIRBF == 0);
    *recv++ =SPI2BUF;
    
	DelayUs(10);
	SpiChnPutC(2,0);
    while (SPI2STATbits.SPIRBF == 0);
    *recv++ =SPI2BUF;

	//spiCon.setSelect(HIGH);
    CS_HIGH();
}



void jstkSetLeds(unsigned char leds)
{
    // bits 0 and 1 of leds will set the jstk leds
	unsigned char recv[5];
	leds |= 0x80;
	jstkGetAll(leds,recv);
}

unsigned short jstkGetX()
{
	unsigned short x;
	unsigned char recv[5];
	jstkGetAll(0,recv);

	x = recv[0];
	x |= (recv[1] << 8);

	return x;	
}

unsigned short jstkGetY()
{
	unsigned short y;
	unsigned char recv[5];
	jstkGetAll(0,recv);

	y = recv[2];
	y |= (recv[3] << 8);

	return y;
}

unsigned char jstkGetBtn()
{
	unsigned char recv[5];
	jstkGetAll(0,recv);

	return recv[4];
}

