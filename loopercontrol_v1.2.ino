#include <elapsedMillis.h>
#include <Bounce2.h>
#include <MIDI.h>


MIDI_CREATE_DEFAULT_INSTANCE();

const int channel = 11;

Bounce button1 = Bounce(2, 5);  // 5 = 5 ms debounce time
Bounce button2 = Bounce(3, 5);  // which is appropriate for good
Bounce button3 = Bounce(4, 5);  // quality mechanical pushbuttons
Bounce button4 = Bounce(5, 5);
Bounce button5 = Bounce(6, 5);
Bounce button6 = Bounce(7, 5);
Bounce button7 = Bounce(8, 5);

const int controllerA1 = 110; 



void setup() {
  Serial.begin(31250);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
}
  int previousA1 = -1;

elapsedMillis msec = 0;



void loop() {

  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();

  if (button1.fallingEdge()) {
    MIDI.sendControlChange(101, 127, channel);  // CC=101
  }
  if (button2.fallingEdge()) {
    MIDI.sendControlChange(102, 127, channel);  // CC=102
  }
  if (button3.fallingEdge()) {
    MIDI.sendControlChange(103, 127, channel);  // CC=103
  }
  if (button4.fallingEdge()) {
    MIDI.sendControlChange(104, 127, channel);  // CC=104
  }
  if (button5.fallingEdge()) {
    MIDI.sendControlChange(105, 127, channel);  // CC=105
  }
 if (button6.fallingEdge()) {
    MIDI.sendControlChange(106, 127, channel);  // CC=106
  }
  if (button7.fallingEdge()) {
    MIDI.sendControlChange(107, 127, channel);  // CC=107
  }
  
  if (button1.risingEdge()) {
    MIDI.sendControlChange(101, 0, channel);  // CC=101
  }
  if (button2.risingEdge()) {
    MIDI.sendControlChange(102, 0, channel);  // CC=102
  }
  if (button3.risingEdge()) {
    MIDI.sendControlChange(103, 0, channel);  // CC=103
  }
  if (button4.risingEdge()) {
    MIDI.sendControlChange(104, 0, channel);  // CC=104
  }
  if (button5.risingEdge()) {
    MIDI.sendControlChange(105, 0, channel);  // CC=105
  }
   if (button6.risingEdge()) {
    MIDI.sendControlChange(106, 0, channel);  // CC=106
  }
  if (button7.risingEdge()) {
    MIDI.sendControlChange(107, 0, channel);  // CC=107
  }
 
 if (msec >= 20) {
    msec = 0;
    int n1 = analogRead(A0) / 8;
   
    // only transmit MIDI messages if analog input changed
    if (abs(n1 - previousA1)>1) {
      MIDI.sendControlChange(controllerA1, n1, channel);
      previousA1 = n1;
    }
 }
}
