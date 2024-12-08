#include "gestion_fichier.h"


int gestion_fichier::compteur_fichier  = 0; // Compteur initilaiser a 0 a chaque debut de boucle


// Note le fichier a deja été  tester dans la main pas besoins d'autre test
vector<vector<int>> gestion_fichier :: get_fichier_data(string lien){//Récupération des donnée d'un fichier
    ifstream fichier(lien); // Ouvre le dossier en lecture
    string ligne;
    vector<vector<int>> grille ; 
    while (getline(fichier, ligne)) { // On va récuperer ligne par ligne les donnée 
        istringstream stream(ligne); // Evite les espaces
        vector<int> ligneVecteur;

        int valeur;
        while (stream >> valeur) { 
            ligneVecteur.push_back(valeur);// impact tout dans ligneVecteur 
        }
        
        grille.push_back(ligneVecteur);// Puis ligne par ligne on impact dans notre grille
    }

    fichier.close();//On ferme le fichier
    return grille ;

}

string gestion_fichier :: create_file(){
    
    cout<<"Choissez le chemin pour stocker l'historique : "<<endl; // On demande a notre utilisateur ou mettre son dossier 
    string path ; // 
    cin>>path ; 
    if (mkdir(path.c_str(), 0777) == 0) {  // 0777 = Permissions complètes Nous permets d'avoir les droits pour crée un dossier
        cout << "Répertoire créé avec succès : " << path << endl;
        return path ; // Message de vérification
    } else {
        perror("Erreur lors de la création du répertoire");
        return 0; // Veut retourner quelque chose mais vue que c'est une erreur je return une erreur
    }

}

void gestion_fichier :: create_fichier(Grille* grille_pointeur,string lien,string lien_nom) { // Méthode permettant de crée un fichier
    gestion_fichier::compteur_fichier += 1 ; // Compteur

    filesystem::path path(lien_nom); // Récupère le nom de notre fichier grace au lien
    string nom = path.stem().string();

    ofstream fichier(lien +"/" +nom+"_out"+to_string(compteur_fichier)+".txt");// A modiifer 
    if (fichier.is_open()) { // test si le fichier s'ouvre
        for(int i=0;i<grille_pointeur->grille.size();i++){ // écrie dans notre fichier
            string ligne = ""; // met des espace entre les 1 0
            for(int j=0;j<grille_pointeur->grille[i].size();j++){
                ligne += to_string(grille_pointeur->grille[i][j].type_cellule)+" ";
            }
            fichier<<ligne<<endl; // écrie ligne par ligne
        }
        
        fichier.close();
        cout << "Fichier créé avec succès : " << lien + "/" +nom+"_out"+to_string(compteur_fichier)+".txt" << endl;// a modif
    } //Test retour si erreur coter clients
    else {
        cout << "Erreur lors de la création du fichier : " << lien + "/" +nom+"_out"+to_string(compteur_fichier)+".txt" << endl;

        }
}


