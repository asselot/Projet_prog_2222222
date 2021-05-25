#pragma once
#include <iostream>
#include "Boite3D.h"

class CubedAir
{	
  public:
	CubedAir(bool nuage) : etat(nuage) {}
	
	//coordonnees de la vitesse du vent -> méthode ou attribut? voir complément mathématique, est-ce que c'est la méthode vitesse qui nous donne ces valeurs? si oui alors attribut
	//cest la norme de la vitesse obtenue dans la methode vitesse donc probablement pas... cest plutot au niveau conceptuel
	
	void set_enthalpie(unsigned int pointx, unsigned int pointy, unsigned int pointz, ChampsPotentiels champo);
	void set_temperature(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1);
	double pression(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1);
	double pression_partielle(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1);
	double pression_vapeur_saturante(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1);
	
	//vu que l'enthalpie dépend de l'altitude est-ce qu'il serait pas mieux de la mettre en méthode du cube d'air comme ça on accède aussi aux coordonnees de la vitesse et tout le monde est content?
	void set_etat(unsigned int px, unsigned int py, unsigned int pz, ChampsPotentiels champo1);
	bool get_etat();
	
	private:
	double enthalpie;
	double temperature;
	bool etat;
};
