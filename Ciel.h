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
	
    Ciel(const ChampsPotentiels& champ) : Boite3D<CubedAir>(champ.get_Nx(), champ.get_Ny(), champ.get_Nz(), champ.get_pas()) // Constructeur du ciel à partir d'un champ de potentiels donné
    {//rajouter le constructeur des cubes d'air
        for (int i(0); i < champ.get_Nx(); ++i)
		{
            for ( int j(0); j < champ.get_Ny(); ++j)
			{
                for ( int k(0); k < champ.get_Nz(); ++k)
				{
					tablO[i][j][k].set_vitesse(champ.vitesse(i, j, k)[0], champ.vitesse(i, j, k)[1], champ.vitesse(i, j, k)[2]);
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
	
	CubedAir precedente(double pas_temps, double x, double y, double z); // Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné

    virtual void dessine_sur(SupportADessin& a_dessiner) override;
		
	// constructeurs+ dessinesur+ affichage
};

	
