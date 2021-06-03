#pragma once

#include <array>
#include "constantes.h"
#include "Boite3D.h"
#include "Potentiel.h"
#include "Montagne.h"

class ChaineDeMontagnes ;

class ChampsPotentiels : public Boite3D<Potentiel>{

	private:

    // Retourne la somme des carrés des normes des vecteurs laplaciens
    double erreur();
	
    void iteration(const ChaineDeMontagnes& chaine, const double& E = 0.1);

	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	
	public:
	
    // Constructeur à partir de coordonnées de la boîte (sans initialisation du tablO)
    ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1.0);


    // Constructeur à partir d'un autre champs (avec initialisation du tablO)
    ChampsPotentiels(ChampsPotentiels const& C);

    // destructeur du champs
    ~ChampsPotentiels() {};

    // Initialise les potentiels du champ potentiel
    void initialise(double vi, const Montagne& mont);
	
    // Retourne true si un potentiel est au bord de la boîte
    //bool estauxbords(Potentiel pot) const;
	
    // Calcule la valeur des laplaciens sur l'ensemble du champ à partir des potentiels
    void calcule_laplaciens(const ChaineDeMontagnes& chaine);

    void resolution (double const& seuil, unsigned int const&  max, bool const& verbeuse, const ChaineDeMontagnes& chaine);
	
    // Calcule la valeur de la vitesse du vent en un point donné
    std::array<double, 3> vitesse(unsigned int const& i, unsigned int const& j, unsigned int const& k) const;
	
    // Norme de la vitesse
    double norme_vitesse(unsigned int const& pointi, unsigned int const&  pointj, unsigned int const&  pointk) const;
	
};
