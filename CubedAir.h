#pragma once
#include <iostream>
#include <array> 
#include "Boite3D.h"
#include "ChampsPotentiels.h"
#include "constantes.h"

class CubedAir
{	
	protected:
	std::array<double, 3> vitesse_cubedair; // Vitesse d'un cube 
	
	//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	friend class Ciel;
	public:
	
	CubedAir() { vitesse_cubedair[0] = 0; vitesse_cubedair[1] = 0; vitesse_cubedair[2] = 0; }
	
	CubedAir(std::array<double, 3> vit_init) : vitesse_cubedair(vit_init) {} 
	
	double enthalpie(unsigned int pointx, unsigned int pointy, unsigned int pointz) const; // Calcule l'enthalpie en un point donné
	
	double temperature(unsigned int px, unsigned int py, unsigned int pz) const; // Calcule la température en un point donné
	
	double pression(unsigned int px, unsigned int py, unsigned int pz) const; // Calcule la pression en un point donné
	
	double pression_partielle(unsigned int px, unsigned int py, unsigned int pz) const; // Calcule la pression de l'eau (Peau)
	
	double pression_vapeur_saturante(unsigned int px, unsigned int py, unsigned int pz) const; // Calcule la pression de la rosée (Prosée)
	
	bool etat(unsigned int px, unsigned int py, unsigned int pz) const; // Détermine l'état du cube d'air, elle retourne true si il est sous forme de nuage 
	
	void set_vitesse(double coordx, double coordy, double coordz); // Associe les valeurs données aux coordonnées de la vitesse du cube 
	
    void affiche(std::ostream& sortie, unsigned int px, unsigned int py, unsigned int pz) const; // Affiche les différents attributs du cube d'air
	
	double vitesse_norme() const; // Calcule la norme de la vitesse d'un cube d'air 
	
	void affiche_etat(unsigned int px, unsigned int py, unsigned int pz) const; // Affiche 1 si le cube est un nuage, 0 sinon
	
	//ENTHALPIE ET CSTE DE BERNOUILLI CHANGENT 
};
