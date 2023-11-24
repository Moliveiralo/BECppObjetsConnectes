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
#include "Personne.h"
#include "Piece.h"
#include "Visiteur.h"

using namespace std;

int main(){
    Personne personne1("Maxime");
    Personne personne2;

    personne2.setUsername("Ines");

    personne1.setLightPreferences(100, 214, 137, 56);
    short * tabPref = personne1.getLightPreferences();
    short * tabPref2 = personne2.getLightPreferences();

    cout << "Les preferences de " << personne1.getUsername() << " sont : " << tabPref[0] << " " << tabPref[1] << " " << tabPref[2] << endl;
    cout << "Les preferences de " << personne2.getUsername() << " sont : " << tabPref2[0] << " " << tabPref2[1] << " " << tabPref2[2] << endl;

    return 0;
}