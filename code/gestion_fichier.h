#include "grille.h"


class gestion_fichier {
    protected:
    static int compteur_fichier ; // Parametre qui vas nous permetre de calculer le nombre de fichier crées et de les marqués 
    public:
    static void create_fichier(Grille* grille,string lien) ; //Méthode pour créer un fichier
    static vector<vector<int>> get_fichier_data(string lien);  //Méthode pour récuperer le contenue d'un fichier
    static string create_file();//renvoie le liens d'un dossier crée 

};

