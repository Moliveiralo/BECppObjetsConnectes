/**
 * @project Intellight
 * @file Principal.cpp
 * @brief fichier source de la classe principale avec les fonstions set up et loop
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 05/12/2023
 */

#include "Principal.h"


Principal::Principal():nbLeds(2), leds(DATA_PIN,CLOCK_PIN,nbLeds){}

void Principal::setup(){
    // Création des UART émulés pour les numpads
    mySerial = new SoftwareSerial(RX1,TX1);
    mySerial2= new SoftwareSerial(RX2, TX2);

    // Création des numpads
    numpad1 = new Numpad(mySerial);
    numpad2 = new Numpad(mySerial2);

    // Fixage du baud rate des UART émulés
    numpad1->getSerial()->begin(9600);
    numpad2->getSerial()->begin(9600);

    // Fixage du baud rate de l'UART réel de l'ESP8266
    Serial.begin(9600);

    // Initialisation des LEDs RGB chainables
    leds.init();

    // Par défaut, on éteint toutes les lumières.
    leds.setColorRGB(0, 0, 0, 0);
    leds.setColorRGB(1, 0, 0, 0);

    // Creation des pieces dans l'appartement avec leur numpad associé
    appt.ajouterPiece("Salon", numpad1);
    appt.ajouterPiece("Chambre", numpad2);
}

void Principal::loop(){
    while (numpad1->getSerial()->available()){
        switch(numpad1->getTouche()){

        }
    }

    while (numpad2->getSerial()->available()){
        switch(numpad2->getTouche()){

        }
    }
}

