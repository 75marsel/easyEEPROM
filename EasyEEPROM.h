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
  @version 3 abstraction
  GITHUB: https://github.com/75marsel/easyEEPROM
*/


#ifndef EasyEPPROM_h
#define EasyEEPROM_h

#include "Arduino.h"

class EasyEEPROM
{
  public:
    void addAdmin(char* data);
    bool checkAdmin();
    void addPhoneNumber(char* data, int position);
    void readPhoneNumber(char* data, int position);
    bool deletePhoneNumber(int position);
    bool checkIfExist(char* data, int position);
    void clearAll();
    void clearExceptAdmin();
    void showAllNumbers();
    int getLength();
  private:
    int _ADDRESS_OFFSET = 0x00;
};

#endif