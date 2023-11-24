/**
 * @project Intellight
 * @file Appartement.h
 * @brief header de la classe Appartement
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 22/11/2023
 */

#ifndef BECPPOBJETSCONNECTES_APPARTEMENT_H
#define BECPPOBJETSCONNECTES_APPARTEMENT_H

#include <iostream>
#include <list>
#include "Piece.h"
#include "Personne.h"

class Appartement {
private :
    /************* Attributs *************/
    short id; // Identifiant de l'appartement
    short nbPiece; // Nb de pièces qu'il y a dans l'appartement

    // Liste de pieces
    list<Piece>  listePieces;
    list<Piece>::iterator itPiece;

    // Liste de personnes
    list<Personne> listePersonne;


    /*Variable de classe*/
    static short nbAppartement;

public :

    /************* Constructeur *************/
    Appartement(); // Creation d'un nouvel appartement


    /************* Méthodes *************/
    //Getters
    short getID() const; // Renvoie l'identifiant de l'appartement
    short getNbPiece() const; // Renvoie le nb de piece qu'il y a dans l'appartement


    // Autres methodes
    void ajouterPiece (float intensity, short r, short g, short b);
    void retirerPiece (short pieceId);

    /************* Destructeur *************/
};

#endif //BECPPOBJETSCONNECTES_APPARTEMENT_H
