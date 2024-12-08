#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#pragma once
using namespace std ;
#include "choix_mode.h"

/*
Classe fille de choix_mode c'est cette classe qui va nous permettre réelement de faire fonctionner notre programme
Grace au constrcuteur de choix_mode nous possédons ainsi les données de l'utilisateur que nous pouvons utiliser dans notre fonction 
principale jeux-de-la-vie 
La Méthode jeux_de_la_vie_jeux seras detailler dans la partie .cpp
Cette Méthode reliants beaucoup d'autre classe nous permets aussi d'y mettre toute les bibliothèque qu'utilise les classes 
Cela nous évite les doublons 

*/


class jeux_de_la_vie :public choix_mode {
    public:
    jeux_de_la_vie(int it, int temp, bool mode, string lien) : choix_mode(it, temp, mode, lien) {} 
    void jeux_de_la_vie_jeux();
};




