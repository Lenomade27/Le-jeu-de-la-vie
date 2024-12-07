//! Test unitaire pour la création d'une matrice à partir d'un fichier.txt

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

int gridWidth = 0;
int gridHeight = 0;
int maDonnee;
int monInt;
bool monBooleen;
int compteur = 0;
int compteurl = 0;
bool select1 = true;

int main(){
  std::ifstream fichier_source("init.txt"); // emplacement fichier pas nom
  std::string ligne;
  std::getline(fichier_source, ligne);
  std::istringstream iss(ligne);
  for (int i=0; i<2;i++){
    iss >> monInt;
    switch(compteur){
      case 0: gridWidth = monInt;break;
      case 1: gridHeight = monInt;break;
    }
    compteur++;
    }

  std::vector<std::vector<int>> fGrid(gridWidth, std::vector<int>(gridHeight));
  std::cout<<"La grille aura une largeur de "<< gridWidth <<" et une longueur de "<< gridHeight<< std::endl;

  while (std::getline(fichier_source, ligne)){
    std::istringstream iss(ligne);
    std::cout<<ligne<<std::endl;
      for (int x=0; x<gridWidth ; x++){
        iss >> monBooleen;
        fGrid[x][compteurl] = monBooleen;
        std::cout<<"coordonnées de la matrice (" << x << ";"<< compteurl << "): valeur = "<< fGrid[x][compteurl] << std::endl;
      } 
    compteurl++;
  }

  return 0;
}
