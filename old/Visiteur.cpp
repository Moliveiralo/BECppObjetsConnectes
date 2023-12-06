/**
 * @project Intellight
 * @file Visiteur.cpp
 * @brief Classe Visiteur
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#include "Visiteur.h"

Visiteur::Visiteur() : Personne() {
    autorise = false;
}

Visiteur::Visiteur(std::string us_name) : Personne(us_name) {
    autorise = false;
}

Visiteur::Visiteur(std::string us_name, bool a) : Personne(us_name){
    autorise = a;
}
