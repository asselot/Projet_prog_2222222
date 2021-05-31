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
	private:
	
	double erreur(); // Retourne la somme des carrés des normes des vecteurs laplaciens
	
	void iteration( double E = 0.1); // Aucune idée
	
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	
	public:
	
	ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1) : Boite3D(nox, noy, noz, p) {} // Constructeur d'un champ potentiel
	
	void initialise(double vi, const Montagne& mont); // Initialise les potentiels du champ potentiel
	
	bool estauxbords(Potentiel pot) const; // Retourne true si un potentiel est au bord de la boîte
	
	void calcule_laplaciens(); // Calcule la valeur des laplaciens sur l'ensemble du champ à partir des potentiels 
	
	void resolution ( double seuil = 2.2621843e-5, unsigned int max = 5000, bool verbeuse = false); //bruh
	
	std::array<double, 3> vitesse(unsigned int i, unsigned int j, unsigned int k) const; // Calcule la valeur de la vitesse du vent en un point donné
	
	double norme_vitesse(unsigned int pointi, unsigned int pointj, unsigned int pointk) const; // Norme de la vitesse
	
};
