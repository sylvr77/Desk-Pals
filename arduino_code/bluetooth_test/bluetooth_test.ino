#include <SoftwareSerial.h>

SoftwareSerial BT(5, 6); // RX, TX

// void setup() {
//   Serial.begin(9600);
//   BT.begin(9600);
//   Serial.println("Ready");
// }

// void loop() {
//   BT.listen();
//   if (BT.available()) {
//     char c = BT.read();
//     Serial.print("BT got: ");
//     Serial.println(c);
//   }

//   if (Serial.available()) {
//     char c = Serial.read();
//     BT.write(c);
//   }
// }

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nReady");
}

void loop() {
  if (BT.available()) {
    char c = BT.read();
    Serial.print("BT got: ");
    Serial.println(c);

    BT.print("Echo: ");
    BT.println(c);
  }
}