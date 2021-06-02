#pragma once 
#include <iostream>
#include "Vecteur2D.h"

class Potentiel
{
	protected:
	Vecteur2D poten; // Potentiel en lui-même 
	
	private:
	Vecteur2D laplacien; // Laplacien qui lui est associé

	
	friend class ChampsPotentiels; // Permet à la classe Champs Potentiels d'accéder à ses attributs protégés
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	public:
    Potentiel() = default;
    Potentiel(Vecteur2D const& p, Vecteur2D const& l) : poten(p), laplacien(l) {} // Constructeur d'un potentiel
	
    void affiche(std :: ostream& sortie) const; // Affiche les attributs d'un potentiel
	
};
