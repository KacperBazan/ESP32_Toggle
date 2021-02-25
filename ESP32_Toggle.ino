/*
 * Program Name: ESP32_Toggle
 * Program Description: Use the ESP32 board, an LED, and a button to toggle an LED on and off. 
 * Board Type: ESP2 DOIT-DEVKIT-V1
 * Date Started: Feb/23/2021
 * Author: Kacper Bazan
 * Author Link: https://github.com/KacperBazan
 */

/*
 * References
 * ESP_Wroom_32 Pinout: https://circuits4you.com/wp-content/uploads/2018/12/ESP32-Pinout.jpg
 * Toggle Switch Info: https://www.arduino.cc/en/Tutorial/BuiltInExamples/StateChangeDetection
 */

const int led = 2;
const int button = 4;
int toggle = 0;
int buttonState = 0;     //Default to not pressed.
int lastButtonState = 0; //Default to not pressed.

int curTime = 0;
int td = 50;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(115200);
  Serial.flush();
}

void ToggleButton()
{
  if (millis() - curTime > td) //Set a time delay to prevent immediate bouncing of the toggle value.
  {
    buttonState = digitalRead(button);
    if (buttonState != lastButtonState)
    {
      if (buttonState == HIGH)
      {
        toggle = !toggle;
      }
    }
    lastButtonState = buttonState;
    curTime = millis();
  }
}

void loop()
{
  ToggleButton();
  digitalWrite(led, toggle);
}
