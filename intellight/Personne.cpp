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
    nbPersonnes++; // On incrémente le nombre total de personnes existantes
    id = nbPersonnes; // On définit l'id unique de la personne
    username = "NULL"; // Affectation d'un nom par défaut
    isHere = false; // Par défaut, la personne n'est pas présente dans l'appartement

    // On définit le code de l'utilisateur sur les numpads
    code = -1;

    // Par défaut, la personne n'est ni un invite, ni un administrateur
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
    nbPersonnes++; // On incrémente le nombre total de personnes existantes
    id = nbPersonnes; // On définit l'id unique de la personne
    username = us_name; // Affectation du nom
    isHere = false; // Par défaut, la personne n'est pas présente dans l'appartement

    // On définit le code de l'utilisateur sur les numpads
    code = -1;

    // Par défaut, la personne n'est ni un invite, ni un administrateur
    admin = false;
    visiteur = false;

    // Par défaut, on règle la lumière sur une lumière blanche à 100% d'intensité
    lightIntensity = 100.0;
    R = 255;
    G = 255;
    B = 255;
}

Personne::Personne(const String& us_name, bool estAdmin, bool estVisiteur){
    nbPersonnes++; // On incrémente le nombre total de personnes existantes
    id = nbPersonnes; // On définit l'id unique de la personne
    username = us_name; // Affectation du nom
    isHere = false; // Par défaut, la personne n'est pas présente dans l'appartement

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
}

Personne::Personne(const String& us_name, bool estAdmin, bool estVisiteur, short c){
    nbPersonnes++; // On incrémente le nombre total de personnes existantes
    id = nbPersonnes; // On définit l'id unique de la personne
    username = us_name; // Affectation du nom
    isHere = false; // Par défaut, la personne n'est pas présente dans l'appartement

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

    // Les préférences sont modulées par l'intensité lumineuse
    // Ex: je veux du rouge (255, 0, 0) à 50% d'intensité lumineuse
    // --> (127, 0, 0) donc du rouge mais moins lumineux
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
    return (c == code); // Pour ne pas accéder de manière directe au code, on compare le code en paramètre à celui de l'utilisateur
}


/* ---------- Méthodes de classe: ---------- */

short Personne::getNbPersonnes() {
    return nbPersonnes;
}


/* ---------- Surcharge d'opérateurs: ---------- */
bool Personne::operator==(const Personne& autrePersonne) const{
    return this->getId() == autrePersonne.getId(); // Comme les id sont uniques, on les compare pour savoir si c'est la même personne
}


/* ---------- Destructeur: ---------- */
Personne::~Personne(){
    // On n'a aucun pointeur à delete
}