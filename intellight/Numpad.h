//
// Created by maxim on 06/12/2023.
//

#ifndef BECPPOBJETSCONNECTES_NUMPAD_H
#define BECPPOBJETSCONNECTES_NUMPAD_H

/* Les numpads sont des claviers tactiles capacitifs fonctionnant en UART.
 * Comme l'ESP8266 n'a qu'un seul UART et que ce dernier est utilisé par la connexion en USB,
 * Nous utilisons la librairie SoftwareSerial pour créer à partir de 2 pins d'IO des UART émulés.
 * De cette manière, on peut implémenter nos numpads en UART.
*/

class Numpad {
private:
    /* Attributs */
    short Tx, Rx; // Numéro des pins associées au numpad
    uint8_t data;
    SoftwareSerial * serial;


public:
    /* Constructeurs */
    Numpad();
    Numpad(short tx, short rx, SoftwareSerial& s);

    /* Méthodes */
    // Getters
    uint8_t getData();
    short getRx();
    short getTx();


    // Setters
    void setRx(short rx);
    void setTx(short tx);


    // Autres méthodes
    void updateData(); // Permet d'effectuer une lecture sur le numpad et de mettre à jour data.


    // Destructeurs
    ~Numpad() = default;
};


#endif //BECPPOBJETSCONNECTES_NUMPAD_H
