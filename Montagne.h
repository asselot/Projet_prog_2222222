#pragma once
#include <iostream> 
#include <cmath>
#include <vector>
#include <iostream>
#include "Dessinable.h"
#include "SupportADessin.h"

// Classe représentant une montagne

class Montagne : public Dessinable 
{
	private:
	
	double x0; // Coordonnée en x du centre de la montagne 
	
	double y0; // Coordonnée en y du centre de la montagne 
	
	double H; // Hauteur de la montagne 
	
	double ex; // Etalement en x de la montagne 
	
	double ey; // Etalement en y de la montagne
	
	int dimension; // Permet d'inscrire la taille de la boite3D dans la montagne
	
	public:
	
	// Constructeur à partir des coordonnées d'un point, une hauteur, un certain étalement et la dimension de la boîte
    Montagne(double const& x = 0, double const& y = 0, double const& h = 0, double const& ox = 0, double const& oy = 0, int const& dim = 30);
	
    // Constructeur de copie
    Montagne(Montagne const& montagne) = default;

    // Destructeur
    virtual ~Montagne();
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	// Méthode virtuelle qui calcule la valeur de l'altitude en un point donné et sera redéfinie pour une chaîne
    virtual double altitude(double const& a, double const& b) const; 
			
	// Méthode dessine_sur redéfinie héritée par Dessinable
    virtual void dessine_sur(SupportADessin &a_dessiner) override ;
	
	// Méthode affichant les paramètres
    std::ostream& affiche(std::ostream& sortie) const;
    
    // Retourne la dimension de la boite - necessaire pour itérer sur les altitudes afin de dessiner la montagne - cf vue_opengl.cc
    int get_dimension() const;
	
};

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& sortie, Montagne const& montagne);



