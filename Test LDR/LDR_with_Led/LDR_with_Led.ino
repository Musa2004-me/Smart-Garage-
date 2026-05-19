#define LDR A0
#define led1 6
#define led2 5

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(LDR, INPUT);

}

void loop() {
  // Read the actual analog value
  int value = analogRead(LDR);

  // Map the average value from MIN to MAX into PWM values
  int ledPwmValue = map(value, 0, 1023, 0, 255);

  // Write mapped value as PWM signal to LEDs
  analogWrite(led2, ledPwmValue);
  analogWrite(led1, ledPwmValue);

  // Add a small delay to avoid flooding the serial output
  delay(100);
}
