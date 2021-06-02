#pragma once
#include <iostream>
#pragma once
#include <iostream>
#include "Boite3D.h"
#include "ChampsPotentiels.h"
#include "constantes.h"

class CubedAir
{	
	private:
	double enthalpie; // Enthalpie d'un cube
	
	double temperature; // Température d'un cube
	
	double pression; // Pression d'un cube 
	
	double pression_partielle; // Pression de l'eau dans un cube 
	
	double pression_vapeur_saturante; // Pression de la rosée dans un cube 
	
	protected:
	bool etat; // Etat d'un cube (nuage ou non)
	
	std::array<double, 3> vitesse_cubedair; // Vitesse d'un cube 
	
	//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	friend class Ciel;
	public:
	CubedAir() : enthalpie(0), temperature(0), pression(0), pression_partielle(0), pression_vapeur_saturante(0), etat(false) {} // Constructeur d'un cube d'air 
	
	void set_enthalpie(unsigned int pointx, unsigned int pointy, unsigned int pointz); // Calcule l'enthalpie en un point donné
	
	void set_temperature(unsigned int px, unsigned int py, unsigned int pz); // Calcule la température en un point donné
	
	void set_pression(unsigned int px, unsigned int py, unsigned int pz); // Calcule la pression en un point donné
	
	void set_pression_partielle(unsigned int px, unsigned int py, unsigned int pz); // Calcule la pression de l'eau (Peau)
	
	void set_pression_vapeur_saturante(unsigned int px, unsigned int py, unsigned int pz); // Calcule la pression de la rosée (Prosée)
	
	void set_etat(unsigned int px, unsigned int py, unsigned int pz); // Détermine l'état du cube d'air, elle retourne true si il est sous forme de nuage 
	
	bool get_etat() const; // Retourne l'état du cube d'air (nuage ou non)
	
	void set_vitesse(double coordx, double coordy, double coordz); // Associe les valeurs données aux coordonnées de la vitesse du cube 
	
    void affiche(std :: ostream& sortie) const; // Affiche les différents attributs du cube d'air
	
	double vitesse_norme() const; // Calcule la norme de la vitesse d'un cube d'air 
	
	void affiche_etat() const; // Affiche 1 si le cube est un nuage, 0 sinon
	
};
