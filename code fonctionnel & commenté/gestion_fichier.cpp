#include "gestion_fichier.h"
int gestion_fichier::compteur_fichier  = 0; // le compteur est initialisé à 0 au début de chaque boucle

// note : Le fichier a déjà été testé dans la fonction main, il n'est donc pas nécessaire de refaire d'autres tests
vector<vector<int>> gestion_fichier::get_fichier_data(string lien) { // récupération des données d'un fichier
    ifstream fichier(lien); // ouvre le fichier en mode lecture
    string ligne;
    vector<vector<int>> grille; 
    while (getline(fichier, ligne)) { // récupère ligne par ligne les données
        istringstream stream(ligne); // permet de gérer les espaces
        vector<int> ligneVecteur;

        int valeur;
        while (stream >> valeur) { 
            ligneVecteur.push_back(valeur); // Ajoute chaque valeur dans le vecteur ligneVecteur
        }
        
        grille.push_back(ligneVecteur); // Ajoute chaque ligne dans la grille
    }

    fichier.close(); // Ferme le fichier après la lecture
    return grille; // Retourne la grille de données
}

string gestion_fichier::create_file() {
    cout << "Veuillez choisir le chemin pour stocker l'historique : " << endl; // Demande à l'utilisateur où enregistrer le dossier 
    string path; 
    cin >> path; 
    if (mkdir(path.c_str(), 0777) == 0) {  // 0777 = Permissions complètes, permet de créer un dossier avec tous les droits
        cout << "Répertoire créé avec succès : " << path << endl;
        return path; // Retourne le chemin du répertoire créé
    } else {
        perror("Erreur lors de la création du répertoire");
        return 0; // En cas d'erreur, retourne une valeur d'erreur
    }
}

void gestion_fichier::create_fichier(Grille* grille_pointeur, string lien) { // Méthode permettant de créer un fichier
    gestion_fichier::compteur_fichier += 1; // Incrémentation du compteur de fichiers
    ofstream fichier(lien + "/" + "<nom_du_fichier_dentree>_out" + to_string(compteur_fichier) + ".txt"); // Création du fichier avec un nom unique
    if (fichier.is_open()) { // Vérifie si le fichier a été ouvert correctement
        for (int i = 0; i < grille_pointeur->grille.size(); i++) { // Écriture ligne par ligne dans le fichier
            string ligne = ""; // Initialise une chaîne vide pour chaque ligne
            for (int j = 0; j < grille_pointeur->grille[i].size(); j++) {
                ligne += to_string(grille_pointeur->grille[i][j].type_cellule) + " "; // Ajoute les valeurs séparées par des espaces
            }
            fichier << ligne << endl; // Écrit la ligne dans le fichier
        }
        
        fichier.close();
        cout << "Fichier créé avec succès : " << lien + "/" + "<nom_du_fichier_dentree>_out" + to_string(compteur_fichier) + ".txt" << endl; // Message de confirmation
    } else {
        cout << "Erreur lors de la création du fichier : " << lien + "/" + "<nom_du_fichier_dentree>_out" + to_string(compteur_fichier) + ".txt" << endl; // Message d'erreur
    }
}
