#include "affichage.h"
#include "grille.h"
using namespace std ;

affichage :: affichage (Grille* grille_aff){ // on construit directement la fenêtre de notre programme on en fait un pointeur pour ne pas la cloner
    cellSize = 10; 
    gridWidth = grille_aff->grille[0].size(); // la grille est ainsi dimensionné à la bonne taille
    gridHeight = grille_aff->grille.size();
    window = new sf::RenderWindow(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Game of Life"); //Création de notre fenetre du jeu de la vie
}   

affichage::~affichage() { // permet de supprimer la fenêtre quand l'objet est détruit // à voir
    delete this->window;
} 

void affichage :: update_affichage(Grille* grille_aff){// Cette fonction met à jour notre fenêtre grace à la grille fournie 
        window->clear();
        sf::RectangleShape cell(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
        for (int x = 0; x < gridHeight; ++x) {
            for (int y = 0; y < gridWidth; ++y) {
                if (grille_aff->grille[x][y].type_cellule == 1) { //dessine une case blanche si la case est en état vivant
                    cell.setPosition(y * cellSize, x * cellSize);
                    window->draw(cell); 
                }
            }
        }
        window->display(); // met à jour la fenêtre


    

}










