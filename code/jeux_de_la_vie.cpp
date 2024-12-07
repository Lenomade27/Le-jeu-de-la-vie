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
//string lien_doss = gestion_fichier::create_file();
//gestion_fichier::create_fichier(grille_i,lien_doss) ;
//Grille :: afficherGrille(grille_i);
string lien_doss = gestion_fichier::create_file();
Grille :: afficherGrille(grille_i);
cout<<" "<<endl;
bool condition = true ;
while(this->iteration>0 && condition != 0){
    this->iteration --;
    observer :: fouille_grille(grille_i);
    Grille :: refresh_grille(grille_i);
    condition = Grille :: test_grille(grille_i);
    //cout<<condition<<endl;
    //Grille :: afficherGrille(grille_i);
    //cout<<this->iteration<<endl;
    if (condition != 0){
        gestion_fichier::create_fichier(grille_i,lien_doss) ;
    }
    
    
}
}
}



