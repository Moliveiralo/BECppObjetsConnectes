# **IntelLight**
NAJI INES et OLIVEIRA LOPES Maxime - 4AE TP SE 4

![image](https://github.com/Moliveiralo/BECppObjetsConnectes/assets/133717115/c3eb05d3-3a6d-4b9f-8f24-57b10fc4de82)


## Concept Initial
IntelLight est un nouveau concept de lumière intelligente. Chaque habitant (ou invité) du domicile peut disposer d'un tag NFC sur lui (sur son porteclé, dans sa poche, ...) permettant de l'identifier. Depuis une interface graphique (qui pourrait si on voulait pousser l'idée jusqu'au bout être déclinée en application android avec les lecteurs de puces NFC intégrés au téléphone), ce dernier peut définir ses préférences en termes de lumière: couleur, intensité, heures pendant lesquelles les lumières sont allumées...

Lorsqu'un habitant entre dans le domicile, les lumières de la pièce s'allument selon ses préférences et le suivent à chaque fois qu'il change de pièce. Les invités, par défaut, n'ont pas d'autorisation pour contrôler la lumière. L'administrateur, lui, est prioritaire sur tout le monde.

### Priorités
1. Utilisateur prioritaire (administrateur)
2. Habitant (un habitant avec un id plus faible sera prioritaire par rapport à un habitant avec un id plus élevé)
3. Visiteur **autorisé à modifier les paramètres de la lumière**

## Instructions
### **Comment compiler ?**
Ouvrir intellight.ino dans le dossier intellight. 
Compiler ce document.

### **Comment réaliser le montage ?**
1) Brancher les pinpads comme suit:
--> **NUMPAD 1**: D1 D2
--> **NUMPAD 2**: D5 D6
2) Brancher les leds comme suit:
--> **LEDS RGB en série**: D7 D8

Le montage global est résumé sur le schéma ci-dessous:

![image](https://github.com/Moliveiralo/IntelLight--OLIVEIRA-LOPES-Maxime--NAJI-Ines/assets/133717115/d423b9ec-6c02-49a0-b3fa-7fc06da8e15b)

Le code est prêt à être implémenté. 

### **Comment intéragir ?**
Une fois le code implémenté sur la carte, 3 modes vont s'enchainer à la suite. Il faut ouvrir le serial monitor où s'afficheront diverses informations telles que le mode en cours.
1) Séquence automatique d'entrée et sortie des personnes.
2) Chaque touche d'une NUMPAD correspond à une couleur de LED pour la pièce associée. La touche "#" permet de sortir de ce mode et de passer au mode suivant. 
3) Mode "libre" --> on rentre un code sur le NUMPAD pour faire rentrer une personne dans la pièce. Voici les codes : 
   - **** : mode disco, pour arrêter le mode disco on réappuie sur *
   - 1234 : habitant 1, couleur associée : violet
   - 1793 : habitant 2, couleur associée : jaune
   - 8520 : administrateur (habitant prioritaire), couleur associée : vert
   - 4785 : invité, couleur associée : blanc 

Ce dernier mode est dégradé : on ne peut pas faire sortir une personne d'une pièce.Si on change une personne de piece, une exception va donc se lever. 

Si on veut repartir au début (séquence automatique) il faut appuyer sur le bouton reset de la carte. 
