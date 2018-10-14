#define _DISABLE_OPENADC10_CONFIGPORT_WARNING 1
#define _SUPPRESS_PLIB_WARNING 1
#include "plib.h"
#include "motors.h"

static unsigned char motor1ON=0, motor2ON=0, 
        motor1Dir=3,motor2Dir=3; // initial direction is unknonw -> 3


#ifdef MOTORS_CONNECTED_TO_JC
// PMod JC
#define	trisMotor1DirSet                 TRISGSET   // Motor 1 direction bit
#define	trisMotor1DirClr                 TRISGCLR
#define	prtMotor1DirSet                  PORTGSET
#define	prtMotor1DirClr                  PORTGCLR
#define	bnMotor1Dir                      12

#define	trisMotor2DirSet                 TRISGSET   // Motor 2 direction bit
#define	trisMotor2DirClr                 TRISGCLR
#define	prtMotor2DirSet                  PORTGSET
#define	prtMotor2DirClr                  PORTGCLR
#define	bnMotor2Dir                      0

#define	trisMotor1EnSet                 TRISGSET   // Motor 1 enable bit
#define	trisMotor1EnClr                 TRISGCLR
#define	prtMotor1EnSet                  PORTGSET
#define	prtMotor1EnClr                  PORTGCLR
#define	bnMotor1En                      13

#define	trisMotor2EnSet                 TRISGSET   // Motor 2 enable bit
#define	trisMotor2EnClr                 TRISGCLR
#define	prtMotor2EnSet                  PORTGSET
#define	prtMotor2EnClr                  PORTGCLR
#define	bnMotor2En                      1

#define	trisMotor1SASet                 TRISGSET   // Motor 1 sensor A bit
#define	trisMotor1SAClr                 TRISGCLR
//#define	prtMotor1SASet                  PORTGSET
//#define	prtMotor1SAClr                  PORTGCLR
#define prtMotor1SADat			PORTGbits.RG14
#define	bnMotor1SA                      14

#define	trisMotor1SBSet                 TRISGSET   // Motor 1 sensor B bit
#define	trisMotor1SBClr                 TRISGCLR
//#define	prtMotor1SBSet                  PORTGSET
//#define	prtMotor1SBClr                  PORTGCLR
#define prtMotor1SBDat			PORTGbits.RG15
#define	bnMotor1SB                      15

#define	trisMotor2SASet                 TRISFSET   // Motor 2 sensor A bit
#define	trisMotor2SAClr                 TRISFCLR
//#define	prtMotor2SASet                  PORTFSET
//#define	prtMotor2SAClr                  PORTFCLR
#define prtMotor2SADat			PORTFbits.RF0
#define	bnMotor2SA                      0

#define	trisMotor2SBSet                 TRISFSET   // Motor 2 sensor B bit
#define	trisMotor2SBClr                 TRISFCLR
//#define	prtMotor2SBSet                  PORTFSET
//#define	prtMotor2SBClr                  PORTFCLR
#define prtMotor2SBDat			PORTFbits.RF1
#define	bnMotor2SB                      1
#endif

#ifdef MOTORS_CONNECTED_TO_JD
// PMod JD
#define	trisMotor1DirSet                 TRISDSET   // Motor 1 direction bit
#define	trisMotor1DirClr                 TRISDCLR
#define	prtMotor1DirSet                  PORTDSET
#define	prtMotor1DirClr                  PORTDCLR
#define	bnMotor1Dir                      7

#define	trisMotor2DirSet                 TRISDSET   // Motor 2 direction bit
#define	trisMotor2DirClr                 TRISDCLR
#define	prtMotor2DirSet                  PORTDSET
#define	prtMotor2DirClr                  PORTDCLR
#define	bnMotor2Dir                      6

#define	trisMotor1EnSet                 TRISDSET   // Motor 1 enable bit
#define	trisMotor1EnClr                 TRISDCLR
#define	prtMotor1EnSet                  PORTDSET
#define	prtMotor1EnClr                  PORTDCLR
#define	bnMotor1En                      1

#define	trisMotor2EnSet                 TRISDSET   // Motor 2 enable bit
#define	trisMotor2EnClr                 TRISDCLR
#define	prtMotor2EnSet                  PORTDSET
#define	prtMotor2EnClr                  PORTDCLR
#define	bnMotor2En                      2

#define	trisMotor1SASet                 TRISDSET   // Motor 1 sensor A bit
#define	trisMotor1SAClr                 TRISDCLR
//#define	prtMotor1SASet                  PORTDSET
//#define	prtMotor1SAClr                  PORTDCLR
#define prtMotor1SADat			PORTDbits.RD9
#define	bnMotor1SA                      9

#define	trisMotor1SBSet                 TRISCSET   // Motor 1 sensor B bit
#define	trisMotor1SBClr                 TRISCCLR
//#define	prtMotor1SBSet                  PORTCSET
//#define	prtMotor1SBClr                  PORTCCLR
#define prtMotor1SBDat			PORTCbits.RC1
#define	bnMotor1SB                      1

#define	trisMotor2SASet                 TRISDSET   // Motor 2 sensor A bit
#define	trisMotor2SAClr                 TRISDCLR
//#define	prtMotor2SASet                  PORTDSET
//#define	prtMotor2SAClr                  PORTDCLR
#define prtMotor2SADat			PORTDbits.RD10
#define	bnMotor2SA                      10

