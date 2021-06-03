#pragma once
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
		
virtual void dessine(Systeme const& Sys) override;
virtual void dessine(Montagne const& montagne) override;
virtual void dessine(ChaineDeMontagnes const& chaine) override;
virtual void dessine(Ciel const& ciel) override;

private : 

std::ostream& flot; 

	
};
