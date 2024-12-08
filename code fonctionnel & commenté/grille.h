#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include "case.h" 
#pragma once

class Grille {
public: // à revoir
    vector<vector<Case>> grille; 

public:
    // constructeur avec un lien de fichier en paramètre pour initialiser la grille
    Grille(string lien);
    // méthode qui teste si la grille est redondante
    static bool test_grille(Grille* grille_test);
    // méthode qui détermine les voisins d'une case
    static void set_voisin(Grille* grille_vois, int i, int j, bool mode);
    // méthode pour afficher la grille (optionnel/test)
    static void afficherGrille(Grille* grille_aff);
    // méthode qui met à jour la grille et modifie les cases nécessaires
    static void refresh_grille(Grille* grille_aff);
};
