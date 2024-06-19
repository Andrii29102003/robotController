#include <SoftwareSerial.h>

#define R_Motor 2
#define Speed   3
#define L_Motor 4

SoftwareSerial BTSerial(10, 11); // RX, TX

float speedCoef = 0.3;

void zero(){
  digitalWrite(R_Motor, HIGH);
  digitalWrite(Speed, LOW);
  digitalWrite(L_Motor, HIGH);
}

void right() {
  digitalWrite(R_Motor, LOW);
  delay(500);
  analogWrite(Speed, 255 * speedCoef);
}

void front() {
  analogWrite(Speed, 255 * speedCoef);
}

void left() {
  digitalWrite(L_Motor, LOW);
  delay(500);
  analogWrite(Speed, 255 * speedCoef);
}

void revers(){
  digitalWrite(R_Motor, LOW);
  digitalWrite(L_Motor, LOW);
  delay(500);
}

void setup() {
  BTSerial.begin(9600); // the baud rate of HC-05 is usually 38400
  Serial.begin(9600); 
  pinMode(R_Motor, OUTPUT);
  pinMode(Speed, OUTPUT);
  pinMode(L_Motor, OUTPUT);

}

void loop() { 
  if (BTSerial.available()) {
    char c = BTSerial.read();
    Serial.println(c);
    switch(c){
      case '0':
        zero();
        break;
      case 'R':
        right();
        break;
      case 'F':
        front();
        break;
      case 'L':
        left();
        break;
      case 'B':
        revers();
        break;
      case '1':
        speedCoef = 0.3;
        break;
      case '2':
        speedCoef = 0.5;
        break;
      case '3':
        speedCoef = 1;
        break;
    }
  }
}
