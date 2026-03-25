void setup() {
  // pins D0 - D13 can be used as input (read voltage) or output (send voltage)
  pinMode(13, OUTPUT);


  // pinmode(2, INPUT);



  /* 
  so the way it works is that connect arduino pins --> motor drivers --> motor --> wheel
  
  motor driver (L298N):
  connect the 3 blue part to battery
  then 1 motor driver can run 2 motors (out1...4)
  in1...in4 is what u need to connect to arduino digital pins to control which direction motors spin

  ena / enb ... this is going to be control the speed of the turning

  */ 
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);

  // int val = digitalRead(2);
}
