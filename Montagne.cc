#include <cmath>
#include <iostream>
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

// Méthode permettant d'afficher les attributs d'une montagne
/*void Montagne :: affiche_para(ostream& sortie) const
{
	sortie << " une montagne : " << endl;
	sortie << type << " de paramètre : " << endl;
	sortie << " centre de la montagne (" << x0 << "," << y0 << ");" << endl;
	sortie << " hauteur maximale : " << H << endl;
	sortie << " étalement en x : " << ex << endl;
	sortie << " étalement en y : " << ey << endl;
	
	
}*/

std::ostream& operator<<(std :: ostream& sortie, Montagne const& montagne)
{
    sortie << " une montagne : " << std ::  endl;
    sortie << " centre de la montagne (" << montagne.get_x0() << "," << montagne.get_y0() << ");" << std :: endl;
    sortie << " hauteur maximale : " << montagne.get_H() << std :: endl;
    sortie << " étalement en x : " << montagne.get_ex() << std :: endl;
    sortie << " étalement en y : " << montagne.get_ey() << std :: endl;
	return sortie;
}



// Méthode dessine_sur redéfinie héritée par Dessinable
void Montagne::  dessine_sur(SupportADessin& a_dessiner)
{
	a_dessiner.dessine(*this);
	
}

double Montagne:: get_x0() const
{
	return x0;
}
	
double Montagne:: get_y0() const
{
	return y0;
}
	
double Montagne:: get_H() const
{
	return H;
}
	
double Montagne:: get_ex() const
{
	return ex;
}
	
double Montagne:: get_ey() const
{
	return ey;
}


// Constructeur d'une montagne à partir d'un centre, une hauteur et un certain étalement
Montagne :: Montagne(double const& x, double const& y, double const& h, double const& ox, double const& oy, int const& dim)
    : x0(x), y0(y), H(h), ex(ox), ey(oy), dimension(dim) {}

// Constructeur à partir d'une montagne
Montagne :: Montagne(const Montagne& montagne)
    : Montagne(montagne.get_x0(), montagne.get_y0(), montagne.get_H(), montagne.get_ex(), montagne.get_ey(), montagne.get_dimension())
{}

ChaineDeMontagnes :: ChaineDeMontagnes(Montagne const& mont) : Montagne(mont)
{
    montagnes_simples.push_back(mont);
}
void ChaineDeMontagnes:: affiche(ostream& sortie) const
{
    for (auto const& element : montagnes_simples)
    {
        sortie << element;
    }

}

ostream& operator<<(ostream& sortie, ChaineDeMontagnes const& chaine)
{
    chaine.affiche(sortie);
    return sortie;
}

