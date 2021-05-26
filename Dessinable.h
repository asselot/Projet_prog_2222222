#pragma once
#include <iostream>
#include "SupportADessin.h"

//Cette classe abstraite s'occupe de dessiner les différents objets (Montagnes, ciel...) de la simulation
class Dessinable  
{
	public :
	
	//Méthode virtuelle pure redéfinie dans les différentes sous-classes à dessiner
	void dessine_sur(SupportADessin& a_dessiner) = 0;
	
	Dessinable(SupportADessin& a_dessiner);
	
	virtual ~Dessinable() {}
	
	protected :
	
	//On indique quel support à dessin on souhaite utiliser
	SupportADessin* support; 
};
