// Modified from Nikon camera demonstration code.
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!

#include "signal_codes.h"

int IRledPin =  13;    // LED connected to digital pin 13

void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
 
  Serial.begin(9600);
}
 
void loop()                     
{
  Serial.println("Listening for IR signal");
  uint16_t test[200];
  int count;
  count = listenForIR(test, 200);
  if (CompareSignals(test, count, MicrosoftOK)) {
    Serial.println("OK detected");
  }
  if (CompareSignals(test, count, MicrosoftLeftArrow)) {
    Serial.println("Left detected");
    selectPreviousInput();
  }
  if (CompareSignals(test, count, MicrosoftRightArrow)) {
    Serial.println("Right detected");
    selectNextInput();
  }
}

void selectPreviousInput() {
  delay(500);
  SendCode(TVInput);
  delay(250);  // wait .5 seconds
  SendCode(TVUpArrow);
  delay(250);
  SendCode(TVEnter);
}

void selectNextInput() {
  delay(500);
  SendCode(TVInput);
  delay(250);  // wait .5 seconds
  SendCode(TVDownArrow);
  delay(250);
  SendCode(TVEnter);
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}

void SendCode(int *code_array) {
  // Pulse a code to an IR transmitter
  // Args:
  //  code_array: 1D array of pulse lengths denoted in 10s 
  //  of milliseconds: on, off, on, off, etc.
  //  Array is terminated by a 0 off code.
  uint8_t i;
  for(i = 0; code_array[i] != 0; i += 2) {
    pulseIR(code_array[i] * 10);
    delayMicroseconds(code_array[i+1] * 10);
  }
  Serial.println("Codes sent:");
  Serial.println(i, DEC);
}


