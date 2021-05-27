#pragma once
#include "Montagne.h"
#include "Systeme.h"
#include "Ciel.h"
#include "SupportADessin.h"
#include <iostream>

// Super-classe qui est dédiée à la « visualisation » de la modélisation (mode texte ou graphique)
// Classe abstraite dont hérite TextViewer (texte) et Open_vueGL (graphisme)

class SupportADessin 
{
	public:
// On suppose ici que les supports ne seront ni copiés ni déplacés	
virtual ~SupportADessin() = default;

// Constructeur de la classe
SupportADessin() {}

// Méthodes virtuelles pures qui indiquent comment afficher les différents objets de la simulation
// Ces méthodes sont pures car la classe ne sait pas encore comment afficher les elements dessinables

virtual void dessine(Systeme const& a_dessiner) const = 0;
virtual void dessine(Montagne const& a_dessiner) const = 0;
virtual void dessine(Ciel const& a_dessiner) const = 0;
	
protected : 
	
// Permet d'éviter les copies de support à dessin, qui n'auraient pas de sens 
	
SupportADessin(SupportADessin const&) = delete;
SupportADessin& operator=(SupportADessin const&) = delete;
			
	
};
