#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <sys/stat.h>
using namespace std ;
#include "grille.h"


class gestion_fichier {
    protected:
    static int compteur_fichier ; 
    public:
    static void create_fichier(Grille* grille,string lien) ; //creer le fichier 
    static vector<vector<int>> get_fichier_data(string lien); 
    static string create_file();//renvoie le liens du dossier crée 

};

