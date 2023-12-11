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