#pragma once
#include <iostream>

class SupportADessin 
{
	public:
	
virtual ~SupportADessin() = default;
// on suppose ici que les supports ne seront ni copiés ni déplacés

virtual void dessine(Systeme const&) = 0;
virtual void dessine(Montagne const&) = 0;
virtual void dessine(Ciel const&) = 0;



};