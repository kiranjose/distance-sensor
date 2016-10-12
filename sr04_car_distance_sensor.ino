/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 */


#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED

int maximumRange = 300; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);

 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(LEDPin, LOW); 
 }
 if (distance >= 90 && distance <= 100){
 Serial.println("step2");
 digitalWrite(2, HIGH); 
 }
 else {
 digitalWrite(2, LOW); 
 }
 if (distance >= 80 && distance < 90){
 Serial.println("step3");
 digitalWrite(3, HIGH); 
 }
 else {
 digitalWrite(3, LOW); 
 } 
 
  if (distance >= 70 && distance < 80){
 Serial.println("step4");
 digitalWrite(4, HIGH); 
 }
 else {
 digitalWrite(4, LOW); 
 } 
 
  if (distance >= 60 && distance < 70){
 Serial.println("step5");
 digitalWrite(5, HIGH); 
 }
 else {
 digitalWrite(5, LOW); 
 } 
  
  if (distance >= 50 && distance < 60){
 Serial.println("step6");
 digitalWrite(6, HIGH); 
 }
 else {
 digitalWrite(6, LOW); 
 } 
  
  if (distance >= 40 && distance < 50){
 Serial.println("step7");
 digitalWrite(9, HIGH); 
 }
 else {
 digitalWrite(9, LOW); 
 } 
  
  if (distance >= 30 && distance < 40){
 Serial.println("step8");
 digitalWrite(10, HIGH); 
 }
 else {
 digitalWrite(10, LOW); 
 } 
  
  if (distance >= 20 && distance < 30){
 Serial.println("step9");
 digitalWrite(11, HIGH); 
 }
 else {
 digitalWrite(11, LOW); 
 } 
  
  if (distance >= 10 && distance < 20){
 Serial.println("step10");
 digitalWrite(12, HIGH); 
 }
 else {
 digitalWrite(12, LOW); 
 }  
 //Delay 50ms before next reading.
 delay(50);
}
