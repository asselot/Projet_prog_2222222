#pragma once
#include <iostream>
#include "Montagne.h"
#include "Ciel.h"
#include "ChampsPotentiels.h"

// Représente ce qui forme un système physique

class Systeme : public Dessinable

{
	
public :


Systeme (Systeme const& S);

// Constructeur de copie nécessaire 
Systeme (Montagne& M, Ciel& C, ChampsPotentiels& Ch)
: ptr_champs(new ChampsPotentiels(Ch)), ptr_ciel(new Ciel(C)), ptr_hill(new Montagne(M)) {}

// Destructeur de la classe : delete chaque attributs car ce sont des pointeurs
~Systeme()
{
    ptr_champs->~ChampsPotentiels();
    delete ptr_champs;
    ptr_champs = nullptr;
    delete ptr_ciel;
    delete ptr_hill;
}

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Fait appel aux méthodes affiche() des différents composants du système
std::ostream& affiche (std::ostream& sortie) const;

// Démarre modélisation du système : créer un champ de potentiel et un ciel, dessine et fait évoluer le système 
void demarre (SupportADessin& a_dessiner);

// Méthode dessine_sur() héritée de Dessinable
virtual void dessine_sur(SupportADessin& a_dessiner) override;

private : 

// Fait évoluer le système (surtout nuage?)
void evolue (SupportADessin& a_dessiner);

//--------------------------------------------------------------ATTRIBUTS-------------------------------------------------------------//

ChampsPotentiels* ptr_champs;
Ciel* ptr_ciel;
Montagne* ptr_hill;

//--------------------------------------------------------------OPERATEUR-------------------------------------------------------------//

	
// Interdiction de la copie: conceptuellement problématique
Systeme(Systeme& systeme) = delete; 
};

std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys);
