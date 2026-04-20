#include <SoftwareSerial.h>
// probably going to use these pins...
//  arduino tx, rx resp needs to connect to bluetooth rx, tx resp 
//  hence, blue to 5 to HM10 TX, white to 6 to HM10 RX 
SoftwareSerial BT(5,6); 

// global vars...
bool testing = true;

// pins...
// motor driver...
const int ENA = 11;
const int ENB = 10;
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 2;
const int IN4 = 3;

int motorSpeed = 100;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  BT.begin(9600);

  // "clear" serial...
  for (int i = 0; i < 30; i++) {
    Serial.println();
  }

  Serial.println(F("Accepting new keyboard command... {\"f\": forward, \"b\": backward, \"r\": clockwise rotation, \"l\": counterclockwise rotation}, \"s\": stop}"));
  BT.println(F("Accepting new keyboard command... {\"f\": forward, \"b\": backward, \"r\": clockwise rotation, \"l\": counterclockwise rotation}, \"s\": stop}"));
  stop();
}


void stop(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(500);

  return;
}

void forward(){
  // changing dirs...
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // applying speed...
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  return;
}

void backward(){
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  return;
}

void clkwise_rot(){
  // wheel1 backward...
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);

  // wheel2 forward...
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  return;
}
void ctrclkwise_rot(){
  // wheel1 forward...
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);

  // wheel2 backward... 
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  return;
}


void loop() {
  if (BT.available() > 0) {
    char cmd = BT.read();

    // throw away "trivial" chars...
    if (cmd == '\n' || cmd == '\r') {
      return;
    }

    Serial.print(F("Rcvd: "));
    Serial.println(cmd);

    BT.print(F("Received: "));
    BT.println(cmd);

    

    if (cmd == 'f'){
      if (testing) {
        stop();
        forward();
      }

      else {
        Serial.println(F("Moving forward..."));
        BT.println(F("Moving forward..."));
      }
    }

    else if (cmd == 'b'){
      if (testing) {
        stop();
        backward();
      }

      else {
        Serial.println(F("Moving backward..."));
        BT.println(F("Moving backward..."));
      }
    }

    else if (cmd == 'r'){
      if (testing) {
        stop();
        clkwise_rot();
      }

      else {
        Serial.println(F("Spinning clockwise..."));
        BT.println(F("Spinning clockwise..."));
      }
    }

    else if (cmd == 'l'){
      if (testing) {
        stop();
        ctrclkwise_rot();
      }

      else {
        Serial.println(F("Spinning counterclockwise..."));
        BT.println(F("Spinning counterclockwise..."));
      }
    }

    else if (cmd == 's'){
      stop();
    }

    else {
      Serial.println(F("Invalid input... please type one of the following : {\"f\": forward, \"b\": backward, \"r\": clockwise rotation, \"l\": counterclockwise rotation}"));
      BT.println(F("Invalid input... please type one of the following : {\"f\": forward, \"b\": backward, \"r\": clockwise rotation, \"l\": counterclockwise rotation}"));
    }

  }
}


