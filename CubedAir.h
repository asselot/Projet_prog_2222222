#pragma once
#include <iostream>
#include <array>
#include "Boite3D.h"
#include "ChampsPotentiels.h"
#include "constantes.h"

class CubedAir
{
    protected:

    // Vitesse d'un cube
    std::array<double, 3> vitesse_cubedair;

    //--------------------------------------------------------------METHODES-------------------------------------------------------------//

    public:

    // Constructeur de cube à vitesse nulle
    CubedAir();

    // Constructeur de cube à partir de la vitesse initiale
    CubedAir(std::array<double, 3> vit_init);

    // Constructeur par défaut
    ~CubedAir() = default;

    // Retourne l'enthalpie en un point donné
    double enthalpie(unsigned int pz, double pas) const;

    // Retourne la température en un point donné
    double temperature(unsigned int pz, double pas) const;

    // Retourne la pression en un point donné
    double pression(unsigned int pz, double pas) const;

    // Retourne la pression de l'eau (Peau)
    double pression_partielle(unsigned int pz, double pas) const;

    // Retourne la pression de la rosée (Prosée)
    double pression_vapeur_saturante(unsigned int pz, double pas) const;

    // Détermine l'état du cube d'air, elle retourne true si il est sous forme de nuage
    bool etat(unsigned int pz, double pas) const;

    // Associe les valeurs données aux coordonnées de la vitesse du cube
    void set_vitesse(double coordx, double coordy, double coordz);

    // Affiche les différents attributs du cube d'air
    void affiche(std::ostream& sortie, unsigned int pz, double pas) const;

    // Retourne la norme de la vitesse d'un cube d'air
    double vitesse_norme() const;

    // Retourne la norme de la vitesse d'un cube d'air au carré
    double v2() const;

    // Affiche 1 si le cube est un nuage, 0 sinon
    void affiche_etat(unsigned int pz, double pas) const;

};
