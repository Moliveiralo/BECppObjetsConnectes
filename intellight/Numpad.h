//
// Created by maxim on 06/12/2023.
//

#ifndef BECPPOBJETSCONNECTES_NUMPAD_H
#define BECPPOBJETSCONNECTES_NUMPAD_H

#include <Arduino.h>
#include "SoftwareSerial.h"

/* Les numpads sont des claviers tactiles capacitifs fonctionnant en UART.
 * Comme l'ESP8266 n'a qu'un seul UART et que ce dernier est utilisé par la connexion en USB,
 * Nous utilisons la librairie SoftwareSerial pour créer à partir de 2 pins d'IO des UART émulés.
 * De cette manière, on peut implémenter nos numpads en UART.
*/

class Numpad {
private:
    /* Attributs */
    uint8_t data; // Contient la donnée lue depuis le numpad. Elle n'est pas formattée de manière lisible par un humain.
    SoftwareSerial * mySerial; // Pointeur vers l'UART émulé pour le numpad

    short * code; // Tableau de nombres contenant le code tapé sur le numpad
    short nbDigits, nbEtoiles;


    /* Méthodes */
    void updateData() const; // Permet d'effectuer une lecture sur le numpad et de mettre à jour data.


public:
    /* Constructeurs */
    Numpad(); // Constructeur par défaut, ne sera à priori jamais utilisé.
    Numpad(SoftwareSerial * s); // Constructeur permettant de créer un numpad avec un UART associé

    /* Méthodes */
    // Getters
    uint8_t getData() const; // Permet d'obtenir l'attribut data de manière non lisible par un humain.
    char getTouche() const; // Permet d'obtenir de manière lisible par un humain la touche sur laquelle l'utilisateur a appuyé.
    short getCode() const; // Permet d'obtenir de manière lisible par un humain une suite de 4 digits tapés sur le numpad.
    SoftwareSerial * getSerial(); // Permet d'accéder à l'UART associé au numpad
    short getNbDigits() const;
    short getNbEtoiles() const;

    // Autres méthodes
    void addDigitToCode(short digit);
    void resetNbEtoiles();
    void incrNbEtoiles();
    void resetCode();

    // Destructeurs
    ~Numpad() = default; // Destructeur par défaut pour le moment -- A MODIFIER POUR SUPPRIMER L'UART
};


#endif //BECPPOBJETSCONNECTES_NUMPAD_H
