#include "grille.h"
#include "observer.h"
#include "gestion_fichier.h"
#include "jeux_de_la_vie.h"
#include "affichage.h"



Grille :: Grille(string lien){
    vector<vector<int>> grille_int = gestion_fichier::get_fichier_data(lien);//récuperation de la grille dans notre fichier
    grille.resize(grille_int.size());
    // Redimensionner chaque ligne pour qu'elle ait le bon nombre de colonnes
    for (int i = 0; i < grille_int.size(); ++i) {
        grille[i].resize(grille_int[i].size());  // Redimensionner chaque ligne
    }

    for (int i=0;i<grille_int.size();i++){ //Insertion des cases dans notre grille vivante ou morte
        for(int j=0; j<grille_int[j].size();j++){
            if (grille_int[i][j]==0) {
                Case a ;
                grille[i][j] = a ; 
            }
            else if (grille_int[i][j]==1) {
                Case b(1) ; 
                grille[i][j] = b ;
            }
        }
    }

}



void Grille :: afficherGrille(Grille* grille_aff){ // test d'affichage
    for(int i=0;i<grille_aff->grille.size();i++){
            for(int j=0;j<grille_aff->grille[i].size();j++){
                cout << grille_aff->grille[i][j].type_cellule<<" " ;  // a changer test actuel en fonction du besoins
            }
            cout << endl;
    }


}

bool Grille :: test_grille(Grille* grille_test){ // Va tester notre grille pour éviter les répetition
    for(int i=0;i<grille_test->grille.size();i++){
            for(int j=0;j<grille_test->grille[i].size();j++){ //Compare type_cellule et type_cellule_past pour voir si ya du changement entre le présent et l'actuel si oui pour une cellule alors sa return true donc si se code finis c'est qu'aucune case na changer 
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
    if(mode){//set marqueur : Le marqueur permet d'éviter de voir les cases qui ne changerons pas donc celle avec aucune cellule vivante dans leurs voisins (prend en compte les coins et les côté)
        grille_vois->grille[i][j].ping = true;//Marque toute les cellule autour d'une case vivante et elle même
        if(i+1<taille_ligne && j-1>0)grille_vois->grille[i+1][j-1].ping = true; // +1 et -1 permet d'éviter de sortir des limites
        if(i+1<taille_ligne && j+1 < taille_colone )grille_vois->grille[i+1][j+1].ping = true;
        if(i-1>0 && j>0)grille_vois->grille[i-1][j-1].ping = true;
        if(i-1>0 && j < taille_colone)grille_vois->grille[i-1][j+1].ping = true;
        if(i-1>0)grille_vois->grille[i-1][j].ping = true;
        if(j-1>0)grille_vois->grille[i][j-1].ping = true;
        if(i+1<taille_ligne)grille_vois->grille[i+1][j].ping = true;
        if(j+1<taille_colone)grille_vois->grille[i][j+1].ping = true;
    }
    else {//set compteur : compte les cellules vivantes au alentour de la cellule (prend en compte les coins et les côté) 
        int compt = 0;
        if (i + 1 < taille_ligne && j - 1 >= 0 && grille_vois->grille[i + 1][j - 1].type_cellule == 1) compt++;// +1 et -1 permet d'éviter de sortir des limites
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



void Grille :: refresh_grille(Grille* grille_ref){// Mets a jour notre grille pour changer l'états des cellules en fonction des règles 
for(int i=0;i<grille_ref->grille.size();i++){//On fouille dans notre liste et on ne regarde que les cellules marquer
        for(int j=0;j<grille_ref->grille[i].size();j++){
            if(grille_ref->grille[i][j].ping == true){
                grille_ref->grille[i][j].ping = false  ; // Mets a jour leur marqueur puisque notre grille ne change pas
                if(grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 0)//Une cellule morte possédant exactement trois voisines vivantes devient vivante.
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0 ;
                }
                else if (grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 1)//Une cellule vivante possédant trois voisines vivantes reste vivante
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0 ;
                }
                else if (grille_ref->grille[i][j].compteur == 2 && grille_ref->grille[i][j].type_cellule == 1)//Une cellule vivante possédant deux voisines vivantes reste vivante
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0 ;
                }
                else {
                    grille_ref->grille[i][j].set_case(0); //Ne réponds a aucun critère alors elle meurt
                    grille_ref->grille[i][j].compteur = 0 ;
                }
            }
        }
    }


}
