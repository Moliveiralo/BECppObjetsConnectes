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

#include <iostream>
#include <string>

using namespace std;

class Piece {
private :
    /************* Attributs *************/
    // Identification de la piece
    std::string nom;
    short id;

    // Etat de la lumiere dans la piece
    bool ledAllumee;
    short R, G, B;

public :
    /************* Constructeur *************/
    Piece(std::string nom, short id);


    /************* Methodes *************/
    // Getters
    std::string getNom() const;
    short getId() const;


    // Autres methodes
    void allumerLumiere (short r, short g, short b); // Allume la lumiere avec certaines caracteristiques
    void eteindreLumiere (); // Etient la lumiere et remet a 0 ses caracteristiques

    /************* Destructeur *************/
};


#endif //BECPPOBJETSCONNECTES_PIECE_H
