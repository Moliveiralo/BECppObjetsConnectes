/**
 * @project Intellight
 * @file Appartement.cpp
 * @brief source de la classe Appartement
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 22/11/2023
 */

#include "Appartement.h"

/************* Instanciation des variables de classe *************/
short Appartement::nbAppartement=0;


/************* Constructeur *************/
Appartement::Appartement(){
    nbAppartement++;
    id = nbAppartement;
    nbPiece=0;
}


/************* Méthodes *************/
// Getters
short Appartement::getID() const {
    return id;
}

short Appartement::getNbPiece() const {
    return nbPiece;
}

short Appartement::getNbAppartements() {
    return nbAppartement;
}

// Autres methodes
void Appartement::ajouterPiece(const String& nom, Numpad * npad) {
    nbPiece++;
    Piece nvllePiece(nom, nbPiece, npad);
    listePieces.push_back(nvllePiece);
}

void Appartement::retirerPiece(short pieceId) {
    bool pieceEffacee = false;

    itPiece=listePieces.begin();
    while (not(pieceEffacee) && (itPiece!=listePieces.end())){
        short testId = itPiece->getId();
        if (testId == pieceId){
            pieceEffacee=true;
            listePieces.erase(itPiece);
            nbPiece--;
        }
        itPiece++;
    }
}

void Appartement::ajouterPersonne(Personne *p) {
    listePersonnesExistantes.push_back(p);
}

void Appartement::retirerPersonne(short id){
    bool personneEffacee = false;

    itPersonnesExistantes=listePersonnesExistantes.begin();
    while (not(personneEffacee) && (itPersonnesExistantes!=listePersonnesExistantes.end())){
        Personne * personneActuelle = *itPersonnesExistantes;
        short testId = personneActuelle->getId();
        if (testId == id){
            personneEffacee=true;
            listePersonnesExistantes.erase(itPersonnesExistantes);
        }
        itPersonnesExistantes++;
    }
}

Personne Appartement::getPersonneFromCode(short code) {
    bool personneTrouvee = false; // Initialement, on a pas encore trouvé la personne avec le code correspondant

    // On commence la recherche au début de la liste de personnes.
    Appartement::itPersonnesExistantes = Appartement::listePersonnesExistantes.begin();

    // Tant que l'on a pas trouvé la personne que l'on cherche et que l'on a pas parcouru toute la liste
    while (!personneTrouvee && (Appartement::itPersonnesExistantes!=Appartement::listePersonnesExistantes.end())){
        Personne * personneActuelle = *Appartement::itPersonnesExistantes;

        // Si le code tapé sur le numpad correspond au code de la personne, alors
        if (personneActuelle->verifierCode(code)){
            personneTrouvee=true; // On a trouvé la personne, donc on sort de la boucle
            return *personneActuelle; // On retourne la personne correspondante
            break;
        }

        // Si le code ne correspond pas, on va s'intéresser à la personne suivante dans la liste
        Appartement::itPersonnesExistantes++;
    }

    // Si aucune personne n'a le code tapé, alors on retourne une personne "vide" dont le nom est "NULL".
    return Personne();
}


/************* Surcharge d'operateurs *************/
// Surcharge de l'operatuer []
// Quand on fait Appartement[id], on accede a la piece caracterise par cet id
Piece & Appartement::operator[] (int indice){
    bool pieceTrouvee = false;

    itPiece=listePieces.begin();
    while (not(pieceTrouvee) && (itPiece!=listePieces.end())){
        short testId = itPiece->getId();
        if (testId == indice){
            pieceTrouvee=true;
            break;
        }
        itPiece++;
    }
    return *itPiece;
}