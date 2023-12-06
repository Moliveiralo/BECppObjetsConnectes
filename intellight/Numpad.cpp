//
// Created by maxim on 06/12/2023.
//

#include "Numpad.h"

Numpad::Numpad() {
  data = 0;
  mySerial = nullptr;
}

Numpad::Numpad(SoftwareSerial * s){
  mySerial = s;
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

short Numpad::getCode(){
  int nbDigits = 0;
  short * listeDigits = new short[4];

  // Tant que le code n'est pas complet
  while (nbDigits != 4){
    char touche = getTouche();
    switch (touche){
      // Si la touche tapée n'est pas un nombre, on ne fait rien et on attend une nouvelle entrée
      case '*' :
      case '#' :
      case '-' :
        break;

      // Dans tous les autres cas, la touche appuyée est un nombre. On l'ajoute donc à la liste.
      default:
        listeDigits[nbDigits] = (short) touche;
        nbDigits++;
        break;
    }
  }

  return (listeDigits[0]*1000 + listeDigits[1]*100 + listeDigits[2]*10 + listeDigits[3]);
}

SoftwareSerial * Numpad::getSerial(){
  return mySerial;
}

void Numpad::updateData() {
  data = mySerial->read();
}
