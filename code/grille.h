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
    void set_sum_life(int x,int y);
    static bool test_grille(Grille* grille_test);
    static void set_voisin(Grille* grille_vois,int i ,int j,bool mode);
    // Méthode pour afficher la grille (optionnel/test)
    static void afficherGrille(Grille* grille_aff);

    static void refresh_grille(Grille* grille_aff);
};





