#include "PmodCLP.h"
#include "ClpLib.h"

void initLCD() {
    ClpPinsConfigure();
    ClpInit(displaySetOptionDisplayOn);
    ClpSetBackLight(fTrue);
}

void writeLine(char * string, char line) {
    ClpWriteStringAtPos(string, line, 0);
}

void clearScreen() {
    ClpDisplayClear();
}

void shiftScreen(unsigned char right) {
    ClpDisplayShift((BOOL) right);
}