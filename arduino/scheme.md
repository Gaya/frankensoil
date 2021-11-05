# Arduino board

## Needed:
- 1 Joystick potentiometer (good range)
- 1 Slide potentiometer with knob
- 1 Teensy Board
- 6 electrical wires

See image in folder for breadboard connection scheme.

## Instructions:
1. Solder left pin of Joystick and pin 1 of slider to 3.3v on Teensy
2. Solder middle pin of Joystick to A0 on Teensy
3. Solder pin 2 of slider to A1 on Teensy
4. Solder right pin of Joystick and pin 3 of slider to GND on Teensy
5. Upload ./AnalogControlChange.ino to Teensy board with MIDI output
