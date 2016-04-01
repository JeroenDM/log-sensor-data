/*
  Code to create dummy sensor signal send to raspberry pi
  
  Jeroen De Maeyer 2016
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(readSensors());
  delay(1000);
}

String readSensors() {
  // simulated senor readings
  float v1 = 1.0000;
  float v2 = 2.0000;
  float temperature = 20.0000;
  
  // create data string with sensor readings
  // works from version 0019
  // String default 2 decimal places
  // string(float, decimal places)
  String data = "";
  data += String(v1);
  data += ",";
  data += String(v2);
  data += ",";
  data += String(temperature);
  
  return data;
} 
