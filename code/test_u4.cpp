//! Test unitaire pour afficher une grille à partir d'un fichier d'initialisation

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

const int cellSize = 10;
int gridWidth = 0;
int gridHeight = 0;
int maDonnee;
int monInt;
bool monBooleen;
int compteur = 0;
int compteurl = 0;
bool select1 = true;

std::vector<std::vector<int>> fGrid;

void initializeDim() {
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
  fGrid = std::vector<std::vector<int>>(gridWidth, std::vector<int>(gridHeight));
  std::cout<<"La grille aura une largeur de "<< gridWidth <<" et une longueur de "<< gridHeight<< std::endl;
}

void initializeGrid() {
  std::ifstream fichier_source("init.txt"); // emplacement fichier pas nom
  std::string ligne;
  std::getline(fichier_source, ligne);
  std::istringstream iss(ligne);
  while (std::getline(fichier_source, ligne)){
    std::istringstream iss(ligne);
      for (int x=0; x<gridWidth ; x++){
        iss >> monBooleen;
        fGrid[x][compteurl] = monBooleen;
      } 
    compteurl++;
  }
}

void renderGrid(sf::RenderWindow &window) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (fGrid[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

int main() {
    initializeDim();

    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    
    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window);

        sf::sleep(sf::milliseconds(16));
    }

    return 0;
}
