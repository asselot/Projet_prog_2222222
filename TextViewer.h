pragma once 
# include <iostream>
# include "SupportADessin.h"
# include "Montagne.h"
# include "Systeme.h"
# include "Ciel.h"

// La classe Terminal indique que l'on souhaite afficher la simulation sous forme textuelle sur le terminal
// Va afficher les différentes composantes de Systeme, Montagne et Ciel en fonction des méthodes affiche() de chacun

class TextViewer : public SupportADessin

{

public : 

// Constructeur de classe
TextViewer (std::ostream& flot);
		
virtual void dessine(Systeme const& a_dessiner) const;
virtual void dessine(Montagne const& a_dessiner) const;
virtual void dessine(Ciel const& a_dessiner) const; 	

private : 

std::ostream& flot; 

	
};
