#include <Bounce.h>
#include <Arduino.h>

//  To Do -
//  Easier customization/maintenance?

int LEDpin = 13;
int LEDduration = 100;
int bouncerate = 150;
bool shifting = false;
bool shifted = false;

// Create Bounce objects for each button. The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

Bounce leftarrow = Bounce(21, bouncerate);  // pin# , debounce time
Bounce rightarrow = Bounce(22, bouncerate); // 10 = 10 ms debounce time
Bounce uparrow = Bounce(0, bouncerate);     // which is appropriate for most mechanical pushbuttons
Bounce downarrow = Bounce(23, bouncerate);  // if a button is too "sensitive" 
Bounce spacebar = Bounce(2, bouncerate);    // to rapid touch, you can increase this.
Bounce playpause = Bounce(5, bouncerate); // Control music
Bounce esc = Bounce(6, bouncerate);
Bounce enter = Bounce(7, bouncerate);  // Will use this button as a "Shift" key to add functions
Bounce g_key = Bounce(3, bouncerate);  // Workout Graph
Bounce a_key = Bounce(9, bouncerate);   // Pairing Screen



void setup() {
// Configure the pins for input mode with pullup resistors.
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
// Output  
  pinMode(LEDpin, OUTPUT);    // On-board LED used to ack button-presses (Not really seen inside the case)
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

  if (enter.fallingEdge()) {
    flashled(LEDpin, 50);   // short burst
    shifting = true;
  }
  if (enter.risingEdge()) {
    if (shifted) {  // If we were a shift key, we dont' press but we clear the flag
      shifted = false;
    } else {        // Else, press and release
      Keyboard.press(KEY_ENTER);
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_ENTER);
    }
    shifting = false;
  }  
  // Move on to the other keys checking for 'shift' or not.

  if (leftarrow.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_PAGE_DOWN); // ERG Bias Down
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_PAGE_DOWN);
      shifted = true;
    } else {
      Keyboard.press(KEY_LEFT);
      flashled(LEDpin, LEDduration);
    }
  }
  if (rightarrow.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_PAGE_UP); // ERG Bias Up
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_PAGE_UP);
      shifted = true;
    } else {
      Keyboard.press(KEY_RIGHT);
      flashled(LEDpin, LEDduration);
    }
  }
  if (uparrow.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_3); // Cam 3 (POV)
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_3);
      shifted = true;
    } else {
      Keyboard.press(KEY_UP);
      flashled(LEDpin, LEDduration);
    }
  }
  if (downarrow.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_1); // Cam 1 (Default)
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_1);
      shifted = true;
    } else {
      Keyboard.press(KEY_DOWN);
      flashled(LEDpin, LEDduration);
    }
  }
  if (spacebar.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_0); // Cam 0 (Drone)
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_0);
      shifted = true;
    } else {
      Keyboard.press(KEY_SPACE);
      flashled(LEDpin, LEDduration);
    }
  }
  if (playpause.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_6); // Cam 6 (Rear-Facing - 7 if Fly-by.)
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_6);
      shifted = true;
    } else {
      Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
      flashled(LEDpin, LEDduration);
    }
  }
  if (esc.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_TAB); // Tab - Skip workout segment/interval
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_TAB);
      shifted = true;
    } else {
      Keyboard.press(KEY_ESC);
      flashled(LEDpin, LEDduration);
    }
  }
  if (g_key.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_T); // T - Garage
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_T);
      shifted = true;
    } else {
      Keyboard.press(KEY_G);
      flashled(LEDpin, LEDduration);
    }
  }
  if (a_key.fallingEdge()) {
    if (shifting) {
      Keyboard.press(KEY_E);    // E - Training Menu
      flashled(LEDpin, LEDduration);
      Keyboard.release(KEY_E);
      shifted = true;
    } else {
      Keyboard.press(KEY_A);
      flashled(LEDpin, LEDduration);
    }
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
  if (g_key.risingEdge()) {
    Keyboard.release(KEY_G);
  }  
  if (a_key.risingEdge()) {
    Keyboard.release(KEY_A);
  }  
}
