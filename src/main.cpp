#include <Bounce.h>
#include <Arduino.h>

//  ToDo -
//  1) Actually get Teensy and build/test.
//  2) Add media buttons?  Getting a bit unwieldy for an Altoid tin.

// Navigating the UI
// You can use the following shortcuts when navigating the UI including the Home Screen and your in-game settings.

// Enter	Select.
// Esc	Go back.
// ←	Navigate left.
// ↑	Navigate up.
// →	Navigate right.
// ↓	Navigate down.

// Riding, Running, or Working Out in Zwift
// Check out the table below for available shortcuts while riding, running, working out, or participating in an event.

// ESC Go back.
// A	Access the PAIRED DEVICES screen.
// T	Access your GARAGE.
// G	Toggle Watt/HR Graphs When Riding
// M	Send a group text.
// 1-9	Change your camera view.
// H	Show or hide the display.
// F1-F8	Actions + Sound.
// PC: F10
// OSX: Function + F10	Take a screenshot.
// OSX: Function + F9	Capture a video.
// Space Bar	Activate a power-up.
// P	Enter a Promo Code.
// Down Arrow	Make a U-Turn.
// Up Arrow	Display the Action Bar.
// Left and Right Arrows	Initiate a turn at an intersection.
// E	Open the TRAINING menu.
// Tab	Skip a workout step.
// Page Up/Page Down	Increase or decrease the FTP Bias.

// From https://forum.pjrc.com/threads/53297-Could-anyone-show-me-the-Teensy-2-0-Keyboard-Code

// Create Bounce objects for each button. The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

// Main

Bounce leftarrow = Bounce(0, 10); // pin# , debounce time
Bounce rightarrow = Bounce(1, 10); // 10 = 10 ms debounce time
Bounce uparrow = Bounce(2, 10); // which is appropriate for most mechanical pushbuttons
Bounce downarrow = Bounce(3, 10); // Does this need longer to avoid accidental U-Turns, or is that handles in software?
Bounce spacebar = Bounce(4, 10);
Bounce playpause = Bounce(5, 10); // if a button is too "sensitive"
Bounce esc = Bounce(6, 10); // to rapid touch, you can
Bounce enter = Bounce(7, 10); // increase this time.
// Bounce button8 = Bounce(8, 10);
// Bounce button9 = Bounce(9, 10);



void setup() {
// Configure the pins for input mode with pullup resistors.
// The pushbuttons connect from each pin to ground. When
// the button is pressed, the pin reads LOW because the button
// shorts it to ground. When released, the pin reads HIGH
// because the pullup resistor connects to +5 volts inside
// the chip. LOW for "on", and HIGH for "off" may seem
// backwards, but using the on-chip pullup resistors is very
// convenient. The scheme is called "active low", and it's
// very commonly used in electronics... so much that the chip
// has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP); 
  pinMode(7, INPUT_PULLUP);
// pinMode(8, INPUT_PULLUP);
// pinMode(9, INPUT_PULLUP);

  pinMode(13, OUTPUT);

}

void flashled(int ledpin, int duration){
  // int ledpin = 13;
  // int duration = 100;
  digitalWrite(ledpin, HIGH);
  delay(duration);
  digitalWrite(ledpin, LOW);
  Keyboard.releaseAll();

}

void loop() {
    // Update all the button objects.
  leftarrow.update();
  rightarrow.update();
  uparrow.update();
  downarrow.update(); // U-turn - need a delay?
  spacebar.update();
  playpause.update();
  esc.update();
  enter.update();

// Check each button for "falling" edge.
// Send keybstroke when each button presses
// falling = high (not pressed - voltage from pullup resistor)
// to low (pressed - button connects pin to ground)B5 release

  if (leftarrow.fallingEdge()) {
  Keyboard.press(KEY_LEFT);
  flashled(13, 100);
 }
  if (rightarrow.fallingEdge()) {
    Keyboard.press(KEY_RIGHT);
    flashled(13, 100);
  }
  if (uparrow.fallingEdge()) {
    Keyboard.press(KEY_UP);
    flashled(13, 100);
  }
  if (downarrow.fallingEdge()) {
    Keyboard.press(KEY_DOWN);    // need a delay?
    flashled(13, 100);
  }
  if (spacebar.fallingEdge()) {
    Keyboard.press(KEY_SPACE);
    flashled(13, 100);
  }
  if (playpause.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
    flashled(13, 100);
  }
  if (esc.fallingEdge()) {
    Keyboard.press(KEY_ESC);
    flashled(13, 100);
  }
 if (enter.fallingEdge()) {
    Keyboard.press(KEY_ENTER);
    flashled(13, 100);
  }

// release (i.e. risingEdge) is unused

}

