#pragma once
#include <iostream> 
#include <cmath>
#include <vector>
#include <iostream>
#include "Dessinable.h"
#include "SupportADessin.h"
#include "ChampsPotentiels.h"

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
	
	Montagne() : x0(0), y0(0), H(0), ex(0), ey(0) {} // Constructeur d'une Montagne initialisant tout à 0
	
	virtual double altitude(double a, double b) const; // Méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne 
	
	virtual void set_montagne(double x, double y, double h, double ox, double oy); // Méthode permettant de modifier les attributs d'une montagne avec les valeurs passées en arguments
			
	void dessine_sur(SupportADessin &a_dessiner) override ; // Méthode dessine_sur redéfinie
	
	double get_x0();
	
	double get_y0();
	
	double get_H();
	
	double get_ex();
	
	double get_ey();
	
};

    std::ostream& operator<<(std::ostream& sortie, Montagne const& montagne);


class ChaineDeMontagnes : public Montagne
{
	private:
	unsigned int nombre_montagnes; // Nombre de montagnes simples qui composent la chaîne
	
	unsigned int nombre_chaines; // Nombre de sous-chaînes qui composent la chaîne 
	
	std::vector<Montagne> montagnes_simples; // Tableau de montagnes simples
	
	std::vector<ChaineDeMontagnes> chaines_simples; // Tableau de chaînes simples
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	public: 

	ChaineDeMontagnes(double x, double y, double h, double ox, double oy, const unsigned int &nombre) : Montagne(x, y, h, ox, oy), nombre_montagnes(nombre) // Construit une chaîne composée uniquement de la même montagne simple 
	{
		Montagne mon(x, y, h, ox, oy);
		for (size_t i(0); i < nombre_montagnes; ++i)
		{
			montagnes_simples.push_back(mon);
		}
	}
	
	ChaineDeMontagnes(ChaineDeMontagnes	chaine_a_mettre, const unsigned int &nombre2) : Montagne(0, 0, 0, 0, 0), nombre_chaines(nombre2) // Construit une chaîne composée uniquement de la même sous-chaîne
	{
		for (size_t j(0); j < nombre_chaines; ++j)
		{
			chaines_simples.push_back(chaine_a_mettre);
		}
	}
	
	ChaineDeMontagnes() : Montagne(), nombre_montagnes(0), nombre_chaines(0) // Construit une chaine composée d'une seule montagne et d'une seule chaîne, toutes deux vides
	{
		std::vector<Montagne> monts; 
		std::vector<ChaineDeMontagnes> chais;
		montagnes_simples.push_back(monts);
		chaines_simples.push_back(chais);
	}
	
	ChaineDeMontagnes(const unsigned int &nombre, const unsigned int &nombre2) : Montagne(0, 0, 0, 0, 0), nombre_montagnes(nombre), nombre_chaines(nombre2) // Constructeur ajoutant à la chaîne autant de montagnes simples et de montagnes vides que souhaité
	{
		Montagne mon;
		for (auto i : montagnes_simples)
		{
			montagnes_simples.push_back(mon);
		}
		ChaineDeMontagnes chai; 
		for (auto j : chaines_simples)
		{
			chaines_simples.push_back(chai); 
		}
	}
	
	int get_nbre_montagnes(); // Retourne le nombre de montagnes simples qui composent la chaîne 
	
	int get_nbre_chaines(); // Retourne le nombre de sous-chaînes qui composent la chaîne 
	
	void set_montagne(double x, double y, double h, double ox, double oy, const unsigned int &indice); // Méthode donnant aux attributs de la i-ème montagne simple de la chaîne les valeurs passées en arguments
	
	void set_montagne(ChaineDeMontagnes chaine, const unsigned int &indice); // Méthode remplaçant la i-ème sous-chaîne de la chaîne par celle passée en argument 

	double altitude(double a, double b) const override; // Redéfinition de la méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne 
	
	

};
