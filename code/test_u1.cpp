//! Test unitaire pour la lecture d'une matrice

#include <iostream>
#include <vector>

const int gridWidth = 3;
const int gridHeight = 4;

std::vector<std::vector<int>> fGrid = {
  {1, 0, 1, 0},
  {0, 1, 0, 1},
  {1, 1, 0, 0}
};

int main(){
  for ( int x=0; x<gridWidth ; ++x ){ //permet de parcourir chaque case
    for (int y=0; y<gridHeight ; ++y){
    std::cout<<"donnée de coordonnées (" << x << ";"<< y << "): "<< fGrid[x][y] << std::endl;
    }
  }

  return 0;
}

/*

*/
