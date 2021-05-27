#pragma once
#include <iostream>
#include <string>

// Super classe qui définit une boîte en 3D où va être définit le système physique
// Ciel et ChampsPotentiels sont des boîte 3D --> héritage

// T : variable utilisée dans le triple tableau, CubedAir pour le Ciel et des Potentiels pour le champ de potentiels
template <typename T>

class Boite3D
{
	public:
	
	// Constructeur
	Boite3D(unsigned int nomx, unsigned int nomy, unsigned int nomz, double ps) : Nx(nomx), Ny(nomy), Nz(nomz), pas(ps) {}
	
	// Getteurs
	int getNx() const;
	int getNy() const;
	int getNz() const;
	double getpas();
	
	// Getteur en virtuel pur car le triple tableau sera de nature différente pour les sous classes
	std::vector<std::vector<std::vector<T>>> get_tablO() const = 0;
	
	// Méthode affiche définie différemment pour les sous classes, d'où la méthode virtuelle pure
	virtual void affiche() const = 0;
	
	protected:
	
	unsigned int Nx;
	unsigned int Ny;
	unsigned int Nz;
	double pas;
	
	private : 
	
        // On cherche a pouvoir créer un triple vector dont on peut choisir le type dans les sous classes	
        std::vector<std::vector<std::vector<T>>> tablO; 
	
};
