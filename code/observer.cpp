#include "observer.h"
#include "grille.h"

using namespace std ;

/*Cette Méthode dans notre observateur vas nous permettre de d'abord marquer les cases grace a la Méthode voisin() qui pourons changer de type
et ainsi éviter de regarder les cases inutile qui ne changerons pas.
Puis lors d'un deuxieme passage elle va ainsi prendre en compte que les cases marquer pour utiliser sur celle ci la Méthode set_voisin() 
La Méthode voisin contient deux Méthode(Allez voir le fichier grille.cpp pour plus d'information)
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





