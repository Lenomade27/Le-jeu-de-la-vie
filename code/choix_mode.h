#include <iostream>
using namespace std ;
#pragma once

/*La classe choix du mode va nous permttre de faire une facade a notre programme 
Elle est très peu utiliser car elle sert de constructeur aux coeur de notre programme la ou tout et lier 
Grace a l'héritage cela nous empeche de faire un constructeur dans notre classe jeux-de-la-vie qui va lui récuperer 
la Méthode la plus importante de notre programme qui vas tout relier.
*/


class choix_mode {
    protected:
    int iteration ;
    int temp_entre_iteration ;
    bool mode ;
    string lien_fichier ;
    public:
    choix_mode(int it,int temp,bool modeb,string lien);

};





