#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#pragma once 
#include "grille.h"

class affichage { // permet de construire et de réutiliser notre affichage plus facilement 
    private : 
    int cellSize; // à mettre à jour lors de test total du programme
    int gridWidth  ;
    int gridHeight ;
    public:
    sf::RenderWindow* window; // permet d'éviter des doublons

    public : 
    affichage(Grille* grille_aff);
    void update_affichage(Grille* grille_aff); // met à jour l'affichage à chaque génération
    ~affichage();
};



