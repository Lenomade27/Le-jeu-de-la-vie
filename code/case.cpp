#include "case.h"

Case :: Case(int type){//1 Vivant 
    type_cellule = type ;

}
Case :: Case(){//0 Mort
    type_cellule = 0 ;
}

void Case::set_case(int type){
    this->type_cellule_past = this->type_cellule ;
    this->type_cellule = type ;

}



