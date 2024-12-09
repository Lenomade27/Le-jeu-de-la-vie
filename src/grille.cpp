#include "grille.h"
#include "observer.h"
#include "gestion_fichier.h"
#include "jeux_de_la_vie.h"
#include "affichage.h"

Grille::Grille(string lien) {
    vector<vector<int>> grille_int = gestion_fichier::get_fichier_data(lien); // récupération de la grille depuis le fichier
    grille.resize(grille_int.size());
    // redimensionnement de chaque ligne pour qu'elle ait le bon nombre de colonnes
    for (int i = 0; i < grille_int.size(); ++i) {
        grille[i].resize(grille_int[i].size());  // redimensionner chaque ligne
    }

    for (int i = 0; i < grille_int.size(); i++) { // insertion des cases dans la grille vivante ou morte
        for (int j = 0; j < grille_int[i].size(); j++) {
            if (grille_int[i][j] == 0) {
                Case a;
                grille[i][j] = a;
            }
            else if (grille_int[i][j] == 1) {
                Case b(1);
                grille[i][j] = b;
            }
        }
    }
}

void Grille::afficherGrille(Grille* grille_aff) { // test d'affichage
    for (int i = 0; i < grille_aff->grille.size(); i++) {
        for (int j = 0; j < grille_aff->grille[i].size(); j++) {
            cout << grille_aff->grille[i][j].type_cellule << " "; // affichage du type de cellule
        }
        cout << endl;
    }
}

bool Grille::test_grille(Grille* grille_test) { // teste si la grille a changé pour éviter les répétitions
    for (int i = 0; i < grille_test->grille.size(); i++) {
        for (int j = 0; j < grille_test->grille[i].size(); j++) { 
            // compare type_cellule et type_cellule_past pour voir si des changements ont eu lieu
            if (grille_test->grille[i][j].type_cellule != grille_test->grille[i][j].type_cellule_past) {
                return true; 
            }
        }
    }
    return false;
}

void Grille::set_voisin(Grille* grille_vois, int i, int j, bool mode) { 
    int taille_ligne = grille_vois->grille.size();
    int taille_colone = grille_vois->grille[i].size();
    
    if (mode) { // mode marqueur : permet d'éviter de traiter les cases qui ne changeront pas (cases sans cellules vivantes dans leurs voisins)
        grille_vois->grille[i][j].ping = true; // marque la cellule elle-même
        if (i + 1 < taille_ligne && j - 1 >= 0) grille_vois->grille[i + 1][j - 1].ping = true; // +1 et -1 évitent de sortir des limites
        if (i + 1 < taille_ligne && j + 1 < taille_colone) grille_vois->grille[i + 1][j + 1].ping = true;
        if (i - 1 >= 0 && j - 1 >= 0) grille_vois->grille[i - 1][j - 1].ping = true;
        if (i - 1 >= 0 && j < taille_colone) grille_vois->grille[i - 1][j + 1].ping = true;
        if (i - 1 >= 0) grille_vois->grille[i - 1][j].ping = true;
        if (j - 1 >= 0) grille_vois->grille[i][j - 1].ping = true;
        if (i + 1 < taille_ligne) grille_vois->grille[i + 1][j].ping = true;
        if (j + 1 < taille_colone) grille_vois->grille[i][j + 1].ping = true;
    }
    else { // mode compteur : compte les cellules vivantes autour de la cellule
        int compt = 0;
        if (i + 1 < taille_ligne && j - 1 >= 0 && grille_vois->grille[i + 1][j - 1].type_cellule == 1) compt++; // +1 et -1 évitent de sortir des limites
        if (i + 1 < taille_ligne && j + 1 < taille_colone && grille_vois->grille[i + 1][j + 1].type_cellule == 1) compt++;
        if (i - 1 >= 0 && j - 1 >= 0 && grille_vois->grille[i - 1][j - 1].type_cellule == 1) compt++;
        if (i - 1 >= 0 && j + 1 < taille_colone && grille_vois->grille[i - 1][j + 1].type_cellule == 1) compt++;
        if (i - 1 >= 0 && grille_vois->grille[i - 1][j].type_cellule == 1) compt++;
        if (j - 1 >= 0 && grille_vois->grille[i][j - 1].type_cellule == 1) compt++;
        if (i + 1 < taille_ligne && grille_vois->grille[i + 1][j].type_cellule == 1) compt++;
        if (j + 1 < taille_colone && grille_vois->grille[i][j + 1].type_cellule == 1) compt++;

        grille_vois->grille[i][j].compteur = compt;
    }
}

void Grille::refresh_grille(Grille* grille_ref) { // met à jour la grille en fonction des règles du jeu de la vie
    for (int i = 0; i < grille_ref->grille.size(); i++) { // on parcourt les cellules marquées
        for (int j = 0; j < grille_ref->grille[i].size(); j++) {
            if (grille_ref->grille[i][j].ping == true) {
                grille_ref->grille[i][j].ping = false; // réinitialisation du marqueur
                if (grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 0) // une cellule morte avec exactement 3 voisines vivantes devient vivante
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0;
                }
                else if (grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 1) // une cellule vivante avec 3 voisines vivantes reste vivante
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0;
                }
                else if (grille_ref->grille[i][j].compteur == 2 && grille_ref->grille[i][j].type_cellule == 1) // une cellule vivante avec 2 voisines vivantes reste vivante
                {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0;
                }
                else {
                    grille_ref->grille[i][j].set_case(0); // sinon la cellule meurt
                    grille_ref->grille[i][j].compteur = 0;
                }
            }
        }
    }
}
