#pragma once
#include <iostream>

// Prototypes des classes nécessaires à la déclaration de SupportADessin afin d'éviter une inclusion circulaire
class Ciel;
class Systeme;
class Montagne;
class ChaineDeMontagnes;


// Super classe virtuelle qui représente la façon choisie pour dessiner (écran mode texte ou mode graphique)

class SupportADessin 
{
	
//--------------------------------------------------------------METHODES-------------------------------------------------------------//
	
	public:
	
    virtual ~SupportADessin() = default;
	// on suppose ici que les supports ne seront ni copiés ni déplacés
	
	// Méthode pure pour permettre aux différents objets d'être afficher
    virtual void dessine(Systeme const& Sys) = 0;
    virtual void dessine(Montagne const& montagne) = 0;
    virtual void dessine(ChaineDeMontagnes const& chaine) = 0;
    virtual void dessine(Ciel const& ciel) = 0;

};
