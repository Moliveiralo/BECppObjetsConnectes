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

#include <Arduino.h>
#include <list>
#include "Piece.h"
#include "Personne.h"


class Appartement {
private :
    /************* Attributs *************/
    short id; // Identifiant de l'appartement
    short nbPiece; // Nb de pièces qu'il y a dans l'appartement

    // Liste des pieces de l'appartement
    list<Piece>  listePieces;
    list<Piece>::iterator itPiece;

    // Liste de personnes presente dans l'appartement
    list<Personne> listePersonnesPresentes;
    list<Piece>::iterator itPersonnesPresentes;

    /*Variable de classe*/
    static short nbAppartement;

public :

    /************* Constructeur *************/
    Appartement(); // Creation d'un nouvel appartement


    /************* Méthodes *************/
    //Getters
    short getID() const; // Renvoie l'identifiant de l'appartement
    short getNbPiece() const; // Renvoie le nb de piece qu'il y a dans l'appartement
    short getNbAppartements() const; // Renvoie le nb d'appartements qui ont ete crees

    // Autres methodes
    // Relatives à la liste de pieces
    void ajouterPiece (const String&  nom); // Permet de creer une nouvelle piece dans un appartement
    void retirerPiece (short pieceId); // Retire une piece de l'appartement

    void ajouterPersonnePresente ();
    void retirerPersonne(short id);


    /************* Surcharge d'operateurs *************/
    // Surcharge de l'operatuer []
    // Quand on fait Appartement[id], on accede a la piece caracterise par cet id
    Piece & operator[] (int indice);


    /************* Destructeur *************/

};

#endif //BECPPOBJETSCONNECTES_APPARTEMENT_H
