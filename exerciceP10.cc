#include <iostream> 
#include "constantes.h"
#include "Systeme.h"
#include "TextViewer.h"

// Test de l'affichage texte d'un système

using namespace std;
using namespace Physique;

int main()
{
	// Création du support à dessin pour l'affichage texte
	TextViewer ecran(cout); 
	
	// Création des trois montagnes qui composent la chaîne
	Montagne mont1(15.0, 15.0, 18.0, 5.0, 10.0);
	Montagne mont2(2, 22, 12, 12, 3);
	Montagne mont3(20, 2, 15, 8, 4);
	
	// Création de la chaîne et ajout des montagnes
	ChaineDeMontagnes chaine(mont1);
	chaine.add_montagne(mont2);
	chaine.add_montagne(mont3);

	// Création et initialisation du champ de potentiels
	ChampsPotentiels champ(30, 30, 30, 20.0/29.0);
	champ.initialise(vinfini, chaine);

	// Création et simulation du système
	Systeme sys(champ, chaine);
	sys.demarre(ecran);
	sys.evolue(ecran);
	
}
