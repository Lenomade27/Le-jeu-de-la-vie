#include <vector>
#include <string>
#include "case.h" 
using namespace std ;
#pragma once


class Grille {
public:
    vector<vector<Case>> grille; 

public:
    // Constructeur avec un lien de fichier en paramètre pour initialiser la grille
    Grille(string lien);

    // Méthode pour insérer une cellule dans la grille
    void insertionCellule(int x, int y,Case const & cellule);

    // Méthode pour obtenir une cellule de la grille
    Case getterCellule(int x, int y);

    // Méthode pour afficher la grille (optionnel)
    void afficherGrille();
};





