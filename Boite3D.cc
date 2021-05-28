#include <iostream>
#include <vector>
#inlude "Boite3D.h"

using namespace std;

double Boite3D:: get_pas()
{
	return pas;
}

int Boite3D:: get_Nx()
{
	return Nx;
}

int Boite3D:: get_Ny()
{ 
	return Ny;
} 

int Boite3D:: get_Nz()
{
	return Nz;
}

std::vector<std::vector<std::vector<T>>> get_tablO() const 
{
	return tablO;
}


