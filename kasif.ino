#include <Servo.h>
#include <SPI.h>
#include "RF24.h"

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

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(7, 8);
/**********************************************************/

byte addresses[][6] = {"1Node", "2Node"};
 
void setup() {
  Serial.begin(9600);
  
  // starting radio..........
  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW); 

  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
 
  radio.startListening();
  // starting radio ends....
  
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
  
  waitForCommand();

 // ************************************************* forward ***********//

 
  
//  
//  delay(500);
//  for (int i = 0; i < maxDegree; i++) {
//    delay(10);
//    servoForward(claw);
//  }
//
//
//   delay(500);
//  for (int i = 0; i < maxDegree; i++) {
//    delay(10);
//    servoBackward(claw);
//  }

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


void waitForCommand(){
  
  int command;

  if ( radio.available()) {
    // Variable for the received timestamp
    while (radio.available()) {                                   // While there is data ready
      radio.read( &command, sizeof(int) );             // Get the payload
    }

    radio.stopListening();                                        // First, stop listening so we can talk
    radio.write( &command, sizeof(int) );              // Send the final one back.
    radio.startListening();                                       // Now, resume listening so we catch the next packets.
    Serial.print(F("Sent ack "));
    Serial.println(command);
  }
  
}
