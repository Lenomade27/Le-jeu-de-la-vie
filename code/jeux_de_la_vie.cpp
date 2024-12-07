#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include <iostream>
#include "gestion_fichier.h"
#include "affichage.h"
using namespace std ;
#include <vector>
#include <chrono>
#include <thread>

void jeux_de_la_vie::jeux_de_la_vie_regle(){
if(this->mode){
    cout<<"Mode graphique"<<endl;
    Grille* grille_i = nullptr;
    grille_i = new Grille(this->lien_fichier);
    bool condition = true ;// metre un affichagde pour l'initialisation
    Grille :: afficherGrille(grille_i);

    affichage* affichage_i = nullptr;
    affichage_i = new affichage(grille_i);
    //affichage_i->update_affichage(grille_i);

    this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration));
    while(affichage_i->window->isOpen() &&this->iteration>0 && condition != 0){
        
        sf::Event event;
        while (affichage_i->window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    affichage_i->window->close();
            }
        if (condition != 0){//affichage grille
            affichage_i->update_affichage(grille_i);
        }

        this->iteration --;
        observer :: fouille_grille(grille_i);
        Grille :: refresh_grille(grille_i);
        condition = Grille :: test_grille(grille_i);
        
        this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration));

    }
    
}


else{
cout<<"Mode console"<<endl;
Grille* grille_i = nullptr;
grille_i = new Grille(this->lien_fichier);
string lien_doss = gestion_fichier::create_file();
Grille :: afficherGrille(grille_i);
cout<<" "<<endl;
bool condition = true ;
this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration));
while(this->iteration>0 && condition != 0){
    this->iteration --;
    observer :: fouille_grille(grille_i);
    Grille :: refresh_grille(grille_i);
    condition = Grille :: test_grille(grille_i);
    if (condition != 0){
        gestion_fichier::create_fichier(grille_i,lien_doss) ;
    }
    this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration));
    
}
}
}