#define	trisMotor2SBSet                 TRISCSET   // Motor 2 sensor B bit
#define	trisMotor2SBClr                 TRISCCLR
//#define	prtMotor2SBSet                  PORTCSET
//#define	prtMotor2SBClr                  PORTCCLR
#define prtMotor2SBDat			PORTCbits.RC2
#define	bnMotor2SB                      2
#endif

#ifdef MOTORS_CONNECTED_TO_JB
// PMod JB
#define	trisMotor1DirSet                 TRISGSET   // Motor 1 direction bit
#define	trisMotor1DirClr                 TRISGCLR
#define	prtMotor1DirSet                  PORTGSET
#define	prtMotor1DirClr                  PORTGCLR
#define	bnMotor1Dir                      9

#define	trisMotor2DirSet                 TRISBSET   // Motor 2 direction bit
#define	trisMotor2DirClr                 TRISBCLR
#define	prtMotor2DirSet                  PORTBSET
#define	prtMotor2DirClr                  PORTBCLR
#define	bnMotor2Dir                      15

#define	trisMotor1EnSet                 TRISGSET   // Motor 1 enable bit
#define	trisMotor1EnClr                 TRISGCLR
#define	prtMotor1EnSet                  PORTGSET
#define	prtMotor1EnClr                  PORTGCLR
#define	bnMotor1En                      8

#define	trisMotor2EnSet                 TRISDSET   // Motor 2 enable bit
#define	trisMotor2EnClr                 TRISDCLR
#define	prtMotor2EnSet                  PORTDSET
#define	prtMotor2EnClr                  PORTDCLR
#define	bnMotor2En                      5

#define	trisMotor1SASet                 TRISGSET   // Motor 1 sensor A bit
#define	trisMotor1SAClr                 TRISGCLR
//#define	prtMotor1SASet                  PORTGSET
//#define	prtMotor1SAClr                  PORTGCLR
#define prtMotor1SADat			PORTGbits.RG7
#define	bnMotor1SA                      7

#define	trisMotor1SBSet                 TRISGSET   // Motor 1 sensor B bit
#define	trisMotor1SBClr                 TRISGCLR
//#define	prtMotor1SBSet                  PORTGSET
//#define	prtMotor1SBClr                  PORTGCLR
#define prtMotor1SBDat			PORTGbits.RG6
#define	bnMotor1SB                      6

#define	trisMotor2SASet                 TRISDSET   // Motor 2 sensor A bit
#define	trisMotor2SAClr                 TRISDCLR
//#define	prtMotor2SASet                  PORTDSET
//#define	prtMotor2SAClr                  PORTDCLR
#define prtMotor2SADat			PORTDbits.RD4
#define	bnMotor2SA                      4

#define	trisMotor2SBSet                 TRISBSET   // Motor 2 sensor B bit
#define	trisMotor2SBClr                 TRISBCLR
//#define	prtMotor2SBSet                  PORTBSET
//#define	prtMotor2SBClr                  PORTBCLR
#define prtMotor2SBDat			PORTBbits.RB14
#define	bnMotor2SB                      14
#endif

void initMotors(void) {
    // Directio and Enable bits as outputs (clear cooresponding TRIS bit)
    trisMotor1DirClr = (1 << bnMotor1Dir);
    trisMotor2DirClr = (1 << bnMotor2Dir);
    trisMotor1EnClr = (1 << bnMotor1En);
    trisMotor2EnClr = (1 << bnMotor2En);
    // Sensor bits as inputs (set corresponding TRIS bit)
    trisMotor1SASet = (1 << bnMotor1SA);
    trisMotor1SBSet = (1 << bnMotor2SB);
    trisMotor2SASet = (1 << bnMotor1SA);
    trisMotor2SBSet = (1 << bnMotor2SB);
    setMotor1Enable(0);
    setMotor2Enable(0);

    
}

void setMotor1Direction(unsigned short direction) {
    char motorWasOn=motor1ON;
    direction=direction?1:0;
    
    if(motor1Dir!=direction){
        setMotor1Enable(0);
        if (direction)
            prtMotor1DirSet = (1 << bnMotor1Dir);
        else
            prtMotor1DirClr = (1 << bnMotor1Dir); 
        setMotor1Enable(motorWasOn);
    }
    motor1Dir=direction;
        
}

void setMotor2Direction(unsigned short direction) {
    char motorWasOn=motor2ON;
    direction=direction?1:0;
            
    if(motor2Dir!=direction){
        setMotor2Enable(0);
        if (direction)
            prtMotor2DirSet = (1 << bnMotor2Dir);
        else
            prtMotor2DirClr = (1 << bnMotor2Dir); 
        setMotor2Enable(motorWasOn);
    }
    motor2Dir=direction;
}

void setMotor1Enable(unsigned short enable) {
    motor1ON=enable;
    if (enable)
        prtMotor1EnSet = (1 << bnMotor1En);
    else
        prtMotor1EnClr = (1 << bnMotor1En);
}
void setMotor2Enable(unsigned short enable) {
    motor2ON=enable;
    if (enable)
        prtMotor2EnSet = (1 << bnMotor2En);
    else
        prtMotor2EnClr = (1 << bnMotor2En);
}

unsigned short getMotor1SensorA(void) {
    return prtMotor1SADat;
}
unsigned short getMotor1SensorB(void) {
    return prtMotor1SBDat;
}
unsigned short getMotor2SensorA(void) {
    return prtMotor2SADat;
}
unsigned short getMotor2SensorB(void) {
    return prtMotor2SBDat;
}