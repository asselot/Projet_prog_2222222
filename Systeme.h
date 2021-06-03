#pragma once
#include <iostream>
#include "Montagne.h"
#include "Ciel.h"
#include "ChampsPotentiels.h"
#include "constantes.h"


// Représente ce qui forme un système physique

class Systeme : public Dessinable

{

private :

// Interdiction de la copie: conceptuellement problématique
Systeme(Systeme& systeme) = delete;

public :

// Constructeur à partir d'une montagne déjà initialisée et des dimensions de la boîte
Systeme (int const&  nx, int const&  ny, int const&  nz, double const&  pas,  Montagne const& M);

// Destructeur de la classe
~Systeme() = default;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Fait appel aux méthodes affiche() des différents composants du système
std::ostream& affiche (std::ostream& sortie) const;

// Démarre modélisation du système : créer un champ de potentiel et un ciel, dessine et fait évoluer le système 
void demarre (SupportADessin& a_dessiner);

// Fait évoluer le système (surtout nuage?)
void evolue (SupportADessin& a_dessiner);

// Méthode dessine_sur() héritée de Dessinable
virtual void dessine_sur(SupportADessin& a_dessiner) override;

// En public pour le graphisme


ChampsPotentiels champs;
Ciel ciel;
ChaineDeMontagnes chaine;

};

//--------------------------------------------------------------ATTRIBUTS-------------------------------------------------------------//

std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys);
