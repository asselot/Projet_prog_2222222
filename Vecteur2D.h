#pragma once
#include <iostream>
#include <ostream>
#include <cmath>

class Vecteur2D
{
    protected:
    double coord_x; // coordonnée x
    double coord_y; // coordonnée y
	
    friend std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& vect); // ?
    friend Vecteur2D operator * (const double x, const Vecteur2D& V);
    friend Vecteur2D operator * (const Vecteur2D& V, const double x);
    
    
    // Permet à la classe ChampsPotentiels d'utiliser les attributs d'un vecteurs ... à voir
    friend class ChampsPotentiels;
	
	
    public:
	
   
    // constructeur par défaut au vecteur nul	
    Vecteur2D (const double x=0, const double y=0) 
    : coord_x(x), coord_y(y)
    {}
    
   /* Vecteur2D( Vecteur2D const& autre) /// le constructeur de copie par défaut par défaut suffit amplement
    :coord_x( autre.coord_x), coord_y(autre.coord_y)
    {}*/
	
//--------------------------------------------------------------OPERATEURS INTERNES-------------------------------------------------------------//

    
    //Retourne false si au moins l'une des cordonnées de vector n'est pas égale à celle du vecteur comparé (à la précision près)	
    bool operator == (const Vecteur2D& V) const;

	
    // - opérateur interne - Retourne l'addition au vecteur du vecteur "V" 
    Vecteur2D& operator += (const Vecteur2D& V); 

    
    // - opérateur interne - Retourne la soustraction au vecteur du vecteur "V" 
    Vecteur2D& operator -= (const Vecteur2D& V);  
	
        
    // - opérateur interne - Retourne le vecteur multiplié par x
	Vecteur2D& operator *= (const double& x);
	
    
    // Retourne l'opposé du vecteur
    //Vecteur2D& operator op();  //changer le nom en operateur connu 
	
    // - opérateur interne - Retourne le vecteur unitaire associé à la direction du vecteur initial
    Vecteur2D& operator ~ ();

	Vecteur2D& operator = (Vecteur2D const& V);
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	
    //Retourne le produit scalaire du vecteur appelé et de "V"
    double produit_scal(Vecteur2D const& V) const;
	
	
    //Retourne la norme du vecteur au carré
    double norme2() const;
	
	
    //Retourne la norme du vecteur
    double norme() const;
	
	Vecteur2D oppose() const;
	
    /*// Vecteur unitaire   
    Vecteur2D unitaire() const;*/ 
    
    double get_x() const;
    
    double get_y() const;
    
};

//--------------------------------------------------------------OPERATEURS EXTERNES-------------------------------------------------------------//
		
Vecteur2D operator + (Vecteur2D v1, const Vecteur2D& v2);  // operateur externe +
		
Vecteur2D operator - (Vecteur2D v1, const Vecteur2D& v2);  // operateur externe -
		
Vecteur2D operator * (const double x, const Vecteur2D& V); // operateur externe *

Vecteur2D operator * (const Vecteur2D& V, const double x); // assure commutativité de la multiplication par un scalaire

std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& V); // permet d'afficher un vecteur par surcharge de <<
