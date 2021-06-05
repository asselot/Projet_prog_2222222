#pragma once
#include <iostream>
#include "Vecteur2D.h"
#include <array>

class Potentiel
{

    private:
    
    Vecteur2D poten; // Potentiel en lui-même
    Vecteur2D laplacien; // Laplacien qui lui est associé

    public:
    
//--------------------------------------------------------------CONSTRUCTEURS ET DESTRUCTEUR-------------------------------------------------------------//

    // Constructeur initialisant les deux vecteurs à des vecteurs nuls
    Potentiel();

    // Constructeur d'un potentiel à partir d'un autre potentiel
    Potentiel(Potentiel const& a_copier);

    // Constructeur d'un potentiel à partir de vecteurs
    Potentiel(Vecteur2D const& p, Vecteur2D const& l);
    
    // Constructeur par défaut
     ~Potentiel() = default;
    
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

    // Affiche les attributs d'un potentiel
    std::ostream& affiche(std :: ostream& sortie) const;

    // Retourne la vitesse des potentiels sous forme de tableau pour chacune des composantes de la vitesse
    std::array<double, 3> vitesse_potentiels(const Potentiel& imoins1jk, const Potentiel& ijmoins1k, const Potentiel& ijkmoins1, const Potentiel& iplus1jk, const Potentiel& ijplus1k, const Potentiel& ijkplus1) const;

    void potentiel_iteration(const double& E);

    void calcule_laplacien(const Potentiel& imoins1jk, const Potentiel& ijmoins1k, const Potentiel& ijkmoins1, const Potentiel& iplus1jk, const Potentiel& ijplus1k, const Potentiel& ijkplus1);

    // Setteurs
    void set_laplacien(const double& x, const double& y);
    void set_laplacien(const Vecteur2D& V);
    void set_poten(const Vecteur2D& V);
    void set_poten(const double& x, const double& y);

    // Retourne la norme au carré du laplacien
    double laplacien_norme2() const;

};

// Permet d'afficher un potentiel par surcharge de <<
std::ostream& operator<<(std::ostream& sortie, Potentiel const& P);

