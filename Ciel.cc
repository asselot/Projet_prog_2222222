
#include <iostream>
#include "Ciel.h"

using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Demande à Sixtine
void Ciel :: dessine_sur(SupportADessin& a_dessiner)
{ a_dessiner.dessine(*this); }

// Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné
CubedAir Ciel:: precedente(double pas_temps, double x, double y, double z)
{
	//double norme_vitesse_cubedair(sqrt(tablO[x][y][z].vitesse_cubedair[0]*tablO[x][y][z].vitesse_cubedair[0] + tablO[x][y][z].vitesse_cubedair[1]*tablO[x][y][z].vitesse_cubedair[1] + tablO[x][y][z].vitesse_cubedair[2]*cubes_dair[x][y][z].vitesse_cubedair[2]));
	
	// Calcul du déplacement effectué et mise à jour des coordonnées
	double deplacement(-pas_temps * tablO[x][y][z].vitesse_norme());
	x += deplacement;
	y += deplacement;
	z += deplacement;
	
	// Si on se trouve au-delà de la boîte, l'état du nuage devient false (on ne se trouve plus dans le ciel)
	if ((x > Nx) or (y > Ny) or (z > Nz))
	{
		tablO[x][y][z].etat == false;
		return tablO[x][y][z];
	}
	else
	{
		return tablO[x][y][z];
	}
}




