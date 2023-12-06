/**
 * @project Intellight
 * @file Visiteur.h
 * @brief Header Classe Visiteur
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 23/11/2023
 */

#ifndef BECPPOBJETSCONNECTES_VISITEUR_H
#define BECPPOBJETSCONNECTES_VISITEUR_H

#include "Personne.h"
#include <iostream>

class Visiteur : Personne {
private:
    bool autorise;
public:
    /* Constructeurs */
    Visiteur();
    Visiteur(std::string us_name);
    Visiteur(std::string us_name, bool a);

    /* Méthodes */
    // Destructeur
    ~ Visiteur() = default;

};

#endif //BECPPOBJETSCONNECTES_VISITEUR_H
