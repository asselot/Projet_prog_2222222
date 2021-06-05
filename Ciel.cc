#include <vector>
#include <iostream>
#include "Ciel.h"

using namespace std;

//--------------------------------------------------------------CONSTRUCTEURS-------------------------------------------------------------//

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

                  tablO[i][j].push_back(CubedAir(champ.vitesse(i, j, k)));
                  tablO[i][j][k].set_vitesse(champ.vitesse(i, j, k)[0], champ.vitesse(i, j, k)[1], champ.vitesse(i, j, k)[2]);

              }
          }
      }
  }


  // Constructeur à partir de dimensions données (avec initialisation des CubedAirs)
  Ciel :: Ciel(double const& Nx, double const& Ny, double const& Nz, double const& pas)
      : Boite3D (Nx, Ny, Nz, pas)
  {
      for (int i(0); i < get_Nx(); ++i)
      {
          tablO.push_back(std::vector<std::vector<CubedAir>>());
          for ( int j(0); j < get_Ny(); ++j)
          {
              tablO[i].push_back(std::vector<CubedAir>());
              for ( int k(0); k < get_Nz(); ++k)
              {

                  tablO[i][j].push_back(CubedAir ());
                  tablO[i][j][k].set_vitesse(0., 0., 0.);
              }
          }
      }
  }

  // Constructeur à partir d'un ciel, déjà initialisé, dont les cubes d'air sont défins
 Ciel :: Ciel (Ciel const& C)
     : Boite3D (C.get_Nx(), C.get_Ny(), C.get_Nz(), C.get_pas())
 {
  tablO = C.get_tablO();
 }

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Méthode qui sert à dessiner le ciel héritée de Dessinable
void Ciel :: dessine_sur(SupportADessin& a_dessiner)
{ a_dessiner.dessine(*this); }

// Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné
CubedAir Ciel:: precedente(double& pas_temps, double& x, double& y, double& z)
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


// Initialise l'état des cubes d'air
  void Ciel :: initialise()
  {
      for (unsigned int i(0); i < Nx; ++i)
      {
          for (unsigned int j(0); j < Ny; ++j)
          {
              for (unsigned int k(0); k < Nz; ++k)
              {
                  tablO[i][j][k].etat(k, pas);
              }

          }
      }

  }

 // Affiche les paramètres du ciel
  void affiche(std::ostream& sortie) const
  {
      sortie << "Dimension de la boîte :" << std::endl;
      sortie << "Nx: " << Nx << " Ny : " << Ny << " Nz : " << Nz << std:: endl;
      sortie << "Le pas des cubes :" << pas << std::endl;

      for (int x(0); x < Nx; ++x)
      {
          for ( int y(0); y < Ny; ++y)
          {
              for (int z(0); z < Nz; ++z)
              {

                      tablO[x][y][z].affiche(sortie, z, pas);

              }
          }
      }

  }


// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& sortie, const Ciel& ciel)
{
    ciel.affiche(sortie);
    return sortie;
}




