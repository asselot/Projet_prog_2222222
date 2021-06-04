#include <iostream>
#include "CubedAir.h"
#include "constantes.h"
#include "cmath"

using namespace Physique;
using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

CubedAir::CubedAir() { vitesse_cubedair[0] = 0; vitesse_cubedair[1] = 0; vitesse_cubedair[2] = 0; }  
	
CubedAir::CubedAir(std::array<double, 3> vit_init) : vitesse_cubedair(vit_init) {} 

// Calcule la norme de la vitesse d'un cube d'air 
double CubedAir:: vitesse_norme() const
{
	return sqrt(vitesse_cubedair[0]*vitesse_cubedair[0] + vitesse_cubedair[1]*vitesse_cubedair[1] + vitesse_cubedair[2]*vitesse_cubedair[2]);
}

double CubedAir:: v2() const
{
	return vitesse_cubedair[0]*vitesse_cubedair[0] + vitesse_cubedair[1]*vitesse_cubedair[1] + vitesse_cubedair[2]*vitesse_cubedair[2];
}

// Calcule l'enthalpie en un point donné
double CubedAir:: enthalpie(unsigned int pz, double pas) const
{
	return Physique::cte - Physique::g*pz*pas - 0.5*v2();
}

// Calcule la température en un point donné
double CubedAir:: temperature(unsigned int pz, double pas) const
{
	return (2.0/7.0)*enthalpie(pz, pas)*(Physique::Mair_sec/Physique::R);
}

// Calcule la pression en un point donné
double CubedAir:: pression(unsigned int pz, double pas) const
{
	return (Physique::Pinfini*pow(Physique::Tinfini, -3.5)*pow(temperature(pz, pas), 3.5));
}

// Calcule la pression de l'eau (Peau)
double CubedAir:: pression_partielle(unsigned int pz, double pas) const
{
	return ((pression(pz, pas))*((Physique::tau)/(((Physique::Meau)/(Physique::Mair_sec)) + Physique::tau)) -16);
}

// Calcule la pression de la rosée (Prosée)
double CubedAir:: pression_vapeur_saturante(unsigned int pz, double pas) const
{
	return Physique::Pref*exp(13.96 - 5208.0/temperature(pz, pas));
}

// Détermine l'état du cube d'air, elle retourne true si il est sous forme de nuage 
bool CubedAir:: etat(unsigned int pz, double pas) const
{
	return (pression_partielle(pz, pas) > pression_vapeur_saturante(pz, pas));
}

// Affiche 1 si le cube est un nuage, 0 sinon
void CubedAir:: affiche_etat(unsigned int pz, double pas) const
{
	if (etat(pz, pas))
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
void CubedAir:: affiche(ostream& sortie, unsigned int pz, double pas) const
{
    sortie << vitesse_norme()*vitesse_norme() << " " << enthalpie(pz, pas) << " " << temperature(pz, pas) << " " << pression(pz, pas) << " " << pression_partielle(pz, pas) << " " << pression_vapeur_saturante(pz, pas) << " ";
	affiche_etat(pz, pas);
}
