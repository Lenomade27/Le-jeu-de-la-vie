#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include <iostream>
#include <fstream>
using namespace std ;

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
        jeux = new jeux_de_la_vie(25,1,modeb,liens);
        jeux->jeux_de_la_vie_regle();
    }
    else if (mode == "graphique"){
        modeb = true ;
        int temp ;
        cout<<"Choissez le temp entre chaque itération"<<endl;
        cin >> temp ; 
        jeux = new jeux_de_la_vie(25,temp,modeb,liens);
        jeux->jeux_de_la_vie_regle();
        cout<<jeux->iteration<<endl;
    }
    else {
        cout<<"erreur mod invalide"<<endl ; 
        return 0 ;
    }
    cout<<jeux->iteration<<endl;
    


    return 0 ;
};



