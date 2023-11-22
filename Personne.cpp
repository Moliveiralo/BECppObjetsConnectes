/**
 * @project Intellight
 * @file Personne.cpp
 * @brief Classe personne
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#include "Personne.h"

// Initialisation de la variable de classe
short Personne::nbPersonnes = 0;

// Constructeurs:
Personne::Personne() {
    nbPersonnes++;
    id = nbPersonnes;
    username = "NULL";
    isHere = false;

    // Par défaut, on règle la lumière sur une lumière blanche à 100% d'intensité
    lightIntensity = 100.0;
    R = 255;
    G = 255;
    B = 255;
}

Personne::Personne(std::string us_name) {
    nbPersonnes++;
    id = nbPersonnes;
    username = us_name;
    isHere = false;

    // Par défaut, on règle la lumière sur une lumière blanche à 100% d'intensité
    lightIntensity = 100.0;
    R = 255;
    G = 255;
    B = 255;
}


// Getters:
short Personne::getId() const {
    return id;
}

std::string Personne::getUsername() const {
    return username;
}

bool Personne::getPresence() const {
    return isHere;
}


// Setters:
void Personne::setUsername(std::string u) {
    username = u;
}

void Personne::setPresence(bool p) {
    isHere = p;
}