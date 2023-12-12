/**
 * @project Intellight
 * @file Piece.h
 * @brief header de la classe piece
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#ifndef BECPPOBJETSCONNECTES_PIECE_H
#define BECPPOBJETSCONNECTES_PIECE_H

#include <Arduino.h>
#include <ChainableLED.h>
#include <list>
#include "Personne.h"
#include "Numpad.h"


using namespace std;

class Piece {
private :
    /************* Attributs *************/
    // Identification de la piece
    String nom;
    short id;

    // Etat de la lumiere dans la piece
    // La LED associee a la piece est la LED numero id-1
    bool ledAllumee;
    short R, G, B;

    // Nombre de personnes presentes dans la piece
    short nbPersonnesPresentes;
    bool personnePrioPresente = false;

    // Liste de personnes presentes dans la pièce
    list<Personne*> listePersonnesPresentes;
    list<Personne*>::iterator itPersonnesPresentes;

    // Numpad asocié à la pièce
    Numpad * numpad;

public :
    /************* Constructeur *************/
    Piece(const String& nom, short id, Numpad * npad);


    /************* Methodes *************/
    // Getters
    String getNom() const;
    short getId() const;
    bool getLedAllumee() const;
    short getR() const;
    short getG() const;
    short getB() const;
    short getNbPersonnesPresentes() const;
    list<Personne*> getListPersonnesPresentes() const;
    Numpad * getNumpad();

    // Autres methodes
    void allumerLumiere (short r, short g, short b, ChainableLED *leds); // Allume la lumiere avec certaines caracteristiques
    void eteindreLumiere (ChainableLED *leds); // Etient la lumiere et remet a 0 ses caracteristiques
    void changerCaracteristiques (short r, short g, short b, ChainableLED *leds); // Permet de changer les caracteristiques de la lumiere
    void personneEntre(Personne* nouvellePersonne, ChainableLED *leds); // Une personne entre dans la piece
    void personneSort(Personne* personneSortante, ChainableLED *leds); // Une personne sort de la piece la piece
    bool personnePresente(Personne * p);

    /************* Destructeur *************/
    ~Piece();
};

#endif //BECPPOBJETSCONNECTES_PIECE_H
