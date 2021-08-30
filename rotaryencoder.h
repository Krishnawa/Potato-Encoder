#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H
#include<Arduino.h>

class rotaryencoder
{
private:
    byte ROTARY_ENC_PIN_A;
    byte ROTARY_ENC_PIN_B;
    byte TURN_CW;
    byte TURN_CCW;
    byte NO_CHANGE;
    volatile byte encoderStatus;
    byte readEncoderStatus();
    byte aState[];
    byte index;
    byte lastState;
    int count;

public:
    rotaryencoder(/* args */);
    rotaryencoder(byte ROTARY_ENC_PIN_A, byte ROTARY_ENC_PIN_B);

    byte init();
    int counter();
};


#endif
