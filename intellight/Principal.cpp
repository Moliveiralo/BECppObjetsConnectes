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
    for(int i=1; i<=appt.getNbPiece(); i++){

        // Tant que l'UART associé au numpad est disponible
        while(appt[i].getNumpad()->getSerial()->available()){

            // On récupère la touche qui est appuyée sur le numpad
            char touche = appt[i].getNumpad()->getTouche();

            switch(touche){
                case '*': // Si la touche appuyée est étoile, alors on incrémente le nombre de fois ou étoiles a été tapé
                    appt[i].getNumpad()->incrNbEtoiles();
                    break;
                case '#':
                    if (appt[i].getNumpad()->getNbDigits() == 4){
                        // ON REGARDE SI LE CODE CORRESPOND A QUELQUUN

                        // SI CA CORRESPOND ON FAIT RENTRER LA PERSONNE CORRESPONDANT

                        // SINON ON RESET LE CODE
                    } else { // Si la personne a appuyé sur # mais qu'il y a moins de 4 digits, alors le code tapé est réinitialisé et l'utilisateur peut recommencer à taper son code.
                        appt[i].getNumpad()->resetCode();
                    }
                    break;
                default: // Si l'utilisateur a appuyé sur un chiffre
                    if (appt[i].getNumpad()->getNbDigits() < 4){ // Tant que le code n'est pas complet, on rajoute le digit au code.
                        appt[i].getNumpad()->addDigitToCode((short) touche);
                    }
                    break;
            }
        }




        // Gestion de l'easter egg: si l'utilisateur a tapé 4 fois sur étoiles, on active le mode disco !
        if (appt[i].getNumpad()->getNbEtoiles() == 4){
            leds.setColorHSL(1-(i-1), hue, 1.0, 0.5);
            delay(50);

            if (up) {
                hue += 0.025;
            } else {
                hue -= 0.025;
            }
            if (hue >= 1.0 && up) {
                up = false;
            } else if (hue <= 0.0 && !up) {
                up = true;
            }
        }

        // Si la personne appuie de nouveau sur étoile, l'easter egg est arrêté et le nombre d'étoiles est remis à zéro.
        if (appt[i].getNumpad()->getNbEtoiles()>4){
            appt[i].getNumpad()->resetNbEtoiles();
            leds.setColorRGB(1-(i-1), 0, 0, 0);
        }
    }
//    for(int i=1; i<=appt.getNbPiece(); i++){
//      Serial.println(appt[i].getNom());
//      delay(500);
//    }
}

