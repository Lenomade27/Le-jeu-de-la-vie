/*#include "gestion_fichier.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
}

*/
