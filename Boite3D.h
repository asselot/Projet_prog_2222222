#pragma once
#include <iostream>
#include <string>

template <typename T1>

class Boite3D
{
	public:
	Boite3D(unsigned int nomx, unsigned int nomy, unsigned int nomz, double ps) : Nx(nomx), Ny(nomy), Nz(nomz), pas(ps) {}
	int getNx();
	int getNy();
	int getNz();
	double getpas();
	
	virtual void affiche() = 0;
	
	protected:
	unsigned int Nx;
	unsigned int Ny;
	unsigned int Nz;
	double pas;
	
	private : 
	
	
// on cherche a pouvoir creer un triple vector dont on peut choisir le type dans les classes suivantes et dont on pourrais changer le nom	
 std::vector<std::vector<std::vector<T1>>> nom; 
};
