#include <iostream>
#include "choix_mode.h"

class jeux_de_la_vie :public choix_mode {
public:
jeux_de_la_vie(int it, int temp, bool mode, string lien)
        : choix_mode(it, temp, mode, lien) {}
void jeux_de_la_vie_regle();
};




