#include "choix_mode.h"

choix_mode :: choix_mode (int it,int temp,bool modeb,string lien){ // constructeur qui va récuperer les données validées dans le main par l'utilisateur
    iteration = it ;
    temp_entre_iteration = temp;
    mode = modeb ; // modeb est un booleen car deux modes possibles
    lien_fichier = lien;

}



