#include <EasyEEPROM.h>
#define CHAR_ARRAY_SIZE 5

EasyEEPROM eeprom; // create an instance of EasyEEPROM as eeprom

char sample[CHAR_ARRAY_SIZE] = "hello";
char new_sample[CHAR_ARRAY_SIZE];


void setup() {
  Serial.begin(9600);

  // updates the eeprom 
  eeprom.update_char(sample, CHAR_ARRAY_SIZE);

  // reads and store the EEPROM (that is based on the given length) to the new_sample char array
  eeprom.readchar(new_sample, CHAR_ARRAY_SIZE);

  // prints the new_sample
  Serial.println(new_sample);

  //checks if the given char array is same that is stored in the eeprom (starts at index 0)
  bool isSame = eeprom.isSame_char(new_sample, CHAR_ARRAY_SIZE);

  // clears the eeprom
  eeprom.clear();

  // returns the length of the eeprom
  int length = eeprom.getLength();
  Serial.println(length);
}

void loop() {
  // put your main code here, to run repeatedly:

}
