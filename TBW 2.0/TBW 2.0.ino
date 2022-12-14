/************************************************************************

Teddy Bear wheelchair project program V3.0

This program has the added feature of an IR sensor. The wheel motor will
turn forward until it encounters a blackline. Then, the motor will continue to
spin forward for 1500 ms (to be changed when precice time is determined), stop
for 1500 ms, spin backwards for 1500 ms (also to be changed when precise time is
determined), then stop indefinetly.

*************************************************************************/

//define wheel motor location on breadboard
#define enA 3
#define in1A 4
#define in2A 5
//define lauch motor location on breadboard
#define enB 8
#define in1B 9
#define in2B 10

//define pin locations
const int sensor = 6;///add pin location
//define location to store sensor value
bool val;
int Case = 1;

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

  //define SensorPin as input
  pinMode(sensor, INPUT);
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
  Serial.println("***Wheel motor Stopped");
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

delay(1500);

val = digitalRead(sensor);

while (val == HIGH && Case == 1)
{
  delay(1500);
  Serial.println("stop line detected");
  runMotor1Forward(1500); /// ****insert time it takes to get from black line to required stop position
  stopMotor1(1500);
  runMotor1Backward(1500);/// ****insert time it takes to get from stop point to back to the start of the course
  Case=2;
    break;
  }

if (Case == 1)
{
runMotor1Forward();
}

else if (Case == 2)
{
Serial.println("END OF THE COURSE :)");
stopMotor1(1500);
}



}
