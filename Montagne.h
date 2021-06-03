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

    int dimension; // Permet d'inscrire la taille de la boite3D dans la montagne
	


	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

	public: 

    // Constructeur à partir des coordonnées d'un point, une hauteur et un certain étalement
    Montagne(double const& x = 0, double const& y = 0, double const& h = 0, double const& ox = 0, double const& oy = 0, int const& dim = 30 );
	
    // Constructeur à partir d'une montagne
    Montagne(Montagne const& montagne);

    // Méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne
    virtual double altitude(double const& a, double const& b) const;
	
    // Méthode permettant de modifier les attributs d'une montagne avec les valeurs passées en arguments
    virtual void set_montagne(double const& x, double const& y, double const& h, double const& ox, double const& oy);

    // Méthode dessine_sur redéfinie héritée par Dessinable
    void dessine_sur(SupportADessin &a_dessiner) override ;
	
    // Getteurs

    double get_x0() const;
	
    double get_y0() const;
	
    double get_H() const;
	
    double get_ex() const;
	
    double get_ey() const;

    int get_dimension() const { return dimension; }
	
};

    std::ostream& operator<<(std::ostream& sortie, Montagne const& montagne);



    class ChaineDeMontagnes : public Montagne
    {
        private:

        // Tableau de montagnes simples
        std::vector<Montagne> montagnes_simples;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

        public:

        ChaineDeMontagnes(const Montagne& mont);

        void set_montagne(Montagne const& montagne);

        virtual double altitude(double const& a, double const& b) const override;

        void affiche(std::ostream& sortie) const ;

    };

    std::ostream& operator<<(std::ostream& sortie, ChaineDeMontagnes const& chaine);
