#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "Vecteur2D.h"
#include "constantes.h"
#include "Boite3D.h"
#include "Potentiel.h"
#include "Montagne.h"


class ChampsPotentiels : public Boite3D<Potentiel>
{
	
	public:

	
	// Contructeur qui va construir par défaut une boîte 30x30x30 cubes de pas 1
	ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1) : Boite3D(nox, noy, noz, p) {}
	
	
//--------------------------------------------------------------METHODES--------------------------------------------------------------------//

        
	// Initialise les potentiels de la boîte 
	void initialise (double vi, const Montagne& mont);
	
	
	// Retourne true si un potentiel (vecteur) est au bord de la boîte
	bool estauxbords (Potentiel pot) const;
	
	
	// Calcule le laplacien en tout point intérieur de la boîte
	void calcule_laplaciens();
	
	
	void iteration (double E = 0.1);
	
	
	void resolution (double seuil = 2.2621843e-5, unsigned int max = 5000, bool verbeuse = false);
	
	
	// Retourne le vecteur vitesse sous forme de tableau fixe (les trois coordonées)
	std::array<double, 3> vitesse (unsigned int i, unsigned int j, unsigned int k) const;
	
	double norme_vitesse (unsigned int pointi, unsigned int pointj, unsigned int pointk);

	// Méthode qui affiche le champ
	virtual void affiche() const override; 
		
	private:
	
	// Retourne la somme des carrés des normes des vecteurs laplaciens
	double erreur();
};
