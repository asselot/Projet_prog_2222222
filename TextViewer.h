pragma once 
# include <iostream>
# include "SupportADessin"

// Classe qui va permettre d'afficher en mode texte Systeme, Montagne et Ciel. C'est donc un support à dessin
// Va afficher les différentes composantes de Systeme, Montagne et Ciel en fonction des méthodes affiche() de chacun

class TextViewer : public SupportADessin

{
virtual void dessine(Systeme const&);
virtual void dessine(Montagne const&);
virtual void dessine(Ciel const&); 	
	
private :

std :: ostream& flot; 

	
};
