// Define pins for the ultrasonic sensor
#define trigPin1  3 //**************IMP PWM Pin****************
#define echoPin1  4
#define trigPin2  5 //**************IMP PWM Pin****************
#define echoPin2  7
#define buzzerPin 2 // Define pin for the buzzer
// Frequency of the buzzer sound when activated (in Hz)
const int buzzerFrequency = 1000; // 1000 Hz


void setup() {
  
  Serial.begin(9600); // Start the Serial Monitor
  
  
  pinMode(trigPin1, OUTPUT); // Set the trigPin as an OUTPUT
  
  pinMode(echoPin1, INPUT); // Set the echoPin as an INPUT
  
  pinMode(trigPin2, OUTPUT); // Set the trigPin as an OUTPUT
  
  pinMode(echoPin2, INPUT); // Set the echoPin as an INPUT
  pinMode(buzzerPin, OUTPUT); // Set the buzzerPin as an OUTPUT
}


void loop() {
  // Variables to store the duration and distance
  long duration_1;
  float distance_1;
 
long duration_2;
  float distance_2;
  
  // Clear the trigPin1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);

  // Set the trigPin1 HIGH for 10 microseconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Read the echoPin1, and get the duration of the pulse
  duration_1 = pulseIn(echoPin1, HIGH);

  // Calculate the distance in cm
  distance_1 = duration_1 * 0.034 / 2;   // /100 for the simulation 

  // Print the distance1 to the Serial Monitor
  Serial.print("Distance_1: ");
  Serial.print(distance_1);
  Serial.println(" cm");

  // Check if the distance is less than 4 cm
  if (distance_1 < 4) {
    delay(100);
    digitalWrite(trigPin1, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin1, LOW); 
     
      Serial.println(duration_1);
     
    // Activate the buzzer with a specified frequency
    tone(buzzerPin, buzzerFrequency);
    delay(duration_1);
    noTone(buzzerPin);
 }else {
    // Deactivate the buzzer
    noTone(buzzerPin);
 }
 // Clear the trigPin2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  // Set the trigPin2 HIGH for 10 microseconds
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  // Read the echoPin2, and get the duration of the pulse
  duration_2 = pulseIn(echoPin2, HIGH);

  // Calculate the distance in cm
  distance_2 = duration_2 * 0.034 / 2;   // /100 for the simulation 

  // Print the distance2 to the Serial Monitor
  Serial.print("Distance_2: ");
  Serial.print(distance_2);
  Serial.println(" cm");

  // Check if the distance is less than 4 cm
  if (distance_2 < 4) {
    delay(100);
    digitalWrite(trigPin2, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin2, LOW); 
     
      Serial.println(duration_2);
     
    // Activate the buzzer with a specified frequency
    tone(buzzerPin, buzzerFrequency);
    delay(duration_2);
    noTone(buzzerPin);
 }
 else {
    // Deactivate the buzzer
    noTone(buzzerPin);
 }
  // Wait for a short period before the next measurement
  delay(100);
 }
