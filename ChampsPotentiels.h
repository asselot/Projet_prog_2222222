#pragma once

#include <array>
#include "constantes.h"
#include "Boite3D.h"
#include "Potentiel.h"
#include "Montagne.h"
#include "Vecteur2D.h"

class ChampsPotentiels : public Boite3D<Potentiel>
{

    private:

    double erreur(); // Retourne la somme des carrés des normes des vecteurs laplaciens

    void iteration(const ChaineDeMontagnes& chaine, const double& E = 0.1); // Aucune idée


//--------------------------------------------------------------METHODES-------------------------------------------------------------//

    public:

    ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1.0);

    ChampsPotentiels(ChampsPotentiels const& C);

    ~ChampsPotentiels();

    void initialise(double vi, const Montagne& mont); // Initialise les potentiels du champ potentiel

    //bool estauxbords(Potentiel pot) const; // Retourne true si un potentiel est au bord de la boîte

    void calcule_laplaciens(const ChaineDeMontagnes& chaine); // Calcule la valeur des laplaciens sur l'ensemble du champ à partir des potentiels

    void resolution(double const& seuil, unsigned int const& max, bool const& verbeuse, const ChaineDeMontagnes& chaine); //bruh

    std::array<double, 3> vitesse(unsigned int const& i, unsigned int const& j, unsigned int const& k) const; // Calcule la valeur de la vitesse du vent en un point donné

    double norme_vitesse(unsigned int const& pointi, unsigned int const& pointj, unsigned int const& pointk) const; // Norme de la vitesse

};


