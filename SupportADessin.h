#pragma once
#include <iostream>


class Montagne; // Prototypes des classes nécessaires à la déclaration de SupportADessin afin d'éviter une inclusion circulaire
class Ciel;
class Systeme;

class SupportADessin 
{
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	public:
	virtual ~SupportADessin() = default; // demander à Sixtine de les commenter 
	
	virtual void dessine(Systeme const&) = 0;
	
	virtual void dessine(Montagne const&) = 0;
	
	virtual void dessine(Ciel const&) = 0;

};
