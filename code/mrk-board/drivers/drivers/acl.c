#include "acl.h"
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


#ifdef ACC1_CONNECTED_TO_JJ1
    #define AxyAnalogIn 0
    #define AzAnalogIn 3
#endif
#ifdef ACC1_CONNECTED_TO_JJ2
    #define AxyAnalogIn 4
    #define AzAnalogIn 9
#endif
#ifdef ACC1_CONNECTED_TO_JB2
    #define AxyAnalogIn 15
    #define AzAnalogIn 14
#endif

void initAcc1(){
    initAnalogInputs(1<<AxyAnalogIn | 1<<AzAnalogIn);
}
unsigned short getA1xy(){
    return ReadADC10(AxyAnalogIn);
}
unsigned short getA1z(){
    return ReadADC10(AzAnalogIn);
}

void initAcc2() {
    #define CCLK (80000000)	// processor frequency
    #define PBCLK  (CCLK/8)	// peripherals frequency
    #define Fsck 50000		// desired frequency (?)
    #define BRG_VAL (PBCLK/2/Fsck)

    OpenI2C1( I2C_EN, BRG_VAL );

    
    //DelayMs(200);
    RestartI2C1();//Send the Stop condition
    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 0 ); //transmit write command
    //DelayMs(10);
    IdleI2C1();

    MasterWriteI2C1( 0x2D ); //Power_Ctl register
    //DelayMs(20);
    IdleI2C1();

    //DelayMs(20);//Wait to complete
    MasterWriteI2C1( 0x08 ); //Start measurement mode

    //NotAckI2C1();
    StopI2C1();//Send the Stop condition
    IdleI2C1();     //Wait to complete
    
}
unsigned short getA2x() {
    unsigned short data0 = 0;
    unsigned short data1 = 0;
    
    RestartI2C1();//Send the Stop condition
    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 0 ); //transmit write command
    IdleI2C1();     //Wait to complete
    MasterWriteI2C1( 50 );  // DATAX0 address
    //MasterWriteI2C1( 0x0 );  // Device ID address (answer is 0x1D)
    //MasterWriteI2C1( 0x2C );  // BW_RATE address (answer is 0x0A)
    IdleI2C1();     //Wait to complete

    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 1 ); //transmit read command
    IdleI2C1();     //Wait to complete

    //IdleI2C1();     //Wait to complete
    //MastergetsI2C1(2, dataBytes, 152);
    //data=dataBytes[1]<<4+dataBytes[0]>>4;
    data0 = MasterReadI2C1();
    //IdleI2C1();
    //DelayUs(20);
    AckI2C1();
    DelayUs(10);
    data1 = MasterReadI2C1(); 	// Automatically reads next register
    //NackI2C1();
    StopI2C1();//Send the Stop condition
    IdleI2C1();//Wait to complete
    
    return ( (data0 & 0xFF) | ( (data1 & 0xFF) << 8 ) );//
}
unsigned short getA2y() {
    unsigned short data0 = 0;
    unsigned short data1 = 0;

    RestartI2C1();//Send the Stop condition
    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 0 ); //transmit write command
    IdleI2C1();     //Wait to complete
    MasterWriteI2C1( 0x34 );  // DATAY0 address
    IdleI2C1();     //Wait to complete

    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 1 ); //transmit read command
    IdleI2C1();     //Wait to complete

    //IdleI2C1();     //Wait to complete
    //MastergetsI2C1(2, dataBytes, 152);
    //data=dataBytes[1]<<4+dataBytes[0]>>4;
    data0 = MasterReadI2C1();
    //IdleI2C1();
    //DelayUs(20);
    AckI2C1();
    DelayUs(10);
    data1 = MasterReadI2C1();	// Automatically reads next register
    //NackI2C1();
    StopI2C1();//Send the Stop condition
    IdleI2C1();//Wait to complete

    return ( (data0 & 0xFF) | ( (data1 & 0xFF) << 8 ) );
}
unsigned short getA2z() {
    unsigned short data0 = 0;
    unsigned short data1 = 0;

    RestartI2C2();//Send the Stop condition
    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 0 ); //transmit write command
    IdleI2C1();     //Wait to complete
    MasterWriteI2C1( 0x36 );  // DATAZ0 address
    IdleI2C1();     //Wait to complete

    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 1 ); //transmit read command
    IdleI2C1();     //Wait to complete

    //IdleI2C1();     //Wait to complete
    //MastergetsI2C1(2, dataBytes, 152);
    //data=dataBytes[1]<<4+dataBytes[0]>>4;
    data0 = MasterReadI2C1();
    //IdleI2C1();
    //DelayUs(20);
    AckI2C1();
    DelayUs(10);
    data1 = MasterReadI2C1();	// Automatically reads next register
    //NackI2C1();
    StopI2C1();//Send the Stop condition
    IdleI2C1();//Wait to complete

    return ( (data0 & 0xFF) | ( (data1 & 0xFF) << 8 ) );
    
}


