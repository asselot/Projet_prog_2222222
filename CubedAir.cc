#include <iostream>
#include "CubedAir.h"
#include "constantes.h"
#include "cmath"

using namespace Physique;
using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//


// Calcule la norme de la vitesse d'un cube d'air 
double CubedAir:: vitesse_norme() const
{
	return sqrt(vitesse_cubedair[0]*vitesse_cubedair[0] + vitesse_cubedair[1]*vitesse_cubedair[1] + vitesse_cubedair[2]*vitesse_cubedair[2]);
}

// Calcule l'enthalpie en un point donné
double CubedAir:: enthalpie(unsigned int px, unsigned int py, unsigned int pz) const
{
	return Physique::cte - Physique::g*pz - 0.5*vitesse_norme()*vitesse_norme();
}

// Calcule la température en un point donné
double CubedAir:: temperature(unsigned int px, unsigned int py, unsigned int pz) const
{
	return (2.0/7.0)*enthalpie(px, py, pz)*(Physique::Mair_sec/Physique::R);
}

// Calcule la pression en un point donné
double CubedAir:: pression(unsigned int px, unsigned int py, unsigned int pz) const
{
	return (Physique::Pinfini*pow(Physique::Tinfini, -3.5)*pow(temperature(px, py, pz), 3.5));
}

// Calcule la pression de l'eau (Peau)
double CubedAir:: pression_partielle(unsigned int px, unsigned int py, unsigned int pz) const
{
	return ((Physique::tau*pression(px, py, pz))/((Physique::Meau/Physique::Mair_sec) + Physique::tau));
}

// Calcule la pression de la rosée (Prosée)
double CubedAir:: pression_vapeur_saturante(unsigned int px, unsigned int py, unsigned int pz) const
{
	return Physique::Pref*exp(13.96 - 5208.0/temperature(px, py, pz));
}

// Détermine l'état du cube d'air, elle retourne true si il est sous forme de nuage 
bool CubedAir:: etat(unsigned int px, unsigned int py, unsigned int pz) const
{
	return (pression_partielle(px, py, pz) > pression_vapeur_saturante(px, py, pz));
}

// Affiche 1 si le cube est un nuage, 0 sinon
void CubedAir:: affiche_etat(unsigned int px, unsigned int py, unsigned int pz) const
{
	if (etat(px, py, pz))
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}

// Associe les valeurs données aux coordonnées de la vitesse du cube 
void CubedAir:: set_vitesse(double coordx, double coordy, double coordz)
{
	vitesse_cubedair[0] = coordx;
	vitesse_cubedair[1] = coordy;
	vitesse_cubedair[2] = coordz;
}

// Affiche les différents attributs du cube d'air 
void CubedAir:: affiche(ostream& sortie, unsigned int px, unsigned int py, unsigned int pz) const
{
    sortie << vitesse_norme()*vitesse_norme() << " " << enthalpie(px, py, pz) << " " << temperature(px, py, pz) << " " << pression(px, py, pz) << " " << pression_partielle(px, py, pz) << " " << pression_vapeur_saturante(px, py, pz) << " ";
	affiche_etat(px, py, pz);
}
