byte result;
unsigned long ledOffDuration[4];
unsigned long prevTime, deltaTime, currentTime;

const int BUTTON_PINS[] = {2,4,7,8};
const int LED_PINS[] = {3,5,6,9};
const int MAX_BRIGHTNESS = 255;
const int MIN_BRIGHTNESS = 1;
const int BRIGHTNESS_FADE_DURATION = 300;
const float BRIGHTNESS_EXPONENT = 10;

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
  result = 0;
  
  for (int i = 0; i < 4; i++)
  {
    if(processInput(i))
      result |= (byte)(1 << i);
  }

  Serial.write(result);

  currentTime = millis();
  deltaTime = currentTime - prevTime;
  prevTime = currentTime;
}

bool processInput(int i)
{
  if (digitalRead(BUTTON_PINS[i]) == LOW)
  {
    ledOffDuration[i] = 0;
    analogWrite(LED_PINS[i], MAX_BRIGHTNESS);
    return true;
  }
  else
  {
    analogWrite(LED_PINS[i],
    fscale(ledOffDuration[i],0,BRIGHTNESS_FADE_DURATION,MAX_BRIGHTNESS,MIN_BRIGHTNESS,BRIGHTNESS_EXPONENT));
    ledOffDuration[i]+=deltaTime;
    return false;
  }
}

float fscale(float inputValue, float originalMin, float originalMax, float newBegin, float
newEnd, float curve){

  float OriginalRange = 0;
  float NewRange = 0;
  float zeroRefCurVal = 0;
  float normalizedCurVal = 0;
  float rangedValue = 0;
  boolean invFlag = 0;

  // condition curve parameter
  // limit range

  if (curve > 10) curve = 10;
  if (curve < -10) curve = -10;

  curve *=-.1; // - invert and scale - this seems more intuitive - postive numbers give more weight to high end on output
  curve = pow(10, curve); // convert linear scale into lograthimic exponent for other pow function

  // Check for out of range inputValues
  if (inputValue < originalMin) {
    inputValue = originalMin;
  }
  if (inputValue > originalMax) {
    inputValue = originalMax;
  }

  // Zero Refference the values
  OriginalRange = originalMax - originalMin;

  if (newEnd > newBegin){
    NewRange = newEnd - newBegin;
  }
  else
  {
    NewRange = newBegin - newEnd;
    invFlag = 1;
  }

  zeroRefCurVal = inputValue - originalMin;
  normalizedCurVal  =  zeroRefCurVal / OriginalRange;   // normalize to 0 - 1 float

  // Check for originalMin > originalMax  - the math for all other cases i.e. negative numbers seems to work out fine
  if (originalMin > originalMax ) {
    return 0;
  }

  if (invFlag == 0){
    rangedValue =  (pow(normalizedCurVal, curve) * NewRange) + newBegin;
  }
  else     // invert the ranges
  {  
    rangedValue =  newBegin - (pow(normalizedCurVal, curve) * NewRange);
  }

  return rangedValue;
}
