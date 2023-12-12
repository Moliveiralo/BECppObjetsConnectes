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

    // Creation des personnes qui peuvent gerer les lumieres de l'appartement
    Personne * habitant1; // Deux habitants classiques
    Personne * habitant2; // Deux habitants classiques
    Personne * habitantPrio; // Un habitant prioritaire
    Personne * invite; // Un invité


    // Pointeurs vers les UART émulés pour le numpad 1 et 2
    SoftwareSerial * mySerial, * mySerial2;

    // Pointeurs
    Numpad * numpad1,* numpad2;

    // Variables utilisées pour le mode disco
    float hue; // Valeur de la hue de la lumière
    boolean up; // Tendance de hue (montant 0-->1 ou descendant 1-->0)

    // Pour notre test en mode dégradé
    bool quitterModeSequence; // Vaut vrai si on souhaite quitter le mode séquence
    bool quitterModeCouleur; // Vaut vrai si on souhaite quitter le mode couleur
    bool premiereFois; // Vaut vrai si c'est la première itération de la boucle du mode couleur. Permet de ne pas spammer le serial avec le message de lancement du mode.


public:
    /************* Constructeurs *************/
    Principal();

    /************* Methodes *************/
    void setup(); // Fonction de set up du .ino de l'ide arduino
    void loop(); // Fonction loop du .ino de l'ide arduino
};

#endif //BECPPOBJETSCONNECTES_PRINCIPAL_H
