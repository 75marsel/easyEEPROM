/**
  easyEEPROM.cpp - Arduino library for char array handling on EEPROM

  Copyright (c) 2024 Jeric Marcel Gappi

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 3
  of the License, or (at your option) any later version.

  EASY EEPROM LIBARY 
  GITHUB: https://github.com/75marsel/easyEEPROM

  @author Gappi, Jeric Marcel L.
  @version 3 abstraction

*/

#include <EasyEEPROM.h>

#define CHAR_ARRAY_SIZE 14

char adminNumber[CHAR_ARRAY_SIZE] = "+639059918742";

char number1[CHAR_ARRAY_SIZE] = "+639059918999";
char number2[CHAR_ARRAY_SIZE] = "+639059918777";
char number3[CHAR_ARRAY_SIZE] = "+639059918888";
char number4[CHAR_ARRAY_SIZE] = "+639059918111";

char empty_adminNum[CHAR_ARRAY_SIZE + 1]; // + 1 for null terminator

char empty_num1[CHAR_ARRAY_SIZE + 1];
char empty_num2[CHAR_ARRAY_SIZE + 1];
char empty_num3[CHAR_ARRAY_SIZE + 1];
char empty_num4[CHAR_ARRAY_SIZE + 1];


EasyEEPROM eeprom; // create an instance of EasyEEPROM as eeprom


void setup() {
  Serial.begin(9600);
 
  // add admin number
  eeprom.addAdmin(adminNumber);

  // check admin number
  bool isAdminExist = eeprom.checkAdmin();

  // print admin number note: 0 means index of admin at eeprom
  // this saves the value of the index 0 stored in eeprom to the empty_adminNum
  eeprom.readPhoneNumber(empty_adminNum, 0); 
  Serial.print("Admin Number: ");
  Serial.println(empty_adminNum);
  
  // add other phone numbers
  eeprom.addPhoneNumber(number1, 1);
  eeprom.addPhoneNumber(number2, 2);
  eeprom.addPhoneNumber(number3, 3);
  eeprom.addPhoneNumber(number4, 4);

  // print all other numbers (see below)
  printNumbers();

  // delete a number 
  Serial.print("Is Delete Success?: ");
  Serial.println(eeprom.deletePhoneNumber(1));
  Serial.print("Is Delete Success?: ");
  Serial.println(eeprom.deletePhoneNumber(3));
  printNumbers();

  // check if a number exist in specific index (good to use with for loop)
  // admin -> 0
  // number 1 -> 1
  // number 2 -> 2
  // number 3 -> 3
  // number 4 -> 4
  // number 5 -> 5

  bool isNumExist = eeprom.checkIfExist(number1, 1);
  if(isNumExist) {
    Serial.println("Number1 exists!");
  }
  else {
    Serial.println("Number1 Does Not Exist!");
  }

  // check if a number exist using for loop ( good if registering )
  bool isRegistered = false;
  for(int i = 0; i < 5; i++) {
    if(eeprom.checkIfExist(number1, i)) {
      isRegistered = true;
      break;
    }
  }
  Serial.print("NUMBER1 LOOP CHECK: ");
  Serial.println(isRegistered); // 0 false, 1 true

  // clears all data in eeprom 
  //eeprom.clearAll();

  // clears all except admin
  //eeprom.clearExceptAdmin();

  // get the length
  //int length = eeprom.getLength();

}

void loop() {
  // put your main code here, to run repeatedly:

}


void printNumbers() {
  // print all other numbers

  // variable to store and the index of that number
  eeprom.readPhoneNumber(empty_num1, 1);
  Serial.print("Number1: ");
  Serial.println(empty_num1);

  eeprom.readPhoneNumber(empty_num2, 2);
  Serial.print("Number2: ");
  Serial.println(empty_num2);

  eeprom.readPhoneNumber(empty_num3, 3);
  Serial.print("Number3: ");
  Serial.println(empty_num3);

  eeprom.readPhoneNumber(empty_num4, 4);
  Serial.print("Number4: ");
  Serial.println(empty_num4);
  Serial.println();
}