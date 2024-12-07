#include "grille.h"
#include "observer.h"
#include "gestion_fichier.h"
#include "jeux_de_la_vie.h"
#include "affichage.h"
#include <vector>
using namespace std ; 


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



void Grille :: afficherGrille(Grille* grille_aff){
for(int i=0;i<grille_aff->grille.size();i++){
        for(int j=0;j<grille_aff->grille[i].size();j++){
            cout << grille_aff->grille[i][j].type_cellule<<" " ;  // a changer test actuel
        }
        cout << endl;
    }


}

bool Grille :: test_grille(Grille* grille_test){
for(int i=0;i<grille_test->grille.size();i++){
        for(int j=0;j<grille_test->grille[i].size();j++){
            if (grille_test->grille[i][j].type_cellule != grille_test->grille[i][j].type_cellule_past) {
                return true ; 
            }
        }
        
    }
return false ;
}

void Grille :: set_voisin(Grille* grille_vois,int i ,int j,bool mode){//true marque les cases que l'on devra repasser et false va compter les case vivante autour
int taille_ligne =  grille_vois->grille.size();
int taille_colone =  grille_vois->grille[i].size();
if(mode){//set marqueur
grille_vois->grille[i][j].ping = true;
if(i+1<taille_ligne && j-1>0)grille_vois->grille[i+1][j-1].ping = true;
if(i+1<taille_ligne && j+1 < taille_colone )grille_vois->grille[i+1][j+1].ping = true;
if(i-1>0 && j>0)grille_vois->grille[i-1][j-1].ping = true;
if(i-1>0 && j < taille_colone)grille_vois->grille[i-1][j+1].ping = true;
if(i-1>0)grille_vois->grille[i-1][j].ping = true;
if(j-1>0)grille_vois->grille[i][j-1].ping = true;
if(i+1<taille_ligne)grille_vois->grille[i+1][j].ping = true;
if(j+1<taille_colone)grille_vois->grille[i][j+1].ping = true;
}
else {//set compteur
int compt = 0;
if (i + 1 < taille_ligne && j - 1 >= 0 && grille_vois->grille[i + 1][j - 1].type_cellule == 1) compt++;
if (i + 1 < taille_ligne && j + 1 < taille_colone && grille_vois->grille[i + 1][j + 1].type_cellule == 1) compt++;
if (i - 1 >= 0 && j - 1 >= 0 && grille_vois->grille[i - 1][j - 1].type_cellule == 1) compt++;
if (i - 1 >= 0 && j + 1 < taille_colone && grille_vois->grille[i - 1][j + 1].type_cellule == 1) compt++;
if (i - 1 >= 0 && grille_vois->grille[i - 1][j].type_cellule == 1) compt++;
if (j - 1 >= 0 && grille_vois->grille[i][j - 1].type_cellule == 1) compt++;
if (i + 1 < taille_ligne && grille_vois->grille[i + 1][j].type_cellule == 1) compt++;
if (j + 1 < taille_colone && grille_vois->grille[i][j + 1].type_cellule == 1) compt++;

grille_vois->grille[i][j].compteur = compt ; 
}
}

void Grille :: refresh_grille(Grille* grille_ref){
for(int i=0;i<grille_ref->grille.size();i++){
        for(int j=0;j<grille_ref->grille[i].size();j++){
            if(grille_ref->grille[i][j].ping == true){
                grille_ref->grille[i][j].ping = false  ;
                if(grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 0){
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0 ;
                }
                else if (grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 1)
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0 ;
                }
                else if (grille_ref->grille[i][j].compteur == 2 && grille_ref->grille[i][j].type_cellule == 1)
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0 ;
                }
                else {
                    grille_ref->grille[i][j].set_case(0);
                    grille_ref->grille[i][j].compteur = 0 ;
                }
            }
        }
    }


}
