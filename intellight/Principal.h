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

#include "Appartement.h"
#include "SoftwareSerial.h"
#include "Numpad.h"

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

#define DATA_PIN D7 // Broche de données du LED
#define CLOCK_PIN D8 // Broche d'horloge du LED
#define RX1 D5 // Broche RX du 1er UART émulé
#define TX1 D6 // Broche TX du 1er UART émulé
#define RX2 D1 // Broche RX du 2ème UART émulé
#define TX2 D2 // Broche TX du 2ème UART émulé


class Principal{
private:
    /************* Attributs *************/
    // Leds chainees : 1 led par piece
    short nbLeds; // Nombre de leds = nombre de pieces
    ChainableLED leds;

    // Attribut relatif à l'appartement
    Appartement appt;

    // Creation d'une personne qui peut gerer les lumieres de l'appartement
    Personne habitant1;

    SoftwareSerial * mySerial, * mySerial2;
    Numpad * numpad1,* numpad2;


public:
    /************* Constructeurs *************/
    Principal();

    /************* Methodes *************/
    void setup(); // Fonction de set up du .ino de l'ide arduino
    void loop(); // Fonction loop du .ino de l'ide arduino
};

#endif //BECPPOBJETSCONNECTES_PRINCIPAL_H
