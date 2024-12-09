//!case.cpp
Case::Case(int type, bool isObstacle) { // 1 = vivant, 0 = mort
    type_cellule = type;
    this->isObstacle = isObstacle; //! ajout de la pté obstacle
}

Case::Case() {
    type_cellule = 0; // par défaut : cellule morte
    isObstacle = false; //! par défaut, une cellule n'est pas un obstacle
}

void Case::set_case(int type) {
    if (!isObstacle) { //! rend la cellule obstacle inmodifiable
        this->type_cellule_past = this->type_cellule;
        this->type_cellule = type;
    }
}

//! grille.cpp
Grille::Grille(string lien) {
    vector<vector<int>> grille_int = gestion_fichier::get_fichier_data(lien);
    grille.resize(grille_int.size());
    for (int i = 0; i < grille_int.size(); ++i) {
        grille[i].resize(grille_int[i].size());
    }

    for (int i = 0; i < grille_int.size(); i++) {
        for (int j = 0; j < grille_int[i].size(); j++) {
            if (grille_int[i][j] == 0) {
                Case a;
                grille[i][j] = a;
            } else if (grille_int[i][j] == 1) {
                Case b(1);
                grille[i][j] = b;
            } else if (grille_int[i][j] == -1) { //! -1 représente un obstacle
                Case obstacle(0, true); //! cellule morte définie comme obstacle
                grille[i][j] = obstacle;
            }
        }
    }
}

void Grille::set_obstacle(int x, int y) {
    if (x >= 0 && x < grille.size() && y >= 0 && y < grille[0].size()) {
        grille[x][y].isObstacle = true; //! définit la cellule comme obstacle
    }
}

void Grille::set_voisin(Grille* grille_vois, int i, int j, bool mode) {
    int taille_ligne = grille_vois->grille.size();
    int taille_colone = grille_vois->grille[0].size();

    auto lecture_toric_index = [](int index, int taille) {
        return (index + taille) % taille;
    };

    if (mode) {
        grille_vois->grille[i][j].ping = true;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int ni = lecture_toric_index(i + dx, taille_ligne);
                int nj = lecture_toric_index(j + dy, taille_colone);
                if (!grille_vois->grille[ni][nj].isObstacle) { //! ignore les cellules obstacles
                    grille_vois->grille[ni][nj].ping = true;
                }
            }
        }
    } else {
        int compt = 0;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                int ni = lecture_toric_index(i + dx, taille_ligne);
                int nj = lecture_toric_index(j + dy, taille_colone);
                if (!grille_vois->grille[ni][nj].isObstacle && grille_vois->grille[ni][nj].type_cellule == 1) { //! ignore les cellules obstacles
                    compt++;
                }
            }
        }
        grille_vois->grille[i][j].compteur = compt;
    }
}

void Grille::refresh_grille(Grille* grille_ref) {
    for (int i = 0; i < grille_ref->grille.size(); i++) {
        for (int j = 0; j < grille_ref->grille[i].size(); j++) {
            if (grille_ref->grille[i][j].isObstacle) continue; //! ignore les cellules obstacles
            if (grille_ref->grille[i][j].ping == true) {
                grille_ref->grille[i][j].ping = false;
                if (grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 0) {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0;
                } else if (grille_ref->grille[i][j].compteur == 3 && grille_ref->grille[i][j].type_cellule == 1) {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0;
                } else if (grille_ref->grille[i][j].compteur == 2 && grille_ref->grille[i][j].type_cellule == 1) {
                    grille_ref->grille[i][j].set_case(1);
                    grille_ref->grille[i][j].compteur = 0;
                } else {
                    grille_ref->grille[i][j].set_case(0);
                    grille_ref->grille[i][j].compteur = 0;
                }
            }
        }
    }
}
