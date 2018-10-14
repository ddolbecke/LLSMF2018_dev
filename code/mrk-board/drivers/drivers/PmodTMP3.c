#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define _SUPPRESS_PLIB_WARNING 1
#include "plib.h"

#define SLAVE_ADDRESS 0x48

void initTemp(){
    #define CCLK (80000000)
    #define PBCLK  (CCLK/8)
    #define Fsck 200000
    #define BRG_VAL (PBCLK/2/Fsck)
    
    OpenI2C1( I2C_EN, BRG_VAL );
    
    //DelayMs(200);
    RestartI2C2();//Send the Stop condition
    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 0 ); //transmit write command
    //DelayMs(10);
    IdleI2C1();
   
    MasterWriteI2C1( 0x01 ); //config pointer
    //DelayMs(20);
    IdleI2C1();
    
    
    //DelayMs(20);//Wait to complete
    MasterWriteI2C1( 0x60 ); //Temperature address
    
    //NotAckI2C1();
    StopI2C1();//Send the Stop condition
    IdleI2C1();     //Wait to complete
    
}

 short getTemp(){ 
    short data;
    RestartI2C2();//Send the Stop condition
    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 0 ); //transmit write command
    IdleI2C1();     //Wait to complete
    MasterWriteI2C1( 0 ); //Temperature address
    IdleI2C1();     //Wait to complete
    
    StartI2C1();
    IdleI2C1();//Wait to complete
    MasterWriteI2C1( (SLAVE_ADDRESS << 1) | 1 ); //transmit read command
    IdleI2C1();     //Wait to complete
    
    //IdleI2C1();     //Wait to complete
    //MastergetsI2C1(2, dataBytes, 152);
    //data=dataBytes[1]<<4+dataBytes[0]>>4;
    data=MasterReadI2C1()<<4;  
    //IdleI2C1();
    //DelayUs(20);
    AckI2C1();
    DelayUs(10);
    data|=MasterReadI2C1()>>4;
    StopI2C1();//Send the Stop condition
    IdleI2C1();//Wait to complete
    return data;//
}