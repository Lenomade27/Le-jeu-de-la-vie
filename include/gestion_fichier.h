#include "grille.h"

class gestion_fichier {
    private:
        static int compteur_fichier ; // paramètre qui permet de calculer le nombre de fichiers créés et de les marquer
    public:
        static void create_fichier(Grille* grille,string lien,string lien_nom) ; //méthode pour créer un fichier
        static vector<vector<int>> get_fichier_data(string lien);  // méthode pour récupérer le contenu d'un fichier
        static string create_file(); // renvoie le lien d'un dossier créé
};
