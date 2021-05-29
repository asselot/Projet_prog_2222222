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
void CubedAir:: set_enthalpie(unsigned int pointx, unsigned int pointy, unsigned int pointz)
{
	enthalpie = (Physique::cte - Physique::g*pointz - 0.5*vitesse_norme()*vitesse_norme());
}

// Calcule la température en un point donné
void CubedAir:: set_temperature(unsigned int px, unsigned int py, unsigned int pz)
{
	set_enthalpie(px, py, pz);
	temperature = ((2.0/7.0)*enthalpie*(Physique::Mair_sec/Physique::R));
}

// Calcule la pression en un point donné
void CubedAir:: set_pression(unsigned int px, unsigned int py, unsigned int pz)
{
	set_temperature(px, py, pz);
	pression = Physique::Pinfini*pow(Physique::Tinfini, -3.5)*pow(temperature, 3.5);
}

// Calcule la pression de l'eau (Peau)
void CubedAir:: set_pression_partielle(unsigned int px, unsigned int py, unsigned int pz)
{
	set_pression(px, py, pz);
	pression_partielle = ((Physique::tau*pression)/((Physique::Meau/Physique::Mair_sec) + Physique::tau));
}

// Calcule la pression de la rosée (Prosée)
void CubedAir:: set_pression_vapeur_saturante(unsigned int px, unsigned int py, unsigned int pz)
{
	set_temperature(px, py, pz);
	pression = Physique::Pref*exp(13.96 - 5208.0/temperature);
}

// Détermine l'état du cube d'air, elle retourne true si il est sous forme de nuage 
void CubedAir:: set_etat(unsigned int px, unsigned int py, unsigned int pz)
{
	set_pression_partielle(px, py, pz);
	set_pression_vapeur_saturante(px, py, pz);
	etat = (pression_partielle > pression_vapeur_saturante);
}

// Retourne l'état du cube d'air (nuage ou non)
bool CubedAir :: get_etat() const
{
    return etat;
}

// Affiche 1 si le cube est un nuage, 0 sinon
void CubedAir:: affiche_etat() const
{
	if (etat == true)
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
void CubedAir:: affiche()
{
	cout << vitesse_norme()*vitesse_norme() << " " << enthalpie << " " << temperature << " " << pression << " " << pression_partielle << " " << pression_vapeur_saturante << " ";
	affiche_etat();
}
	
	
