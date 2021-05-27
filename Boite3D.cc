#include <iostream>
#inlude "Boite3D.h"

using namespace std;

double Boite3D:: getpas()
{
	return pas;
}

int Boite3D:: getNx()
{
	return Nx;
}

int Boite3D:: getNy()
{ 
	return Ny;
} 

int Boite3D:: getNz()
{
	return Nz;
}

std::vector<std::vector<std::vector<T>>> get_tablO() const 
{
	return tablO;
}


