#include <keyboard.h>
#include <Adafruit_CircuitPlayground.h>

const int MUTE_BUTTON = 6;
const int DEBOUNCE_DELAY = 50;

char ctrlKey = KEY_LEFT_CTRL;

int slideCounter = 0;
int currentButtonState = 0;
int lastSteadyState = 0;
int lastFlickerableState = 0;
int lastDebounceTime = 0;


void setup()
{
CircuitPlayground.begin();
pinMode(MUTE_BUTTON, INPUT_PULLDOWN);
Serial.Begin(115200);

Keyboard.begin();
Serail.println("Ready to deploy Move the CPX slide switch to the left  to enable the mute button ");

}
void loop()
{
while(CircuitPlayground.slideSwitch())
{
if(slideCounter == 0)
{
Serialprintln("Ready to Mute ");
slideCounter += 1;

}
currentButtonState = digitalRead(MUTE_BUTTON);
lastDebounceTime = millis();
lastFlickerableState = currentButtonState;
}
if((millis() - lastDebounceTime)  > DEBOUNCE_DELAY)
{
if(lastSteadyState == 1 && currentButtonState == 0)
{
CircuitPlayground.redLED(HIGH);
Serail.println("Pressed");
keyboard.press(ctrlKey);
keyboard.press(KEY_LEFT_CTRL);
keyboard.press('m');

}
lastSteadyState = currentButtonState;
CicuitPlayground.redLED(LOW);
keyboard.releaseAll();

}
slideCounter = 0;
keyboard.releaseAll();


}





