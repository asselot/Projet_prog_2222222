#pragma once

#include <array>
#include "constantes.h"
#include "Boite3D.h"
#include "Potentiel.h"
#include "Montagne.h"

class ChampsPotentiels : public Boite3D<Potentiel>
{

	private:
	
	
	
	void iteration(const ChaineDeMontagnes& chaine, const double& E = 0.1); // Aucune idée

	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	
	public:
	double erreur(); // Retourne la somme des carrés des normes des vecteurs laplaciens
    ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1) : Boite3D(nox, noy, noz, p) 
    {
	
        for (size_t i(1); i < Nz-1; ++i)
        {
            for(size_t j(1); j < Ny-1; ++j)
            {
                for (size_t k(1); k < Nx-1; ++k)
                {                   
					tablO[i][j][k].laplacien.coord_x = 0;
					tablO[i][j][k].laplacien.coord_y = 0;
				}
			}
		}

	} // Constructeur d'un champ potentiel
	
    virtual ~ChampsPotentiels() = default;
    
	void initialise(double vi, const Montagne& mont); // Initialise les potentiels du champ potentiel
	
	bool estauxbords(Potentiel pot) const; // Retourne true si un potentiel est au bord de la boîte
	
	void calcule_laplaciens(const ChaineDeMontagnes& chaine); // Calcule la valeur des laplaciens sur l'ensemble du champ à partir des potentiels 
	
	void resolution(double seuil, unsigned int max, bool verbeuse, const ChaineDeMontagnes& chaine); //bruh
	
	std::array<double, 3> vitesse(unsigned int i, unsigned int j, unsigned int k) const; // Calcule la valeur de la vitesse du vent en un point donné
	
	double norme_vitesse(unsigned int pointi, unsigned int pointj, unsigned int pointk) const; // Norme de la vitesse
	
};
