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

    up = true;
    hue = 0.0;
}


void Principal::loop(){
    // On vérifie pour chaque pièce de l'appartement
    for(int i=0; i<appt.getNbPiece(); i++){

        // Tant que le numpad est disponible
        while(appt[i].getNumpad()->getSerial()->available()){

            // On récupère la touche qui est appuyée sur le numpad
            char touche = appt[i].getNumpad()->getTouche();

            switch(touche){
                case '*': // Si la touche appuyée est étoile, alors on incrémente le nombre de fois ou étoiles a été tapé
                    appt[i].getNumpad()->incrNbEtoiles();

                    // Si la personne a fait 4 fois étoile, on lance l'easter egg. Celui-ci s'arrête quand la personne réappuie sur étoile.
                    while (appt[i].getNumpad()->getNbEtoiles() == 4){
                        if (appt[i].getNumpad()->getTouche() == '*') {
                            appt[i].getNumpad()->incrNbEtoiles();
                        }
                        leds.setColorHSL(i, hue, 1.0, 0.5);
                        delay(50);

                        if (up) {
                            hue += 0.025;
                        } else {
                            hue -= 0.025;
                        }
                        if (hue>=1.0 && up) {
                            up = false;
                        } else if (hue<=0.0 && !up) {
                            up = true;
                        }
                    }
                    break;
                case '#':
                    break;
                default:
                    if (appt[i].getNumpad()->getNbDigits() != 4){
                        appt[i].getNumpad()->addDigitToCode((short) touche);
                    }
                    break;
            }
        }
    }
}

