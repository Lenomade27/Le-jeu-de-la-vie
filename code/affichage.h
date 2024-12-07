#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "grille.h"
#pragma once 
class affichage {
    public : 
    int cellSize;
    int gridWidth  ;
    int gridHeight ;
    sf::RenderWindow* window;

    public : 
    affichage(Grille* grille_aff);
    void update_affichage(Grille* grille_aff);//mets a jour l'affichage
    ~affichage();

};



