#include <iostream>
using namespace std ;

class Case {
    public:
        int type_cellule; // type de la cellule actuelle
        int type_cellule_past = 0; // type précédent de la cellule
        bool ping = false;  // permet de marquer une case
        int compteur = 0; // compte le nombre de cases vivantes aux alentours de celle-ci
        Case(); // constructeur case morte 
        Case(int type); // constructeur case vivante
        void set_case(int type); 

};

