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

    // Retourne la somme des carrés des normes des vecteurs laplaciens
    double erreur();

    void iteration(const ChaineDeMontagnes& chaine, const double& E = 0.1);
    
    
    public:

//--------------------------------------------------------------CONSTRUCTEURS ET DESTRUCTEUR-------------------------------------------------------------//

    // Constructeur du champ à partir des dimensions de la boîte avec initialisation du laplacien
    ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1.0);

    // Constructeur à partir d'es dimensions de la boîte'un autre champ
    ChampsPotentiels(ChampsPotentiels const& C);

    // Destructeur de la classe
    ~ChampsPotentiels() = default ;
    
//--------------------------------------------------------------METHODES-------------------------------------------------------------//

    // Initialise les potentiels du champ potentiel
    void initialise(double vi, const Montagne& mont);

    // Calcule la valeur des laplaciens sur l'ensemble du champ à partir des potentiels
    void calcule_laplaciens(const ChaineDeMontagnes& chaine);

    void resolution(double const& seuil, unsigned int const& max, bool const& verbeuse, const ChaineDeMontagnes& chaine);

    // Retourne la vitesse du vent en un point donné sous forme de tableau dont les composants représentent les composantes de la vitesse en x, y, z
    std::array<double, 3> vitesse(unsigned int const& i, unsigned int const& j, unsigned int const& k) const;

    // Retourne la norme de la vitesse
    double norme_vitesse(unsigned int const& pointi, unsigned int const& pointj, unsigned int const& pointk) const;

    // Permet d'afficher les paramètres du champ
    void affiche(std::ostream& sortie) const;

};

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& sortie, const ChampsPotentiels& champ);
