#include <iostream>
#include <fstream>
using namespace std ;
#include "grille.h"
#pragma once

class gestion_fichier {
protected:
string chemin_fichier ; 

public:
void creat_fichier(Grille grille) ;
void get_fichier() ; 


};

