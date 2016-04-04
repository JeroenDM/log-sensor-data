float temp_in_celsius = 0, temp_in_kelvin=0, temp_in_fahrenheit=0;

void setup()
{
  Serial.begin(9600); 
}

void loop()
{

  //Reads the input and converts it to Kelvin degrees
  temp_in_kelvin = analogRead(0) * 5.0 / 1024.0 * 100;
  
  //Converts Kelvin to Celsius minus 2.5 degrees error
  //temp_in_celsius = temp_in_kelvin - 2.5 - 273.15;
  temp_in_celsius = temp_in_kelvin - 273.15;

  //Print the temperature in Celsius to the serial port
  Serial.print("Celsius: ");
  Serial.println(temp_in_celsius);                  


  delay(1000); 
}
