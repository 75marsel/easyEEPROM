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
  @version 2.29022024 hotfix

*/

#include <EasyEEPROM.h>

#define CHAR_ARRAY_SIZE 13


char number1[CHAR_ARRAY_SIZE] = "+639059918742";
char number2[CHAR_ARRAY_SIZE] = "+639059918999";
char number3[CHAR_ARRAY_SIZE] = "+639059918777";
char number4[CHAR_ARRAY_SIZE] = "+639059918888";
char number5[CHAR_ARRAY_SIZE] = "+639059918111";

char empty_num1[CHAR_ARRAY_SIZE + 1]; // + 1 for null terminator
char empty_num2[CHAR_ARRAY_SIZE + 1];
char empty_num3[CHAR_ARRAY_SIZE + 1];
char empty_num4[CHAR_ARRAY_SIZE + 1];
char empty_num5[CHAR_ARRAY_SIZE + 1];


EasyEEPROM eeprom; // create an instance of EasyEEPROM as eeprom


void setup() {
  Serial.begin(9600);
  // sample use case

  // store number1, number2, number3 to eeprom
  // PARAMETERS: array, starting index in eeprom, length of the array (end index in eeprom)
  eeprom.update_char(number1, 0, CHAR_ARRAY_SIZE - 1);

  // FORMULA: CHAR_ARRAY_SIZE*n  where n is the nth place (pang-ilan si number)
  // we do CHAR_ARRAY_SIZE*n as we add the length of array (current index) plus the length of the array (actual data to store)
  // where n is the rank (nth place) of the char array
  eeprom.update_char(number2, CHAR_ARRAY_SIZE , CHAR_ARRAY_SIZE*2 - 1);

  // same procedure at number2
  eeprom.update_char(number3, CHAR_ARRAY_SIZE*2, CHAR_ARRAY_SIZE*3 - 1);

  // same procedure at number2
  eeprom.update_char(number4, CHAR_ARRAY_SIZE*3, CHAR_ARRAY_SIZE*4 - 1);

  // same procedure at number2
  eeprom.update_char(number5, CHAR_ARRAY_SIZE*4, CHAR_ARRAY_SIZE*5 - 1);

  // READ EEPROM EXAMPLE

  // pass the sample char array and updates the new_sample with that value that is being read at the eeprom
  // paramters: char array for storing the eeprom values, starting index in eeprom, desired end index at eeprom
  eeprom.read_char(empty_num1, 0, CHAR_ARRAY_SIZE - 1); // minus one before the '+' of another number
  eeprom.read_char(empty_num2, CHAR_ARRAY_SIZE, CHAR_ARRAY_SIZE*2 - 1);
  eeprom.read_char(empty_num3, CHAR_ARRAY_SIZE*2, CHAR_ARRAY_SIZE*3 - 1);
  eeprom.read_char(empty_num4, CHAR_ARRAY_SIZE*3, CHAR_ARRAY_SIZE*4 - 1);
  eeprom.read_char(empty_num5, CHAR_ARRAY_SIZE*4, CHAR_ARRAY_SIZE*5 - 1);
  Serial.println();
  Serial.print("NUM 1: ");
  Serial.println(empty_num1);
  Serial.print("NUM 2: ");
  Serial.println(empty_num2);
  Serial.print("NUM 3: ");
  Serial.println(empty_num3);
  Serial.print("NUM 4: ");
  Serial.println(empty_num4);
  Serial.print("NUM 5: ");
  Serial.println(empty_num5);

  bool isSame = eeprom.isSame_char(empty_num5, CHAR_ARRAY_SIZE*4, CHAR_ARRAY_SIZE*5 - 1);
  Serial.print("Is same?: ");
  Serial.println(isSame);
}

void loop() {
  // put your main code here, to run repeatedly:

}


/**
 * HOW EEPROM WORKS
 * 
 * 
 * INDEX: [0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16].................->[1023]
 * VALUE:  +  6  3  9  0  6  2  6  1  8  7   6   5  '\0'  +  6   3
 * 
 * as you can see this is like an array.
 * 
 * to read
 * 
 * eeprom.read_char(CHAR_ARRAY, START_INDEX, END_INDEX);
 * 
 * whereas char_array is the array where will store the value that is being read at the eeprom.
 * whereas start_index is where at the eeprom we will start reading
 * whereas end_index is at what part of eeprom we should stop reading and recommended to be always stop at a null terminator ('\0')
*/