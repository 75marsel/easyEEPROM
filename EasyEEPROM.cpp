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
  @version 2.29022024
  GITHUB: https://github.com/75marsel/easyEEPROM
*/


#include "Arduino.h"
#include <EEPROM.h>
#include "EasyEEPROM.h"

/**
  Updates the EEPROM with the given char array.

  @param data the char array that will be stored to the EEPROM.
  @param start_index the index position where we will fetch the starting character
  @param end_index the index position where we will fetch the last character
  @return None
*/
void EasyEEPROM::update_char(char* data, int start_index, int end_index)
{
  for(int i = 0, ei = start_index; ei < end_index; i++, ei++) {
    byte p = (byte) data[i];
    EEPROM.update(_ADDRESS_OFFSET + ei, p);
  }
  EEPROM.update(_ADDRESS_OFFSET + end_index, '\0');
}

/**
  Stores the EEPROM data with the given char array and length.

  @param data the char array that will be stored to the EEPROM.
  @param start_index the index position where we will fetch the starting character
  @param end_index the index position where we will fetch the last character
  @return None
*/
void EasyEEPROM::read_char(char* data, int start_index, int end_index) {
  for(int i = 0, ei = start_index; ei < end_index; i++, ei++) {
    char p = (char) EEPROM.read(ei);

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
bool EasyEEPROM::isSame_char(char* data, int start_index, int end_index) {
  int length = strlen(data);
  char temp[length];

  for(int i = 0, ei = start_index; ei < end_index; i++, ei++)
    temp[i] = (char) EEPROM.read(ei);
  
  temp[length] = '\0';

  if(strcmp(temp, data) == 0)
    return true;
  
  return false;
}

// Clears the EEPROM with 0 value
void EasyEEPROM::clear() {
  for(int i = 0; i < EEPROM.length(); i++) {
    EEPROM.update(i, 0);
  }
}

/**
 Returns the length of the EEPROM (value in bytes)
 @return (int) the length of eeprom.
*/
int EasyEEPROM::getLength() {
  return EEPROM.length();
}