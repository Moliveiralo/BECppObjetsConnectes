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

    // Paramètres initiaux du mode disco
    up = true;
    hue = 0.0;

    // Création de chaque habitant/invité et définition de ses préférences lumineuses
    habitant1 = new Personne("Inès", false, false, 1234);
    habitant1->setRGB(255,0,255);

    habitant2 = new Personne("Maxime", false, false, 1793);
    habitant2->setRGB(255,215,0);

    habitantPrio = new Personne("Stacy", true, false, 8520);
    habitantPrio->setRGB(0,255,0);

    invite = new Personne("Brittany", false, true, 4785);
    invite->setRGB(223, 115, 255);

    // Si nos listes de personnes fonctionnaient, on ajouterait chaque personne créée à la liste de personnes existantes
//    appt.ajouterPersonne(*habitant1);
//    appt.ajouterPersonne(*habitant2);
//    appt.ajouterPersonne(*habitantPrio);
//    appt.ajouterPersonne(*invite);

    // Valeurs par défaut pour le bon lancement des modes
    quitterModeCouleur = false;
    quitterModeSequence = false;
    premiereFois = true;
}


void Principal::loop(){
    delay(5000);

    /***** PREMIER MODE : LECTURE D'UNE SEQUENCE *****/
    while (!quitterModeSequence){ // Tant que l'on ne veut pas changer de mode
      Serial.println("Mode Séquence");

      appt[1].personneEntre(habitant1, &leds); // Habitant 1 entre dans pièce 1

      delay(2000);

      appt[1].personneEntre(habitant2, &leds); // Habitant 2 entre dans pièce 1

      delay(2000);

      appt[1].personneSort(habitant1, &leds);  // Habitant 1 sort de pièce 1

      delay(2000);

      appt[2].personneEntre(habitant1, &leds);  // Habitant 1 entre dans pièce 2

      delay(2000);

      appt[1].personneEntre(habitantPrio, &leds);  // Habitant Prio entre dans pièce 1

      delay(2000);

      appt[1].personneSort(habitantPrio, &leds);  // Habitant Prio sort de pièce 1

      delay(2000);

      appt[1].personneSort(habitant2, &leds);  // Habitant 2 sort de pièce 1

      delay(2000);

      appt[2].personneEntre(invite, &leds);  // Invité entre dans pièce 2

      delay(2000);

      appt[2].personneSort(habitant1, &leds);  // Habitant 1 sort de pièce 2 (invité tout seul donc ses préférences s'appliquent)

      delay(2000);

      appt[2].personneSort(invite, &leds);  // Invité sort de pièce 2

      quitterModeSequence = true;
      Serial.println("Fin de la séquence.");

      delay(3000);
    }


    /***** DEUXIEME MODE : COULEUR POUR CHAQUE TOUCHE DU NUMPAD  *****/
    while (!quitterModeCouleur){ // Tant que l'on ne veut pas changer de mode
      // A la première itération, on affiche un message indiquant le changement de mode.
        if (premiereFois){
          Serial.println("Mode couleur");
          premiereFois = false;
        }

        // On itère pour chaque pièce de l'appartement
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
                        Serial.println("Fin du mode couleur");
                        quitterModeCouleur = true;
                        Serial.println("Mode Libre");
                        break;
                    default:
                        break;
                }
            }
        }
    }



    /***** TROISIEME MODE : LIBRE (MODE DEGRADE) *****/
    while(1){
        // On vérifie pour chaque pièce de l'appartement
        for(int i=1; i<=appt.getNbPiece(); i++){

            // Tant que l'UART associé au numpad est disponible
            while(appt[i].getNumpad()->getSerial()->available()){

                // On récupère la touche qui est appuyée sur le numpad
                char touche = appt[i].getNumpad()->getTouche();

                switch(touche){
                    case '*': // Si la touche appuyée est étoile, alors on incrémente le nombre de fois ou étoiles a été tapé
                        appt[i].getNumpad()->incrNbEtoiles();
                        Serial.println("*");
                        break;


                    case '#':
                        Serial.println("#");
                        if (appt[i].getNumpad()->getNbDigits() == 4){
                            // On cherche une personne dont le code correspond à celui entré sur le numpad
                            Personne * personneCorrespondante;

                            Serial.println("Code:");
                            Serial.println(appt[i].getNumpad()->getCode());
                            // Nous avons eu des soucis avec les listes de personnes dans la classe appartement qui génère une exception
//                        Personne personneCorrespondante = appt.getPersonneFromCode(appt[i].getNumpad()->getCode());

                            if (habitant1->verifierCode(appt[i].getNumpad()->getCode())){
                                personneCorrespondante = habitant1;
                                Serial.println("habitant 1 correspond au code tapé");
                            } else if (habitant2->verifierCode(appt[i].getNumpad()->getCode())){
                                personneCorrespondante = habitant2;
                                Serial.println("habitant 2 correspond au code tapé");
                            } else if (habitantPrio->verifierCode(appt[i].getNumpad()->getCode())){
                                personneCorrespondante = habitantPrio;
                                Serial.println("habitant prioritaire correspond au code tapé");
                            } else if (invite->verifierCode(appt[i].getNumpad()->getCode())){
                                personneCorrespondante = invite;
                                Serial.println("invité correspond au code tapé");
                            } else {
                                personneCorrespondante = new Personne();
                                Serial.println("aucune personne ne correspond au code tapé");
                            }
                            appt[i].getNumpad()->resetCode();

                            // Si une personne correspondante existe
                            if (personneCorrespondante->getUsername() != "NULL"){
                                if (appt[i].getNbPersonnesPresentes() == 0){ // Si la pièce est vide, la personne entre directement dans la pièce
                                    // if (appt[i-1].getNbPersonnesPresentes() != 0){  // Si l'autre pièce n'est pas vide, on tente de faire sortir la personne de la pièce (si elle n'y était pas, rien ne se passe)
                                    //     appt[1 - i].personneSort(personneCorrespondante, &leds);
                                    // }
                                    appt[i].personneEntre(personneCorrespondante, &leds);

                                } else { // Si la pièce n'est pas vide

                                    if (appt[i-1].getNbPersonnesPresentes() != 0){
                                        // if (appt[1-i].personnePresente(personneCorrespondante)){ // Si l'autre pièce n'est pas vide, on tente de faire sortir la personne de la pièce (si elle n'y était pas, rien ne se passe)
                                        //     appt[1-i].personneSort(personneCorrespondante, &leds);
                                        // }
                                    }
                                    // appt[i].personneSort(personneCorrespondante, &leds); // On tente de faire sortir la personne de la pièce (si elle n'y était pas, rien ne se passe)
                                    appt[i].personneEntre(personneCorrespondante, &leds); // Enfin, on fait rentrer la personne dans la pièce
                                }

                                // Fonctionnement initial, ne fonctionne pas car personnePresente ne fonctionne pas.
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
                        Serial.println(touche);

                        if (appt[i].getNumpad()->getNbDigits() < 4){ // Tant que le code n'est pas complet, on rajoute le digit au code.
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

                delay(25);

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
    }
}