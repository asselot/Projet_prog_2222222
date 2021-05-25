# include <iostream>
# include "SupportADessin"

// afficher les différents composants de Systeme, Montagne et Ciel en fonction des méthodes affiche() de chacun

void TextViewer :: dessine(Systeme const& a_dessiner)
{
	a_dessiner. affiche(); 
}

void TextViewer :: dessine(Montagne const& a_dessiner)
{
	a_dessiner. affiche_para(); 
}

void TextViewer :: dessine(Ciel const& a_dessiner)
{
	a_dessiner.affiche();
}
		
	

