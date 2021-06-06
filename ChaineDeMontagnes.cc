#include <cmath>
#include <iostream>
#include <vector>
#include "ChaineDeMontagnes.h"
#include "Montagne.h"
#include "Dessinable.h"
#include "SupportADessin.h"

using namespace std;

//--------------------------------------------------------------CONSTRUCTEURS & DESTRUCTEUR-------------------------------------------------------------//

// Constructeur d'une chaine à partir d'une montagne
ChaineDeMontagnes :: ChaineDeMontagnes(Montagne const& mont)
: Montagne(mont)
{
	montagnes_simples.push_back(mont);
}

// Constructeur d'une chaine à partir des élements d'une montagne
ChaineDeMontagnes :: ChaineDeMontagnes(double const& x, double const& y, double const& h, double const& ox, double const& oy, int const& dim)
{
	Montagne M(x, y, h, ox, oy, dim);
	montagnes_simples.push_back(M);
}

// Destructeur
ChaineDeMontagnes:: ~ChaineDeMontagnes() {}

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Ajoute une montagne à la chaîne
void ChaineDeMontagnes:: add_montagne(Montagne const& montagne) 
{
	montagnes_simples.push_back(montagne);
}

// Permet d'obtenir les montagnes simples de la chaine
Montagne ChaineDeMontagnes:: get_montagnes_simples(int const& x) const
{
    return montagnes_simples[x];
}

// Retourne la taille de la montagne
unsigned int ChaineDeMontagnes::  get_taille() const
{
    return montagnes_simples.size();
}

// Retourne le maximum des altitudes des montagnes simples qui composent la chaîne 
double ChaineDeMontagnes:: altitude(double const& a, double const& b) const 
{
	double retour(0);

	for (size_t i(0); i < montagnes_simples.size(); ++i)
	{
		if (montagnes_simples[i].altitude(a, b) > retour) // Détermine le maximum des altitudes des montagnes de la chaîne
		{
			retour = montagnes_simples[i].altitude(a, b); 
		}
	}
	return retour;
}

// Affiche une chaîne de montagnes
std::ostream& ChaineDeMontagnes:: affiche(std::ostream& sortie) const 
{
	sortie << "Une chaine de montagne composée des " << montagnes_simples.size() << " montagnes simples suivantes :" << endl;
	
	for (auto const& element : montagnes_simples)
	{
		sortie << element;
		sortie << endl;
	}
	return sortie;
}

// Méthode dessine_sur redéfinie pour la classe
void ChaineDeMontagnes::  dessine_sur(SupportADessin& support)
{
	support.dessine(*this);
}

// Surcharge de l'opérateur << pour l'affichage d'une chaîne
std::ostream& operator<<(std::ostream& sortie, ChaineDeMontagnes const& chaine)
{
	return chaine.affiche(sortie);
}
