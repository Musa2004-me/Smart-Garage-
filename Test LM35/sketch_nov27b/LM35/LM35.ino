#define LM35 A0
void setup() {
  // Begin serial communication
  Serial.begin(9600);

  // Set LM35 pin as input
  pinMode(LM35, INPUT); 
}

void loop() {
  // Read analog value from LM35
  int sensor_Value = analogRead(LM35);

  // Convert the analog reading (0-1023) to voltage (0-5V)
  float voltage = (sensor_Value / 1023.0) * 5.0;

  // Calculate temperature based on LM35's sensitivity (10mV/°C)
  float temperature = voltage * 100.0 / 2.8;

  // Print the processed temperature to the serial monitor
  Serial.print("Processed Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");
 
  delay(3000);
  
}
