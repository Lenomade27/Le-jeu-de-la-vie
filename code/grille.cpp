#include "grille.h"
#include "observer.h"
#include "gestion_fichier.h"
#include "jeux_de_la_vie.h"
#include "affichage.h"
#include <vector>


Grille :: Grille(string lien){
vector<vector<int>> grille_int = gestion_fichier::get_fichier_data(lien);
for (int i=0;i<grille_int.size();i++){
    for(int j=0; j<grille_int[j].size();j++){
        cout << grille_int[i][j] << " " ; 
    }
    cout<<endl;
}

}
void Grille :: insertionCellule(int x, int y,Case const & cellule){

}
/*Case Grille :: getterCellule(int x, int y){

}*/
void Grille :: afficherGrille(){

}
