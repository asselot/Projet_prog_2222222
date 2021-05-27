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
virtual void Systeme :: demarre ()
{
	ptr_champs ->resolution();
	&ptr_ciel (&ptr_champs)
	dessine_sur();
	evolue();
}

// Méthode dessine_sur() héritée de Dessinable
virtual void Systeme :: dessine_sur() override
{ A->dessine(*this); }

// Fait évoluer le système (surtout nuage?)
virtual void Systeme ::  evolue ()
{
	dessine_sur ();	
}

//--------------------------------------------------------------OPERATEUR-------------------------------------------------------------//

std::ostream& operator<<(std::ostream& sortie, Systeme const& Sys)
{
	Sys.affiche(sortie);
}
