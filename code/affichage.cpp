#include "affichage.h"
#include "grille.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std ;
/*
const int cellSize = 10;
const int gridWidth = 80;
const int gridHeight = 80;

std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

void initializeGrid() {
    std::srand(std::time(0));
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;  // Randomly initialize cells as alive or dead
        }
    }
}

void renderGrid(sf::RenderWindow &window) {
    int x, y;
    
    window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (x = 0; x < gridWidth; ++x) {
        for (y = 0; y < gridHeight; ++y) {
            if (grid[x][y] == 1) {
                cell.setPosition(x * cellSize, y * cellSize);
                window.draw(cell);
            }
        }
    }
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");
    
    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        renderGrid(window);

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
*/

affichage :: affichage (Grille* grille_aff){ // on construit directement la fenetre de notre programme on en fais un pointeur pour pas la cloner
cellSize = 100;
gridWidth = grille_aff->grille[0].size();
gridHeight = grille_aff->grille.size();
window = new sf::RenderWindow(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");

}   
affichage::~affichage() {//permet de supprimer la fenetre quand l'objet est détruits
    delete this->window;
} 

void affichage :: update_affichage(Grille* grille_aff){
        window->clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
        for (int x = 0; x < gridHeight; ++x) {
            for (int y = 0; y < gridWidth; ++y) {
                if (grille_aff->grille[x][y].type_cellule == 1) {
                    cell.setPosition(y * cellSize, x * cellSize);
                    window->draw(cell);
                }
            }
        }
        window->display();

    

}//met a jour la window











