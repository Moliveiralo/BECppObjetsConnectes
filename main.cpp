/**
 * @project Intellight
 * @file main.cpp
 * @brief Fichier principal
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#include <iostream>
#include "./Intellight/Appartement.h"

using namespace std;

/* Organisation des pins:
 * NUMPAD N°1 (Pièce principale):
 * D1 20
 * D2 19
 *
 * NUMPAD N°2 (Chambre):
 * D5 5
 * D6 6
 *
 * LEDS:
 * D7 7
 * D8 8
 */

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
