
// Read sensors and put data in one string
String readSensors() {
  
  fsrReading = analogRead(fsrPin);
  fsrForce = voltage2force(fsrReading);
 
  
  // simulated senor readings
  float v2 = 2.0000;
  float temperature = 20.0000;
  
  // create data string with sensor readings
  // works from version 0019
  // String default 2 decimal places
  // string(float, decimal places)
  String data = "";
  data += String(fsrForce);
  data += ",";
  data += String(v2);
  data += ",";
  data += String(temperature);
  
  return data;
}

// Convert analog reading to force on the fsr sensor
// credit to www.ladyada.net/learn/sensors/fsr.html
long voltage2force(int reading) {
  
  // local vars for calcultations
  int fsrVoltage;     // the analog reading converted to voltage
  unsigned long fsrResistance;  // The voltage converted to resistance, can be very big so make "long"
  unsigned long fsrConductance; 
  long force;

  // analog voltage reading ranges from about 0 to 1023 which maps to 0V to 5V (= 5000mV)
  fsrVoltage = map(reading, 0, 1023, 0, 5000);
  if (fsrVoltage == 0) {
      force = 0;
   } else {
      // The voltage = Vcc * R / (R + FSR) where R = 10K and Vcc = 5V
      // so FSR = ((Vcc - V) * R) / V        yay math!
      fsrResistance = 5000 - fsrVoltage;     // fsrVoltage is in millivolts so 5V = 5000mV
      fsrResistance *= 10000;                // 10K resistor
      fsrResistance /= fsrVoltage;
      
      fsrConductance = 1000000;           // we measure in micromhos so 
      fsrConductance /= fsrResistance;
 
      // Use the two FSR guide graphs to approximate the force
      if (fsrConductance <= 1000) {
        force = fsrConductance / 80;   
      } else {
        force = fsrConductance - 1000;
        force /= 30;          
      }
  }
  
  return force;
}
