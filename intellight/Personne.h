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
#include <list>

class Personne {
private:
    /* Variables de classe */
    static short nbPersonnes; // Variable de classe permettant de compter le nombre de personnes existantes

    // Liste des personnes existantes
    static std::list<Personne> listePersonne; // Liste de toutes les personnes existantes
    static std::list<Personne>::iterator itPersonne; // Itérateur sur la liste de personnes

    /* Données générales sur l'utilisateur */
    short id; // Identifiant de l'utilisateur
    short code; // Code de l'utilisateur à rentrer sur le numpad
    String username; // Nom d'utilisateur ou sinon le prénom/nom de la personne
    bool isHere; // Statut de présence de l'utilisateur dans le domicile
    bool admin; // Vrai si la personne est administrateur
    bool visiteur; // Vrai si la personne est visiteur

    /* Données de préférence de l'utilisateur */
    float lightIntensity; // Intensité lumineuse en pourcentage. Cette variable est comprise entre 0.0% et 100.0%.
    short R, G, B; // Intensité lumineuse en rouge, vert et bleu. Cette variable est comprise entre 0 et 255.

public:
    /* Constructeurs */
    Personne();
    Personne(const String& us_name);
    Personne(const String& us_name, bool estAdmin, bool estVisiteur);
    Personne(const String& us_name, bool estAdmin, bool estVisiteur, short c);


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
    void setCode(short c);


    // Autres méthodes
    bool verifierCode(short c);


    // Méthodes de classe
    static short getNbPersonnes();
    static Personne getPersonne(short code);

    // Destructeurs
    ~Personne() = default;
};

#endif //BECPPOBJETSCONNECTES_PERSONNE_H
