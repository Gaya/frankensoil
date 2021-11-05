# Frankensoil

Working on a custom MIDI controller to fit in a 19" mixer rack. Total dimensions are: 49cm x 13cm. The plan is to create a wooden plate and carve / saw room for the different parts. 

## Features:
- 2 Octave Keybed
- Octave shift buttons
- Pitch bend joystick
- Mod "wheel" slider
- Extra AKAI LPK25 functions

## Parts:
- Akai LPK25 (keybed, octave shifter)
- Teensy board
- Joystick potentiometer
- Slide potentiometer

## How it works

Notes will be sent through MIDI over USB by the AKAI LPK25 logic board. It will be connected to a MIDI host.

Pitch and MOD will be sent through MIDI over USB by the Teensy Board to a MIDI host.

This combined can control a synth or DAW.
