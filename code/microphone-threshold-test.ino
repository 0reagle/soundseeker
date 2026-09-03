const int threshold = 1500;                                    //Threshold for detecting Sound
const int micPin = 32;                                         // Microphone pin
bool soundDetected = false;                                    //Sound Detection
const unsigned long sampleWindow = 50;                                   

void setup() {
  pinMode(micPin, INPUT);
  Serial.begin(115200);
  
}

void loop() {
  int soundLevel;
  int lowest = 4095;                                           //Lowest Value currently read
  int highest = 0;                                             //Highest Value currently read
  unsigned long startTime = millis();                          //Gets the current time since the board began to run
  while (millis() - startTime < sampleWindow){                 //Collect readings for 50 ms and track the lowest and highest values
    int value = analogRead(micPin);
    if (value < lowest){
      lowest = value;
    }
    if (highest < value){
      highest = value;
    }
  }
  soundLevel = highest-lowest;
  if (soundLevel > threshold){
    soundDetected = true;
  }
  else{
    soundDetected = false;
  }

  if (soundDetected){
    Serial.println(String("Sound level: ") + soundLevel + " - Sound Detected");
  }
  else{
    Serial.println(String("Sound level: ") + soundLevel + " - No Sound");
  }
  delay(100);                                                                     //Short delay to make the serial output easier to read
}
