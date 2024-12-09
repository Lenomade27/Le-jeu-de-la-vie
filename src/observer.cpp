#include "observer.h"
#include "grille.h"

using namespace std ;

/* cette méthode dans notre observateur permet d'abord de marquer les cases grâce à la méthode voisin(), 
   qui pourra changer de type, afin d'éviter de vérifier les cases inutiles qui ne changeront pas.
   lors d'un deuxième passage, elle prendra en compte uniquement les cases marquées pour appliquer la méthode set_voisin(). 
   la méthode voisin contient deux méthodes (pour plus d'informations, voir le fichier grille.cpp)
*/

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
