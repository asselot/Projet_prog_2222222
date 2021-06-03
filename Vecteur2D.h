#pragma once
#include <iostream>
#include <ostream>
#include <cmath> 

class Vecteur2D
{
    protected:

    double coord_x; // coordonnée x
    double coord_y; // coordonnée y

    // Permet à la classe ChampsPotentiels d'utiliser les attributs d'un vecteurs ... à voir
    friend class ChampsPotentiels;
	
    public:
	
   
    // Constructeur par défaut au vecteur nul
    Vecteur2D (int x=0, int y=0);

   // le constructeur de copie par défaut
   Vecteur2D( Vecteur2D const& autre);

//--------------------------------------------------------------OPERATEURS INTERNES-------------------------------------------------------------//

    
    //Retourne false si au moins l'une des cordonnées de vector n'est pas égale à celle du vecteur comparé (à la précision près)	
    bool operator == (const Vecteur2D& V) const;

	
    // - opérateur interne - Retourne l'addition au vecteur du vecteur "V" 
    Vecteur2D& operator += (const Vecteur2D& V);
	
    
    // - opérateur interne - Retourne la soustraction au vecteur du vecteur "V" 
    Vecteur2D& operator -= (const Vecteur2D& V);
	
        
    // - opérateur interne - Retourne le vecteur multiplié par x
    Vecteur2D& operator *= (const double& x);
	
	
    // - opérateur interne - Retourne le vecteur unitaire associé à la direction du vecteur initial
    Vecteur2D& operator ~ ();

    // - opérateur interne - Affectation
    Vecteur2D& operator = (Vecteur2D const& V);

	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	
    //Retourne le produit scalaire du vecteur appelé et de "V"
    double produit_scal(Vecteur2D const& V) const;
	
	
    //Retourne la norme du vecteur au carré
    double norme2() const;
	
	
    //Retourne la norme du vecteur
    double norme() const;
    
       
    // Retourne l'opposé du vecteur
    Vecteur2D oppose() const;
	
    // getteurs - permet d'accéder aux attributs privés
    double get_x() const;
    double get_y() const;

    // Méthode qui affiche les paramètres du veteur
    void afficher(std::ostream &sortie) const;
};

//--------------------------------------------------------------OPERATEURS EXTERNES-------------------------------------------------------------//


		
Vecteur2D& operator + (Vecteur2D v1, Vecteur2D const& v2);  // operateur externe +
		
Vecteur2D& operator - (Vecteur2D v1,  Vecteur2D const& v2);  // operateur externe -
		
Vecteur2D& operator * (double const& x, Vecteur2D& V); // operateur externe *

Vecteur2D& operator * (Vecteur2D& V, double const& x); // assure commutativité de la multiplication par un scalaire

std::ostream& operator<<(std::ostream& sortie, Vecteur2D const& V); // permet d'afficher un vecteur par surcharge de <<
