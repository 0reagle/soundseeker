int threshold = 1500;
int micPin = 32;

void setup() {
  pinMode(micPin, INPUT);
  Serial.begin(115200);
  
}

void loop() {
  int soundLevel;
  int lowest = 4095;
  int highest = 0;
  unsigned long startTime = millis();
  while (millis() - startTime < 50){
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
    Serial.println(String("Sound level: ") + soundLevel + " - Sound Detected");
  }
  else{
    Serial.println(String("Sound level: ") + soundLevel + " - No Sound");
  }
  delay(100);
}
