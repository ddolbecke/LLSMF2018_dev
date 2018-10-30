

#include "PmodKYPD.h"


#ifdef IR_PROX_CONNECTED_TO_JH


#define KEYPAD_COL_TRIS1 TRISFbits.TRISF13
#define KEYPAD_COL_TRIS2 TRISFbits.TRISF4
#define KEYPAD_COL_TRIS3 TRISFbits.TRISF5
#define KEYPAD_COL_TRIS4 TRISFbits.TRISF12

#define KEYPAD_ROW_TRIS1 TRISEbits.TRISE8
#define KEYPAD_ROW_TRIS2 TRISDbits.TRISD0
#define KEYPAD_ROW_TRIS3 TRISDbits.TRISD8
#define KEYPAD_ROW_TRIS4 TRISDbits.TRISD13

#define KEYPAD_COL_PORT1 PORTFbits.RF13
#define KEYPAD_COL_PORT2 PORTFbits.RF4
#define KEYPAD_COL_PORT3 PORTFbits.RF5
#define KEYPAD_COL_PORT4 PORTFbits.RF12

#define KEYPAD_ROW_PORT1 PORTEbits.RE8
#define KEYPAD_ROW_PORT2 PORTDbits.RD0
#define KEYPAD_ROW_PORT3 PORTDbits.RD8
#define KEYPAD_ROW_PORT4 PORTDbits.RD13

#define KEYPAD_COL_LAT1 LATFbits.LATF13
#define KEYPAD_COL_LAT2 LATFbits.LATF4
#define KEYPAD_COL_LAT3 LATFbits.LATF5
#define KEYPAD_COL_LAT4 LATFbits.LATF12

#define KEYPAD_ROW_LAT1 LATEbits.LATE8
#define KEYPAD_ROW_LAT2 LATDbits.LATD0
#define KEYPAD_ROW_LAT3 LATDbits.LATD8
#define KEYPAD_ROW_LAT4 LATDbits.LATD13

#endif

void keypad_init(void){

}

void keypad_setRows(char rows){
    // set rows as outputs
    KEYPAD_ROW_TRIS1 = 0;
    KEYPAD_ROW_TRIS2 = 0;
    KEYPAD_ROW_TRIS3 = 0;
    KEYPAD_ROW_TRIS4 = 0;

    KEYPAD_ROW_LAT1 = (rows & 0b0001);
    KEYPAD_ROW_LAT2 = (rows & 0b0010)>>1;
    KEYPAD_ROW_LAT3 = (rows & 0b0100)>>2;
    KEYPAD_ROW_LAT4 = (rows & 0b1000)>>3;
}
void keypad_setCols(char cols){
    // set columns as outputs
    KEYPAD_COL_TRIS1 = 0;
    KEYPAD_COL_TRIS2 = 0;
    KEYPAD_COL_TRIS3 = 0;
    KEYPAD_COL_TRIS4 = 0;

    KEYPAD_COL_LAT1 = (cols & 0b0001);
    KEYPAD_COL_LAT2 = (cols & 0b0010)>>1;
    KEYPAD_COL_LAT3 = (cols & 0b0100)>>2;
    KEYPAD_COL_LAT4 = (cols & 0b1000)>>3;    
}
char keypad_readRows(){
    // set rows as inputs
    KEYPAD_ROW_TRIS1 = 1;
    KEYPAD_ROW_TRIS2 = 1;
    KEYPAD_ROW_TRIS3 = 1;
    KEYPAD_ROW_TRIS4 = 1;
    
    return KEYPAD_ROW_PORT1 + 
            2*KEYPAD_ROW_PORT2 +
            4*KEYPAD_ROW_PORT3 +
            8*KEYPAD_ROW_PORT4;
}
char keypad_readCols(){
    // set cols as inputs
    KEYPAD_COL_TRIS1 = 1;
    KEYPAD_COL_TRIS2 = 1;
    KEYPAD_COL_TRIS3 = 1;
    KEYPAD_COL_TRIS4 = 1;
    
    return KEYPAD_COL_PORT1 + 
            2*KEYPAD_COL_PORT2 +
            4*KEYPAD_COL_PORT3 +
            8*KEYPAD_COL_PORT4;
}
