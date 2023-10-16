#include <Bounce.h>
#include <Arduino.h>

//  To Do -
//  Proper enclosure - or at least make Altoid tin mountable.
//  Better 'release' placement.
//  Easier customization/maintenance?

//  I could treat all the keys the same as the down arrow - just like a regular KB does, there's no REQUIREMENT to only blip the key.
//  I just did it that was initially bc it was easiest. But if they ALL did press/flash, release, that should be fine, too.

// Though then I wonder if the bouncerate (actually de-bounce) is too high, and a quick press/release would not register the release and it would hang pressed? I'll have to test.




int LEDpin = 13;
int LEDduration = 100;
int bouncerate = 250;

// Create Bounce objects for each button. The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

Bounce leftarrow = Bounce(2, bouncerate);  // pin# , debounce time
Bounce rightarrow = Bounce(1, bouncerate); // 10 = 10 ms debounce time
Bounce uparrow = Bounce(0, bouncerate);     // which is appropriate for most mechanical pushbuttons
Bounce downarrow = Bounce(3, bouncerate);  // if a button is too "sensitive" 
Bounce spacebar = Bounce(4, bouncerate);    // to rapid touch, you can increase this.
Bounce playpause = Bounce(5, bouncerate); // Control music
Bounce esc = Bounce(8, bouncerate);
Bounce enter = Bounce(6, bouncerate);
Bounce g_key = Bounce(7, bouncerate);  // Workout Graph
Bounce a_key = Bounce(9, bouncerate);   // Pairing Screen



void setup() {
// Configure the pins for input mode with pullup resistors.
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
// Output  
  pinMode(LEDpin, OUTPUT);    // On-board LED used to ack button-presses
}

void flashled(int LEDpin, int duration){
  digitalWrite(LEDpin, HIGH);
  delay(duration);
  digitalWrite(LEDpin, LOW);
  // Keyboard.releaseAll();
}

void loop() {
  // Update all the button objects.
  // (There has to be a better way.)
  leftarrow.update();
  rightarrow.update();
  uparrow.update();
  downarrow.update();
  spacebar.update();
  playpause.update();
  esc.update();
  enter.update();
  g_key.update();
  a_key.update();

// Check each button for "falling" edge.
// Send keystroke when each button presses

// The exception to this is the down arrow for a U-turn in Zwift. This needs held down
// to avoid accidental U-turns.

  if (leftarrow.fallingEdge()) {
  Keyboard.press(KEY_LEFT);
  flashled(LEDpin, LEDduration);
  }
  if (rightarrow.fallingEdge()) {
    Keyboard.press(KEY_RIGHT);
    flashled(LEDpin, LEDduration);
  }
  if (uparrow.fallingEdge()) {
    Keyboard.press(KEY_UP);
    flashled(LEDpin, LEDduration);
  }
  if (downarrow.fallingEdge()) {
    Keyboard.press(KEY_DOWN);
    flashled(LEDpin, LEDduration);
  }
  if (spacebar.fallingEdge()) {
    Keyboard.press(KEY_SPACE);
    flashled(LEDpin, LEDduration);
  }
  if (playpause.fallingEdge()) {
    Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
    flashled(LEDpin, LEDduration);
  }
  if (esc.fallingEdge()) {
    Keyboard.press(KEY_ESC);
    flashled(LEDpin, LEDduration);
  }
  if (enter.fallingEdge()) {
    Keyboard.press(KEY_ENTER);
    flashled(LEDpin, LEDduration);
  }
  if (g_key.fallingEdge()) {
    Keyboard.press(KEY_G);
    flashled(LEDpin, LEDduration);
  }
  if (a_key.fallingEdge()) {
    Keyboard.press(KEY_A);
    flashled(LEDpin, LEDduration);
  }
// RISING (released)
  if (leftarrow.risingEdge()) {
    Keyboard.release(KEY_LEFT);
  }  
  if (rightarrow.risingEdge()) {
    Keyboard.release(KEY_RIGHT);
  }  
  if (uparrow.risingEdge()) {
    Keyboard.release(KEY_UP);
  }  
  if (downarrow.risingEdge()) {
    Keyboard.release(KEY_DOWN);
  }  
  if (spacebar.risingEdge()) {
    Keyboard.release(KEY_SPACE);
  }  
  if (playpause.risingEdge()) {
    Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
  }  
  if (esc.risingEdge()) {
    Keyboard.release(KEY_ESC);
  }  
  if (enter.risingEdge()) {
    Keyboard.release(KEY_ENTER);
  }  
  if (g_key.risingEdge()) {
    Keyboard.release(KEY_G);
  }  
  if (a_key.risingEdge()) {
    Keyboard.release(KEY_A);
  }  
}
