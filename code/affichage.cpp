#include "affichage.h"
#include "grille.h"

using namespace std ;


affichage :: affichage (Grille* grille_aff){ // on construit directement la fenetre de notre programme on en fais un pointeur pour pas la cloner
    cellSize = 2; // Mettre a jour lors de grand test
    gridWidth = grille_aff->grille[0].size();//On la dimmensionne a la bonne taille
    gridHeight = grille_aff->grille.size();
    window = new sf::RenderWindow(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life");//Création de notre fenetre

}   
affichage::~affichage() {//permet de supprimer la fenetre quand l'objet est détruits
    delete this->window;
} 

void affichage :: update_affichage(Grille* grille_aff){// Cette fonction mets a jour notre fenetre grace a la grille fournie 
        window->clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
        for (int x = 0; x < gridHeight; ++x) {
            for (int y = 0; y < gridWidth; ++y) {
                if (grille_aff->grille[x][y].type_cellule == 1) {//dessine une case blanche si ma case est vivante
                    cell.setPosition(y * cellSize, x * cellSize);
                    window->draw(cell); 
                }
            }
        }
        window->display();

    

}//met a jour la fenetre











