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
	

	public: 

//--------------------------------------------------------------CONSTRUCTEURS ET DESTRUCTEUR-------------------------------------------------------------//

    // Constructeur à partir des coordonnées d'un point, une hauteur et un certain étalement
    Montagne(double const& x = 0, double const& y = 0, double const& h = 0, double const& ox = 0, double const& oy = 0, int const& dim = 30);
	
    // Constructeur à partir d'une montagne
    Montagne(Montagne const& montagne) = default;

    // Destructeur
    virtual ~Montagne();

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

    // Méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne
    virtual double altitude(double const& a, double const& b) const;

    // Méthode dessine_sur redéfinie héritée par Dessinable
    void dessine_sur(SupportADessin &a_dessiner) override ;

    // Méthode affichant les paramètres
    std::ostream& affiche(std::ostream& sortie) const;

    // Retourne la dimension de la boite - necessaire pour itérer sur les altitudes afin de dessiner la montagne - cf vue_opengl.cc
    int get_dimension() const;

	
};



/************************************************************ SOUS CLASSE ChaineDeMontagne ***************************************************************/



 class ChaineDeMontagnes : public Montagne

    {
        private:

        // Tableau de montagnes simples
        std::vector<Montagne> montagnes_simples;

        unsigned int taille = 0 ;


        public:
//--------------------------------------------------------------CONSTRUCTEURS-------------------------------------------------------------//

        // Constructeur à partir d'une montagne
        ChaineDeMontagnes(const Montagne& mont);

        // Constructeur à partir d'une autre chaine
        ChaineDeMontagnes( ChaineDeMontagnes const& ch) = default;

        // Constructeur d'une chaine à partir des élements d'une montagne
        ChaineDeMontagnes(double const& x, double const& y, double const& h, double const& ox, double const& oy, int const& dim);

//--------------------------------------------------------------METHODES-------------------------------------------------------------------//

        // Méthode permettant d'ajouter des montagnes à la chaine
        void set_montagne(Montagne const& montagne);

        // Redéfinition de la méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne
        virtual double altitude(double const& a, double const& b) const override;

        // Affiche les attributs de la chaine
        void affiche(std::ostream& sortie) const ;

        // Permet d'obtenir des montagnes de la chaine
        Montagne get_montagnes_simples(int const& x) const;

        // Retourne la taille de la chaine
        unsigned int  get_taille() const;
	
	 // Ajoute toute les montagnes d'un tableau à la chaine
        ChaineDeMontagnes implementation_de_la_chaine(std :: vector<Montagne> const& V);



    };


    // Surcharge de << pour la chaine
    std::ostream& operator<<(std::ostream& sortie, ChaineDeMontagnes const& chaine);

    // Surcharge de << pour la montagne
    std::ostream& operator<<(std::ostream& sortie, Montagne const& montagne);


