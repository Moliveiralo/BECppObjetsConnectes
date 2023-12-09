//
// Created by maxim on 06/12/2023.
//

#include "Numpad.h"

Numpad::Numpad() {
    data = 0;
    mySerial = nullptr;
    code = new short[4];
    nbDigits = 0;
    nbEtoiles = 0;
}

Numpad::Numpad(SoftwareSerial * s){
    mySerial = s;
    data = 0;
    code = new short[4];
    nbDigits = 0;
    nbEtoiles = 0;
}

uint8_t Numpad::getData() const {
  updateData();
  return data;
}

char Numpad::getTouche() const{
  while (mySerial->available()){
    switch(getData()) {
                case 0xE1 : // TOUCHE 1
                    return '1';
                case 0xE2 : // TOUCHE 2
                    return '2';
                case 0xE3 : // TOUCHE 3
                    return '3';
                case 0xE4 : // TOUCHE 4
                    return '4';
                case 0xE5 : // TOUCHE 5
                    return '5';
                case 0xE6 : // TOUCHE 6
                    return '6';
                case 0xE7 : // TOUCHE 7
                    return '7';
                case 0xE8 : // TOUCHE 8
                    return '8';
                case 0xE9 : // TOUCHE 9
                    return '9';
                case 0xEA : // TOUCHE *
                    return '*';
                case 0xEB : // TOUCHE 0
                    return '0';
                case 0xEC : // TOUCHE #
                    return '#';
                default:
                    return '-';
            }
  }
  return '-';
}

short Numpad::getCode() const{
    if (nbDigits == 4){
        return (code[0]*1000 + code[1]*100 + code[2]*10 + code[3]);
    } else {
        return -1;
    }
}

short Numpad::getNbDigits() const {
    return nbDigits;
}
short Numpad::getNbEtoiles() const {
    return nbEtoiles;
}

SoftwareSerial * Numpad::getSerial(){
  return mySerial;
}

void Numpad::updateData() const {
  data = mySerial->read();
}

void Numpad::addDigitToCode(short digit){
    if (nbDigits != 4){
        code[nbDigits] = digit;
        nbDigits++;
    }
}

void Numpad::resetNbEtoiles(){
    nbEtoiles=0;
}

void Numpad::incrNbEtoiles(){
    nbEtoiles++;
}

void Numpad::resetCode(){
    nbDigits = 0;
    delete code;
    code = new short[4];
}