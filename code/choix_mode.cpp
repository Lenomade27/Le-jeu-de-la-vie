#include "choix_mode.h"



choix_mode :: choix_mode (int it,int temp,bool modeb,string lien){//Constructeur qui va récuperer les donnée valider dans le main par l'utilisateur
    iteration = it ;
    temp_entre_iteration = temp;
    mode = modeb ; // mode est un booleen car il n'y a que deux mode disponible graphique ou console
    lien_fichier = lien;

}



