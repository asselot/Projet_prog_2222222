#include <cmath>
#include <iostream>
#include "Montagne.h"
#include "Dessinable.h"
#include "SupportADessin.h"

class ChaineDeMontagnes;

using namespace std;
//--------------------------------------------------------------CONSTRUCTEURS ET DESTRUCTEURS-------------------------------------------------------------//

// Constructeur d'une montagne à partir d'un centre, une hauteur et un certain étalement
Montagne :: Montagne(double const& x, double const& y, double const& h, double const& ox, double const& oy, int const& dim)
    : x0(x), y0(y), H(h), ex(ox), ey(oy), dimension(dim) {}

// Constructeur d'une montagne à partir d'une montagne
/*Montagne :: Montagne(const Montagne& montagne)
    : Montagne(x0, y0, H, ex, ey, dimension)
{}*/

// Constructeur d'une chaine à partir d'une montagne
ChaineDeMontagnes :: ChaineDeMontagnes(Montagne const& mont)
    : Montagne(mont)
{
    montagnes_simples.push_back(mont);
    ++ taille;
}
// Constructeur d'une chaine à partir des élements d'une montagne
ChaineDeMontagnes :: ChaineDeMontagnes(double const& x, double const& y, double const& h, double const& ox, double const& oy, int const& dim)
{
 Montagne M(x, y, h, ox, oy, dim);
 montagnes_simples.push_back(M);
 ++ taille ;

}

// Constructeur d'une chaine à partir d'une autre chaine
/*ChaineDeMontagnes :: ChaineDeMontagnes( ChaineDeMontagnes const& ch)
{
    montagnes_simples = ch.montagnes_simples;
    taille = ch.get_taille();
}*/

// Destructeur
Montagne:: ~Montagne() {}

// Destructeur
ChaineDeMontagnes:: ~ChaineDeMontagnes() {}

//--------------------------------------------------------------METHODES ET OPERATEURS POUR AFFICHER-------------------------------------------------------------//


// Méthode affiche pour une montagne
std::ostream& Montagne:: affiche(std::ostream& sortie) const
{
    sortie << " une montagne : " << endl;
    sortie << " centre de la montagne (" << x0 << "," << y0 << ");" << endl;
    sortie << " hauteur maximale : " << H << endl;
    sortie << " étalement en x : " << ex << endl;
    sortie << " étalement en y : " << ey << endl;
    return sortie;
}

// Surcharge de << pour une Montagne
std::ostream& operator<<(ostream& sortie, Montagne const& montagne)
{
    return montagne.affiche(sortie);
}


// Méthode affiche de la chaine
void ChaineDeMontagnes:: affiche(ostream& sortie) const
{
    for (auto const& element : montagnes_simples)
    {
        sortie << element;
    }

}

// Surcharge de << pour la chaine
ostream& operator<<(ostream& sortie, ChaineDeMontagnes const& chaine)
{
    chaine.affiche(sortie);
    return sortie;
}

//--------------------------------------------------------------METHODES MONTAGNE-------------------------------------------------------------//

// Retourne la dimension de la boite - necessaire pour itérer sur les altitudes afin de dessiner la montagne - cf vue_opengl.cc
int Montagne::  get_dimension() const
{
    return dimension;
}

// Méthode virtuelle qui calcule l'altitude d'une montagne
double Montagne:: altitude(double const& a, double const& b) const
{
    double altitude(H*exp(-((a-x0)*(a-x0))/(2*ex*ex)-((b-y0)*(b-y0))/(2*ey*ey)));
    if (altitude < 0.5) { return 0; }
    else { return altitude; }
}

// Méthode dessine_sur() redéfinie héritée par Dessinable
void Montagne:: dessine_sur(SupportADessin & support)
{
  support.dessine(*this);
}
//--------------------------------------------------------------METHODES CHAINE-------------------------------------------------------------//

// Permet d'obtenir les montagnes simples de la chaine
Montagne ChaineDeMontagnes:: get_montagnes_simples(int const& x) const
{
    return montagnes_simples[x];
}

// Retourne la taille de la montagne
unsigned int ChaineDeMontagnes::  get_taille() const
{
    return taille;
}

// Méthode permettant d'ajouter des montagnes à la chaine
void ChaineDeMontagnes:: set_montagne(Montagne const& montagne)
{
    montagnes_simples.push_back(montagne);
    ++ taille;
}

// Méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne
double ChaineDeMontagnes:: altitude(double const& a, double const& b) const
{
    double retour(0);

            for (size_t i(0); i < montagnes_simples.size(); ++i)
            {
                if (montagnes_simples[i].altitude(a, b) > retour)
                {
                    retour = montagnes_simples[i].altitude(a, b);
                }
            }




    return retour;
}
