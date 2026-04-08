// global vars...
bool testing = true;


// initialisation code...
void setup() {
  Serial.begin(9600);

  // "clear" serial...
  for (int i = 0; i < 30; i++) {
    Serial.println();
  }

  Serial.println(F("Accepting new keyboard command... {\"f\": forward, \"b\": backward, \"r\": clockwise rotation, \"l\": counterclockwise rotation}"));
}


// TO DO: pin config for each direction...
void forward(){return;}
void backward(){return;}
void clkwise_rot(){return;}
void ctrclkwise_rot(){return;}


// continuously reads in user input and executes respective direction of wheels...
void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    // throw away "trivial" chars...
    if (cmd == '\n' || cmd == '\r') {
      return;
    }

    Serial.print(F("Received: "));
    Serial.println(cmd);

    if (cmd == 'f'){
       if (!testing) forward();
      else Serial.println(F("Moving forward..."));
    }

    else if (cmd == 'b'){
      if (!testing) backward();
      else Serial.println(F("Moving backward..."));

    }

    else if (cmd == 'r'){
      if (!testing) clkwise_rot();
      else Serial.println(F("Spinning clockwise..."));
    }

    else if (cmd == 'l'){
      if (!testing) ctrclkwise_rot();
      else Serial.println(F("Spinning counterclockwise..."));
    }


    else Serial.println(F("Invalid input... please type one of the following : {\"f\": forward, \"b\": backward, \"r\": clockwise rotation, \"l\": counterclockwise rotation}"));
  }
}
