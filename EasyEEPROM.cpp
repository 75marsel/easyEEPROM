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
  @version 3 abstraction
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
void EasyEEPROM::addAdmin(char* data)
{
  for(int i = 0; i <= 12; i++) {
    byte p = (byte) data[i];
    //Serial.print("Current Letter: ");
    //Serial.println(data[i]);
    EEPROM.update(_ADDRESS_OFFSET + i, p);
  }
  EEPROM.update(_ADDRESS_OFFSET + 12 + 1, '\0');
}

/*
bool EasyEEPROM::removeAdmin(char* data)
{
  
  char first_char = (char) EEPROM.read(0);
  if(first_char != "+")
    return false;

  for(int i = 0; i <= 13; i++) {
    EEPROM.update(_ADDRESS_OFFSET + i, 0);
  }

  return true;
  
  for(int i = 0; i < EEPROM.length(); i++) {
    EEPROM.update(i, 0);
  }
  Serial.println("EEPROM CLEARED!");
}*/

bool EasyEEPROM::checkAdmin()
{
  char first_char = (char) EEPROM.read(0);
  if(first_char != '+')
    return false;

  for(int i = 0; i <= 12; i++) {
    char c = (char) EEPROM.read(i);
    if (!isDigit(c)) {
      return false;
    }
  }

  return true;
}

// 14 start + 12 + 1 null
void EasyEEPROM::addPhoneNumber(char* data, int position) {
  int start = 14;
  int end = 27;

  switch(position) {
    case 0:
      start = 0;
      end = 13; // 26 default then later + 1 for null
    break;
    case 1:
      start = 14;
      end = 27; // 26 default then later + 1 for null
    break;
    case 2:
      start = 28;
      end = 41;
    break;
    case 3:
      start = 42;
      end = 55;
    break;
    case 4:
      start = 56;
      end = 69;
    break;
    default:
      return;
  } 

  for(int i = 0, ei = start; ei < end; i++, ei++) {
    byte p = (byte) data[i];
    EEPROM.update(_ADDRESS_OFFSET + ei, p);
  }
  EEPROM.update(_ADDRESS_OFFSET + end, '\0');
}

// 14 start + 12 + 1 null
bool EasyEEPROM::deletePhoneNumber(int position) {
  int start = 14;
  int end = 27;

  switch(position) {
    case 1:
      start = 14;
      end = 27; // 26 default then later + 1 for null
      break;
    case 2:
      start = 28;
      end = 41;
      break;
    case 3:
      start = 42;
      end = 55;
      break;
    case 4:
      start = 56;
      end = 69;
      break;
    default:
      return false;
  } 

  char first_char = (char) EEPROM.read(start);
  
  if(first_char != '+')
    return false;

  for(int i = start; i <= end; i++) {
    EEPROM.update(_ADDRESS_OFFSET + i, 0);
  }

  return true;
}

void EasyEEPROM::readPhoneNumber(char* data, int position) {
  int start = 14;

  switch(position) {
    case 0:
      start = 0;
      break;
    case 1:
      start = 14;
      break;
    case 2:
      start = 28;
      break;
    case 3:
      start = 42;
      break;
    case 4:
      start = 56;
      break;
    default:
      return;
  }

  int length = 14;

  for (int i = 0, ei = start; i < 13; i++, ei++) {
    data[i] = (char) EEPROM.read(_ADDRESS_OFFSET + ei);
    //Serial.print("current char: ");
    //Serial.println( (char) EEPROM.read(_ADDRESS_OFFSET + ei));
  }

  data[length] = '\0';  // Ensure null terminator at the end of the data array

}

/**
  Checks if the given char array is same with the char array stored in the EEPROM
  that is the same length of the char array given to the function.

  @param data the char array that will be stored to the EEPROM.
  @return true if the result of checking is same.
  @return false if the result of checking is otherwise different.
*/
bool EasyEEPROM::checkIfExist(char* data, int position) {
  int start = 0;

  switch(position) {
    case 0:
      start = 0;
      break;
    case 1:
      start = 14;
      break;
    case 2:
      start = 28;
      break;
    case 3:
      start = 42;
      break;
    case 4:
      start = 56;
      break;
    default:
      return false;
  }

  int length = 14;
  char temp[length + 1];  // Increase the size of temp array by 1

  for(int i = 0, ei = start; i < length; i++, ei++) {
    temp[i] = (char) EEPROM.read(ei);
  }

  temp[length] = '\0';
  if(strcmp(temp, data) == 0) {
    return true;
  }

  return false;
}


// Clears the EEPROM with 0 value
void EasyEEPROM::clearAll() {
  for(int i = 0; i < EEPROM.length(); i++) {
    EEPROM.update(i, 0);
  }
  Serial.println("EEPROM CLEARED!");
}

// Clears the EEPROM with 0 value
void EasyEEPROM::clearExceptAdmin() {
  for(int i = 14; i < EEPROM.length(); i++) {
    EEPROM.update(i, 0);
  }
  Serial.println("EEPROM CLEARED! EXCEPT ADMIN!");
}

/**
 Returns the length of the EEPROM (value in bytes)
 @return (int) the length of eeprom.
*/
int EasyEEPROM::getLength() {
  return EEPROM.length();
}

// Helper function to print EEPROM content
void EasyEEPROM::showAllNumbers() {
  for(int i = 0; i <= 69; i++) {
    char c = (char) EEPROM.read(i);
    if(c == '\0'){
      Serial.println();
    }
    else {
      Serial.print(c);
    }
  }
  Serial.println();
}