#include "jeux_de_la_vie.h"
#include "choix_mode.h"
#include "observer.h"
#include "grille.h"
#include "gestion_fichier.h"
#include "affichage.h"

void jeux_de_la_vie::jeux_de_la_vie_jeux(){
    if(this->mode){ // dès le début, le programme vérifie dans quel mode nous sommes : true = graphique et false = console
        cout<<"Mode graphique"<<endl; // affiche le mode graphique à l'utilisateur
        Grille* grille_i = nullptr;
        grille_i = new Grille(this->lien_fichier); // création de la référence pour la grille, ce qui évite les doublons
        bool condition = true; // condition permettant de vérifier si le programme doit se répéter
        affichage* affichage_i = nullptr; // même chose pour l'affichage
        affichage_i = new affichage(grille_i);

        this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration)); // comme indiqué dans le projet, on fait patienter l'utilisateur pour qu'il puisse voir la grille de départ du fichier
        while(affichage_i->window->isOpen() && this->iteration > 0 && condition != 0){
            /*
            dans cette boucle, on vérifie trois choses : d'une part, si la fenêtre est toujours ouverte, si des itérations restent à effectuer et si le système ne se répète pas grâce à la condition
            */
            sf::Event event;
            while (affichage_i->window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    affichage_i->window->close();
            }
            if (condition != 0){ // cette condition permet d'éviter les doublons lorsque la grille atteint un état stable
                affichage_i->update_affichage(grille_i); // affiche la grille après chaque mise à jour, en affichant initialement la grille sans gêner la suite des boucles
            }
            this->iteration--; // à chaque boucle, le nombre d'itérations diminue pour éviter les boucles infinies

            observer::fouille_grille(grille_i); // méthode permettant de marquer et compter les cases autour des cellules vivantes
            Grille::refresh_grille(grille_i); // méthode qui modifie la grille en fonction des cellules vivantes trouvées par la méthode précédente

            condition = Grille::test_grille(grille_i); // vérifie à chaque boucle si la grille a changé par rapport à la précédente

            this_thread::sleep_for(chrono::milliseconds(this->temp_entre_iteration)); // fait une pause entre chaque itération pour permettre à l'utilisateur de voir les changements
        }
        
    }
    
    //dans cette partie, moins de commentaires, car certaines parties se répètent, on ne commente que les parties modifiées ou essentielles
    

    else{
        cout<<"Mode console"<<endl;
        Grille* grille_i = nullptr; // génération de la grille
        grille_i = new Grille(this->lien_fichier);
        string lien_doss = gestion_fichier::create_file(); // création du dossier pour stocker l'historique des grilles
        cout<<" "<<endl;
        bool condition = true;
        int max_itération = this->iteration ;
        while(this->iteration > 0 && condition != 0){ // cette fois, seulement deux conditions sont vérifiées
            this->iteration--;
            observer::fouille_grille(grille_i);
            Grille::refresh_grille(grille_i);
            condition = Grille::test_grille(grille_i);
            if (condition != 0 && this->iteration > max_itération / 2){
                gestion_fichier::create_fichier(grille_i, lien_doss); // création à chaque itération d'un fichier pour stocker l'état de la grille
            }
        }
    }
}
