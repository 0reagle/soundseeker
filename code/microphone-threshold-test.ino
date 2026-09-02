/*
  Microphone threshold test

  Reads the MAX9814 microphone using ESP32 GPIO32.
  Measures sound level using highest - lowest ADC value over 50 ms.
  Prints whether sound is detected based on a threshold of 1500.
*/

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
    Serial.println("Sound Detected");
  }
  else{
    Serial.println("No Sound");
  }
  delay(100);
}
