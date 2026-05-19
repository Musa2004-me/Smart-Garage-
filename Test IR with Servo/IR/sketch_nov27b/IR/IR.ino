#include <Servo.h>

// Define pins for IR sensors
#define ir_1 2
#define ir_2 4

// Define pins for servos ********PWM*********
#define  servo1Pin 9
#define  servo2Pin 10

// Create Servo objects
Servo servo1;
Servo servo2;

// Total parking spaces
const int totalSpaces = 4;
int freeSpaces = totalSpaces;

// Function to setup the Arduino
void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize IR sensor pins
  pinMode(ir_1, INPUT);
  pinMode(ir_2, INPUT);

  // Initialize servo motors
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  Serial.print("free Spaces = ");
  Serial.println(freeSpaces);

}

// Function to loop continuously
void loop() {
  // Read the state of the IR sensors
  bool ir_1_State = digitalRead(ir_1);
  bool ir_2_State = digitalRead(ir_2);

  // Check if IR sensor 1 is low (vehicle entering)
  if (ir_1_State == 0) {
    if (freeSpaces > 0) {
      Serial.println("Servo_1 opens ");
      servo1.write(90); // Open gate
      while(ir_1_State == 0)//busy wait
      {}
      //delay(2000); // Wait 2 seconds
      Serial.println("Servo_1 closes ");
      servo1.write(0); // Close gate
      freeSpaces--; // Decrease free space
      Serial.print("free Spaces = ");
      Serial.println(freeSpaces);
     // displayNumber(freeSpaces); // Update display
    }
  }

  // Check if IR sensor 2 is low (vehicle exiting)
  if (ir_2_State == 0) {
    if (freeSpaces < totalSpaces) {
      Serial.println("Servo_2 opens ");
      servo2.write(90); // Open gate
      while(ir_2_State == 0)//busy wait
      {}
     // delay(2000); // Wait 2 seconds
      Serial.println("Servo_2 closes ");
      servo2.write(0); // Close gate
      freeSpaces++; // Increase free space
      Serial.print("free Spaces = ");
      Serial.println(freeSpaces);
     // displayNumber(freeSpaces); // Update display
    }
  }

  // Small delay to avoid rapid state changes
  delay(100);
}
