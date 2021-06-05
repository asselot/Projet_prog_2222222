

#include <iostream>
#include "Systeme.h"
#include "Montagne.h"


//--------------------------------------------------------------CONSTRUCTEURS-------------------------------------------------------------//


// Constructeur de Systeme à partir des dimensions de la boîte et d'une montagnes
Systeme:: Systeme (int const& nx, int const& ny, int const& nz, double const& pas, const Montagne &Ch)
    : champs(nx, ny, nz, pas), ciel(nx, ny, nz, pas), chaine (Ch)

{
    champs.initialise( Physique :: vinfini, Ch);
    ciel.initialise();
}

// Constructeur à partir d'une montagne déjà initialisée et des dimensions de la boîte et d'une chaine
Systeme:: Systeme (int const&  nx, int const&  ny, int const&  nz, double const&  pas,  ChaineDeMontagnes const& Ch)
    :  champs(nx, ny, nz, pas), ciel(nx, ny, nz, pas), chaine(Ch)
{
    champs.initialise( Physique :: vinfini, Ch);
    ciel.initialise();
}

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Méthode dessine_sur() héritée de Dessinable
void Systeme :: dessine_sur(SupportADessin& a_dessiner)
{
a_dessiner.dessine(chaine);
// a_dessiner.dessine(ciel);
}


// Démarre modélisation du système : créer un champ de potentiel et un ciel, dessine et fait évoluer le système
void Systeme :: demarre (SupportADessin& a_dessiner)
{
    champs.resolution(2.2621843e-5, 5000, false, chaine);
    dessine_sur(a_dessiner);
    evolue(a_dessiner);
}

// Fait évoluer le système (surtout nuage?)
void Systeme ::  evolue (SupportADessin& a_dessiner)
{
    dessine_sur(a_dessiner);

}

// Fait appel aux opérateurs des différents composants du système
std::ostream& Systeme :: affiche (std::ostream& sortie) const
{
    sortie << " Montagnes : " << chaine << std::endl;
    sortie << " Champs potentiels : " << champs << std::endl;
    sortie << " Ciel : " << ciel << std::endl;
    return sortie;
}

// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys)
{
     return Sys.affiche(sortie);
}
