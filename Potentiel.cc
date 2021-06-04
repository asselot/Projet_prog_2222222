#include <iostream>
#include <vector>
#include "Potentiel.h"

using namespace std;
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
Potentiel::Potentiel(Potentiel const& a_copier) : poten(a_copier.poten), laplacien(a_copier.laplacien) {}


// Affiche les attributs d'un potentiel
std::ostream& Potentiel:: affiche(ostream& sortie) const
{
    sortie << poten;
    return sortie;
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
    return P.affiche(sortie);
}

array<double, 3> Potentiel:: vitesse_potentiels(const Potentiel& imoins1jk, const Potentiel& ijmoins1k, const Potentiel& ijkmoins1, const Potentiel& iplus1jk, const Potentiel& ijplus1k, const Potentiel& ijkplus1) const
{
	array<double, 3> retour;
	retour[0] = ijplus1k.poten.soust_y(ijmoins1k.poten) + ijkmoins1.poten.soust_x(ijkplus1.poten);
	retour[1] = imoins1jk.poten.soust_y(iplus1jk.poten);
	retour[2] = iplus1jk.poten.soust_x(imoins1jk.poten);
	return retour;
}

void Potentiel:: potentiel_iteration(const double& E)
{
	poten = poten + laplacien * E;
}

void Potentiel:: calcule_laplacien(const Potentiel& imoins1jk, const Potentiel& ijmoins1k, const Potentiel& ijkmoins1, const Potentiel& iplus1jk, const Potentiel& ijplus1k, const Potentiel& ijkplus1) 
{
	Potentiel ijk(*this);
	laplacien = (imoins1jk.poten + ijmoins1k.poten + ijkmoins1.poten + iplus1jk.poten + ijplus1k.poten + ijkplus1.poten - 6 * ijk.poten);
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
