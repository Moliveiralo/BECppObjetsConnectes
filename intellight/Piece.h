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
#include <list>
#include "Personne.h"


using namespace std;

class Piece {
private :
    /************* Attributs *************/
    // Identification de la piece
    String nom;
    short id;

    // Etat de la lumiere dans la piece
    bool ledAllumee;
    short R, G, B;

    // Nombre de personnes presentes dans la piece
    short nbPersonnesPresentes;
    // Liste de personnes presentes dans la pièce
    list<Personne> listePersonnesPresentes;
    list<Personne>::iterator itPersonnesPresentes;

public :
    /************* Constructeur *************/
    Piece(const String& nom, short id);


    /************* Methodes *************/
    // Getters
    String getNom() const;
    short getId() const;
    bool getLedAllumee() const;
    short getR() const;
    short getG() const;
    short getB() const;
    short getNbPersonnesPresentes() const;
    list<Personne> getLisPersonnesPresentes() const;

    // Autres methodes
    void allumerLumiere (short r, short g, short b); // Allume la lumiere avec certaines caracteristiques
    void eteindreLumiere (); // Etient la lumiere et remet a 0 ses caracteristiques
    void changerCaracteristiques (short r, short g, short b); // Permet de changer les caracteristiques de la lumiere
    void personneEntre(const Personne& nouvellePersonne); // Rajoute une personne dans la liste des personnes presentes dans la piece
    void personneSort(short personneId); // Retire une personne de la liste des personnes presentes dans la piece

    /************* Destructeur *************/
};


#endif //BECPPOBJETSCONNECTES_PIECE_H
