/**
  easyEEPROM.cpp - Arduino library for char array handling on EEPROM

  Copyright (c) 2024 Jeric Marcel Gappi

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 3
  of the License, or (at your option) any later version.
  
  EASY EEPROM LIBARY 
  Name: easyEEPROM.cpp
  Type: Source file

  @author Gappi, Jeric Marcel L.
  @version 1.19022024

*/


#include "Arduino.h"
#include <EEPROM.h>
#include "EasyEEPROM.h"

/**
  Updates the EEPROM with the given char array.

  @param data the char array that will be stored to the EEPROM.
  @return None
*/
void EasyEEPROM::updateEEPROM_char(char* data)
{
  int l = strlen(data);
  for(int i = 0; i < l; i++) {
    byte p = (byte) data[i];
    EEPROM.update(_ADDRESS_OFFSET + i, p);
  }
  EEPROM.update(_ADDRESS_OFFSET + l + 1, '\0');
}

/**
  Stores the EEPROM data with the given char array and length.

  @param data the char array that will be stored to the EEPROM.
  @param length the length of the char array to be stored.
  @return None
*/
void EasyEEPROM::readEEPROM_char(char* data, int length) {
  for(int i = 0; i < length; i++) {
    char p = (char) EEPROM.read(i);

    if(p == '\0')
      break;
    
    data[i] = p;
  }
}

/**
  Checks if the given char array is same with the char array stored in the EEPROM
  that is the same length of the char array given to the function.

  @param data the char array that will be stored to the EEPROM.
  @return true if the result of checking is same.
  @return false if the result of checking is otherwise different.
*/
bool EasyEEPROM::isSameEEPROM_char(char* data, int length) {
  char temp[length];

  for(int i = 0; i < length; i++)
    temp[i] = EEPROM.read(i);
  
  temp[length] = '\0';

  if(strcmp(temp, data) == 0)
    return true;
  
  return false;
}

// Clears the EEPROM with 0 value
void EasyEEPROM::clearEEPROM() {
  for(int i = 0; i < EEPROM.length(); i++) {
    EEPROM.update(i, 0);
  }
}

/**
 Returns the length of the EEPROM (value in bytes)
 @return (int) the length of eeprom.
*/
int EasyEEPROM::getLengthEEPROM() {
  return EEPROM.length();
}