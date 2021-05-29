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
	
	Ciel(const ChampsPotentiels& champ) : Boite3D(champ.getNx(), champ.getNy(), champ.getNz(), champ.getpas()) // Constructeur du ciel à partir d'un champ de potentiels donné
	{//rahjouter le constructeur des cubes d'air 
		for (unsigned int i(0); i < champ.getNx(); ++i)
		{
			for (unsigned int j(0); j < champ.getNy(); ++j)
			{
				for (unsigned int k(0); k < champ.getNz(); ++k)
				{
					tablO[i][j][k].set_vitesse(champ.vitesse(i, j, k)[0], champ.vitesse(i, j, k)[1], champ.vitesse(i, j, k)[2]);
				}
			}
		}
	}
	
	Ciel(double Lx, double Ly, double Lz, double lambda) : Boite3D(Lx, Ly, Lz, lambda) // Constructeur à partir de dimensions données
	{
		for (unsigned int i(0); i < Lx/lambda; ++i)
		{
			for (unsigned int j(0); j < Ly/lambda; ++j)
			{
				for (unsigned int k(0); k < Lz/lambda; ++k)
				{
					tabl0[i][j][k].set_vitesse(Physique::vinfini, 0, 0);
				}
			}
		}
	}
	
	CubedAir precedente(double pas_temps, double x, double y, double z); // Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné

	virtual void dessine_sur(SupportADessin& a_dessiner) override;
	
	virtual void affiche() override; // Méthode héritée de Boite3D qui affiche tous les cubes d'air du ciel
	
	// constructeurs+ dessinesur+ affichage
};


	
