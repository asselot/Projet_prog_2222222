
#include <iostream>
#include "Systeme.h"

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Fait appel aux méthodes affiche() des différents composants du système
std::ostream& Systeme :: affiche (std::ostream& sortie) const
{
    sortie << " Montagnes : " << *ptr_hill << std::endl;
    sortie << " Champs potentiels : " << *ptr_champs << std::endl;
    sortie << " Ciel : " << *ptr_ciel << std::endl;
    return sortie;
}

Systeme :: Systeme (Systeme const& S) {
    ptr_champs = new ChampsPotentiels(*S.ptr_champs);
    ptr_ciel = new Ciel (*S.ptr_ciel);
    ptr_hill = new Montagne (*S.ptr_hill);
}

// Démarre modélisation du système : créer un champ de potentiel et un ciel, dessine et fait évoluer le système 
void Systeme :: demarre (SupportADessin& a_dessiner)
{
    ptr_champs->resolution();
    ptr_ciel = new Ciel(*ptr_champs); // permet de débeuguer
	dessine_sur(a_dessiner);
	evolue(a_dessiner);
}

// Méthode dessine_sur() héritée de Dessinable
void Systeme :: dessine_sur(SupportADessin& a_dessiner)
{ a_dessiner.dessine(*this); }

// Fait évoluer le système (surtout nuage?)
void Systeme ::  evolue (SupportADessin& a_dessiner)
{
	// pas besoin d'itération sur cubeair
	dessine_sur(a_dessiner);	
}

//--------------------------------------------------------------OPERATEUR-------------------------------------------------------------//

std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys)
{
     return Sys.affiche(sortie);
}
