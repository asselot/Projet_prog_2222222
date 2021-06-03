#include <iostream>
#include "Ciel.h"

using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Demande à Sixtine
void Ciel :: dessine_sur(SupportADessin& a_dessiner)
{ a_dessiner.dessine(*this); }

/*void Ciel:: initialise(const ChampsPotentiels& champi)
{
	for (int i(0); i < champi.get_Nx(); ++i)
		{
			tablO.push_back(vector<vector<CubedAir>> ());
			for (int j(0); j < champi.get_Ny(); ++j)
			{
				tablO[i].push_back(vector<CubedAir> ());
				for (int k(0); k < champi.get_Nz(); ++k)
				{
					tablO[i][j].push_back(CubedAir ()); 
					tablO[i][j][k].set_vitesse(champi.vitesse(i, j, k)[0], champi.vitesse(i, j, k)[1], champi.vitesse(i, j, k)[2]);
				}
			}
		}
}*/

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
		tablO[x][y][z].etat(x, y, z) == false;
		return tablO[x][y][z];
	}
	else
	{
		return tablO[x][y][z];
	}
}
