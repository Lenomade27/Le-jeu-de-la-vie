#include "grille.h"
#include "observer.h"
#include "gestion_fichier.h"
#include "jeux_de_la_vie.h"
#include "affichage.h"
#include <vector>


Grille :: Grille(string lien){
vector<vector<int>> grille_int = gestion_fichier::get_fichier_data(lien);
//note on pourrais optimiser 
grille.resize(grille_int.size());
// Redimensionner chaque ligne pour qu'elle ait le bon nombre de colonnes
for (int i = 0; i < grille_int.size(); ++i) {
    grille[i].resize(grille_int[i].size());  // Redimensionner chaque ligne
}

for (int i=0;i<grille_int.size();i++){
    for(int j=0; j<grille_int[j].size();j++){
         if (grille_int[i][j]==0) {
            Case a ;
            grille[i][j] = a ; 
         }
         else if (grille_int[i][j]==1) {
            Case b(1) ; 
            grille[i][j] = b ;
         }
         else if (grille_int[i][j]==2) {}//cellule vivante masi statique a voir 
         else if (grille_int[i][j]==3) {}//cellule morte mais statique a voir
    }
}

}
void Grille :: insertionCellule(int x, int y,Case const & cellule){

}
/*Case Grille :: getterCellule(int x, int y){

}*/
void Grille :: afficherGrille(){

}
