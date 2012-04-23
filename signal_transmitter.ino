// Modified from Nikon camera demonstration code.
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!

#include "signal_codes.h"

#define MODE_NONE_SELECTED -1
#define MODE_XBOX 0
#define MODE_CABLE 1
#define MODE_COMPUTER 2

int g_current_mode = MODE_CABLE;

int IRledPin =  13;    // LED connected to digital pin 13

void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
 
  Serial.begin(9600);
}
 
void loop()                     
{
  int selected_mode = MODE_NONE_SELECTED; 
  Serial.println("Listening for IR signal");
  uint16_t test[200];
  int count;
  count = listenForIR(test, 200);
  if (CompareSignals(test, count, ApexOK)) {
    Serial.println("OK detected");
    selected_mode = MODE_CABLE;
  }
  if (CompareSignals(test, count, ApexLeftArrow)) {
    Serial.println("Left detected");
    selected_mode = MODE_XBOX;
  }
  if (CompareSignals(test, count, ApexRightArrow)) {
    Serial.println("Right detected");
    selected_mode = MODE_COMPUTER;
  }
  if (selected_mode != MODE_NONE_SELECTED) {
    if (g_current_mode < selected_mode) {
      selectNextInput(selected_mode - g_current_mode);
    }
    if (g_current_mode > selected_mode) {
      selectPreviousInput(g_current_mode - selected_mode);
    }
    g_current_mode = selected_mode;
  }
}

void selectPreviousInput(int steps) {
  delay(500);
  SendCode(TVInput);
  delay(250);
  for (int i=0; i < steps; i++) {
    SendCode(TVUpArrow);
    delay(250);
  }
  SendCode(TVEnter);
}

void selectNextInput(int steps) {
  delay(500);
  SendCode(TVInput);
  delay(250);
  for (int i=0; i < steps; i++) {
    SendCode(TVDownArrow);
    delay(250);
  }
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


