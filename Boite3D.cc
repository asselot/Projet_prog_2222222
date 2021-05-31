#include <iostream>
#include "Boite3D.h"
#include <vector>

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

using namespace std;

// Retourne le nombre de cubes selon x
int Boite3D:: get_Nx() const 
{
	return Nx;
}

// Retourne le nombre de cubes selon y
int Boite3D:: get_Ny() const 
{ 
	return Ny;
} 

// Retourne le nombre de cubes selon z
int Boite3D:: get_Nz() const 
{
	return Nz;
}

// Retourne le pas
double Boite3D:: get_pas() const 
{
	return pas;
}

// Retourne le tableau tridimensionnel
std::vector<std::vector<std::vector<T>>> get_tablO() const 
{
	return tablO;
}

// Affiche les paramètres de la boîte
void Boite3D :: affiche() const
{
	for (unsigned int x(0); x < Nx; ++x)
	{
		for (unsigned int y(0); y < Ny; ++y)
		{
			for (unsigned int z(0); z < Nz; ++z)
			{
				
					tablO[x][y][z].affiche();
				
			}
		}
	}
	
}

ostream& operator << (ostream& sortie, Boite3D& b)
{
	sortie << "Dimension de la boîte :" << endl;
	sortie << "Nx: " << get_Nx << " Ny : " << get_Ny << " Nz : " << get_Nz << endl;
	sortie << "Le pas des cubes :" << get_pas << endl;
	
	for (unsigned int x(0); x < get_Nx; ++x)
	{
		for (unsigned int y(0); y < get_Ny; ++y)
		{
			for (unsigned int z(0); z < get_Nz; ++z)
			{
				
					tablO[x][y][z].affiche();
				
			}
		}
	}
	
}

	
