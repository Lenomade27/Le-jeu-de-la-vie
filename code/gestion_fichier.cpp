#include "gestion_fichier.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <sys/stat.h>
using namespace std ;
/*
class FileManager {
private:
    std::string filename;

public:
    // Constructeur
    FileManager(const std::string& file) : filename(file) {}

    // Méthode pour écrire un tableau de tableaux dans un fichier
    void writeToFile(const std::vector<std::vector<int>>& data) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Impossible d'ouvrir le fichier pour l'écriture.");
        }

        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                file << row[i];
                if (i < row.size() - 1) {
                    file << ","; // Séparateur entre les éléments
                }
            }
            file << "\n"; // Fin de ligne pour chaque tableau
        }

        file.close();
    }

    // Méthode pour lire un tableau de tableaux depuis un fichier
    std::vector<std::vector<int>> readFromFile() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::ios_base::failure("Impossible d'ouvrir le fichier pour la lecture.");
        }

        std::vector<std::vector<int>> data;
        std::string line;

        while (std::getline(file, line)) {
            std::vector<int> row;
            size_t pos = 0;
            while ((pos = line.find(",")) != std::string::npos) {
                row.push_back(std::stoi(line.substr(0, pos)));
                line.erase(0, pos + 1);
            }
            if (!line.empty()) {
                row.push_back(std::stoi(line));
            }
            data.push_back(row);
        }

        file.close();
        return data;
    }
};

int main() {
    try {
        // Nom du fichier
        std::string filename = "data.txt";

        // Création d'un FileManager
        FileManager fileManager(filename);

        // Exemple de données à écrire
        std::vector<std::vector<int>> dataToWrite = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        // Écriture dans le fichier
        fileManager.writeToFile(dataToWrite);
        std::cout << "Données écrites dans le fichier avec succès." << std::endl;

        // Lecture depuis le fichier
        std::vector<std::vector<int>> dataRead = fileManager.readFromFile();

        // Affichage des données lues
        std::cout << "Données lues depuis le fichier :" << std::endl;
        for (const auto& row : dataRead) {
            for (const auto& val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}*/

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





