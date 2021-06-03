
#include <iostream>
#include "Systeme.h"

//--------------------------------------------------------------METHODES-------------------------------------------------------------//


// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys)
{
     return Sys.affiche(sortie);
}

// Fait appel aux opérateurs des différents composants du système
std::ostream& Systeme :: affiche (std::ostream& sortie) const
{
    sortie << " Montagnes : " << montagne << std::endl;
    sortie << " Champs potentiels : " << champs << std::endl;
    sortie << " Ciel : " << ciel << std::endl;
    return sortie;
}

// Méthode dessine_sur() héritée de Dessinable
void Systeme :: dessine_sur(SupportADessin& a_dessiner)
{
a_dessiner.dessine(montagne);
//a_dessiner.dessine(ciel);
}


// Démarre modélisation du système : créer un champ de potentiel et un ciel, dessine et fait évoluer le système
void Systeme :: demarre (SupportADessin& a_dessiner)
{
    champs.resolution();
    dessine_sur(a_dessiner);
    evolue(a_dessiner);
}

// Fait évoluer le système (surtout nuage?)
void Systeme ::  evolue (SupportADessin& a_dessiner)
{
    dessine_sur(a_dessiner);
    // pas besoin d'itération sur cubeair -> toutes les méthodes de ciel

}

// Constructeur de Systeme à partir des dimensions de la boîte et d'une montagnes
Systeme:: Systeme (int const& nx, int const& ny, int const& nz, double const& pas, Montagne const& M)
    : champs(nx, ny, nz, pas), ciel (nx, ny, nz, pas), montagne (M)

{
    champs.initialise( Physique :: vinfini, M);
    ciel.initialise();

}




