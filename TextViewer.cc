# include <iostream>
# include "SupportADessin.h"
# include "Montagne.h"
# include "Ciel.h"
# include "ChampsPotentiels.h"
#include "TextViewer.h"

// afficher les différents composants de Systeme, Montagne et Ciel

void TextViewer :: dessine(Systeme const& Sys)
{
    flot << Sys;
}

void TextViewer :: dessine(Montagne const& montagne)

{
    flot<< montagne;
}

void TextViewer :: dessine(Ciel const& ciel)
{
    flot << ciel;
}

void TextViewer :: dessine (ChaineDeMontagnes const& chaine)
{
    flot << chaine;
}

//Constructeur de classe
TextViewer :: TextViewer (std::ostream& flot) : SupportADessin(), flot(flot) {}

