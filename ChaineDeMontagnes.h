#pragma once
#include <iostream> 
#include <cmath>
#include <vector>
#include <iostream>
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Montagne.h"

// Classe représentant les chaînes de montagnes

class ChaineDeMontagnes : public Montagne
{
	private:
	
	std::vector<Montagne> montagnes_simples; // Tableau de montagnes simples
	
	public: 
	
//--------------------------------------------------------------CONSTRUCTEURS & DESTRUCTEUR-------------------------------------------------------------//
	
	// Constructeur à partir d'une montagne
	ChaineDeMontagnes(const Montagne& mont);
	
	// Constructeur d'une chaine à partir des élements d'une montagne
    ChaineDeMontagnes(double const& x, double const& y, double const& h, double const& ox, double const& oy, int const& dim);
	
	// Constructeur de copie
    ChaineDeMontagnes( ChaineDeMontagnes const& ch) = default;

	// Destructeur
    virtual ~ChaineDeMontagnes() override;
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	// Ajoute une montagne à la chaîne
	void add_montagne(Montagne const& montagne); 
	
	// Retourne le maximum des altitudes des montagnes simples qui composent la chaîne 
	double altitude(double const& a, double const& b) const override;
	
	// Permet d'obtenir des montagnes de la chaine
    Montagne get_montagnes_simples(int const& x) const;

    // Retourne la taille de la chaine
    unsigned int  get_taille() const;
	
	// Affiche une chaîne de montagnes
	std::ostream& affiche(std::ostream& sortie) const;
	
	// Méthode dessine_sur redéfinie pour la classe
	void dessine_sur(SupportADessin& support) override;
	
};

// Surcharge de l'opérateur << pour l'affichage d'une chaîne
std::ostream& operator<<(std::ostream& sortie, ChaineDeMontagnes const& chaine);
