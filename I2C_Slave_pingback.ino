#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;

void setup() {
  Serial.begin(9600);
  //I2C - slave
  Wire.begin(SLAVE_ADDRESS);

  //Callbacks
  Wire.onReceive(receive_);
  Wire.onRequest(send_);

  Serial.println("Ready! on");
  Serial.println(SLAVE_ADDRESS);
}

void loop() {
  delay(50);
}

void receive_(int byteCount){
  while(Wire.available()) {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);
  }
}

void send_(){
  Wire.write(number);
}
