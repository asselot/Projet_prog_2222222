#include <iostream>
#include "Ciel.h"


// Méthode héritée de Dessinable
void Ciel :: dessine_sur(SupportADessin a_dessiner) override
{ a_dessiner.dessine(*this); }


CubedAir Ciel:: precedente(double pas_temps, double x, double y, double z)
{
	double norme_vitesse_cubedair(sqrt(cubes_dair[x][y][z].vitesse_cubedair[0]*cubes_dair[x][y][z].vitesse_cubedair[0] + cubes_dair[x][y][z].vitesse_cubedair[1]*cubes_dair[x][y][z].vitesse_cubedair[1] + cubes_dair[x][y][z].vitesse_cubedair[2]*cubes_dair[x][y][z].vitesse_cubedair[2]));
	
  double deplacement(-pas_temps * norme_vitesse_cubedair);
	
  x += deplacement;
	y += deplacement;
	z += deplacement;
	
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
 //tester ces méthodes!!


void Ciel:: affiche() override
{
	for (size_t x(0); x < get_Nx; ++x)
	{
		for (size_t y(0); y < get_Ny; ++y)
		{
			for (size_t z(0); z < get_Nz; ++z)
			{
				
					tablO[x][y][z].affiche();
				
			}
		}
	}
}

