#pragma once
#include <iostream>
#include "Montagne.h"
#include "Ciel.h"
#include "ChampsPotentiels"

// Représente ce qui forme un système physique

class Systeme : public Dessinable 
{
	
public :

// Constructeur de copie nécessaire 
Systeme (Montagne& M, Ciel& C, ChampsPotentiels& Ch)
: ptr_champs(*Ch), ptr_ciel(*C), ptr_hill(*M) {}

// Destructeur de la classe : delete chaque attributs car ce sont des pointeurs
~Systeme() 
{ 
	delete ptr_champs;
	delete ptr_ciel;
	delete ptr_hill;
}

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

virtual void affiche ();
virtual void demarre ();
virtual void dessine_sur() override;


private : 

//--------------------------------------------------------------ATTRIBUTS-------------------------------------------------------------//

ChampsPotentiels* ptr_champs;
Ciel* ptr_ciel;
Montagne* ptr_hill;
virtual void evolue ();

//--------------------------------------------------------------OPERATEUR-------------------------------------------------------------//

	friend std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys); 

};
