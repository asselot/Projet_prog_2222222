#pragma once
#include <iostream>

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
	int get_Nx() const;
	int get_Ny() const;
	int get_Nz() const;
	double get_pas();
	
	// Getteur du triple tableau sera de nature différente pour les sous classes
	std::vector<std::vector<std::vector<T>>> get_tablO() const ;
	
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
