#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include <fstream>
using namespace std ;

/*
Le main va nous permettre d'initaliser notre programme en récuperant les base de notre utilisateurs : Chemin du fichier,mode choisie ...
Et vas directement effectuer quelque test pour voir que tout fonctionne bien et qu'il n'y ai pas d'erreur et ainsi eviter les tests inutile dans notre programme a l'avenir
Les return 0 nous permettes de fermer le programme direct lors d'erreur pour éviter les cascades
*/

int main(){
    cout<<"Initialisation jeux de la vie "<<endl;
    string liens ;
    cout<<"Veulliez sasir le chemin du fichier de base pour la simulation : "<<endl;
    cin>>liens ; 
    ifstream inputFile(liens);
    if (inputFile.is_open()) {
        cout << "Le fichier est accessible en lecture." << endl;
        inputFile.close(); 
    } else {
        cout << "Erreur : le fichier ne peut pas être ouvert en lecture." << endl;
        return 0 ;
    }
    cout<<"Veulliez sasir un mode(console,graphique) : "<<endl;
    string mode ;
    cin>>mode ;
    bool modeb;


    jeux_de_la_vie* jeux = nullptr;
    if(mode == "console"){
        modeb = false ;
        jeux = new jeux_de_la_vie(25,10,modeb,liens);
        jeux->jeux_de_la_vie_jeux();
    }
    else if (mode == "graphique"){
        modeb = true ;
        int temp ;
        cout<<"Choissez le temp entre chaque itération(milliseconde)"<<endl;
        cin >> temp ; 
        jeux = new jeux_de_la_vie(1000,temp,modeb,liens);
        jeux->jeux_de_la_vie_jeux();
    }
    else {
        cout<<"erreur mod invalide"<<endl ; 
        return 0 ;
    }
    


    return 0 ;
};



