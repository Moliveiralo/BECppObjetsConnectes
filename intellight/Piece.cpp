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
void Piece::allumerLumiere (short r, short g, short b, ChainableLED leds){
    // On allume la lumiere dans la piece
    ledAllumee=true;
    // Et on definit les caracteristiques des lumieres de cette piece
    R=r ; G=g; B=b;
    leds.setColorRGB(id-1, R, G, B);
}

void Piece::eteindreLumiere (ChainableLED leds){
    // On eteint la lumiere de la piece
    ledAllumee=false;
    // On remet les caracteristiques de la lumiere a 0
    R=0; G=0; B=0;
    leds.setColorRGB(id-1, R, G, B);
}

void Piece::changerCaracteristiques(short r, short g, short b, ChainableLED leds) {
    // On redefinit les caracteristiques des lumieres de cette piece
    R=r ; G=g; B=b;
    // Et on les applique a la lumiere
    leds.setColorRGB(id-1, R, G, B);
}

void Piece::personneEntre(const Personne& nouvellePersonne, ChainableLED leds){
    // Lorsqu'une personne entre dans la piece, elle est ajoutee a la liste des personnes
    // presentes dans la piece
    listePersonnesPresentes.push_back(nouvellePersonne);
    nbPersonnesPresentes++;

    // Si la personne est seule la lumiere de la piece s'allume avec ses preference
    if (nbPersonnesPresentes == 1)
        allumerLumiere(nouvellePersonne.getR(), nouvellePersonne.getG(), nouvellePersonne.getB(), ChainableLED leds);

    // Si la personne n'est pas seule mais qu'elle est prioritaire,
    // la lumiere prend les caracteristiques de cette personne
    else if (nouvellePersonne.getEstAdmin())
        changerCaracteristiques(nouvellePersonne.getR(), nouvellePersonne.getG(), nouvellePersonne.getB(), ChainableLED leds);

    // Si la personne n'est pas prioritaire et n'est pas un visiteur,
    // et s'il n'y a pas deja une personne prioritaire dans la piece,
    // on cherche quel est le plus petit id puisque la personne
    // la plus prio est celle avec le plus petit id
    else if (!(nouvellePersonne.getEstVisiteur()) && !(personnePrioPresente)){
        short idMin;
        idMin = nouvellePersonne.getId();
        itPersonnesPresentes = listePersonnesPresentes.begin();

        while (itPersonnesPresentes != listePersonnesPresentes.end()){
            if (itPersonnesPresentes->getId() < idMin) idMin = itPersonnesPresentes->getId();
        }

        if (idMin == nouvellePersonne.getId())
            changerCaracteristiques(nouvellePersonne.getR(), nouvellePersonne.getG(), nouvellePersonne.getB(), ChainableLED leds);
    }
}

void Piece::personneSort(const Personne& personneSortante){
    // On regarde si cette personne etait la personne prioritaire
    // et si c'est le cas on remet le booleen a false
    if (personneSortante.getEstAdmin()) personnePrioPresente = false;

    // On efface ensuite la personne
    itPersonnesPresentes = listePersonnesPresentes.begin();
    while (itPersonnesPresentes!=listePersonnesPresentes.end()){
        short testId = itPersonnesPresentes->getId();
        if (testId == personneSortante.getId()){
            listePersonnesPresentes.erase(itPersonnesPresentes);
            nbPersonnesPresentes--;
        }
        itPersonnesPresentes++;
    }

    // Si la personne etait seule dans la piece on eteint la lumiere
    if (nbPersonnesPresentes == 0) eteindreLumiere(ChainableLED leds);

    // Sinon, s'il n'y a pas de personne prioritaire, on utilise la methode
    // personne entre avec la premiere personne de la liste
    else if (!personnePrioPresente) personneEntre(*listePersonnesPresentes.begin());
    nbPersonnesPresentes--;
}