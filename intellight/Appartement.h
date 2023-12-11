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

    // Liste des personnes existantes
    static list<Personne*> listePersonnesExistantes;
    static list<Personne*>::iterator itPersonnesExistantes;

    /*Variable de classe*/
    static short nbAppartement;

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
    static void ajouterPersonne(Personne * p);
    static void retirerPersonne(short id);



    /************* Surcharge d'operateurs *************/
    // Surcharge de l'opérateur []
    // Quand on fait Appartement[id], on accède à la piece caractérise par cet id
    Piece & operator[] (int indice);


    /************* Destructeur *************/

    /* Fonctions amies */
    friend Personne getPersonneFromCode(short code); // Permet de récupérer une personne dont le code correspond à celui entré en paramètre. Si aucune ne correspond, une personne 'vide' dont le nom est "NULL" est retournée

};


Personne getPersonneFromCode(short code){
    bool personneTrouvee = false; // Initialement, on a pas encore trouvé la personne avec le code correspondant

    // On commence la recherche au début de la liste de personnes.
    Appartement::itPersonnesExistantes = Appartement::listePersonnesExistantes.begin();

    // Tant que l'on a pas trouvé la personne que l'on cherche et que l'on a pas parcouru toute la liste
    while (!personneTrouvee && (Appartement::itPersonnesExistantes!=Appartement::listePersonnesExistantes.end())){
        Personne * personneActuelle = *Appartement::itPersonnesExistantes;

        // Si le code tapé sur le numpad correspond au code de la personne, alors
        if (personneActuelle->verifierCode(code)){
            personneTrouvee=true; // On a trouvé la personne, donc on sort de la boucle
            return *personneActuelle; // On retourne la personne correspondante
            break;
        }

        // Si le code ne correspond pas, on va s'intéresser à la personne suivante dans la liste
        Appartement::itPersonnesExistantes++;
    }

    // Si aucune personne n'a le code tapé, alors on retourne une personne "vide" dont le nom est "NULL".
    return Personne();
}



#endif //BECPPOBJETSCONNECTES_APPARTEMENT_H
