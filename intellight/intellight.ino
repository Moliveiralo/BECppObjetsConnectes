/**
 * @project Intellight
 * @file intellight.ino
 * @brief fichier qui permet d'imoorter le programme sur l'arduino 
 * @authors OLIVEIRA LOPES Maxime
 *          NAJI Ines
 * @date 05/12/2023
 */
#include "Principal.h"

Principal monPrincipal;

void setup() {
  monPrincipal.setup();

}

void loop() {
  monPrincipal.loop(); 
}
