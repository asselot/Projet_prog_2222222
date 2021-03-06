#include "ChampsPotentiels.h"
#include "constantes.h"
#include <cmath>

using namespace std;
using namespace Physique;

//--------------------------------------------------------------CONSTRUCTEURS-------------------------------------------------------------//


{

}

// Constructeur du champ à partir des dimensions de la boîte avec initialisation du laplacien
ChampsPotentiels::ChampsPotentiels(unsigned int nox, unsigned int noy, unsigned int noz, double p) : Boite3D(nox, noy, noz, p)
    {

        for (size_t i(1); i < Nz-1; ++i)
        {
            for(size_t j(1); j < Ny-1; ++j)
            {
                for (size_t k(1); k < Nx-1; ++k)
                {
                    tablO[i][j][k].set_laplacien(0, 0);
                }
            }
        }

    } // Constructeur d'un champ potentiel


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
                retour += tablO[x][y][z].laplacien_norme2();
            }
        }
    }
    return retour;
}


// Calcule la valeur des laplaciens sur l'ensemble du champ à partir des potentiels
void ChampsPotentiels :: calcule_laplaciens(const ChaineDeMontagnes& chaine)
    {
        for (size_t i(1); i < Nz-1; ++i)
        {
            for(size_t j(1); j < Ny-1; ++j)
            {
                for (size_t k(1); k < Nx-1; ++k)
                {

                    if (k < chaine.altitude(i, j))
                    {
                        tablO[i][j][k].set_laplacien(0, 0);
                    }
                    else
                    {
                        tablO[i][j][k].calcule_laplacien(tablO[i-1][j][k], tablO[i][j-1][k], tablO[i][j][k-1], tablO[i+1][j][k], tablO[i][j+1][k], tablO[i][j][k+1]);
                        //cout << i << " " << j << " " << k << " " << tablO[i][j][k];
                        //tablO[i][j][k].set_laplacien (tablO[i-1][j][k].get_poten() + tablO[i][j-1][k].get_poten() + tablO[i][j][k-1].get_poten()
                        //+ tablO[i+1][j][k].get_poten() + tablO[i][j+1][k].get_poten() + tablO[i][j][k+1].get_poten() - 6*tablO[i][j][k].get_poten());
                    }
                }
            }
        }

    }

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
                    tablO[x][y][z].set_laplacien(0, 0);
                }

                else
                {
                     tablO[x][y][z].potentiel_iteration(E); // optimiser cette ligne
                }
            }
        }
    }

}

void ChampsPotentiels:: resolution(double const& seuil, unsigned int const& max, bool const& verbeuse, const ChaineDeMontagnes& chaine)
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
            cout << n << " " << erreur() << endl;
        }
    }
}

// Retourne la vitesse du vent en un point donné sous forme de tableau dont les composants représentent les composantes de la vitesse en x, y, z
array<double, 3> ChampsPotentiels:: vitesse(unsigned int const& i, unsigned int const& j, unsigned int const& k) const
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
            v[2] = 0;
            v[1] = 0;
            v[0] = vinfini;
        }
        else
        {
            v[2] = (1/(2*pas))*tablO[i][j][k].vitesse_potentiels(tablO[i-1][j][k], tablO[i][j-1][k], tablO[i][j][k-1], tablO[i+1][j][k], tablO[i][j+1][k], tablO[i][j][k+1])[2];
            v[1] = (1/(2*pas))*tablO[i][j][k].vitesse_potentiels(tablO[i-1][j][k], tablO[i][j-1][k], tablO[i][j][k-1], tablO[i+1][j][k], tablO[i][j+1][k], tablO[i][j][k+1])[1];
            v[0] = (1/(2*pas))*tablO[i][j][k].vitesse_potentiels(tablO[i-1][j][k], tablO[i][j-1][k], tablO[i][j][k-1], tablO[i+1][j][k], tablO[i][j+1][k], tablO[i][j][k+1])[0];
        }
        //cout << i << " " << j << " " << k << " " << v[0] << " " << v[1] << " " << v[2] << endl;
        return v;
    }

}


// Retourne la norme de la vitesse
double ChampsPotentiels:: norme_vitesse(unsigned int const& pointi, unsigned int const& pointj, unsigned int const& pointk) const
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
                    tablO[x][y][z].set_poten(-(vi/2.0) * (z * pas),(vi/2.0) * (y - (Ny - 1)/2.0) * pas);
                }

                // Si le potentiel (vecteur) est aux bords ou sous la montagne il est initialisé à 0
                else
                {
                    tablO[x][y][z].set_poten(0, 0);
                }
            }
        }
    }
}

// Affiche les paramètre du champ
void ChampsPotentiels:: affiche(std::ostream& sortie) const
{
    sortie << "Dimension de la boîte :" << std::endl;
    sortie << "Nx: " << Nx << " Ny : " << Ny << " Nz : " << Nz << std:: endl;
    sortie << "Le pas des cubes :" << pas << std::endl;

    for (size_t x(0); x < Nx; ++x)
    {
        for ( size_t y(0); y < Ny; ++y)
        {
            for (size_t z(0); z < Nz; ++z)
            {

                    tablO[x][y][z].affiche(sortie);

            }
        }
    }

}

// Surcharge de l'opérateur <<
std::ostream& operator << (std::ostream& sortie, const ChampsPotentiels& champ)
{
     champ.affiche(sortie);
     return sortie;
}


