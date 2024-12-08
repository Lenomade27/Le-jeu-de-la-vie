#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include "gestion_fichier.h"
#include "affichage.h"



void jeux_de_la_vie::jeux_de_la_vie_jeux(){
    if(this->mode){//Dès le début notre programme va regarder dans quelle mode nous somme : true = graphique et false = console
        cout<<"Mode graphique"<<endl;// On affiche ainsi le résulats a notre utilisateur
        Grille* grille_i = nullptr;
        grille_i = new Grille(this->lien_fichier);// On va créer une réference pour notre grille ainsi sa va éviter qu'elle se double  **
        bool condition = true ; // Condition qui vas nous permettre de voir si notre programme se répète
        affichage* affichage_i = nullptr; // De meme avec l'affichage **
        affichage_i = new affichage(grille_i);

        this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration)); // Comme décris dans le projet on va faire attendre notre utilisateur avec la Méthode this_thread::sleep_for pour qu'il puisse voir la grille de base de son fichier
        while(affichage_i->window->isOpen() &&this->iteration>0 && condition != 0){
            /*
            Dans cette boucle nous vérifions trois chose d'une part que notre fenetre et ouverte et que il nous reste des iterations et que notre system ne se répète pas grace a notre condition
            */
            sf::Event event;
            while (affichage_i->window->pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        affichage_i->window->close();
            }
            if (condition != 0){ // Cette condition nosu permets d'éviter les doublons a la fin quand la grille a le meme états 
                affichage_i->update_affichage(grille_i);// De plus grace a sa position lors de la premiere boucle on afficheras a coup sur la grille initial sans gener la suite des boucle
            }
            this->iteration --; // A chaque boucle notre nombre d'iteration baisseras pour éviter les boucles infinie
            
            observer :: fouille_grille(grille_i);//Méthode qui vas permettre de marquer et compter les cases autour des marquer qui sont vivante
            Grille :: refresh_grille(grille_i);//Méthode qui va modifier notre grille en fonction des cases vivantes trouver par la Méthode du dessus 

            condition = Grille :: test_grille(grille_i); // A chaque boucler on va tester si celle ci est diffrente que la précedentes grace a cette Méthode
            
            this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration));// entre chaque boucle pour afficher on va faire attendre le programme donc l'utilisateur pour voir les changements effectuers

        }
        
    }
    /*
    Dans cette partie moins de commentaire car certaine partie se répètes 
    On ne commenteras que les partie modifier ou les partie clé de se programme
    */

    else{
        cout<<"Mode console"<<endl;
        Grille* grille_i = nullptr; // Génération de notre grille
        grille_i = new Grille(this->lien_fichier);
        string lien_doss = gestion_fichier::create_file();// Création du dossier pour stocker les historiques des grilles
        cout<<" "<<endl;
        bool condition = true ;
        while(this->iteration>0 && condition != 0){//Cette fois si seulment deux conditions 
            this->iteration --;
            observer :: fouille_grille(grille_i);
            Grille :: refresh_grille(grille_i);
            condition = Grille :: test_grille(grille_i);
            if (condition != 0){
                gestion_fichier::create_fichier(grille_i,lien_doss) ; // Création a chaque itération d'un fichier de notre grille 
            }
        
        }
    }
}



