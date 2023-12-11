/**
 * @project Intellight
 * @file Personne.cpp
 * @brief Classe personne
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#include "Personne.h"

/* ---------- Initialisation de la variable de classe ---------- */
short Personne::nbPersonnes = 0; // Initialisation du nombre de personnes initialement à 0

/* ---------- Constructeurs: ---------- */
Personne::Personne() {
    nbPersonnes++;
    id = nbPersonnes;
    username = "NULL";
    isHere = false;

    // On définit le code de l'utilisateur sur les numpads
    code = -1;

    // Par défaut, la personne n'est ni un visiteur, ni un administrateur
    admin = false;
    visiteur = false;

    // Par défaut, on règle la lumière sur une lumière blanche à 100% d'intensité
    lightIntensity = 100.0;
    R = 255;
    G = 255;
    B = 255;

    // On n'ajoute pas la personne vide à la liste de personnes car à priori on ne l'utilisera que pour la vérification de code sur les numpads
}

Personne::Personne(const String& us_name) {
    nbPersonnes++;
    id = nbPersonnes;
    username = us_name;
    isHere = false;

    // On définit le code de l'utilisateur sur les numpads
    code = -1;

    // Par défaut, la personne n'est ni un visiteur, ni un administrateur
    admin = false;
    visiteur = false;

    // Par défaut, on règle la lumière sur une lumière blanche à 100% d'intensité
    lightIntensity = 100.0;
    R = 255;
    G = 255;
    B = 255;

    // On ajoute la personne à la liste de personnes
//    listePersonne.push_back(this);
}

Personne::Personne(const String& us_name, bool estAdmin, bool estVisiteur){
    nbPersonnes++;
    id = nbPersonnes;
    username = us_name;
    isHere = false;

    // On définit le code de l'utilisateur sur les numpads
    code = -1;

    // On définit les caractéristiques de priorités de l'utilisateur
    admin = estAdmin;
    visiteur = estVisiteur;

    // Par défaut, on règle la lumière sur une lumière blanche à 100% d'intensité
    lightIntensity = 100.0;
    R = 255;
    G = 255;
    B = 255;

    // On ajoute la personne à la liste de personnes
//    listePersonne.push_back(this);
}

Personne::Personne(const String& us_name, bool estAdmin, bool estVisiteur, short c){
    nbPersonnes++;
    id = nbPersonnes;
    username = us_name;
    isHere = false;

    // On définit le code de l'utilisateur sur les numpads
    code = c;

    // On définit les caractéristiques de priorités de l'utilisateur
    admin = estAdmin;
    visiteur = estVisiteur;

    // Par défaut, on règle la lumière sur une lumière blanche à 100% d'intensité
    lightIntensity = 100.0;
    R = 255;
    G = 255;
    B = 255;

    // On ajoute la personne à la liste de personnes
//    listePersonne.push_back(this);
}


/* ---------- Getters: ---------- */
short Personne::getId() const {
    return id;
}

String Personne::getUsername() const {
    return username;
}

bool Personne::getPresence() const {
    return isHere;
}

short Personne::getR() const{
    return R;
}

short Personne::getG() const{
    return G;
}

short Personne::getB() const{
    return B;
}

short Personne::getLightIntensity() const{
    return lightIntensity;
}

short * Personne::getLightPreferences() const{
    short * tabPref = new short[3];
    tabPref[0] = (short) ((lightIntensity/100)* (float) R);
    tabPref[1] = (short) ((lightIntensity/100)* (float) G);
    tabPref[2] = (short) ((lightIntensity/100)* (float) B);
    return tabPref;
}

bool Personne::getEstAdmin() const {
    return admin;
}

bool Personne::getEstVisiteur() const {
    return visiteur;
}


/* ---------- Setters: ---------- */
void Personne::setUsername(const String& u) {
    username = u;
}

void Personne::setPresence(bool p) {
    isHere = p;
}

void Personne::setR(short r){
    R = r;
}

void Personne::setG(short g){
    G = g;
}

void Personne::setB(short b){
    B = b;
}

void Personne::setRGB(short r, short g, short b){
    R = r;
    G = g;
    B = b;
}

void Personne::setLightIntensity(float i){
    lightIntensity = i;
}

void Personne::setLightPreferences(short r, short g, short b, float i){
    R = r;
    G = g;
    B = b;
    lightIntensity = i;
}

void Personne::setCode(short c){
    code = c;
}


/* ---------- Autres méthodes: ---------- */
bool Personne::verifierCode(short c){
    return (c == code);
}


/* ---------- Méthodes de classe: ---------- */

short Personne::getNbPersonnes() {
    return nbPersonnes;
}


/* ---------- Surcharge d'opérateurs: ---------- */
bool Personne::operator==(const Personne& autrePersonne) const{
    return this->getId() == autrePersonne.getId();
}