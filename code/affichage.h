#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#pragma once 
#include "grille.h"

class affichage { //Permet de construire et de réutiliser notre affichage plus simplement 
    public : 
    int cellSize; // Mettre a jour lors de grand test
    int gridWidth  ;
    int gridHeight ;
    sf::RenderWindow* window; // Evite les doublons

    public : 
    affichage(Grille* grille_aff);
    void update_affichage(Grille* grille_aff);//mets a jour l'affichage
    ~affichage();

};



