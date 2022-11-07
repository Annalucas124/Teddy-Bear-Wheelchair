/************************************************************************

Teddy Bear wheelchair project program V2.0

This program turns on two motors, "wheel" and "launch". Then runs the motors forward
for 1500 milliseconds, stops for 1500 millisecondss backwards for 1500 milliseconds, then stops for 1500 milliseconds.
This cycle repeats until the motors no longer receive power.

*************************************************************************/

//define wheel motor location on breadboard
#define enA 3
#define in1A 4
#define in2A 5
//define lauch motor location on breadboard
#define enB 8
#define in1B 9
#define in2B 10

void setup() {
  // initialize serial communication
  Serial.begin(9600);

  // set wheel motor pins to output
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);

  // Set launch motor pins to output
  pinMode(enB, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);

  // enable wheel and launch motor by setting enA and enB to high permanently
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
}

// Declaring Functions:
// Run wheel motor forward
void runMotor1Forward(int time)
{
  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);
  Serial.println("Spinning motor 1 forward");
  delay(time);
}
// Run launch motor forward
void runMotor2Forward(int time)
{
  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  Serial.println("Spinning motor 2 forward");
  delay(time);
}
// Run wheel motor backward
void runMotor1Backward(int time)
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  Serial.println("Spinning motor 1 backward");
  delay(time);
}
// Run launch motor backward
void runMotor2Backward(int time)
{
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, HIGH);
  Serial.println("Spinning motor 2 backward");
  delay(time);
}
// Stop wheel motor
void stopMotor1(int time)
{
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, LOW);
  Serial.println("Wheel motor Stopped");
  delay(time);
}
// Stop Launch motor
void stopMotor2(int time)
{
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, LOW);
  Serial.println("Launch motor Stopped");
  delay(time);
}

void loop() {
 
runMotor1Forward(1500);
runMotor2Forward(1500);
stopMotor1(1500);
stopMotor2(1500);
runMotor1Backward(1500);
runMotor2Backward(1500);

delay(1500);


}
