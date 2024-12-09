#include <iostream>
using namespace std ;
#pragma once

/*La classe choix du mode va nous permettre de créer une facade, cette dernière est très peu utilisée car elle sert 
de constructeur du coeur de notre programme. Grâce à l'héritage cela nous évite de faire un constructeur dans notre 
classe jeux-de-la-vie, classe qui va récupérer la méthode la plus importante de notre programme qui va tout relier.
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





