#include <iostream>
#include "../general/TextViewer.h"
#include "../general/SupportADessin.h"
#include "../general/Systeme.h"
using namespace std;

int main()
{
  TextViewer ecran(cout);
  Montagne M1(15, 15, 8, 5, 10);
  Montagne M2(12, 8, 10, 5, 5);
  Montagne M3(2, 3, 20, 10, 5);
  ChaineDeMontagnes dessin1 (M1);
  dessin1.set_montagne(M2);
  dessin1.set_montagne(M3);

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

