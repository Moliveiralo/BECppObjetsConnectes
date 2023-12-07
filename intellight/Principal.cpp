/**
 * @project Intellight
 * @file Principal.cpp
 * @brief fichier source de la classe principale avec les fonstions set up et loop
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 05/12/2023
 */

#include "Principal.h"

    // // Definition des parametres de preference des personnes
    // habitant.setRGB(255,0,255);

    // // Initialisation des capteurs Arduino
    // leds.init(); // Initialisation des leds


Principal::Principal():nbLeds(2), leds(13,15,nbLeds){}

void Principal::setUp(){
    // Création des numpads
    numpad1(&mySerial);
    numpad2(&mySerial2);

    // Fixage du baud rate des UART émulés
    numpad1.getSerial()->begin(9600);
    numpad2.getSerial()->begin(9600);

    // Fixage du baud rate de l'UART réel de l'ESP8266
    Serial.begin(9600);

    // Initialisation des LEDs RGB chainables
    leds.init();

    // Par défaut, on éteint toutes les lumières.
    leds.setColorRGB(0, 0, 0, 0);
    leds.setColorRGB(0, 0, 0, 0);

    // Creation des pieces dans l'appartement
    appt.ajouterPiece("Salon");
    appt.ajouterPiece("Chambre");
}

void Principal::loop(){
  while (numpad1.getSerial()->available()){
    switch(numpad1.getData()) {
                case 0xE1 : // TOUCHE 1
                    leds.setColorRGB(1, 0, 255, 255);
                    break;
                case 0xE2 : // TOUCHE 2
                    leds.setColorRGB(1, 255, 0, 255);
                    break;
                case 0xE3 : // TOUCHE 3
                    leds.setColorRGB(1, 255, 255, 0);
                    break;
                case 0xE4 : // TOUCHE 4
                    leds.setColorRGB(1, 255, 0, 0);
                    break;
                case 0xE5 : // TOUCHE 5
                    leds.setColorRGB(1, 0, 0, 255);
                    break;
                case 0xE6 : // TOUCHE 6
                    leds.setColorRGB(1, 0, 255, 0);
                    break;
                case 0xE7 : // TOUCHE 7
                    leds.setColorRGB(1, 128, 128, 255);
                    break;
                case 0xE8 : // TOUCHE 8
                    leds.setColorRGB(1, 255, 255, 128);
                    break;
                case 0xE9 : // TOUCHE 9
                    leds.setColorRGB(1, 128, 255, 255);
                    break;
                case 0xEA : // TOUCHE *
                    leds.setColorRGB(1, 255, 128, 255);
                    break;
                case 0xEB : // TOUCHE 0
                    leds.setColorRGB(1, 128, 0, 255);
                    break;
                case 0xEC : // TOUCHE #
                    leds.setColorRGB(1, 255, 128, 0);
                    break;
                default:
                    break;
    }
  }

  while (numpad2.getSerial()->available()){
    switch(numpad2.getData()) {
                case 0xE1 : // TOUCHE 1
                    leds.setColorRGB(0, 0, 255, 255);
                    break;
                case 0xE2 : // TOUCHE 2
                    leds.setColorRGB(0, 255, 0, 255);
                    break;
                case 0xE3 : // TOUCHE 3
                    leds.setColorRGB(0, 255, 255, 0);
                    break;
                case 0xE4 : // TOUCHE 4
                    leds.setColorRGB(0, 255, 0, 0);
                    break;
                case 0xE5 : // TOUCHE 5
                    leds.setColorRGB(0, 0, 0, 255);
                    break;
                case 0xE6 : // TOUCHE 6
                    leds.setColorRGB(0, 0, 255, 0);
                    break;
                case 0xE7 : // TOUCHE 7
                    leds.setColorRGB(0, 128, 128, 255);
                    break;
                case 0xE8 : // TOUCHE 8
                    leds.setColorRGB(0, 255, 255, 128);
                    break;
                case 0xE9 : // TOUCHE 9
                    leds.setColorRGB(0, 128, 255, 255);
                    break;
                case 0xEA : // TOUCHE *
                    leds.setColorRGB(0, 255, 128, 255);
                    break;
                case 0xEB : // TOUCHE 0
                    leds.setColorRGB(0, 128, 0, 255);
                    break;
                case 0xEC : // TOUCHE #
                    leds.setColorRGB(0, 255, 128, 0);
                    break;
                default:
                    break;
    }
  }
}

