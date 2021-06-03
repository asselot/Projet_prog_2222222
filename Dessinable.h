#pragma once
#include <iostream>
#include "SupportADessin.h"


class Dessinable //  permet de classer les objets qui sont dessinable tout les objets necessaure pour dessiner 
{
	public :
    virtual ~Dessinable() =0;
	virtual void dessine_sur(SupportADessin& a_dessiner) = 0; // Méthode virtuelle pure permettant de faire jsp quoi
	
	
};