/*
 
 Test with PmodACL2

  
#define SPI_CS_PORT IOPORT_G
#define SPI_CS_PIN  BIT_9

#define CS_LOW() PORTClearBits(SPI_CS_PORT, SPI_CS_PIN)
#define CS_HIGH() PORTSetBits(SPI_CS_PORT, SPI_CS_PIN)


void initAcc2(){
    
    short a1;
     Make the Data/Command select, Reset, and SPI CS pins be outputs.
	
    
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
    
    a1=SPI2BUF;

   
	SPI2CON = 0;
	SPI2BRG = 4;				//8Mhz, with 80Mhz PB clock
	SPI2STATbits.SPIROV = 0;
	SPI2CONbits.CKP = 0;
	SPI2CONbits.MSTEN = 1;
	SPI2CONbits.ON = 1;


    
    
    
    
    //OpenSPI2(ENABLE_SDO_PIN|SPI_MODE8_ON|SPI_SMP_OFF|SPI_CKE_OFF|CLK_POL_ACTIVE_HIGH);
    #define CONFIG1 SPICON_MSTEN | SPICON_CKE // master mode           
    #define CONFIG2 SPI_OPEN_MSTEN | SPI_OPEN_SMP_END | SPI_OPEN_CKE_REV | SPI_OPEN_MODE8 |SPICON_ON // master mode  
    #define CONFIG3 SPI_OPEN_MSTEN | SPI_OPEN_SMP_END | SPI_OPEN_CKP_HIGH | SPI_OPEN_CKE_REV | SPI_OPEN_MODE8 |SPICON_ON // master mode  

    
    //SPI2BRG = 0;
    
    //SpiChnOpen(2,CONFIG2,2);
    //SPI2CON = BIT_23 | BIT_15 | BIT_9 | BIT_8 | BIT_5;
    
    //SPI2STAT =
    IEC1bits.SPI2EIE=0;
    IEC1bits.SPI2RXIE=0;
    IEC1bits.SPI2TXIE=0;
    
    //spiWriteByte(0x2D,0x02);
    
}


unsigned short getA2x(){
    return spiReadByte(0x00);
    //spiWriteByte(0x0,0x08);
}
unsigned short getA2y(){
    return 0;
}
unsigned short getA2z(){
    return 0;
}

void spiWriteByte(char address, char data){
    CS_LOW();
    SpiChnPutC(2,0x0A);
    SpiChnPutC(2,address);
    SpiChnPutC(2,data);
    CS_HIGH();  
}

unsigned char spiReadByte(char address){
    unsigned char data;
    int i;

    //SPI2STATbits.SPIRBF=0;
    //while(!SPI2STATbits.SPIRBF){
        CS_LOW();

        while (SPI2STATbits.SPITBE == 0);
        
        SPI2BUF = 0x0B;
        
        while (SPI2STATbits.SPITBE == 0);
        //DelayUs(3);
        SPI2BUF = address;
        
        while (SPI2STATbits.SPITBE == 0);
        //DelayUs(10);
        SpiChnPutC(2,0);
        
        while (SPI2STATbits.SPIRBF == 0);

        data=SPI2BUF;
        
        CS_HIGH();
    //};
    
 
    
    return data;
}
*/