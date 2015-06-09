#include <Servo.h>

Servo claw;
Servo wrist;
Servo elbow;
Servo rim;


// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;


// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;

int clawPin = 12;
int wristPin = 11;
int elbowPin = 10;
int rimPin = 9;


void setup() {
  Serial.begin(9600);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);

  claw.attach(clawPin);
  wrist.attach(wristPin);
  elbow.attach(elbowPin);
  rim.attach(rimPin);
  
  claw.write(0);
  wrist.write(0);
  elbow.write(0);
  rim.write(0);
  
  delay(2000);
}

int maxDegree = 60;

void loop()
{

 // ************************************************* forward ***********//

 
  
  
  delay(500);
  for (int i = 0; i < maxDegree; i++) {
    delay(10);
    servoForward(claw);
  }


   delay(500);
  for (int i = 0; i < maxDegree; i++) {
    delay(10);
    servoBackward(claw);
  }

//  delay(500);
//  for (int i = 0; i < maxDegree; i++) {
//    servoForward(wrist);
//    delay(15);
//  }
//
//  delay(500); 
//  for (int i = 0; i < maxDegree; i++) {
//    servoForward(elbow);
//    delay(15);
//  }
//
//  delay(500); 
//  for (int i = 0; i < maxDegree; i++) {
//    servoForward(rim);
//    delay(15);
//  }

 // ************************************************* backward ***********//


//  delay(500);
//  for (int i = 0; i < maxDegree; i++) {
//    servoBackward(wrist);
//    delay(15);
//  }
//
//  delay(500); 
//  for (int i = 0; i < maxDegree; i++) {
//    servoBackward(elbow);
//    delay(15);
//  }
//
//  delay(500); 
//  for (int i = 0; i < maxDegree; i++) {
//    servoBackward(rim);
//    delay(15);
//  }



  //  delay(3000);
  //  forward();
  //  delay(1000);
  //  stop();
  //
  //  delay(3000);
  //  backward();
  //  delay(1000);
  //  stop();
  //
  //  delay(3000);
  //  right();
  //  delay(1000);
  //  stop();
  //
  //  delay(3000);
  //  left();
  //  delay(1000);
  //  stop();
}

void right() {
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);

  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
}

void left() {
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);

  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
}

void backward() {
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);

  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
}

void forward() {
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);

  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
}

void stop() {
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);

  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, LOW);
}

void servoForward(Servo servo) {
  int position = servo.read();

  if (position != 180)
    servo.write(position + 1);

}

void servoBackward(Servo servo) {
  int position = servo.read();

  if (position != 0)
    servo.write(position - 1);
}
