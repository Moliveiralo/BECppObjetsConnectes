/**
 * @project Intellight
 * @file Principal.cpp
 * @brief fichier source de la classe principale avec les fonstions set up et loop
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 05/12/2023
 */

#include "Principal.h"

/************* Liste des pins du NodeMCU 1.0 *************/
/*static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;*/


Principal::Principal():nbLeds(2), leds(13,15,nbLeds){}

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
    //appartTest[1].allumerLumiere (100, 0, 100);
    //appartTest[2].eteindreLumiere ();
  
    leds.setColorRGB(0, appartTest[1].getR(), appartTest[1].getG(), appartTest[1].getB());
    leds.setColorRGB(1, appartTest[2].getR(), appartTest[2].getG(), appartTest[2].getB());

    delay(1000);

    appartTest[1].personneSort(1);
    appartTest[2].personneEntre(habitant);
    //appartTest[1].eteindreLumiere ();
    //appartTest[2].allumerLumiere (0,255,0); 
    leds.setColorRGB(0, appartTest[1].getR(), appartTest[1].getG(), appartTest[1].getB());
    leds.setColorRGB(1, appartTest[2].getR(), appartTest[2].getG(), appartTest[2].getB());

    delay(1000);

    appartTest[2].personneSort(habitant.getId());
}

