#pragma once
#include <iostream>
#include "Vecteur2D.h"

class Potentiel
{

    friend class Ciel;
    private:
    Vecteur2D poten; // Potentiel en lui-même
    Vecteur2D laplacien; // Laplacien qui lui est associé


    friend class ChampsPotentiels; // Permet à la classe Champs Potentiels d'accéder à ses attributs protégés

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

    public:
    // Constructeur initialisant les deux vecteurs à des vecteurs nuls
    Potentiel();

    // Constructeur d'un potentiel
    Potentiel(Vecteur2D const& p, Vecteur2D const& l);// Constructeur d'un potentiel

    void affiche(std :: ostream& sortie) const; // Affiche les attributs d'un potentiel

    // Getteur de potentiel et laplacien
    Vecteur2D get_laplacien() const;
    Vecteur2D get_poten() const;

    void set_laplacien(const double& x, const double& y);
    void set_laplacien(const Vecteur2D& V);
    void set_poten(const Vecteur2D& V);
    void set_poten(const double& x, const double& y);
    double laplacien_norme2() const;

};

// Permet d'afficher un potentiel par surcharge de <<
std::ostream& operator<<(std::ostream& sortie, Potentiel const& P);
