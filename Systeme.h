#pragma once
#include <iostream>
#include "Montagne.h"
#include "Ciel.h"
#include "ChampsPotentiels.h"
#include "constantes.h"


// Représente ce qui forme un système physique

class Systeme : public Dessinable

{

public :

//--------------------------------------------------------------CONSTRUCTEURS ET DESTRUCTEUR-------------------------------------------------------------//

// Constructeur à partir d'une montagne déjà initialisée et des dimensions de la boîte et d'une montagne
Systeme (int const&  nx, int const&  ny, int const&  nz, double const&  pas,  Montagne const& M);

// Constructeur à partir d'une montagne déjà initialisée et des dimensions de la boîte et d'une chaine
Systeme (int const&  nx, int const&  ny, int const&  nz, double const&  pas,  ChaineDeMontagnes const& Ch);


// Construteur à partir d'un autre systeme
Systeme(const Systeme& systeme) = delete;

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

//--------------------------------------------------------------ATTRIBUTS-------------------------------------------------------------//

// En public pour le graphisme -> faire des getteurs ?

ChampsPotentiels champs;
Ciel ciel;
ChaineDeMontagnes chaine;

};


std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys);
