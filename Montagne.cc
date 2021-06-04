#include <cmath>
#include <iostream>
#include <vector>
#include "Montagne.h"
#include "Dessinable.h"
#include "SupportADessin.h"
using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Méthode virtuelle qui calcule l'altitude d'une montagne pure
double Montagne:: altitude(double const& a, double const& b) const 
{
	double altitude(H*exp(-((a-x0)*(a-x0))/(2*ex*ex)-((b-y0)*(b-y0))/(2*ey*ey)));
	if (altitude < 0.5) { return 0; }
	else { return altitude; }
}

// Méthode virtuelle permettant de modifier les attributs d'une montagne avec les valeurs passées en arguments
void Montagne:: set_montagne(double const& x, double const& y, double const& h, double const& ox, double const& oy) 
{
	x0 = x;
	y0 = y;
	H = h;
	ex = ox;
	ey = oy;
}

std::ostream& operator<<(ostream& sortie, Montagne const& montagne)
{
	return montagne.affiche(sortie);
}


// Méthode dessine_sur redéfinie
void Montagne::  dessine_sur(SupportADessin& a_dessiner)
{
	a_dessiner.dessine(*this);
	
}

std::ostream& Montagne:: affiche(std::ostream& sortie) const
{
	sortie << " une montagne : " << endl;
	sortie << " centre de la montagne (" << x0 << "," << y0 << ");" << endl;
	sortie << " hauteur maximale : " << H << endl;
	sortie << " étalement en x : " << ex << endl;
	sortie << " étalement en y : " << ey << endl;
	return sortie;
}

// Méthode donnant aux attributs de la i-ème montagne simple de la chaîne les valeurs passées en arguments
void ChaineDeMontagnes:: set_montagne(Montagne const& montagne) 
{
	montagnes_simples.push_back(montagne);
}

// Méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne 
double ChaineDeMontagnes:: altitude(double const& a, double const& b) const 
{
	double retour(0);

			for (size_t i(0); i < montagnes_simples.size(); ++i)
			{
				if (montagnes_simples[i].altitude(a, b) > retour)
				{
					retour = montagnes_simples[i].altitude(a, b); 
				}
			}

		
		
	
	return retour;
}

