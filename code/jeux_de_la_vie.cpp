#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include <iostream>
using namespace std ;
#include <vector>


void jeux_de_la_vie::jeux_de_la_vie_regle(){
if(this->mode){
cout<<"Mode graphique"<<endl;
}
else{
cout<<"Mode console"<<endl;

}
}



