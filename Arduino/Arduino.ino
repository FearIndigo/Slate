float ledBrightness[4];

const int BUTTON_PINS[] = {2,4,7,8};
const int LED_PINS[] = {3,5,6,9};
const int MAX_BRIGHTNESS = 255;
const int MIN_BRIGHTNESS = 5;
const float BRIGHTNESS_FADE = 0.9;

void setup()
{
  Serial.begin(9600);
  
  for (int i = 0; i < 4; i++)
  {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
    pinMode(LED_PINS[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    Serial.write(processInput(i));
  }
  
  Serial.println();
}

char processInput(int i)
{
  if (digitalRead(BUTTON_PINS[i]) == LOW)
  {
    ledBrightness[i] = MAX_BRIGHTNESS;
    analogWrite(LED_PINS[i], (int)ledBrightness[i]);
    return '1';
  }
  else
  {
    ledBrightness[i] = max(ledBrightness[i] * BRIGHTNESS_FADE, MIN_BRIGHTNESS);
    analogWrite(LED_PINS[i], (int)ledBrightness[i]);
    return '0';
  }
}
