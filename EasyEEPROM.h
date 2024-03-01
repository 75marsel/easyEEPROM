/**
  EasyEEPROM.h - Header file for char array handling on EEPROM

  Copyright (c) 2024 Jeric Marcel Gappi

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 3
  of the License, or (at your option) any later version.

  EASY EEPROM LIBRARY HEADER FILE
  Name: EasyEEPROM.h
  Type: Header file

  @author Gappi, Jeric Marcel L.
  @version 2.29022024 hotfix
  GITHUB: https://github.com/75marsel/easyEEPROM
*/


#ifndef EasyEPPROM_h
#define EasyEEPROM_h

#include "Arduino.h"

class EasyEEPROM
{
  public:
    void update_char(char* data, int start_index, int end_index);
    void read_char(char* data, int start_index, int end_index);
    bool isSame_char(char* data, int start_index, int end_index);
    void copyCharArray(const char* source, char* destination, size_t arrayLength); 
    void clear();
    int getLength();
  private:
    int _ADDRESS_OFFSET = 0x00;
};

#endif