# About

Simple IR signal "bridge," which can transmit a sequence of IR codes in
response to received signals.

Based heavily on Limor's tutorial
(http://www.ladyada.net/learn/sensors/ir.html).

# Usage

This code is intended for use with an Arduino controller, PNA4602 IR detector
(or its friend, the compatible GP1UX311QS
[http://www.adafruit.com/products/157]), and a 940nm LED (easy to pick up in
many places; mine happen to come from Radio Shack). Wire the IR detector
to pin 2 and the IR LED to pin 13; you can then install this program on
your Arduino.

The program listens for specific IR codes (at HEAD, it listens for "OK",
"Left Arrow", or "Right Arrow" from an Apex Digital remote control). Once a
code is detected, a set of pre-programmed IR commands are broadcast via the
IR LED. At HEAD, the codes that are transmitted correspond to the sequence
of commands to select one of three pre-defined inputs on my home television
(see http://www.youtube.com/watch?v=PRGOaQNUUkM for a demonstration). A small
state machine tracks which input is currently selected so that pressing "OK"
always sets the TV to cable input.

For detailed information, investigate the "loop" routine in
signal_transmitter.ino, and/or connect the Arduino to the serial monitor and
observe the messages sent when different IR patterns are seen.

To determine the IR patterns for your own controller, you may wish to use
the sister project: the Arduino remote signal decoder
(https://github.com/fixermark/arduino_remote_signal_decoder).

# License

This code is public domain. For more information, feel free to contact me via
Github. You should also definitely investigate the original tutorial at
http://www.ladyada.net/learn/sensors/ir.html