#include <iostream>
#include "Systeme.h"

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Fait appel aux méthodes affiche() des différents composants du système
void Systeme :: affiche (ostream& sortie) const
{
	sortie << " Montagnes : " << &ptr_hill << endl;
	sortie << " Champs potentiels : " << &ptr_champs << endl;
	sortie << " Ciel : " << &ptr_ciel << endl;
}

// Démarre modélisation du système : créer un champ de potentiel et un ciel, dessine et fait évoluer le système 
virtual void Systeme :: demarre (SupportADessin& a_dessiner)
{
	ptr_champs ->resolution();
	ptr_ciel = new Ciel(&ptr_champs); // permet de débeuguer 
	dessine_sur(a_dessiner);
	evolue(a_dessiner);
}

// Méthode dessine_sur() héritée de Dessinable
virtual void Systeme :: dessine_sur(SupportADessin& a_dessiner) override
{ a_dessiner->dessine(*this); }

// Fait évoluer le système (surtout nuage?)
virtual void Systeme ::  evolue (SupportADessin& a_dessiner)
{
	// pas besoin d'itération sur cubeair
	dessine_sur(a_dessiner);	
}

//--------------------------------------------------------------OPERATEUR-------------------------------------------------------------//

std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys)
{
	Sys.affiche(sortie);
}
