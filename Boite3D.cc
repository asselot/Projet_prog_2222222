#include <iostream>
#include "Boite3D.h"
#include <vector>

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

using namespace std;

// Retourne le nombre de cubes selon x
int Boite3D:: getNx() const 
{
	return Nx;
}

// Retourne le nombre de cubes selon y
int Boite3D:: getNy() const 
{ 
	return Ny;
} 

// Retourne le nombre de cubes selon z
int Boite3D:: getNz() const 
{
	return Nz;
}

// Retourne le pas
double Boite3D:: getpas() const 
{
	return pas;
}

// Retourne le tableau tridimensionnel
std::vector<std::vector<std::vector<T>>> get_tablO() const 
{
	return tablO;
}
