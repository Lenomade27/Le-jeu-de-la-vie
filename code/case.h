#include <iostream>
using namespace std ;

class Case {
    public:
    int type_cellule; // type de la cellule actuelle
    int type_cellule_past = 0; // 0 car a la premiere itération les cases n'existe pas
    bool ping = false;  // permet de marqué une case
    int compteur = 0; // Compte le nombre de cases vivante au alentour de celle ci
    public:
    Case(); // Constructeur case morte 
    Case(int type); // Constructeur case vivante
    void set_case(int type); // setter

};

