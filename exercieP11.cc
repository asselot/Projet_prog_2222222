#include <QApplication>
#include "glwidget.h"
#include "../general/Boite3D.h"
#include "../general/ChampsPotentiels.h"
#include "../general/Ciel.h"
#include "../general/Systeme.h"
#include "../general/Montagne.h"
#include "../general/SupportADessin.h"
#include "../general/constantes.h"
#include "../general/TextViewer.h"
#include "vue_opengl.h"
#include <iostream>
#include <string>

using namespace std;
using namespace Physique;

// Ajoute toute les montagnes d'un tableau à la chaine
ChaineDeMontagnes implementation_de_la_chaine(std :: vector<Montagne> const& V, ChaineDeMontagnes chaine)
{
    for (const auto&  element : V)
    {
        chaine.set_montagne(element);
    }
    return chaine;
}




int main(int argc, char* argv[])
{

cout << " Affichage textuelle " << endl;
cout << endl;

        // Création du support à dessin pour l'affichage texte
        TextViewer ecran(cout);

        // Création des trois montagnes qui composent la chaîne
        Montagne mont1(15.0, 15.0, 18.0, 5.0, 10.0);


        // Création de la chaîne et ajout des montagnes
        ChaineDeMontagnes chaine(mont1);


        // Création et initialisation du champ de potentiels
        ChampsPotentiels champ(30, 30, 30, 20.0/29.0);
        champ.initialise(vinfini, chaine);

       // Création et simulation du système
        Systeme sys(champ, chaine);
        sys.demarre(ecran);
        sys.evolue(ecran);

cout << endl;    // C'est beau quand c'est espacé

cout << " Affichage graphique " << endl;

cout << endl;    // ON RESPIRE !

        // Création du support à dessin pour l'affichage graphique
        QApplication a(argc, argv);


        GLWidget w(champ, chaine);
        w.show();

        return a.exec();

  return 0;
}
