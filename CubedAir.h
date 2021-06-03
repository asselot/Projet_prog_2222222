#pragma once
#include <iostream>
#include "Boite3D.h"
#include "ChampsPotentiels.h"
#include "constantes.h"


class CubedAir
{
    protected:
    std::array<double, 3> vitesse_cubedair; // Vitesse d'un cube

    //--------------------------------------------------------------METHODES-------------------------------------------------------------//

    public:

    // Constructeur qui met la vitesse des cubes à 0
    CubedAir();

    // Constructeur à partir de la vitesse
    CubedAir(std::array<double, 3> vit_init);

    double enthalpie(unsigned int pz, double pas) const; // Calcule l'enthalpie en un point donné

    double temperature(unsigned int pz, double pas) const; // Calcule la température en un point donné

    double pression(unsigned int pz, double pas) const; // Calcule la pression en un point donné

    double pression_partielle(unsigned int pz, double pas) const; // Calcule la pression de l'eau (Peau)

    double pression_vapeur_saturante(unsigned int pz, double pas) const; // Calcule la pression de la rosée (Prosée)

    bool etat(unsigned int pz, double pas) const; // Détermine l'état du cube d'air, elle retourne true si il est sous forme de nuage

    void set_vitesse(double coordx, double coordy, double coordz); // Associe les valeurs données aux coordonnées de la vitesse du cube

    void affiche(std::ostream& sortie, unsigned int pz, double pas) const; // Affiche les différents attributs du cube d'air

    double vitesse_norme() const; // Calcule la norme de la vitesse d'un cube d'air

    double v2() const;

    void affiche_etat(unsigned int pz, double pas) const; // Affiche 1 si le cube est un nuage, 0 sinon

};
