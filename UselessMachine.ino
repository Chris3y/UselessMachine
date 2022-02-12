#include <Servo.h>

Servo doorServo;
Servo armServo;

const int SWITCH_PIN = 12; 

const int DOOR_SERVO_PIN = 5;
const int DOOR_OPEN_POS = 170;
const int DOOR_CLOSED_POS = 96;

const int ARM_SERVO_PIN = 6;
const int ARM_EXTEND_POS = 0;
const int ARM_RETRACT_POS = 170;

const int RGB_GREEN_PIN = 4;
const int RGB_RED_PIN = 2;
  
void setup()
{
  pinMode(SWITCH_PIN, INPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
  pinMode(RGB_RED_PIN, OUTPUT);
  
  digitalWrite(RGB_GREEN_PIN, HIGH);
  
  doorServo.attach(DOOR_SERVO_PIN);
  armServo.attach(ARM_SERVO_PIN);
  
  doorServo.write(DOOR_CLOSED_POS);
  armServo.write(ARM_RETRACT_POS);
}

void loop()
{
  if (digitalRead(SWITCH_PIN) == HIGH) 
  {
    digitalWrite(RGB_GREEN_PIN, LOW);
    digitalWrite(RGB_RED_PIN, HIGH);
    
    delay(500);
    doorServo.write(DOOR_OPEN_POS);
    delay(1000);
    armServo.write(ARM_EXTEND_POS);
    delay(1000);
    armServo.write(ARM_RETRACT_POS);
    delay(1000);
    doorServo.write(DOOR_CLOSED_POS);
    delay(500);
    
    digitalWrite(RGB_RED_PIN, LOW);
    digitalWrite(RGB_GREEN_PIN, HIGH);
  }
  delay(30); 
}
