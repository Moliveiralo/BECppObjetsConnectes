/**
 * @project Intellight
 * @file Principal.cpp
 * @brief fichier source de la classe principale avec les fonstions set up et loop
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 05/12/2023
 */

#include "Principal.h"

void Principal::setUp(){
    // Creation des pieces dans l'appartement
    appartTest.ajouterPiece("Salon");
    appartTest.ajouterPiece("Chambre");

    // Definition des parametres de preference des personnes
    habitant.setRGB(255,0,255);

    // Initialisation des capteurs Arduino
    leds.init(); // Initialisation des leds

}

void Principal::loop(){

    appartTest[1].personneEntre(habitant);

    leds.setColorRGB(0, appartTest[1].getR(), appartTest[1].getG(), appartTest[1].getB());
    leds.setColorRGB(1, appartTest[2].getR(), appartTest[2].getG(), appartTest[2].getB());

    delay(1000);

    appartTest[1].personneSort(1);
    appartTest[2].personneEntre(habitant);
    leds.setColorRGB(0, appartTest[1].getR(), appartTest[1].getG(), appartTest[1].getB());
    leds.setColorRGB(1, appartTest[2].getR(), appartTest[2].getG(), appartTest[2].getB());

    delay(1000);

    appartTest[2].personneSort(1);
}

