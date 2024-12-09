#include "case.h"

Case :: Case(int type){ // 1 = vivant 
    type_cellule = type ;

}
Case :: Case(){// 0 = mort 
    type_cellule = 0 ;
}

void Case::set_case(int type){ // setter qui nous permet d'enregistrer l'état antérieur d'une cellule
    this->type_cellule_past = this->type_cellule ;
    this->type_cellule = type ;

}



