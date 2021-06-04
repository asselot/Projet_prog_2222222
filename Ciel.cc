#include <iostream>
#include "Ciel.h"

using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

Ciel::Ciel(ChampsPotentiels const& champ) : Boite3D<CubedAir>(champ.get_Nx(), champ.get_Ny(), champ.get_Nz(), champ.get_pas()) // Constructeur du ciel à partir d'un champ de potentiels donné
    {
        for (int i(0); i < champ.get_Nx(); ++i)
		{
			tablO.push_back(std::vector<std::vector<CubedAir>>());
            for ( int j(0); j < champ.get_Ny(); ++j)
			{
				tablO[i].push_back(std::vector<CubedAir>());
                for ( int k(0); k < champ.get_Nz(); ++k)
				{
					tablO[i][j].push_back(CubedAir());
					tablO[i][j][k].set_vitesse(champ.vitesse(i, j, k)[0], champ.vitesse(i, j, k)[1], champ.vitesse(i, j, k)[2]);
				}
			}
		}
	}
	
Ciel::Ciel(double Lx, double Ly, double Lz, double lambda) : Boite3D<CubedAir>(Lx, Ly, Lz, lambda) // Constructeur à partir de dimensions données
	{
		for (unsigned int i(0); i < Lx/lambda; ++i)
		{
			for (unsigned int j(0); j < Ly/lambda; ++j)
			{
				for (unsigned int k(0); k < Lz/lambda; ++k)
				{
                    tablO[i][j][k].set_vitesse(Physique::vinfini, 0, 0);
				}

		}
     }
    }

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
CubedAir Ciel:: precedente(double const& pas_temps, double& x, double& y, double& z, double const& pas)
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
		tablO[x][y][z].etat(z, pas) == false;
		return tablO[x][y][z];
	}
	else
	{
		return tablO[x][y][z];
	}
}
