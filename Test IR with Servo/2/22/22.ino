#include <Servo.h>

// Define pins for IR sensors
#define ir1Pin 2


// Define pins for servos ********PWM*********
#define  servo1Pin 9


// Create Servo objects
Servo servo1;


// Total parking spaces
const int totalSpaces = 4;
int freeSpaces = totalSpaces;

// Function to setup the Arduino
void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize IR sensor pins
  pinMode(ir1Pin, INPUT);


  // Initialize servo motors
  servo1.attach(servo1Pin);

 Serial.println(freeSpaces);
/*
  // Initialize 7-segment display pins
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  
  //Display initial free spaces
  displayNumber(freeSpaces); 
  */
}

// Function to loop continuously
void loop() {
  // Read the state of the IR sensors
  bool ir1State = digitalRead(ir1Pin);
  

  // Check if IR sensor 1 is low (vehicle entering)
  if (ir1State == 0) {
    if (freeSpaces > 0) {
   Serial.println("servo_1 Open");
      servo1.write(90); // Open gate
      delay(2000); // Wait 2 seconds
      Serial.println("servo_1 close");
      servo1.write(0); // Close gate
     freeSpaces--; // Decrease free space
     Serial.print("freeSpaces is : ");
     Serial.println(freeSpaces);
    
     // displayNumber(freeSpaces); // Update display
    }
  }

 
  

  // Small delay to avoid rapid state changes
  delay(100);
}
/*
// Function to display number on 7-segment display
void displayNumber(int number) {
  // Turn off all segments first
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);

  // Display the number on the 7-segment display
  switch (number) {
    case 0:
      digitalWrite(segmentA, HIGH);
      */
