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
Piece:: Piece(std::string nom, short id){
    this->nom=nom;
    this->id=id;

    // Quand la piece est cree, par defaut la lumiere est eteinte
    // et les caracteristiques de sa lumiere sont a 0
    ledAllumee=false;
    R=0; G=0; B=0;
}

/************* Methodes *************/
// Getters
std::string Piece::getNom() const{
    return nom;
}

short Piece::getId() const{
    return id;
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