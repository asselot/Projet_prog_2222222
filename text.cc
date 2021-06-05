#include <iostream>
#include "../general/TextViewer.h"
#include "../general/SupportADessin.h"
#include "../general/Systeme.h"
using namespace std;

// Ajoute toute les montagnes d'un tableau à la chaine
ChaineDeMontagnes implementation_de_la_chaine(std :: vector<Montagne> const& V, ChaineDeMontagnes chaine)
{
    for (const auto&  element : V)
    {
        chaine.set_montagne(element);
    }
    return chaine;
}


int main()
{
  TextViewer ecran(cout);
  Montagne M1(15, 15, 8, 5, 10);
  Montagne M2(12, 8, 10, 5, 5);
  Montagne M3(2, 3, 20, 10, 5);

  vector<Montagne> V = {M2,M2};
  ChaineDeMontagnes dessin1 (M1);
 implementation_de_la_chaine(V, dessin1);

  ChampsPotentiels ch;

  Systeme c(ch, dessin1);

  cout << "Au départ :" << endl;
  c.dessine_sur(ecran);

  /*c.evolue(ecran);
  cout << "Après un pas de calcul :" << endl;
  c.dessine_sur(ecran);

  c.evolue(ecran);
  cout << "Après deux pas de calcul :" << endl;
  c.dessine_sur(ecran);*/

  return 0;
}

