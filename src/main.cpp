#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include <fstream>
using namespace std ;

/*
le main permet d'initialiser notre programme en récupérant les informations de base de l'utilisateur : chemin du fichier, mode choisi, etc.
il effectue ensuite quelques vérifications pour s'assurer que tout fonctionne correctement et qu'il n'y a pas d'erreurs, afin d'éviter des tests inutiles dans le programme à l'avenir.
les return 0 permettent de fermer le programme directement en cas d'erreur, afin d'éviter les cascades d'erreurs.
*/

int main(){
    cout<<"Initialisation du jeu de la vie "<<endl;
    string liens ;
    cout<<"Veuillez saisir le chemin du fichier de base pour la simulation : "<<endl;
    cin>>liens ; 
    ifstream inputFile(liens);
    if (inputFile.is_open()) {
        cout << "Le fichier est accessible en lecture." << endl;
        inputFile.close(); 
    } else {
        cout << "Erreur : le fichier ne peut pas être ouvert en lecture." << endl;
        return 0 ;
    }
    cout<<"Veuillez saisir un mode (console, graphique) : "<<endl;
    string mode ;
    cin>>mode ;
    bool modeb;


    jeux_de_la_vie* jeux = nullptr;
    if(mode == "console"){
        modeb = false ;
        jeux = new jeux_de_la_vie(25,0,modeb,liens);
        jeux->jeux_de_la_vie_jeux();
    }
    else if (mode == "graphique"){
        modeb = true ;
        int temp ;
        cout<<"Choisissez le temps entre chaque itération (en millisecondes) : "<<endl;
        cin >> temp ; 
        jeux = new jeux_de_la_vie(1000,temp,modeb,liens);
        jeux->jeux_de_la_vie_jeux();
    }
    else {
        cout<<"Erreur : mode invalide."<<endl ; 
        return 0 ;
    }
    


    return 0 ;
};
