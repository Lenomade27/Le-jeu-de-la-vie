#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#pragma once
using namespace std ;
#include "choix_mode.h"

/*
classe dérivée de choix_mode. Cette classe permet de faire fonctionner le programme.
Grâce au constructeur de choix_mode, nous obtenons les données de l'utilisateur que nous pouvons utiliser dans notre fonction 
principale jeux_de_la_vie.
La méthode jeux_de_la_vie_jeux sera détaillée dans le fichier .cpp.
Cette méthode, reliant plusieurs autres classes, permet également d'inclure toutes les bibliothèques utilisées par les classes, 
ce qui évite les doublons.
*/

class jeux_de_la_vie : public choix_mode {
    public:
    jeux_de_la_vie(int it, int temp, bool mode, string lien) : choix_mode(it, temp, mode, lien) {} 
    void jeux_de_la_vie_jeux();
};
