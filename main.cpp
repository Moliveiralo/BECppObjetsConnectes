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

    personne1.setLightPreferences(100, 214, 137, 56);
    short * tabPref = personne1.getLightPreferences();

    cout << tabPref[0] << " " << tabPref[1] << " " << tabPref[2] << endl;

    return 0;
}