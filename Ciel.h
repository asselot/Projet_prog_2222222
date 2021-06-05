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



	public:

    // Constructeur du ciel à partir d'un champ de potentiels donné (avec initialisation des CubedAirs)
    Ciel(ChampsPotentiels const& champ);

    // Constructeur à partir de dimensions données (avec initialisation des CubedAirs)
    Ciel(double const& Nx, double const& Ny, double const& Nz, double const& pas);

    // Constructeur à partir d'un ciel (avec initialisation des CubedAirs)
    Ciel(Ciel const& C);

    // Calcul du déplacement du nuage pendant un temps donné à partir d'un point donné
    CubedAir precedente(double& pas_temps, double& x, double& y, double& z);

    // Initialise l'état des cubes d'air
    void initialise();

    // Méthode héritée de Dessinable
    virtual void dessine_sur(SupportADessin& a_dessiner) override;
		
    // Destructeur de la classe
    virtual ~Ciel() = default;

    // Affiche les paramètres du ciel
     void affiche(std::ostream& sortie) const;
};

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& sortie, const Ciel& ciel);
