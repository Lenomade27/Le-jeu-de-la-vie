#include "grille.h"


class gestion_fichier {
    private:
    static int compteur_fichier ; // Parametre qui vas nous permetre de calculer le nombre de fichier crées et de les marqués 
    public:
    static void create_fichier(Grille* grille,string lien,string lien_nom) ; //Méthode pour créer un fichier avec le nom de l'origine_out
    static vector<vector<int>> get_fichier_data(string lien);  //Méthode pour récuperer le contenue d'un fichier
    static string create_file();//renvoie le liens d'un dossier crée 

};

