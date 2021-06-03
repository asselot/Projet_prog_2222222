#pragma once

#include <iostream>
#include <vector>

// Super classe qui définit une boîte en 3D où va être définit le système physique
// Ciel et ChampsPotentiels sont des boîte 3D --> héritage

// T : variable utilisée dans le triple tableau, CubedAir pour le Ciel et des Potentiels pour le champ de potentiels
template <typename T>
class Boite3D
{
	
	protected:

	unsigned int Nx; // Nombre de cubes dans la boîte dans la direction x
	 
	unsigned int Ny; // Nombre de cubes dans la boîte dans la direction y
	
	unsigned int Nz; // Nombre de cubes dans la boîte dans la direction x
	
	double pas; // Pas séparant les cubes 
	
    std::vector<std::vector<std::vector<T>>> tablO; // Tableau tridimensionnel dont le type de variables sera déterminé lors de la déclaration d'une sous classe
    
    
//--------------------------------------------------------------METHODES-------------------------------------------------------------//


	public:

    // Constructeur d'une Boîte3D
    Boite3D(unsigned int nomx, unsigned int nomy, unsigned int nomz, double ps)
        : Nx(nomx), Ny(nomy), Nz(nomz), pas(ps)
    {
        std::vector<T> v1D(Nx);
        std::vector<std::vector<T>> v2D(Ny,v1D);
        std::vector<std::vector<std::vector<T>>> v3D(Nz, v2D);
        tablO = v3D;



    }
	
    int get_Nx() const { return Nx; } // Retourne le nombre de cubes selon x
	
    int get_Ny() const {return Ny; } // Retourne le nombre de cubes selon y
	
    int get_Nz() const { return Nz; } // Retourne le nombre de cubes selon z
	
    double get_pas() const { return pas; } // Retourne le pas


    std::vector<std::vector<std::vector<T>>> get_tablO() const { return tablO; } // Retourne le tableau tridimensionnel
	
	
};


// Affiche les paramètres de la boîte

template <typename T>
std::ostream& operator << (std::ostream& sortie, Boite3D <T> const& b)
{
    sortie << "Dimension de la boîte :" << std::endl;
    sortie << "Nx: " << b.get_Nx() << " Ny : " << b.get_Ny() << " Nz : " << b.get_Nz() << std:: endl;
    sortie << "Le pas des cubes :" << b.get_pas() << std::endl;

    for (int x(0); x < b.get_Nx(); ++x)
    {
        for ( int y(0); y < b.get_Ny(); ++y)
        {
            for (int z(0); z < b.get_Nz(); ++z)
            {

                    (b.get_tablO()[x][y][z]).affiche(sortie);

            }
        }
    }
return sortie;
}
