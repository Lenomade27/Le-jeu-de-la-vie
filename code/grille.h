#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <filesystem>
#include "case.h" 

#pragma once

class Grille {
public: // a revoir
    vector<vector<Case>> grille; 

public:
    // Constructeur avec un lien de fichier en paramètre pour initialiser la grille
    Grille(string lien);
    // Méthode qui va tester si la grille est redondante
    static bool test_grille(Grille* grille_test);
    // Méthode qui va regarder les voisin d'une case 
    static void set_voisin(Grille* grille_vois,int i ,int j,bool mode);
    // Méthode pour afficher la grille (optionnel/test)
    static void afficherGrille(Grille* grille_aff);
    // Méthode qui va mettre a jour notre grille et changer les cases qui doivent être changer
    static void refresh_grille(Grille* grille_aff);
};





