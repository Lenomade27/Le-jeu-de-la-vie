#include <vector>
#include <string>
#include "case.h" 
using namespace std ;
#pragma once


class Grille {
private:
    vector<vector<Case>> grille; 

public:
    // Constructeur par défaut
    Grille();

    // Constructeur avec un fichier en paramètre pour initialiser la grille
    Grille(const string& fichier);

    // Méthode pour insérer une cellule dans la grille
    void insertionCellule(int x, int y,Case const & cellule);

    // Méthode pour obtenir une cellule de la grille
    Case getterCellule(int x, int y) const;

    // Méthode pour afficher la grille (optionnel)
    void afficherGrille() const;
};





