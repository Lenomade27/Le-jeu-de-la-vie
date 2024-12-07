//! Test unitaire pour la lecture des données d'un fichier.txt

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

int gridWidth;
int gridHeight;
int maDonnee;
int compteur = 0;

int main(){
  std::ifstream fichier_source("init.txt"); // emplacement fichier pas nom
  std::string ligne;
  while (std::getline(fichier_source, ligne)){
    std::istringstream iss(ligne);
    while (iss >> maDonnee){
      std::cout<< "Donnee "<< ++compteur <<" = "<<maDonnee<<std::endl; 
      switch(compteur){
        case 1: gridWidth = maDonnee ;break;
        case 2: gridHeight = maDonnee;break;
        default: std::cout<<"Cette donnée est un booléen de la matrice"<<std::endl; break; 
      }
    }
  }
  std::vector<std::vector<int>> fGrid(gridWidth, std::vector<int>(gridHeight));
  std::cout<<"La grille aura une largeur de "<< gridWidth <<" et une longueur de "<< gridHeight<< std::endl;

  return 0;
}

/*

*/
