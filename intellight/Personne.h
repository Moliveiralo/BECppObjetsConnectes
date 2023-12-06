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


#include <Arduino.h>

// (Idée de classe dérivée: personne prioritaire?)

class Personne {
private:
    /* Variables de classe */
    static short nbPersonnes;


    /* Données générales sur l'utilisateur */
    short id; // Identifiant de l'utilisateur -- remplacer par l'ID du tag NFC ?
    short code; // Code de l'utilisateur a rentrer sur le pin pad
    String username; // Nom d'utilisateur ou sinon le prénom/nom de la personne
    bool isHere; // Statut de présence de l'utilisateur dans le domicile
    bool admin; // Vrai si la personne est administrateur
    bool visiteur; // Vrai si la personne est visiteur

    /* Données de préférence de l'utilisateur */
    float lightIntensity;
    short R, G, B;

public:
    /* Constructeurs */
    Personne();
    Personne(const String& us_name);
    Personne(bool estAdmin, bool estVisiteur);


    /* Méthodes */
    // Getters
    short getId() const;
    String getUsername() const;
    bool getPresence() const;
    short getR() const;
    short getG() const;
    short getB() const;
    short getLightIntensity() const;
    short * getLightPreferences() const;
    bool getEstAdmin() const;
    bool getEstVisiteur() const;


    // Setters
    void setUsername(const String&  u);
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
