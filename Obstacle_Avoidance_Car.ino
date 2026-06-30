#include <Servo.h>

// Motor pins
#define ENA 5
#define IN1 2
#define IN2 3
#define ENB 6
#define IN3 4
#define IN4 7

// Sensor pins
#define TRIG 8
#define ECHO 10

// Servo
Servo myServo;
#define SERVO_PIN 9

// Variables
int distance = 0;
int distLeft = 0;
int distRight = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  myServo.attach(SERVO_PIN);
  myServo.write(90);
  
  delay(2000);
  Serial.println("System Ready");
}

void loop() {
  distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance > 30) {
    moveForward();
    Serial.println("Moving Forward");
  } else {
    stopMotors();
    Serial.println("Obstacle Detected - Scanning");
    delay(800);
    
    myServo.write(30);
    delay(400);
    myServo.write(90);
    delay(500);
    distLeft = getDistance();
    Serial.print("Left Distance: ");
    Serial.println(distLeft);
    
    myServo.write(150);
    delay(400);
    myServo.write(90);
    delay(500);
    distRight = getDistance();
    Serial.print("Right Distance: ");
    Serial.println(distRight);
    
    if (distLeft > distRight) {
      Serial.println("Turning Left");
      turnLeft();
      delay(800);
    } else {
      Serial.println("Turning Right");
      turnRight();
      delay(800);
    }
  }
  
  delay(100);
}

int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH, 30000);
  int dist = duration * 0.034 / 2;
  
  if (dist == 0 || dist > 400) {
    return 400;
  }
  return dist;
}

void moveForward() {
  analogWrite(ENA, 150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  analogWrite(ENB, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

void turnLeft() {
  analogWrite(ENA, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  analogWrite(ENB, 150);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  analogWrite(ENA, 150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  analogWrite(ENB, 150);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
