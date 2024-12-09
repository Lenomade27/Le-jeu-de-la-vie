    !// grille.cpp
    void Grille::set_voisin(Grille* grille_vois, int i, int j, bool mode) {
    int taille_ligne = grille_vois->grille.size();
    int taille_colone = grille_vois->grille[0].size();

    //! fonction utilitaire pour gérer les indices de manière torique
    auto lecture_toric_index = [](int index, int taille) {
        return (index + taille) % taille; //! gestion des indices pour les bords toriques
    };

    if (mode) { // mode marqueur
        grille_vois->grille[i][j].ping = true; // marcage cellule actuelle
        //! parcours les voisins dans un espace torique
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue; // ignore la cellule elle-même
                int ni = lecture_toric_index(i + dx, taille_ligne); //! gestion torique des indices de ligne
                int nj = lecture_toric_index(j + dy, taille_colone); 
                grille_vois->grille[ni][nj].ping = true; // marque les voisins
            }
        }
    } else { // mode compteur
        int compt = 0;
        //! parcours les voisins dans un espace torique pour compter les cellules vivantes
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue; // ignore la cellule elle-même
                int ni = lecture_toric_index(i + dx, taille_ligne); //! gestion torique des indices de ligne
                int nj = lecture_toric_index(j + dy, taille_colone); 
                if (grille_vois->grille[ni][nj].type_cellule == 1) compt++; // incrémente si voisin vivant
            }
        }
        grille_vois->grille[i][j].compteur = compt; // enregistre le nombre de voisins vivants
    }
}
