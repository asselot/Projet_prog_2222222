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
	
    Ciel(ChampsPotentiels const& champ);
    Ciel(double Lx, double Ly, double Lz, double lambda);
    
    //void initialise(const ChampsPotentiels& champi);
	
	CubedAir precedente(double const& pas_temps, double& x, double& y, double& z, double const& pas); // Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné

    virtual void dessine_sur(SupportADessin& a_dessiner) override;
		
	// constructeurs+ dessinesur+ affichage
};

	
