#include <iostream>
#include "CubeAir.h"

void CubedAir:: set_enthalpie(unsigned int pointx, unsigned int pointy, unsigned int pointz, ChampsPotentiels champo)
{
	enthalpie = (Physique::cte - Physique::g*pointz*champo.getpas() - 0.5*champo.norme_vitesse(pointx, pointy, pointz)*champo.norme_vitesse(pointx, pointy, pointz));
}
	
void CubedAir:: set_temperature(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1)
{
	set_enthalpie(px, py, pz, champo1);
	temperature = ((2.0/7.0)*enthalpie*(Physique::Mair_sec/Physique::R));
}

double CubedAir:: pression(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1)
{
	set_temperature(px, py, pz, champo1);
	return Physique::Pinfini*pow(Physique::Tinfini, -3.5)*pow(temperature, 3.5);
}

double CubedAir:: pression_partielle(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1)
{
	return ((Physique::tau*pression(px, py, pz, champo1))/((Physique::Meau/Physique::Mair_sec) + Physique::tau));
}

double CubedAir:: pression_vapeur_saturante(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1)
{
	set_temperature(px, py, pz, champo1);
	return Physique::Pref*exp(13.96 - 5208.0/temperature);
}

void CubedAir:: set_etat(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1)
{
	etat = (pression_partielle(px, py, pz, champo1) > pression_vapeur_saturante(px, py, pz, champo1));
}
bool CubedAir :: get_etat()
{
    return etat;
}

