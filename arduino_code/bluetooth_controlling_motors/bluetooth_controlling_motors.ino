#include <SoftwareSerial.h>
// probably going to use these pins...
//  arduino tx, rx resp needs to connect to bluetooth rx, tx resp 
//  hence, blue to 5 to HM10 TX, white to 6 to HM10 RX 
SoftwareSerial BT(5,6); 

// global vars...
bool testing = true;

void setup() {
  // initialising arduino pins...
  // ENA... (orange1)
  pinMode(13, OUTPUT);
  // ENB... (orange2)
  pinMode(12, OUTPUT);

  // K1 / K2...
  // IN2... (brown)
  pinMode(8, OUTPUT);
  // IN1... (red)
  pinMode(9, OUTPUT);
  
  // K3 / K4...
  // IN3... (blue)
  pinMode(2, OUTPUT);
  // IN4... (green)
  pinMode(3, OUTPUT);


  // initialising bluetooth... 
  //   effectively just another serial port...
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
  // not ENA ==> stop...
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  delay(500);

  return;
}

void forward(){
  // (ENA 1 and IN1 and not IN2) ==> K1, K2 rotate forward...
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  
  // wheel1...
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);

  // wheel2...
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);

  return;
}

void backward(){
  // (ENA 1 and not IN1 and IN2) ==> K1, K2 rotate backward...
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);


  // wheel1...
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  // wheel2...
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

  return;
}

// TO DO: get K3, K4 on here... pin config for each direction...
void clkwise_rot(){
  // ENA, ENB HIGH
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);

  // wheel1... backward
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  // wheel2... forward
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);

  return;
}
void ctrclkwise_rot(){
  // ENA, ENB HIGH
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);

  // wheel1... forward
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  
  // wheel2... backward
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

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


