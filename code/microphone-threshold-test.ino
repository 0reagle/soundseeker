void setup() {
  pinMode(32, INPUT);
  Serial.begin(115200);
  
}

void loop() {
  int soundLevel;
  int lowest = 4095;
  int highest = 0;
  unsigned long startTime = millis();
  while (millis() - startTime < 50){
    int value = analogRead(32);
    if (value < lowest){
      lowest = value;
    }
    if (highest < value){
      highest = value;
    }
  }
  soundLevel = highest-lowest;
  if (soundLevel > 1500){
    Serial.println(String("Sound level: ") + soundLevel + " - Sound Detected");
  }
  else{
    Serial.println(String("Sound level: ") + soundLevel + " - No Sound");
  }
  delay(100);
}
