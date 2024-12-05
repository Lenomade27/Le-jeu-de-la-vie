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
Grille* grille_i = nullptr;
(void)grille_i;
grille_i = new Grille(this->lien_fichier);;
cout<<grille_i->grille[0][0].type_cellule<<endl;

}
else{
cout<<"Mode console"<<endl;
Grille* grille_i = nullptr;
(void)grille_i;
grille_i = new Grille(this->lien_fichier);
cout<<grille_i->grille[0][0].type_cellule<<endl;






}
}



