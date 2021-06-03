#include <vector>
#include <iostream>
#include "Ciel.h"

using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Méthode qui sert à dessiner le ciel héritée de Dessinable
void Ciel :: dessine_sur(SupportADessin& a_dessiner)
{ a_dessiner.dessine(*this); }

// Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné
CubedAir Ciel:: precedente(double const& pas_temps, double const& x, double const& y, double const& z)
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


// Initialise l'état des cubes d'air
  void Ciel :: initialise()
  {
      for (unsigned int i(0); i < get_Nx(); ++i)
      {
          for (unsigned int j(0); j < get_Ny(); ++j)
          {
              for (unsigned int k(0); k < get_Nz(); ++k)
              {
                  tablO[i][j][k].set_etat(i, j, k);
              }

          }
      }

  }


  // Constructeur du ciel à partir d'un champ de potentiels donné
  Ciel :: Ciel(ChampsPotentiels const& champ)

      : Boite3D(champ.get_Nx(), champ.get_Ny(), champ.get_Nz(), champ.get_pas())

  {
      for (unsigned int i(0); i < Nx; ++i)
      {
          // Afin de créer les 3 dimensions du tableau, on rajoute un Potentiel à chaque nouvelle itération sur chaque dimension
          tablO.push_back(vector<vector<CubedAir>> ());

          for (unsigned int j(0); j < Ny; ++j)
          {
              tablO[i].push_back(vector<CubedAir> ());

              for (unsigned int k(0); k < Nz; ++k)
              {
                  tablO[i][j].push_back(CubedAir ());
                  tablO[i][j][k].set_vitesse(champ.vitesse(i, j, k)[0], champ.vitesse(i, j, k)[1], champ.vitesse(i, j, k)[2]);
              }
          }
      }
  }


  // Constructeur à partir de dimensions données (avec initialisation des CubedAirs)
  Ciel :: Ciel(double const& Nx, double const& Ny, double const& Nz, double const& pas)
      : Boite3D (Nx, Ny, Nz, pas)
  {

              for (unsigned int i(0); i < Nx; ++i)
              {
                  for (unsigned int j(0); j < Ny; ++j)
                  {
                      for (unsigned int k(0); k < Ny; ++k)
                      {
                          tablO[i][j][k].set_vitesse(Physique::vinfini, 0, 0);
                      }

              }
          }

  }
