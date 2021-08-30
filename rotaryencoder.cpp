
#include "rotaryencoder.h"
rotaryencoder::rotaryencoder(byte ROTARY_ENC_PIN_A, byte ROTARY_ENC_PIN_B){
this ->ROTARY_ENC_PIN_A = ROTARY_ENC_PIN_A;
this ->ROTARY_ENC_PIN_B = ROTARY_ENC_PIN_B;

  TURN_CW =   0;
  TURN_CCW =  1;
  NO_CHANGE = 2;
  encoderStatus = NO_CHANGE;
  aState[] = {3, 2, 0, 1, 3, 2, 0, 1, 3};
  index = 4;
  lastState = 3;
  count =0;
}


byte rotaryencoder::readEncoderStatus(){
  byte A_Output = digitalRead(ROTARY_ENC_PIN_A);
  byte B_Output = digitalRead(ROTARY_ENC_PIN_B);
  byte currentState = (2 * A_Output) + B_Output;
  
  if (currentState != lastState) {
    
    if (currentState == aState[index + 1]) {
      index++;
      if (index == 8) {
        count++;
        index = 4;
        encoderStatus = TURN_CW;
        return count;
        return encoderStatus;
      }
    }
    else if (currentState == aState[index - 1]) {
      index--;
      if (index == 0) {
        count--;
        index = 4;
        encoderStatus = TURN_CCW;
        return count;
        return encoderStatus;
      }
    }
    lastState = currentState;
  }
}

byte rotaryencoder::init(){
    attachInterrupt(digitalPinToInterrupt(ROTARY_ENC_PIN_A), readEncoderStatus, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ROTARY_ENC_PIN_B), readEncoderStatus, CHANGE);
}

int rotaryencoder::counter(){
    if (encoderStatus != NO_CHANGE){
    noInterrupts();
    int tempCount;
    interrupts();
    tempCount=count;
    return tempCount;
    encoderStatus = NO_CHANGE;
}
