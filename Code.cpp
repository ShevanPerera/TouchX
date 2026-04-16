// Motor pins for the left side
unsigned long lastTouchTime = 0; // Variable to track the last touch timeconst unsigned long sleepDelay = 600000; // 10 minutes in millisecondsbool tired = 0;
bool angry = 0;
bool happy = 0;
bool curious = 0; // if true, draw the outer eye larger when looking left or rightbool cyclops = 0; // if true, draw only one eye
bool eyeL_open = 0; // left eye opened or closed?
bool eyeR_open = 0; // right eye opened or closed?
#define DEFAULT 0
#define TIRED 1
#define ANGRY 2
#define HAPPY 3
#include <Adafruit_SSD1306.h>
#define touchSensor 8
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);#include <FluxGarage_RoboEyes.h>
roboEyes roboEyes; // create RoboEyes instance
const int leftMotor1 = 4; // Motor 1 input pin 1 (IN1)
const int leftMotor2 = 5; // Motor 1 input pin 2 (IN2)
// Motor pins for the right side
const int rightMotor1 = 7; // Motor 2 input pin 1 (IN3)
const int rightMotor2 = 6; // Motor 2 input pin 2 (IN4)+
// Ultrasonic sensor pins
const int trigPin = A0; // Trigger pin
const int echoPin = A1; // Echo pin
// Variables for calculating distance
long duration;
int distance;
void setup() {
Serial.begin(9600);
pinMode(touchSensor, INPUT);
// Startup OLED Display
// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
pinMode(touchSensor, INPUT);
// Startup OLED Display
// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C or 0x3D
Serial.println(F("SSD1306 allocation failed"));
for (;;)
; // Don't proceed, loop forever
}
// Startup robo eyes
roboEyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100); // screen-width, screen-height, max framerate
// Define some automated eyes behaviour
roboEyes.setAutoblinker(ON, 3, 2);
roboEyes.setIdleMode(ON, 2, 2);
// Define eye shapes, all values in pixels
//roboEyes.setWidth(36, 36); // byte leftEye, byte rightEye
//roboEyes.setHeight(36, 36); // byte leftEye, byte rightEye
//roboEyes.setBorderradius(8, 8); // byte leftEye, byte rightEye
//roboEyes.setSpacebetween(10); // int space -> can also be negative
// Cyclops mode
//roboEyes.setCyclops(ON); // bool on/off -> if turned on, robot has only on eye
// Define mood, curiosity and position
//roboEyes.setMood(DEFAULT); // mood expressions, can be TIRED, ANGRY, HAPPY, DEFAULT
//roboEyes.setPosition(DEFAULT); // cardinal directions, can be N, NE, E, SE, S, SW, W, NW, DEFAULT (default = horizontally and vertically centered)
//roboEyes.setCuriosity(ON); // bool on/off -> when turned on, height of the outer eyes increases when moving to the very left or very right
// Set horizontal or vertical flickering
//roboEyes.setHFlicker(ON, 2); // bool on/off, byte amplitude -> horizontal flicker: alternately displacing the eyes in the defined amplitude in pixels
//roboEyes.setVFlicker(ON, 2); // bool on/off, byte amplitude -> vertical flicker: alternately displacing the eyes in the defined amplitude in pixels
// Play prebuilt oneshot animations
//roboEyes.anim_confused(); // confused - eyes shaking left and right
//roboEyes.anim_laugh(); // laughing - eyes shaking up and down
// Set motor pins as outputs
pinMode(leftMotor1, OUTPUT);
pinMode(leftMotor2, OUTPUT);
pinMode(rightMotor1, OUTPUT);
pinMode(rightMotor2, OUTPUT);
// Set ultrasonic sensor pins
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
// Measure distance from the ultrasonic sensor
roboEyes.update(); // update eyes drawings
if (digitalRead(touchSensor) == HIGH) {
// If the touch sensor is activated, show happy mood
roboEyes.setMood(HAPPY); // Set mood to happy
} else {
// Optionally, reset the mood to default if the sensor is not activated
roboEyes.setMood(DEFAULT); // Set back to default mood
}
// Don't use delay() here in order to ensure fluid eyes animations.
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2; // Calculate the distance in cm
// Print distance for debugging
Serial.print("Distance: ");
Serial.println(distance);
// Obstacle avoidance logic
if (distance < 20) {
// Obstacle detected, stop and reverse
stopCar();
delay(500);
reverseCar();
delay(500);
// Turn to avoid obstacle
turnRight(); // You can adjust for left turn if needed
delay(500);
} else {
// No obstacle, move forward
moveForward();
}
delay(100);
}
void moveForward() {
digitalWrite(motorLeftForward, HIGH);
digitalWrite(motorRightForward, HIGH);
}
// Function to move backward
void moveBackward() {
digitalWrite(motorLeftBackward, HIGH);
digitalWrite(motorRightBackward, HIGH);
}
// Function to turn right
void turnRight() {
digitalWrite(motorLeftForward, HIGH);
digitalWrite(motorRightBackward, HIGH);
}
// Function to stop movement
void stopMoving() {
digitalWrite(motorLeftForward, LOW);
digitalWrite(motorLeftBackward, LOW);
digitalWrite(motorRightForward, LOW);
digitalWrite(motorRightBackward, LOW);
}
// Function to check for obstacles
bool checkObstacle() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration * 0.034 / 2);
if (distance < 20) { // If an obstacle is detected within 20 cm
return true;
} else {
return false
