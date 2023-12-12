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

#include "Piece.h"


class Appartement {
private :
    /************* Attributs *************/
    short id; // Identifiant de l'appartement
    short nbPiece; // Nb de pièces qu'il y a dans l'appartement

    // Liste des pieces de l'appartement
    list<Piece> listePieces;
    list<Piece>::iterator itPiece;

    // Nous avions des erreurs à la compilation causees par cette liste que l'on a pas reussit a corriger
    // Nous avons tout de meme laisse tout ce que nous avions code pour cette liste et l'avons commente
//    // Liste des personnes existantes
//    static list<Personne> listePersonnesExistantes;
//    static list<Personne>::iterator itPersonnesExistantes;

    /*Variable de classe*/
    static short nbAppartement; // Nombre d'appartements

public :

    /************* Constructeur *************/
    Appartement(); // Creation d'un nouvel appartement


    /************* Méthodes *************/
    //Getters
    short getID() const; // Renvoie l'identifiant de l'appartement
    short getNbPiece() const; // Renvoie le nb de piece qu'il y a dans l'appartement
    static short getNbAppartements() ; // Renvoie le nb d'appartements qui ont ete crees

    // Autres methodes
    // Relatives à la liste de pieces
    void ajouterPiece(const String& nom, Numpad * npad); // Permet de creer une nouvelle piece dans un appartement
    void retirerPiece (short pieceId); // Retire une piece de l'appartement
//    static void ajouterPersonne(Personne p); // Ajouter une personne a la liste
//    static void retirerPersonne(short id); // Retirer une personne de la liste
//    Personne getPersonneFromCode(short code); // Permet de récupérer une personne dont le code correspond à celui entré en paramètre. Si aucune ne correspond, une personne 'vide' dont le nom est "NULL" est retournée



    /************* Surcharge d'operateurs *************/
    // Surcharge de l'opérateur []
    // Quand on fait Appartement[id], on accède à la piece caractérise par cet id
    Piece & operator[] (int indice);


    /************* Destructeur *************/
    ~Appartement();
};



#endif //BECPPOBJETSCONNECTES_APPARTEMENT_H
