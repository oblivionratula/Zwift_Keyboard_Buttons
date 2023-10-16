This project uses a Teensy LC to send keystrokes to a USB host.
In my case, this is the Zwift cycling/running game.

Keep in mind I have no idea what I'm doing and I've just tweaked other's examples.

You'll have to set pin numbers and KEY_ commands accordingly.
Add/remove what you need.
Feel free to correct what I've got wrong.

For reference, this version is build based on a Teensy LC mounted on a breakout board a friend made, so the pins used make sense FOR ME.
Feel free to alter the layout for what works for you.

Pin 13 is assigned to the onboard LED and I use that as a confirmation of keystrokes.
The exception to this is the Down Arrow key, bceause this key needs to be held down.
It does not auto-release after a delay like the other keys.

The way I did the release in the flash loop feels wrong, but it saved pasting a bunch of times.
As I said, I don't know what I'm doing.

This was coded in VS Code using the PlatformIO. Carrying over to Arduino, I should think would be trivial,
but DO NOTE, I beleive there you have to speficy this is a USB Keyboard in some pulldown.
Here that is handled in the platformio.ini file. YMMV

Also note if programming the Teensy from Debian/Linux, if it doesn't program, look for an error message mentioning udev rules.
Download the rules from:
https://www.pjrc.com/teensy/00-teensy.rules


HARDWARE:
Withthe Teensy LC, the hardware side is dead simple. Ground any pin (aside from 13) and Bob's your uncle. Ineed mroe buttons, but for my prototype, I have 5 small pushbuttons mounted up in an Altoid tin, Teensy insulated by tape, one ground wire to all the buttons, and then individual leads to each pin.

I plan to 3D print a case. If I get to that I'll add the stl or a link to Thingiverse. I also plan to 3D print the male part of a Garmin Edge (and similar) GPS mount to attach to the tin (or print w/ the enclosure) for easy handlebar mounting.


If you're clueless like me, here's some stuff that got me going:
https://wackyresearch.com/hacking-the-teensy-with-vs-code-and-platformio/
https://forum.pjrc.com/threads/53297-Could-anyone-show-me-the-Teensy-2-0-Keyboard-Code

Basic guide, but missing full working example useful to me:
https://www.pjrc.com/teensy/td_keyboard.html

Not used, but another reference:
https://www.pjrc.com/teensy/usb_keyboard.html

Notes from Zwift on available KB shortcuts:
Navigating the UI
You can use the following shortcuts when navigating the UI including the Home Screen and your in-game settings.

Enter	Select.
Esc	Go back.
←	Navigate left.
↑	Navigate up.
→	Navigate right.
↓	Navigate down.

Riding, Running, or Working Out in Zwift
Check out the table below for available shortcuts while riding, running, working out, or participating in an event.

ESC Go back.
A	Access the PAIRED DEVICES screen.
T	Access your GARAGE.
G	Toggle Watt/HR Graphs When Riding
M	Send a group text.
1-9	Change your camera view.
H	Show or hide the display.
F1-F8	Actions + Sound.
PC: F10 OSX: Function + F10	Take a screenshot.
OSX: Function + F9	Capture a video.
Space Bar	Activate a power-up.
P	Enter a Promo Code.
Down Arrow	Make a U-Turn.
Up Arrow	Display the Action Bar.
Left and Right Arrows	Initiate a turn at an intersection.
E	Open the TRAINING menu.
Tab	Skip a workout step.
Page Up/Page Down	Increase or decrease the FTP Bias.


HTH.
