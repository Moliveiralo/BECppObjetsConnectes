/**
 * @project Intellight
 * @file Personne.h
 * @brief Header Classe personne
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#ifndef BECPPOBJETSCONNECTES_PERSONNE_H
#define BECPPOBJETSCONNECTES_PERSONNE_H

#include <iostream>
#include <string>
//#include "Piece.h"

// (Idée de classe dérivée: personne prioritaire?)

class Personne {
private:
    /* Variables de classe */
    static short nbPersonnes;


    /* Données générales sur l'utilisateur */
    short id; // Identifiant de l'utilisateur -- remplacer par l'ID du tag NFC ?
    std::string username; // Nom d'utilisateur ou sinon le prénom/nom de la personne
    bool isHere; // Statut de présence de l'utilisateur dans le domicile


    /* Données de préférence de l'utilisateur */
    float lightIntensity;
    short R, G, B;

public:
    /* Constructeurs */
    Personne();
    Personne(std::string us_name);


    /* Méthodes */
    // Getters
    short getId() const;
    std::string getUsername() const;
    bool getPresence() const;
    short getR() const;
    short getG() const;
    short getB() const;
    short getLightIntensity() const;
    short * getLightPreferences() const;


    // Setters
    void setUsername(std::string u);
    void setPresence(bool p);
    void setR(short r);
    void setG(short g);
    void setB(short b);
    void setRGB(short r, short g, short b);
    void setLightIntensity(float i);
    void setLightPreferences(short r, short g, short b, float i);


    // Autres méthodes


    // Méthodes de classe
    static short getNbPersonnes();


    // Destructeurs
    ~Personne() = default;
};

#endif //BECPPOBJETSCONNECTES_PERSONNE_H
