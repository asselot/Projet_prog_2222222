#pragma once
#include <iostream>
#include "SupportADessin.h"

//  Super classe virtuellle permettant de classer les objets qui sont dessinables pour dessiner
// Montagne, Ciel sont DESSINABLES --> elles héritent donc de cette classe

class Dessinable

{
	public :

    // Destructeur de la classe
    virtual ~Dessinable() =0;

    // Méthode virtuelle redéfinit dans chaque sous classe pour les dessiner sur un support; d'où le fait qu'elle soit pure
    virtual void dessine_sur(SupportADessin& a_dessiner) = 0;
	
	
};
