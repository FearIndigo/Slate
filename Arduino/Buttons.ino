bool input[4];
char output[4];
float ledBrightness[4];

const int BUTTON_PINS[] = {2,4,7,8};
const int LED_PINS[] = {3,5,6,9};
const int MAX_BRIGHTNESS = 255;
const int MIN_BRIGHTNESS = 5;
const float BRIGHTNESS_FADE = 0.9;

void setup()
{
  Serial.begin(9600);
  
  pinMode(BUTTON_PINS[0], INPUT_PULLUP);
  pinMode(BUTTON_PINS[1], INPUT_PULLUP);
  pinMode(BUTTON_PINS[2], INPUT_PULLUP);
  pinMode(BUTTON_PINS[3], INPUT_PULLUP);
  
  pinMode(LED_PINS[0], OUTPUT);
  pinMode(LED_PINS[1], OUTPUT);
  pinMode(LED_PINS[2], OUTPUT);
  pinMode(LED_PINS[3], OUTPUT);
}

void loop()
{
  input[0] = readInput(0);
  input[1] = readInput(1);
  input[2] = readInput(2);
  input[3] = readInput(3);

  for (int i = 0; i < 4; i++)
  {
    output[i] = input[i] ? '1' : '0';
  }

  Serial.write(output, 4);
  Serial.println();
}

bool readInput(int i)
{
  if (digitalRead(BUTTON_PINS[i]) == LOW)
  {
    ledBrightness[i] = MAX_BRIGHTNESS;
    analogWrite(LED_PINS[i], (int)ledBrightness[i]);
    return true;
  }
  else
  {
    ledBrightness[i] = max(ledBrightness[i] * BRIGHTNESS_FADE, MIN_BRIGHTNESS);
    analogWrite(LED_PINS[i], (int)ledBrightness[i]);
    return false;
  }
}
