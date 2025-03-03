#include <EEPROM.h>

int GetInt(int add1, int add2) {
  return EEPROM.read(add1) * 256 + EEPROM.read(add2);
}

void SetInt(int add1, int add2, int num) {
  EEPROM.write(add1, num / 256);
  EEPROM.write(add2, num % 256);
}


void setup() {
  Serial.begin(9600);
  int value = GetInt(0, 1);
  //Serial.println("Value: " + value);
  Serial.println(value);
}

void loop() {
  if (Serial.available()) {
    int input = Serial.parseInt();
    SetInt(0, 1, input);
    
    int newValue = GetInt(0, 1);
    Serial.println(newValue);
    delay(100);
  }
}
