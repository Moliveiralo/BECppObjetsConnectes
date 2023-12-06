/**
 * @project Intellight
 * @file Piece.h
 * @brief header de la classe piece
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 16/11/2023
 */

#include "Piece.h"


/************* Constructeur *************/
Piece:: Piece(const String& nom, short id){
    this->nom=nom;
    this->id=id;

    // Quand la piece est cree, par defaut la lumiere est eteinte
    // et les caracteristiques de sa lumiere sont a 0
    ledAllumee=false;
    R=0; G=0; B=0;
}

/************* Methodes *************/
// Getters
String Piece::getNom() const{
    return nom;
}

short Piece::getId() const{
    return id;
}

bool Piece::getLedAllumee() const{
    return ledAllumee;
}

short Piece::getR() const{
    return R;
}

short Piece::getG() const{
    return G;
}

short Piece::getB() const{
    return B;
}

short Piece::getNbPersonnesPresentes() const {
    return nbPersonnesPresentes;
}

list<Personne> Piece::getLisPersonnesPresentes() const{
    return listePersonnesPresentes;
}

// Autres methodes
void Piece::allumerLumiere (short r, short g, short b){
    // On allume la lumiere dans la piece
    ledAllumee=true;
    // Et on definit les caracteristiques des lumieres de cette piece
    R=r ; G=g; B=b;
}

void Piece::eteindreLumiere (){
    // On eteint la lumiere de la piece
    ledAllumee=false;
    // On remet les caracteristiques de la lumiere a 0
    R=0; G=0; B=0;
}

void Piece::changerCaracteristiques(short r, short g, short b) {
    // On redefinit les caracteristiques des lumieres de cette piece
    R=r ; G=g; B=b;
}

void Piece::personneEntre(const Personne& nouvellePersonne){
    // Lorsqu'une personne entre dans la piece, elle est ajoutee a la liste des personnes
    // presentes dans la piece
    listePersonnesPresentes.push_back(nouvellePersonne);
    nbPersonnesPresentes++;

    // Si la personne est seule la lumiere de la piece s'allume avec ses preference
    if (nbPersonnesPresentes == 1) allumerLumiere(nouvellePersonne.getR(), nouvellePersonne.getG(), nouvellePersonne.getB());

    // Si la personne n'est pas seule mais qu'elle est prioritaire,
    // la lumiere prend les caracteristiques de cette personne
    else if (nouvellePersonne.getEstAdmin()) changerCaracteristiques(nouvellePersonne.getR(), nouvellePersonne.getG(), nouvellePersonne.getB());

    // Si la personne n'est pas prioritaire et n'est pas un visiteur,
    // on regarde si il
    else if (!(nouvellePersonne.getEstVisiteur())){
        itPersonnesPresentes = listePersonnesPresentes.begin();
    }
}

void Piece::personneSort(short personneId){

    itPersonnesPresentes = listePersonnesPresentes.begin();
    while (itPersonnesPresentes!=listePersonnesPresentes.end()){
        short testId = itPersonnesPresentes->getId();
        if (testId == personneId){
            listePersonnesPresentes.erase(itPersonnesPresentes);
            nbPersonnesPresentes--;
        }
        itPersonnesPresentes++;
    }
    if (nbPersonnesPresentes == 0) eteindreLumiere();
}