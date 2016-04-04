/*
Connect one end of FSR to power, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html

Jeroen De Maeyer 2016
*/
 
int fsrPin = 0;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divider
long fsrForce;       // Finally, the resistance converted to force

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(readSensors());
  delay(1000);
}


