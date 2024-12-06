#include "observer.h"
#include "grille.h"
#include <vector>
#include <string>
using namespace std ;



void observer :: fouille_grille(Grille* grille_obs){
for(int i=0;i<grille_obs->grille.size();i++){
        for(int j=0;j<grille_obs->grille[i].size();j++){
            if (grille_obs->grille[i][j].type_cellule==1){
                Grille :: set_voisin(grille_obs,i ,j,true);
            }
        }
    }
    for(int i=0;i<grille_obs->grille.size();i++){
        for(int j=0;j<grille_obs->grille[i].size();j++){
            if (grille_obs->grille[i][j].ping == true){
                Grille :: set_voisin(grille_obs,i ,j,false);
            }
        }
    }
}





