#include <iostream>
#include <vector>
#include "Potentiel.h"

using namespace std;
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Affiche les attributs d'un potentiel
void Potentiel:: affiche(ostream& sortie) const
{
    sortie << poten << " " << laplacien << endl;
}


