// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;


// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;

int servoMotor1Pin = 6;


void setup() {
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT); 
  
  pinMode(servoMotor1Pin, OUTPUT); 
}

void loop()
{ 
  delay(3000);
  forward();
  delay(1000);
  stop(); 
  
  delay(3000);
  backward(); 
  delay(1000);
  stop(); 
  
  delay(3000);
  right(); 
  delay(1000);
  stop(); 
  
  delay(3000);
  left();  
  delay(1000);
  stop(); 
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

void servoForward(int servoMotorNo, int derece){
  if(servoMotorNo == 1){
    digitalWrite(servoMotor1Pin, HIGH);
  }
  
}

void servoBackward(int servoMotorNo, int derece){
  
  
}
