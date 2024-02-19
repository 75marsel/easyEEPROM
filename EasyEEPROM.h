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
  @version 1.19022024

*/


#ifndef EasyEPPROM_h
#define EasyEEPROM_h

#include "Arduino.h"

class EasyEEPROM
{
  public:
    void update_char(char* data, int length);
    void read_char(char* data, int length);
    bool isSame_char(char* data, int length);
    void clear();
    int getLength();
  private:
    int _ADDRESS_OFFSET = 0x00;
};

#endif