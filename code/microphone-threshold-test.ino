const int threshold = 1500;                                    //Threshold for detecting sound
const int micPin = 32;                                         // Microphone pin
bool soundDetected = false;                                    // Stores whether sound is currently detected
const unsigned long sampleWindow = 50;                                   
int soundLevel;

void setup() {
  pinMode(micPin, INPUT);
  Serial.begin(115200);
  
}

int measureSoundLevel(){
  int lowest = 4095;                                           // Lowest ADC value in the current sample window
  int highest = 0;                                             // Highest ADC value in the current sample window
  unsigned long startTime = millis();                          // Start time for this sample window
  while (millis() - startTime < sampleWindow){                 //Collect readings for 50 ms and track the lowest and highest values
    int value = analogRead(micPin);
    if (value < lowest){
      lowest = value;
    }
    if (highest < value){
      highest = value;
    }
  }
  return (highest - lowest);
  
}

void loop() {
   soundLevel = measureSoundLevel();
  soundDetected = soundLevel > threshold;
  if (soundDetected){
    Serial.println(String("Sound level: ") + soundLevel + " - Sound Detected");
  }
  else{
    Serial.println(String("Sound level: ") + soundLevel + " - No Sound");
  }
  delay(100);                                                                     //Short delay to make the serial output easier to read
}
