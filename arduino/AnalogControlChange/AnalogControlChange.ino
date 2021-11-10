/* USB MIDI AnalogControlChange Example

   You must select MIDI from the "Tools > USB Type" menu
   http://www.pjrc.com/teensy/td_midi.html

   This example code is in the public domain.
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;


void setup() {
  pinMode(A0, INPUT);
}

// store previously sent values, to detect changes
int previousA0 = -1;
int previousA1 = -1;

elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
  if (msec >= 20) {
    msec = 0;
    int n0 = analogRead(A0); // 0-1024
    int n1 = analogRead(A1); // 0-1024

    int pitchValue = map(n0, 0, 1024, -8191, 8191);
    int modValue = map(n1, 0, 1024, 0, 127);
    
    // only transmit MIDI messages if analog input;;  changed
    if (n0 != previousA0) {
      usbMIDI.sendPitchBend(pitchValue, channel);
      previousA0 = n0;
    }

    if (n1 != previousA1) {
      // 1 for MOD wheel
      usbMIDI.sendControlChange(1, modValue, channel);
      previousA1 = n1;
    }
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}
