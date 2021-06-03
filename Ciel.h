#pragma once 
#include <iostream>
#include <vector>
#include "Boite3D.h"
#include "CubedAir.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "ChampsPotentiels.h"

class Ciel : public Boite3D<CubedAir>, public Dessinable
{
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	friend class CubedAir;
	public:
	
    Ciel(ChampsPotentiels const& champ) : Boite3D<CubedAir>(champ.get_Nx(), champ.get_Ny(), champ.get_Nz(), champ.get_pas()) // Constructeur du ciel à partir d'un champ de potentiels donné
    {
        for (int i(0); i < champ.get_Nx(); ++i)
		{
			tablO.push_back(std::vector<std::vector<CubedAir>>());
            for ( int j(0); j < champ.get_Ny(); ++j)
			{
				tablO[i].push_back(std::vector<CubedAir>());
                for ( int k(0); k < champ.get_Nz(); ++k)
				{
					//CubedAir cube(CubedAir(champ.vitesse(i, j, k)));
					tablO[i][j].push_back(CubedAir(champ.vitesse(i, j, k)));
					//tablO[i][j][k].set_vitesse(champ.vitesse(i, j, k)[0], champ.vitesse(i, j, k)[1], champ.vitesse(i, j, k)[2]);
				}
			}
		}
	}
	
    Ciel(double Lx, double Ly, double Lz, double lambda) : Boite3D<CubedAir>(Lx, Ly, Lz, lambda) // Constructeur à partir de dimensions données
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
    
    //void initialise(const ChampsPotentiels& champi);
	
	CubedAir precedente(double pas_temps, double x, double y, double z); // Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné

    virtual void dessine_sur(SupportADessin& a_dessiner) override;
		
	// constructeurs+ dessinesur+ affichage
};

	
