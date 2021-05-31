#pragma once
#include <iostream>
#include <vector>

// Super classe qui définit une boîte en 3D où va être définit le système physique
// Ciel et ChampsPotentiels sont des boîte 3D --> héritage

// T : variable utilisée dans le triple tableau, CubedAir pour le Ciel et des Potentiels pour le champ de potentiels
template <typename T> class Boite3D
{
	
	protected:
	unsigned int Nx; // Nombre de cubes dans la boîte dans la direction x
	 
	unsigned int Ny; // Nombre de cubes dans la boîte dans la direction y
	
	unsigned int Nz; // Nombre de cubes dans la boîte dans la direction x
	
	double pas; // Pas séparant les cubes 
	
    std::vector<std::vector<std::vector<T>>> tablO; // Tableau tridimensionnel dont le type de variables sera déterminé lors de la déclaration d'une sous classe
    
    
//--------------------------------------------------------------METHODES-------------------------------------------------------------//


	public:
	Boite3D(unsigned int nomx, unsigned int nomy, unsigned int nomz, double ps) : Nx(nomx), Ny(nomy), Nz(nomz), pas(ps) {} // Constructeur d'une Boîte3D
	
	int get_Nx() const; // Retourne le nombre de cubes selon x
	
	int get_Ny() const; // Retourne le nombre de cubes selon y
	
	int get_Nz() const; // Retourne le nombre de cubes selon z
	
	double get_pas() const; // Retourne le pas
	
	virtual void affiche() const; // Méthode virtuelle pure permettant d'afficher une instance 
	
	std::vector<std::vector<std::vector<T>>> get_tablO() const; // Retourne le tableau tridimensionnel
	
	
};

std :: ostream& operator << (std :: ostream& sortie, Boite3D& b);
