#pragma once
#include <iostream>

// Super-classe qui est dédiée à la « visualisation » de la modélisation (mode texte ou graphique)
// Classe abstraite dont hérite TextViewer (texte) et Open_vueGL (graphisme)

class SupportADessin 
{
	public:
	
virtual ~SupportADessin() = default;
// On suppose ici que les supports ne seront ni copiés ni déplacés

// Méthodes virtuelles pures qui indiquent comment afficher les différents objets de la simulation
// Ces méthodes sont pures car la classe ne sait pas encore comment afficher les elements dessinables

virtual void dessine(Systeme const&) = 0;
virtual void dessine(Montagne const&) = 0;
virtual void dessine(Ciel const&) = 0;
	
protected : 
	
// Permet d'éviter les copies de support à dessin, qui n'auraient pas de sens 
	
SupportADessin(SupportADessin const&) = delete;
SupportADessin& operator=(SupportADessin const&) = delete;
			
	
};
