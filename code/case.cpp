#include "case.h"

Case :: Case(int type){
type_cellule = type ;  
}
Case :: Case(){
type_cellule = 0 ;
type_cellule = 0 ;   
}

void Case::set_case(int type){
    this->type_cellule_past = this->type_cellule ;
    this->type_cellule = type ;

}



