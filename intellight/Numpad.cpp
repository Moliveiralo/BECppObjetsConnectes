//
// Created by maxim on 06/12/2023.
//

#include "Numpad.h"

Numpad::Numpad() {
    data = 0; // Initialement, le numpad n'a pas encore renvoyé de valeur.
    mySerial = nullptr; // Aucun UART n'est associé au numpad
    code = new short[4]; // On crée le code en tant que tableau de digits
    nbDigits = 0; // Initialement, le code ne contient aucun digit
    nbEtoiles = 0; // Initialement, on n'a tapé aucune étoile au clavier
}

Numpad::Numpad(SoftwareSerial * s){
    mySerial = s; // On associe l'UART entrée en paramètre au numpad
    data = 0; // Initialement, le numpad n'a pas encore renvoyé de valeur.
    code = new short[4]; // On crée le code en tant que tableau de digits
    nbDigits = 0; // Initialement, le code ne contient aucun digit
    nbEtoiles = 0; // Initialement, on n'a tapé aucune étoile au clavier
}

uint8_t Numpad::getData() {
  updateData(); // On rafraichit l'attribut data contenant le code correspondant à la touche appuyée sur le numpad
  return data;
}

char Numpad::getTouche(){
  while (mySerial->available()){
    switch(getData()) { // En fonction de la touche appuyée sur le numpad
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
    if (nbDigits == 4){ // Si le code contient bien 4 digits, on retourne le code
        return (code[0]*1000 + code[1]*100 + code[2]*10 + code[3]);
    } else { // Sinon, on retourne -1
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
  data = mySerial->read(); // Lecture de data à partir de l'UART émulé
}

void Numpad::addDigitToCode(char digit){
    switch (digit) { // Pour chaque chiffre, on ajoute le chiffre au code et on incrémente le nombre de digits contenus dans le code
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
    nbDigits = 0; // Remise à zéro du nombre de digits
    delete [] code; // Suppression du code et libération de la mémoire
    code = new short[4]; // On recrée un code de zéro sur un nouvel espace mémoire
}

Numpad::~Numpad(){
    delete [] mySerial; // Suppression de l'UART émulé
    delete [] code; // Suppression du tableau contenant les digits du code

}