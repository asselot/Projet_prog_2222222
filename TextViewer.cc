# include <iostream>
# include "SupportADessin.h"
# include "Montagne.h"
# include "Ciel.h"
# include "ChampsPotentiels.h"
#include "TextViewer.h"

// afficher les différents composants de Systeme, Montagne et Ciel

void TextViewer :: dessine(Systeme const& Sys) const
{
    flot << Sys;
}

void TextViewer :: dessine(Montagne const& montagne) const
{
    flot<< montagne;
}

void TextViewer :: dessine(Ciel const& ciel) const
{
    flot << ciel;
}


//Constructeur de classe
TextViewer :: TextViewer (std::ostream& flot) : SupportADessin(), flot(flot) {}


