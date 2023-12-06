/**
 * @project Intellight
 * @file main.cpp
 * @brief Fichier principal
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#include <iostream>
#include "Appartement.h"

using namespace std;

int main(){

    Appartement appart1;
    cout << "L'identifiant de l'apparement cree est : " << appart1.getID()
    << ". Pour l'instant cet appartement a " << appart1.getNbPiece() << " pieces." << endl;
    appart1.ajouterPiece("salon");
    appart1.ajouterPiece("cuisine");
    appart1.ajouterPiece("chambre");
    cout << "Dans l'appart " << appart1.getID() << " il y a maintenant " << appart1.getNbPiece() << " pieces." << endl;
    appart1.retirerPiece(2);
    cout << "Dans l'appart " << appart1.getID() << " il y a maintenant " << appart1.getNbPiece() << " pieces." << endl;
    cout << "Test surcharge de l'operateur : " << appart1[1].getId() << endl;
    return 0;
}
