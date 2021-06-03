#include <iostream>
#include <vector>
#include "Potentiel.h"

using namespace std;
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Affiche les attributs d'un potentiel
void Potentiel:: affiche(ostream& sortie) const
{
    sortie << poten << " " << laplacien << endl;
}

// Constructeur d'un potentiel
Potentiel :: Potentiel(Vecteur2D const& p, Vecteur2D const& l) : poten (p), laplacien (l) {}

// Constructeur initialisant les deux vecteurs à des vecteurs nuls
Potentiel :: Potentiel()
    : poten(), laplacien()
{}

// Permet d'afficher un potentiel par surcharge de <<
std::ostream& operator<<(std::ostream& sortie, Potentiel const& P)
{
    P.affiche(sortie);
    return sortie;
}

Vecteur2D Potentiel:: get_laplacien() const
{
    return laplacien;
}
Vecteur2D Potentiel:: get_poten() const
{
    return poten;
}

double Potentiel :: laplacien_norme2() const
{
    return laplacien.norme2();
}

void Potentiel:: set_laplacien(const double& x, const double& y)
{
	Vecteur2D V(x, y);
	set_laplacien(V);
}

void Potentiel:: set_poten(const Vecteur2D& V)
{
  poten = V;
}

void Potentiel:: set_poten(const double& x, const double& y)
{
	Vecteur2D V(x, y);
	set_poten(V);
}

 void Potentiel:: set_laplacien(const Vecteur2D& V)
 {
     laplacien = V;
 }
