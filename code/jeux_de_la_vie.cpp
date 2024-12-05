#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include <iostream>
#include "gestion_fichier.h"
using namespace std ;
#include <vector>


void jeux_de_la_vie::jeux_de_la_vie_regle(){
if(this->mode){
cout<<"Mode graphique"<<endl;
//Grille* grille_i = nullptr;
//grille_i = new Grille(this->lien_fichier);;//penser a l'utiliser sinon bug
//cout<<grille_i->grille[0][1].type_cellule<<endl;

}
else{
cout<<"Mode console"<<endl;
Grille* grille_i = nullptr;
grille_i = new Grille(this->lien_fichier);//penser a l'utiliser sinon bug
//cout<<grille_i->grille[0][2].type_cellule<<endl;
string lien_doss = gestion_fichier::create_file();
gestion_fichier::create_fichier(grille_i,lien_doss) ;



}
}



