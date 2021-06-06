#include <cmath>
#include <iostream>
#include <vector>
#include "Montagne.h"
#include "Dessinable.h"
#include "SupportADessin.h"
using namespace std;

//--------------------------------------------------------------CONSTRUCTEURS & DESTRUCTEURS-------------------------------------------------------------//

// Constructeur d'une montagne à partir d'un centre, une hauteur et un certain étalement
Montagne :: Montagne(double const& x, double const& y, double const& h, double const& ox, double const& oy, int const& dim)
: x0(x), y0(y), H(h), ex(ox), ey(oy), dimension(dim) {}

// Destructeur
Montagne:: ~Montagne() {}

//--------------------------------------------------------------METHODES & OPERATEURS D'AFFICHAGE-------------------------------------------------------------//

// Méthode affiche pour une montagne
std::ostream& Montagne:: affiche(std::ostream& sortie) const
{
    sortie << " une montagne : " << endl;
    sortie << " centre de la montagne (" << x0 << "," << y0 << ");" << endl;
    sortie << " hauteur maximale : " << H << endl;
    sortie << " étalement en x : " << ex << endl;
    sortie << " étalement en y : " << ey << endl;
    return sortie;
}

// Surcharge de << pour une Montagne
std::ostream& operator<<(ostream& sortie, Montagne const& montagne)
{
    return montagne.affiche(sortie);
}

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Méthode virtuelle qui calcule l'altitude d'une montagne pure
double Montagne:: altitude(double const& a, double const& b) const 
{
	double altitude(H*exp(-((a-x0)*(a-x0))/(2*ex*ex)-((b-y0)*(b-y0))/(2*ey*ey)));
	if (altitude < 0.5) { return 0; }
	else { return altitude; }
}

// Méthode dessine_sur redéfinie
void Montagne::  dessine_sur(SupportADessin& support)
{
	support.dessine(*this);
}

// Retourne la dimension de la boite - necessaire pour itérer sur les altitudes afin de dessiner la montagne - cf vue_opengl.cc
int Montagne::  get_dimension() const
{
    return dimension;
}


