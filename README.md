# **IntelLight**
NAJI INES et OLIVEIRA LOPES Maxime - 4AE TP SE 4

![image](https://github.com/Moliveiralo/BECppObjetsConnectes/assets/133717115/c3eb05d3-3a6d-4b9f-8f24-57b10fc4de82)


## Concept:
IntelLight est un nouveau concept de lumière intelligente. Chaque habitant (ou invité) du domicile peut disposer d'un tag NFC sur lui (sur son porteclé, dans sa poche, ...) permettant de l'identifier. Depuis une interface graphique (qui pourrait si on voulait pousser l'idée jusqu'au bout être déclinée en application android avec les lecteurs de puces NFC intégrés au téléphone), ce dernier peut définir ses préférences en termes de lumière: couleur, intensité, heures pendant lesquelles les lumières sont allumées...

Lorsqu'un habitant entre dans le domicile, les lumières de la pièce s'allument selon ses préférences et le suivent à chaque fois qu'il change de pièce. Les invités, par défaut, n'ont pas d'autorisation pour contrôler la lumière. L'administrateur, lui, est prioritaire sur tout le monde.

### Priorités:
1. Utilisateur prioritaire (administrateur)
2. Habitant (un habitant avec un id plus faible sera prioritaire par rapport à un habitant avec un id plus élevé)
3. Visiteur **autorisé à modifier les paramètres de la lumière**

## Instructions
### **Comment compiler ?**
Ouvrir intellight.ino dans le dossier intellight. 
Compiler ce document.

### **Comment exécuter ?**
1) Brancher les pinpads comme suit:
--> **NUMPAD 1**: D1 D2
--> **NUMPAD 2**: D5 D6
2) Brancher les leds comme suit:
--> **LEDS RGB en série**: D7 D8

![image](https://github.com/Moliveiralo/BECppObjetsConnectes/assets/133717115/3703471c-14ca-402b-867a-5df25019ad17)

Le code est prêt à être implémenté. 

### **Comment intéragir ?**
Une fois le code implémenté sur la carte, chosir le mode de test :
1) appuyer sur la touche 1 du NUMPAD : séquence automatique d'entrée et sortie des personnes 
2) appuyer sur la touche 2 du NUMPAD : 
3) appauyer sur la touche 3 du NUMPAD : 

Si on veut changer de mode, il faut faut appuyer sur le bouton de reset de la carte Arduino. 


## Classes:
blabla

## Dépendances:
Aucune pour le moment.
