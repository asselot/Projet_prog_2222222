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
~Systeme() {}

{ 
	delete ptr_champs;
	delete ptr_ciel;
	delete ptr_hill;
}

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Fait appel aux méthodes affiche() des différents composants du système
virtual void affiche ();

// Démarre modélisation du système : créer un champ de potentiel et un ciel, dessine et fait évoluer le système 
virtual void demarre ();

// Méthode dessine_sur() héritée de Dessinable
virtual void dessine_sur() override;

private : 

// Fait évoluer le système (surtout nuage?)
virtual void evolue ();

//--------------------------------------------------------------ATTRIBUTS-------------------------------------------------------------//

ChampsPotentiels* ptr_champs;
Ciel* ptr_ciel;
Montagne* ptr_hill;

//--------------------------------------------------------------OPERATEUR-------------------------------------------------------------//

friend std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys); 
	
// Interdiction de la copie: conceptuellement problématique
Systeme(Systeme& systeme) = delete; 
};
