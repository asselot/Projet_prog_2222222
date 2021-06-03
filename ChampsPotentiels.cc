#include "ChampsPotentiels.h"
#include "constantes.h"
#include <cmath>

using namespace std;
using namespace Physique;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

/*void ChampsPotentiels::remettre(Montagne m){
    for (unsigned int x(0); x < Nx; ++x)
	{
		for (unsigned int y(0); y < Ny; ++y)
		{
			for (unsigned int z(0); z < Nz; ++z)
			{
                if (m.altitude(x,y)> z)
                {
                    potentiels3D[x][y][z].laplacien.coord_x = 0;
                    potentiels3D[x][y][z].laplacien.coord_y = 0;
                }
            }
        }
    }
}*/

// Retourne la somme des carrés des normes des vecteurs laplaciens
double ChampsPotentiels:: erreur()
{
	// Effectue une itération sur toute la boîte
	double retour(0);
	for (unsigned int x(0); x < Nx; ++x)
	{
		for (unsigned int y(0); y < Ny; ++y)
		{
			for (unsigned int z(0); z < Nz; ++z)
			{
				retour += tablO[x][y][z].laplacien.norme2(); 
			}
		}
	}
	return retour;
}

// Retourne true si un potentiel est au bord de la boîte
bool ChampsPotentiels:: estauxbords(Potentiel pot) const
{
	if ((pot.poten.coord_x == 0) or (pot.poten.coord_x == Nx-1) or (pot.poten.coord_y == 0) or (pot.poten.coord_y == Ny-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Calcule la valeur des laplaciens sur l'ensemble du champ à partir des potentiels 
void ChampsPotentiels :: calcule_laplaciens(const ChaineDeMontagnes& chaine)
//Vecteur2D calcul;
    {
        for (size_t i(1); i < Nz-1; ++i)
        {
            for(size_t j(1); j < Ny-1; ++j)
            {
                for (size_t k(1); k < Nx-1; ++k)
                {   
					
					if (k < chaine.altitude(i, j))
					{
						tablO[i][j][k].laplacien.coord_x = 0;
						tablO[i][j][k].laplacien.coord_y = 0;
					}
					else
					{
					
					
					/*calcul = (tablO[i-1][j][k].poten + tablO[i][j-1][k].poten + tablO[i][j][k-1].poten 
					+ tablO[i+1][j][k].poten + tablO[i][j+1][k].poten + tablO[i][j][k+1].poten - 6.0 * tablO[i][j][k].poten);*/	
					//cout << tablO[i-1][j][k].poten << endl;   
					
					tablO[i][j][k].laplacien = tablO[i-1][j][k].poten + tablO[i][j-1][k].poten + tablO[i][j][k-1].poten 
					+ tablO[i+1][j][k].poten + tablO[i][j+1][k].poten + tablO[i][j][k+1].poten - tablO[i][j][k].poten * 6.0;
					          
					/*tablO[i][j][k].laplacien.coord_x = (tablO[i-1][j][k].poten.coord_x + tablO[i][j-1][k].poten.coord_x + tablO[i][j][k-1].poten.coord_x 
					+ tablO[i+1][j][k].poten.coord_x + tablO[i][j+1][k].poten.coord_x + tablO[i][j][k+1].poten.coord_x - tablO[i][j][k].poten.coord_x * 6.0);
					
					tablO[i][j][k].laplacien.coord_y = (tablO[i-1][j][k].poten.coord_y + tablO[i][j-1][k].poten.coord_y + tablO[i][j][k-1].poten.coord_y 
					+ tablO[i+1][j][k].poten.coord_y + tablO[i][j+1][k].poten.coord_y + tablO[i][j][k+1].poten.coord_y - tablO[i][j][k].poten.coord_y * 6.0);*/
					//cout << i << " " << j << " " << k << " " << tablO[i][j][k].laplacien << endl;		
				    }					
                }
            }
        }
        
    }
	
// Elle fait quoi cette méthode?
void ChampsPotentiels:: iteration(const ChaineDeMontagnes& chaine, const double& E) 
{
	for (unsigned int x(1); x < Nx-1; ++x)
	{
		for (unsigned int y(1); y < Ny-1; ++y)
		{
			for (unsigned int z(1); z < Nz-1; ++z)
			{
				if (z < chaine.altitude(x, y))
				{
					tablO[x][y][z].laplacien.coord_x = 0;
					tablO[x][y][z].laplacien.coord_y = 0;
				}
				
				else 
				{
					tablO[x][y][z].poten = tablO[x][y][z].poten + tablO[x][y][z].laplacien * E;
				}
			}
		}
	}
	
}
		
// Jsp non plus
void ChampsPotentiels:: resolution (double seuil, unsigned int max, bool verbeuse, const ChaineDeMontagnes& chaine)
{
	unsigned int n = 0;	
	calcule_laplaciens(chaine);
	while (( erreur() > seuil ) and (n < max))
	{
		++n;
		calcule_laplaciens(chaine);
		iteration(chaine, 0.1);
        if (verbeuse)
		{
			cout<<n<<" "<<erreur()<<endl;
		}
			/*
			for (unsigned int x(0); x < Nx; ++x)
			{
				for (unsigned int y(0); y < Ny; ++y)
				{
					for (unsigned int z(0); z < Nz; ++z)
					{
						tablO[x][y][z].affiche();
					}
				}
			}*/
		
	}
}
		
// Calcule la valeur de la vitesse du vent en un point donné
array<double, 3> ChampsPotentiels:: vitesse(unsigned int i, unsigned int j, unsigned int k) const
{
	array <double, 3> v ({0, 0, 0}); // Coordonnées initialisées à (0, 0, 0)
	
	if (( i >= Nx) or ( j >= Ny) or ( k >= Nz)) // Si les i, j, k ne respectent pas les dimensions de la boîte --> erreur !
	{
		cerr << "Erreur : dimension fausse " << endl;
		return v; 
	}
	else 
	{
		if ((i == 0) or (i == Nx-1) or (j == 0) or (j == Ny-1) or (k == 0) or (k == Nz-1))
		{
			v[2] = vinfini;
			v[1] = vinfini;
			v[0] = vinfini;
		}
		else
		{
			v[2] = (1/(2*pas))*(tablO[i+1][j][k].poten.coord_x - tablO[i-1][j][k].poten.coord_x);
			v[0] = (1/(2*pas))*(tablO[i-1][j][k].poten.coord_y - tablO[i+1][j][k].poten.coord_y);
			v[1] = (1/(2*pas))*(tablO[i][j+1][k].poten.coord_y - tablO[i][j-1][k].poten.coord_y - tablO[i][j][k+1].poten.coord_x + tablO[i][j][k-1].poten.coord_x);
		}
		//cout << i << " " << j << " " << k << " " << v[0] << " " << v[1] << " " << v[2] << endl;
		return v; 
	}	

}


// Norme de la vitesse
double ChampsPotentiels:: norme_vitesse(unsigned int pointi, unsigned int pointj, unsigned int pointk) const
{
	// Crée un tableau à 3 éléments regroupant les coordonnées de la vitesse calculée avec la méthode vitesse() au point donné
	array<double, 3> coord_vitesse(vitesse(pointi, pointj, pointk));
	
	return sqrt(coord_vitesse[0]*coord_vitesse[0] + coord_vitesse[1]*coord_vitesse[1] + coord_vitesse[2]*coord_vitesse[2]);
}



// Initialise les potentiels du champ potentiel
void ChampsPotentiels:: initialise(double vi, Montagne const& mont) 
{
	for (unsigned int x(0); x < Nx; ++x)
	{
		// Afin de créer les 3 dimensions du tableau, on rajoute un Potentiel à chaque nouvelle itération sur chaque dimension 
		tablO.push_back(vector<vector<Potentiel>> ());
		
		for (unsigned int y(0); y < Ny; ++y)
		{
			tablO[x].push_back(vector<Potentiel> ());
			
			for (unsigned int z(0); z < Nz; ++z)
			{
				tablO[x][y].push_back(Potentiel ()); 
				
				// Vérifie que le potentiel ne soit ni aux bords de la boîte ni en dessous de la montagne 
				// if( not (estauxbords(potentiels3D[x][y][z])) or (z >= mont.altitude(x, y))
				if ((x == 0) or (x == Nx-1) or (y == 0) or (y == Ny-1) or (z >= mont.altitude(x, y))) 
				{
					tablO[x][y][z].poten.coord_x = - (vi/2.0) * (z * pas);
					tablO[x][y][z].poten.coord_y = (vi/2.0) * (y - (Ny - 1)/2.0) * pas;	
				}
				
				// Si le potentiel (vecteur) est aux bords ou sous la montagne il est initialisé à 0
				else
				{
					tablO[x][y][z].poten.coord_x = 0;
					tablO[x][y][z].poten.coord_y = 0;
				}
			}
		}
	}
}
