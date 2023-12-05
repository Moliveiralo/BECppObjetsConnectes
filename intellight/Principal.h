/**
 * @project Intellight
 * @file Principal.cpp
 * @brief header de la classe principale avec les fonstions set up et loop
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 05/12/2023
 */

#ifndef BECPPOBJETSCONNECTES_PRINCIPAL_H
#define BECPPOBJETSCONNECTES_PRINCIPAL_H

#include <Arduino.h>
#include <ChainableLED.h>
#include "Appartement.h"
#include "Piece.h"
#include "Personne.h"

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

class Principal{
private:
    /************* Attributs *************/
    // Leds chainees : 1 led par piece
    short nbLeds; // Nombre de leds = nombre de pieces
    ChainableLED leds;

    // Attribut relatif à l'appartement
    Appartement appartTest;

    // Creation d'une personne qui peut gerer les lumieres de l'appartement
    Personne habitant;

public:

  Principal();
    /************* Methodes *************/
    void setUp(); // Fonction de set up du .ino de l'ide arduino
    void loop(); // Fonction loop du .ino de l'ide arduino
};

#endif //BECPPOBJETSCONNECTES_PRINCIPAL_H
