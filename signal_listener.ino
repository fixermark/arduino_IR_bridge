// Authored by Mark Tomczak (iam@fixermark.com).
// Listens for signals.
// Adapted from the tutorial at http://www.ladyada.net/learn/sensors/ir.html

// We need to use the 'raw' pin reading methods
// because timing is very important here and the digitalRead()
// procedure is slower!
//uint8_t IRpin = 2;
// Digital pin #2 is the same as Pin D2 see
// http://arduino.cc/en/Hacking/PinMapping168 for the 'raw' pin mapping
#define IRpin_PIN      PIND
#define IRpin          2
 
// the maximum pulse we'll listen for - 65 milliseconds is a long time
#define MAXPULSE 65000
 
// what our timing resolution should be, larger is better
// as its more 'precise' - but too large and you wont get
// accurate timing
#define RESOLUTION 20 

// What percentage of variance we allow between signal and target values.
#define FUZZINESS 20

// Pulls in pulses and stores them in an array.
// Args:
//   input_array: Array in which to store on-off pulse cells.
//   array_size: Maximum index of the input array. Must be
//    divisible by 2.
// Returns:
//   Number of pulses received.
int listenForIR(uint16_t *input_array, int array_size) {
  uint8_t currentpulse = 0;
 
  while (1) {
    uint16_t highpulse, lowpulse;  // temporary storage timing
    highpulse = lowpulse = 0; // start out with no pulse length
 
//  while (digitalRead(IRpin)) { // this is too slow!
    while (IRpin_PIN & (1 << IRpin)) {
       // pin is still HIGH
 
       // count off another few microseconds
       highpulse++;
       delayMicroseconds(RESOLUTION);
 
       // If the pulse is too long, we 'timed out' - either nothing
       // was received or the code is finished, so print what
       // we've grabbed so far, and then reset
       if ((highpulse >= MAXPULSE) && (currentpulse != 0)) {
         return currentpulse;
       }
    }
    // we didn't time out so lets stash the reading
    input_array[currentpulse] = highpulse;
    currentpulse++;
    // same as above
    while (! (IRpin_PIN & _BV(IRpin))) {
       // pin is still LOW
       lowpulse++;
       delayMicroseconds(RESOLUTION);
       if ((lowpulse >= MAXPULSE)  && (currentpulse != 0)) {
         return currentpulse;
       }
    }
    input_array[currentpulse] = lowpulse;
 
    // we read one high-low pulse successfully, continue!
    currentpulse++;
    if (currentpulse >= array_size) {
      return currentpulse;
    }
  }
}

// Compares two signals and determines if they match. The
// incoming signal is compared in a "sliding" method; if
// the signal and target don't match exactly, the front of the signal
// is consumed and match is re-tried.
// Args:
//   signal: The incoming signal, as a sequence of OFF-ON pulses.
//    THe first OFF is ignored.
//   signal_length: The length of the incoming signal.
//   target: The target signal, which is NULL-terminated.
// Returns:
//   true if the signal matches, false otherwise.
bool CompareSignals(uint16_t *signal, int signal_length, int *target) {
  int counter = 0;
  while (counter < signal_length) {
    for (counter = 0; counter < signal_length; ++counter) {
      if (target[counter]==0) {
        return true;
      }
      int signal_code = signal[counter+1] * RESOLUTION / 10;
      if (abs(signal_code - target[counter]) > 
        (signal_code * FUZZINESS / 100)) {
          signal++;
          signal_length--;
          break;
      }
    }
  }
  return false;
}
