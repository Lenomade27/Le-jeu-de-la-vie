#include "gestion_fichier.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <sys/stat.h>
using namespace std ;



int gestion_fichier::compteur_fichier  = 0; 



vector<vector<int>> gestion_fichier :: get_fichier_data(string lien){
    ifstream fichier(lien);
    string ligne;
    vector<vector<int>> grille ; 
    while (getline(fichier, ligne)) { 
        istringstream stream(ligne);
        vector<int> ligneVecteur;

        int valeur;
        while (stream >> valeur) { 
            ligneVecteur.push_back(valeur);
        }
        
        grille.push_back(ligneVecteur);
    }

    fichier.close();
    return grille ;

}
string gestion_fichier :: create_file(){
    
    cout<<"Choissez le chemin pour stocker l'historique : "<<endl;
    string path ;
    cin>>path ; 
    if (mkdir(path.c_str(), 0777) == 0) {  // 0777 = Permissions complètes
        cout << "Répertoire créé avec succès : " << path << endl;
        return path ;
    } else {
        perror("Erreur lors de la création du répertoire");
        return 0; // Veut retourner quelque chose mais vue que c'est une erreur je return une erreur
    }

}

void gestion_fichier :: create_fichier(Grille* grille_pointeur,string lien) {
    gestion_fichier::compteur_fichier += 1 ; 
    ofstream fichier(lien +"/" +"fichier"+to_string(compteur_fichier)+".txt");
    if (fichier.is_open()) {
        for(int i=0;i<grille_pointeur->grille.size();i++){
            string ligne = "";
        for(int j=0;j<grille_pointeur->grille[i].size();j++){
            ligne += to_string(grille_pointeur->grille[i][j].type_cellule)+" ";
        }
        fichier<<ligne<<endl;
        }
        
        fichier.close();
        cout << "Fichier créé avec succès : " << lien + "/" +"fichier"+to_string(compteur_fichier)+".txt" << endl;
    } else {
        cout << "Erreur lors de la création du fichier : " << lien + "/" +"fichier"+to_string(compteur_fichier)+".txt" << endl;

        }
}


