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

    habitant1 = new Personne("Inès", false, false, 1234);
    habitant1->setRGB(255,0,255);
    habitant2 = new Personne("Maxime", false, false, 1793);
    habitant2->setRGB(255,215,0);
    habitantPrio = new Personne("Stacy", true, false, 8520);
    habitantPrio->setRGB(0,255,0);
    invite = new Personne("Brittany", false, true, 4785);
    invite->setRGB(223, 115, 255);

    // Si nos listes de personnes fonctionnaient
//    appt.ajouterPersonne(*habitant1);
//    appt.ajouterPersonne(*habitant2);
//    appt.ajouterPersonne(*habitantPrio);
//    appt.ajouterPersonne(*invite);

    modeNumpad = new char[2];
    modeNumpad[0] = '.';
    modeNumpad[1] = '.';
}


void Principal::loop(){
    for(int j = 1; j<appt.getNbPiece(); j++){
        if (modeNumpad[j] == '.'){

        } else {
            switch (modeNumpad[j]) {

                case '1':{ // Séquence prédéfinie
                    // +habitant1
                    appt[1].personneEntre(habitant1, &leds);

                    delay(2000);

                    // +habitant2 (rien)
                    appt[1].personneEntre(habitant2, &leds);

                    delay(2000);

                    // -habitant1 (hab2 lum)
                    appt[1].personneSort(habitant1, &leds);

                    delay(2000);

                    // +habitant1 pièce 2
                    appt[2].personneEntre(habitant1, &leds);

                    delay(2000);

                    // +habitantPrio
                    appt[1].personneEntre(habitantPrio, &leds);

                    delay(2000);

                    // -habitantPrio
                    appt[1].personneSort(habitantPrio, &leds);

                    delay(2000);

                    // -habitant 2
                    appt[1].personneSort(habitant2, &leds);

                    delay(2000);

                    // +invite pièce 2
                    appt[2].personneEntre(invite, &leds);

                    delay(2000);

                    // -invite pièce 2
                    appt[2].personneSort(invite, &leds);

                    delay(2000);

                    // - habitant1 pièce 2
                    appt[2].personneSort(invite, &leds);

                    delay(5000);
                    break;
                }



                case '2':{ // Touche numpad --> couleur
                    for(int i=1; i<=appt.getNbPiece(); i++) {

                        // Tant que l'UART associé au numpad est disponible
                        while (appt[i].getNumpad()->getSerial()->available()) {

                            // On récupère la touche qui est appuyée sur le numpad
                            char touche = appt[i].getNumpad()->getTouche();

                            switch (touche) {
                                case '1' : // TOUCHE 1
                                    leds.setColorRGB(1-(i-1), 0, 255, 255);
                                    break;
                                case '2' : // TOUCHE 2
                                    leds.setColorRGB(1-(i-1), 255, 0, 255);
                                    break;
                                case '3' : // TOUCHE 3
                                    leds.setColorRGB(1-(i-1), 255, 255, 0);
                                    break;
                                case '4' : // TOUCHE 4
                                    leds.setColorRGB(1-(i-1), 255, 0, 0);
                                    break;
                                case '5' : // TOUCHE 5
                                    leds.setColorRGB(1-(i-1), 0, 0, 255);
                                    break;
                                case '6' : // TOUCHE 6
                                    leds.setColorRGB(1-(i-1), 0, 255, 0);
                                    break;
                                case '7' : // TOUCHE 7
                                    leds.setColorRGB(1-(i-1), 128, 128, 255);
                                    break;
                                case '8' : // TOUCHE 8
                                    leds.setColorRGB(1-(i-1), 255, 255, 128);
                                    break;
                                case '9' : // TOUCHE 9
                                    leds.setColorRGB(1-(i-1), 128, 255, 255);
                                    break;
                                case '*' : // TOUCHE *
                                    leds.setColorRGB(1-(i-1), 255, 128, 255);
                                    break;
                                case '0' : // TOUCHE 0
                                    leds.setColorRGB(1-(i-1), 128, 0, 255);
                                    break;
                                case '#' : // TOUCHE #
                                    leds.setColorRGB(1-(i-1), 255, 128, 0);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    break;
                }



                case '3': { // A la main (pas entièrement fonctionnel)
                    // On vérifie pour chaque pièce de l'appartement
                    {
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
                                            // On cherche une personne dont le code correspond à celui entré sur le numpad
                                            Personne * personneCorrespondante;

                                            // Nous avons eu des soucis avec les listes de personnes dans la classe appartement qui génère une exception
//                        Personne personneCorrespondante = appt.getPersonneFromCode(appt[i].getNumpad()->getCode());

                                            if (habitant1->verifierCode(appt[i].getNumpad()->getCode())){
                                                personneCorrespondante = habitant1;
                                            } else if (habitant2->verifierCode(appt[i].getNumpad()->getCode())){
                                                personneCorrespondante = habitant2;
                                            } else if (habitantPrio->verifierCode(appt[i].getNumpad()->getCode())){
                                                personneCorrespondante = habitantPrio;
                                            } else if (invite->verifierCode(appt[i].getNumpad()->getCode())){
                                                personneCorrespondante = invite;
                                            } else {
                                                personneCorrespondante = new Personne();
                                            }
                                            appt[i].getNumpad()->resetCode();

                                            // Si une personne correspondante existe
                                            if (personneCorrespondante->getUsername() != "NULL"){
                                                if (appt[i].getNbPersonnesPresentes() == 0){
                                                    if (appt[i-1].getNbPersonnesPresentes() != 0){
                                                        appt[1 - i].personneSort(personneCorrespondante, &leds);
                                                    }
                                                    appt[i].personneEntre(personneCorrespondante, &leds);
                                                } else {
                                                    if (appt[i-1].getNbPersonnesPresentes() != 0){
                                                        // Si la personne était dans l'autre pièce, alors elle en sort
                                                        if (appt[1-i].personnePresente(personneCorrespondante)){
                                                            appt[1-i].personneSort(personneCorrespondante, &leds);
                                                        }
                                                    }
                                                    appt[i].personneSort(personneCorrespondante, &leds);
                                                    Serial.println("Sortie 2");
                                                    appt[i].personneEntre(personneCorrespondante, &leds);
                                                    Serial.println("Entrée");
                                                }

                                                // // Si la personne n'était pas déjà dans la pièce
                                                // if (!appt[i].personnePresente(personneCorrespondante)){
                                                //   Serial.println("La personne n'est pas présente dans la piece du numpad");



                                                //     // Entrée de la personne dans la pièce actuelle
                                                //     appt[i].personneEntre(personneCorrespondante, &leds);

                                                // } else { // Si la personne était déjà présente, elle sort de la pièce
                                                //     appt[i].personneSort(personneCorrespondante, &leds);
                                                // }


                                                // Sinon, on reset le code
                                            } else {
                                                appt[i].getNumpad()->resetCode();
                                            }

                                            // Si la personne a appuyé sur # mais qu'il y a moins de 4 digits, alors le code tapé est réinitialisé et l'utilisateur peut recommencer à taper son code.
                                        } else {
                                            appt[i].getNumpad()->resetCode();
                                        }
                                        break;
                                    default: // Si l'utilisateur a appuyé sur un chiffre
                                        // Tant que le code n'est pas complet, on rajoute le digit au code.
                                        if (appt[i].getNumpad()->getNbDigits() < 4){
                                            appt[i].getNumpad()->addDigitToCode(touche);
                                        }

                                        // Si le code était déjà complet et que l'on appuie à nouveau sur un chiffre, on reset le code et on ajoute le nouveau digit au code
                                        if (appt[i].getNumpad()->getNbDigits() >= 5){
                                            Serial.println(appt[i].getNumpad()->getCode());
                                            appt[i].getNumpad()->resetCode();
                                            appt[i].getNumpad()->addDigitToCode(touche);
                                        }
                                        break;
                                }
                            }




                            // Gestion de l'easter egg: si l'utilisateur a tapé 4 fois sur étoiles, on active le mode disco !
                            if (appt[i].getNumpad()->getNbEtoiles() == 4){
                                leds.setColorHSL(1-(i-1), hue, 1.0, 0.5);

                                if (appt[1-i].getNumpad()->getNbEtoiles() == 4){
                                    delay(25);
                                } else {
                                    delay(50);
                                }

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
                            break;
                        }
                    }
                }
                default: { // Si c'est une autre touche qui a été appuyée, elle ne correspond à aucun mode prédéfini. On remet à zéro.
                    modeNumpad[j] = '.';
                }
        }
    }

        // SELECTION DU MODE:
        // 1 : séquence
        // 2 : touche du numpad --> couleur
        // 3 : on peut faire rentrer des personnes à la main
        // **** : disco
    }
}

