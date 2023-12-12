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

uint8_t Numpad::getData() {
  updateData();
  return data;
}

char Numpad::getTouche(){
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

void Numpad::updateData() {
  data = mySerial->read();
}

void Numpad::addDigitToCode(char digit){
    switch (digit) {
        case '1':
            code[nbDigits] = 1;
            nbDigits++;
            break;
        case '2':
            code[nbDigits] = 2;
            nbDigits++;
            break;
        case '3':
            code[nbDigits] = 3;
            nbDigits++;
            break;
        case '4':
            code[nbDigits] = 4;
            nbDigits++;
            break;
        case '5':
            code[nbDigits] = 5;
            nbDigits++;
            break;
        case '6':
            code[nbDigits] = 6;
            nbDigits++;
            break;
        case '7':
            code[nbDigits] = 7;
            nbDigits++;
            break;
        case '8':
            code[nbDigits] = 8;
            nbDigits++;
            break;
        case '9':
            code[nbDigits] = 9;
            nbDigits++;
            break;
        case '0':
            code[nbDigits] = 0;
            nbDigits++;
            break;
        default:
            break;
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

Numpad::~Numpad(){
    delete [] mySerial; // Suppression de l'UART émulé
    delete [] code; // Suppression du tableau contenant les digits du code

}