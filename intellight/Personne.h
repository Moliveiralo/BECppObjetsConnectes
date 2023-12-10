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
    Personne(); // Constructeur vide, utilisé par la méthode getPersonne() si aucune personne n'a été trouvée
    Personne(const String& us_name); // Création d'une personne à partir de son nom uniquement
    Personne(const String& us_name, bool estAdmin, bool estVisiteur); // Création d'une personne avec son nom tout en désignant si elle est admin ou visiteur
    Personne(const String& us_name, bool estAdmin, bool estVisiteur, short c); // Création d'une personne avec son nom tout en désignant si elle est admin ou visiteur et en spécifiant son code sur les numpads


    /* Méthodes */
    // Getters
    short getId() const; // Permet de récupérer l'id d'une personne
    String getUsername() const; // Permet de récupérer le nom d'une personne
    bool getPresence() const; // Permet de savoir si la personne est présente dans l'appartement
    short getR() const; // Permet de récupérer la préférence de la personne concernant le rouge
    short getG() const; // Permet de récupérer la préférence de la personne concernant le vert
    short getB() const; // Permet de récupérer la préférence de la personne concernant le bleu
    short getLightIntensity() const; // Permet de récupérer la préférence de la personne concernant l'intensité lumineuse
    short * getLightPreferences() const; // Permet de récupérer l'ensemble des préférences de la personne en termes de lumière
    bool getEstAdmin() const; // Permet de savoir si la personne est admin
    bool getEstVisiteur() const; // Permet de savoir si la personne est visiteur


    // Setters
    void setUsername(const String&  u); // Permet de changer le nom de la personne
    void setPresence(bool p); // Permet de définir si la personne est présente dans l'appartement ou non
    void setR(short r); // Permet de changer la préférence de la personne concernant le rouge
    void setG(short g); // Permet de changer la préférence de la personne concernant le vert
    void setB(short b); // Permet de changer la préférence de la personne concernant le bleu
    void setRGB(short r, short g, short b); // Permet de changer la préférence de la personne concernant le rouge, le vert et le bleu
    void setLightIntensity(float i); // Permet de changer la préférence de la personne concernant l'intensité de la lumière
    void setLightPreferences(short r, short g, short b, float i); // Permet de changer les préférence de la personne concernant la lumière
    void setCode(short c); // Permet de changer le code de la personne sur les numpads de l'appartement


    // Autres méthodes
    bool verifierCode(short c); // Permet de vérifier si un code correspond bien à celui de la personne. Retourne true si c'est le cas, false sinon.


    // Méthodes de classe
    static short getNbPersonnes(); // Permet de savoir combien de personnes existent au total


    // Destructeurs
    ~Personne() = default; // Destructeur de personne


    /* Fonctions amies */
    friend Personne getPersonne(short code); // Permet de récupérer une personne dont le code correspond à celui entré en paramètre. Si aucune ne correspond, une personne 'vide' dont le nom est "NULL" est retournée.
};






Personne getPersonne(short code){
    bool personneTrouvee = false; // Initialement, on a pas encore trouvé la personne avec le code correspondant

    // On commence la recherche au début de la liste de personnes.
    Personne::itPersonne = Personne::listePersonne.begin();

    // Tant que l'on a pas trouvé la personne que l'on cherche et que l'on a pas parcouru toute la liste
    while (not(personneTrouvee) && (Personne::itPersonne!=Personne::listePersonne.end())){

        // Si le code tapé sur le numpad correspond au code de la personne, alors
        if (Personne::itPersonne->verifierCode(code)){
            personneTrouvee=true; // On a trouvé la personne, donc on sort de la boucle
            return *Personne::itPersonne; // On retourne la personne correspondant
            break;
        }

        // Si le code ne correspond pas, on va s'intéresser à la personne suivante dans la liste
        Personne::itPersonne++;
    }

    // Si aucune personne n'a le code tapé, alors on retourne une personne "vide" dont le nom est "NULL".
    return Personne();
}






#endif //BECPPOBJETSCONNECTES_PERSONNE_H
