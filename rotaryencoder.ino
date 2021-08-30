// /*TODO

//     Implement Algorithm
//     (1) define array of expected states
//     (2)start with neutral state value of 3 (index 4)
//         + check if state has chnged then..
//         + check incoming state value
//         + compare incomming state w/ neighbour
//     (3) adjust state index if input matches a neighbour
//     (4) ++/-- count when the state reaches 8/0 respectively
//      + display result to serial monitor window
// */
// const unsigned int ROTARY_ENC_PIN_A = 3;
// const unsigned int ROTARY_ENC_PIN_B = 2;
// #define TURN_CW  0
// #define TURN_CCW 1
// #define NO_CHANGE 2
// volatile byte encoderStatus = NO_CHANGE;

// //Direction     ┌─  ccw  ─┐  N  ┌─  cw  ─┐
// //Index          0  1  2  3  4  5  6  7  8
// byte aState[] = {3, 2, 0, 1, 3, 2, 0, 1, 3};
// byte index = 4;
// byte lastState = 3;
// int count =0;
// void setup() {
//   Serial.begin(9600);
//   Serial.println("Start Now!");
//   Serial.print(" ");
//   attachInterrupt(digitalPinToInterrupt(ROTARY_ENC_PIN_A), readEncoderStatus, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(ROTARY_ENC_PIN_B), readEncoderStatus, CHANGE);
// }

//   void readEncoderStatus(){
//         byte A_Output = digitalRead(ROTARY_ENC_PIN_A);
//   byte B_Output = digitalRead(ROTARY_ENC_PIN_B);
//   byte currentState = (2 * A_Output) + B_Output;
  
//   if (currentState != lastState) {
    
//     if (currentState == aState[index + 1]) {
//       index++;
//       if (index == 8) {
//         count++;
//         index = 4;
//         encoderStatus = TURN_CW;
//       }
//     }
//     else if (currentState == aState[index - 1]) {
//       index--;
//       if (index == 0) {
//         count--;
//         index = 4;
//         encoderStatus = TURN_CCW;
//       }
//     }
//     lastState = currentState;
//     //Serial.println(lastState);
//   }
//   }
// void loop() {
// if (encoderStatus != NO_CHANGE){
//     noInterrupts();
//     int tempCount;
//     interrupts();
//     tempCount=count;
//     Serial.println(tempCount);
//     encoderStatus = NO_CHANGE;
//    // Serial.println("cool");
// }
//  //delay(10);
// }