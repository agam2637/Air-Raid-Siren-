 int pirPin = A0;      
 int sensorValue;


void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}//setup

void loop() {
  sensorValue = analogRead(pirPin);
  Serial.println(sensorValue);

  if (sensorValue == 0) {
    Serial.println("Restricted Airspace. Leave Immediately");
    noTone(13);
    }//if
  else {
      Serial.println("Under Attack");
      airRaidSiren(400, 1000, 5000);
   }//else
  
  delay(100); // Small delay to avoid overwhelming the serial output
}//loop

void airRaidSiren(int startFreq, int endFreq, int duration) {
  // This function controls the sound of the alarm
  for (int freq = startFreq; freq <= endFreq; freq++) {
    tone(13, freq);
    delay(duration / (endFreq - startFreq)); 
  }//for
  
  for (int freq = endFreq; freq >= startFreq; freq--) {
    tone(13, freq);
    delay(duration / (endFreq - startFreq)); 
  }//for
  
  delay(500); 
}//airRaidSiren
