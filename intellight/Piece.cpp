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
Piece:: Piece(const String& nom, short id, Numpad * npad){
    this->nom=nom;
    this->id=id;

    // Quand la piece est cree, par defaut la lumiere est eteinte
    // et les caracteristiques de sa lumiere sont a 0
    ledAllumee=false;
    R=0; G=0; B=0;

    // Chaque pièce est associée à un numpad
    numpad = npad;

    nbPersonnesPresentes=0;
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

list<Personne*> Piece::getListPersonnesPresentes() const{
    return listePersonnesPresentes;
}

// Autres methodes
void Piece::allumerLumiere (short r, short g, short b, ChainableLED *leds){
    // On allume la lumiere dans la piece
    ledAllumee=true;
    // Et on definit les caracteristiques des lumieres de cette piece
    R=r ; G=g; B=b;
    leds->setColorRGB(1-(id-1), R, G, B);
}

void Piece::eteindreLumiere (ChainableLED *leds){
    // On eteint la lumiere de la piece
    ledAllumee=false;
    // On remet les caracteristiques de la lumiere a 0
    R=0; G=0; B=0;
    leds->setColorRGB(1-(id-1), R, G, B);
}

void Piece::changerCaracteristiques(short r, short g, short b, ChainableLED *leds) {
    // On redefinit les caracteristiques des lumieres de cette piece
    R=r ; G=g; B=b;
    // Et on les applique a la lumiere
    leds->setColorRGB(1-(id-1), R, G, B);
}

void Piece::personneEntre(Personne* nouvellePersonne, ChainableLED *leds){
    // Lorsqu'une personne entre dans la piece, elle est ajoutee a la liste des personnes
    // presentes dans la piece
    listePersonnesPresentes.push_back(nouvellePersonne);
    nbPersonnesPresentes++;

    // Si la personne est seule la lumiere de la piece s'allume avec ses preference
    if (nbPersonnesPresentes == 1)
        allumerLumiere(nouvellePersonne->getR(), nouvellePersonne->getG(), nouvellePersonne->getB(), leds);

    // Si la personne n'est pas seule mais qu'elle est prioritaire,
    // la lumiere prend les caracteristiques de cette personne
    else if (nouvellePersonne->getEstAdmin()){
      changerCaracteristiques(nouvellePersonne->getR(), nouvellePersonne->getG(), nouvellePersonne->getB(), leds);
      personnePrioPresente = true;
    }


    // Si la personne n'est pas prioritaire et n'est pas un invite,
    // et s'il n'y a pas deja une personne prioritaire dans la piece,
    // on change les caracteriques de la lumiere avec les preferences de la premiere personne
    else if (!(nouvellePersonne->getEstVisiteur()) && !(personnePrioPresente)){
        itPersonnesPresentes = listePersonnesPresentes.begin();
        changerCaracteristiques((*itPersonnesPresentes)->getR(), (*itPersonnesPresentes)->getG(), (*itPersonnesPresentes)->getB(), leds);
        // GERER QUAND LA PREMIERE PERSONNE DE LA LISTE EST UN VISITEUR
    }
}

void Piece::personneSort(Personne* personneSortante, ChainableLED *leds){
    bool personneTrouvee = false;

    Serial.println(nbPersonnesPresentes);
    if (nbPersonnesPresentes != 0){
        // On regarde si cette personne etait la personne prioritaire
        // et si c'est le cas on remet le booleen a false
        if (personneSortante->getEstAdmin()) personnePrioPresente = false;

        // On efface ensuite la personne
        itPersonnesPresentes = listePersonnesPresentes.begin();

        while ((itPersonnesPresentes != listePersonnesPresentes.end()) && !personneTrouvee) {
            short testId = (*itPersonnesPresentes)->getId();

            if (testId == personneSortante->getId()) {
                itPersonnesPresentes = listePersonnesPresentes.erase(itPersonnesPresentes);
                nbPersonnesPresentes--;
                personneTrouvee = true;
            } else itPersonnesPresentes++;
        }

        if (personneTrouvee) {
            // Si la personne etait seule dans la piece on eteint la lumiere
            if (nbPersonnesPresentes == 0) { eteindreLumiere(leds); }

                // Sinon, s'il n'y a pas de personne prioritaire, on utilise la methode
                // personne entre avec la premiere personne de la liste
            else if (!personnePrioPresente) {

                // On met les caracteriques de la lumiere avec les preferences de la premiere personne de la liste
                itPersonnesPresentes = listePersonnesPresentes.begin();
                changerCaracteristiques((*itPersonnesPresentes)->getR(), (*itPersonnesPresentes)->getG(),
                                        (*itPersonnesPresentes)->getB(), leds);
                // GERER QUAND LA PREMIERE PERSONNE DE LA LISTE EST UN VISITEUR
            }
        }
    }
}

Numpad *Piece::getNumpad() {
    return numpad;
}

bool Piece::personnePresente(Personne * p){
    bool personneTrouvee = false; // Initialement, on a pas encore trouvé la personne avec le code correspondant

    // On commence la recherche au début de la liste de personnes.
    Piece::itPersonnesPresentes = Piece::listePersonnesPresentes.begin();
    Serial.println("On commence la recherche");

    Serial.println(nbPersonnesPresentes);

    // Si la pièce est vide, on sait d'office que la personne n'est pas présente. On ne commence pas la recherche.
    if (nbPersonnesPresentes == 0){
        Serial.println("La piece est vide, on retourne false");
        return false;
    }

    // Tant que l'on n'a pas trouvé la personne que l'on cherche et que l'on n'a pas parcouru toute la liste
    while (!(personneTrouvee) && (Piece::itPersonnesPresentes!=Piece::listePersonnesPresentes.end())){
        Personne * personnePointee = *itPersonnesPresentes;

        Serial.println("On rentre dans le while");
        // Si le code tapé sur le numpad correspond au code de la personne, alors
        if (*personnePointee == *p){
            Serial.println("On rentre dans le if");
            personneTrouvee=true; // On a trouvé la personne, donc on sort de la boucle
            break;
        }

        // Si le code ne correspond pas, on va s'intéresser à la personne suivante dans la liste
        Piece::itPersonnesPresentes++;
        if (Piece::itPersonnesPresentes == Piece::listePersonnesPresentes.end()){
            break;
        }
    }

    // Si aucune personne n'a le code tapé, alors on retourne une personne "vide" dont le nom est "NULL".
    return personneTrouvee;
}