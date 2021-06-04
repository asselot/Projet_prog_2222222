#pragma once
#include <iostream> 
#include <cmath>
#include <vector>
#include <iostream>
#include "Dessinable.h"
#include "SupportADessin.h"

class Montagne : public Dessinable 
{
	private:
	
	double x0; // Coordonnée en x du centre de la montagne 
	
	double y0; // Coordonnée en y du centre de la montagne 
	
	double H; // Hauteur de la montagne 
	
	double ex; // Etalement en x de la montagne 
	
	double ey; // Etalement en y de la montagne 
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	public: 
	Montagne(double x, double y, double h, double ox, double oy) : x0(x), y0(y), H(h), ex(ox), ey(oy) {} // Constructeur d'une montagne avec des valeurs données 
	
	~Montagne() {}
	
	virtual double altitude(double const& a, double const& b) const; // Méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne 
	
	virtual void set_montagne(double const& x, double const& y, double const& h, double const& ox, double const& oy); // Méthode permettant de modifier les attributs d'une montagne avec les valeurs passées en arguments
			
	void dessine_sur(SupportADessin &a_dessiner) override ; // Méthode dessine_sur redéfinie
	
	std::ostream& affiche(std::ostream& sortie) const;
	
};

    std::ostream& operator<<(std::ostream& sortie, Montagne const& montagne);


class ChaineDeMontagnes : public Montagne
{
	private:
	
	std::vector<Montagne> montagnes_simples; // Tableau de montagnes simples
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	public: 
	
	ChaineDeMontagnes(const Montagne& mont) : Montagne(mont)
	{
		montagnes_simples.push_back(mont);
	}
	
	void set_montagne(Montagne const& montagne); // Méthode donnant aux attributs de la i-ème montagne simple de la chaîne les valeurs passées en arguments

	double altitude(double const& a, double const& b) const override; // Redéfinition de la méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne 
	
	

};
