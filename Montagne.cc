#include <cmath>
#include <iostream>
#include "Montagne.h"
#include "Dessinable.h"
#include "SupportADessin.h"
using namespace std;

//--------------------------------------------------------------METHODES-------------------------------------------------------------//

// Méthode virtuelle qui calcule l'altitude d'une montagne pure
double Montagne:: altitude(double a, double b) const 
{
	double altitude(H*exp(-((a-x0)*(a-x0))/(2*ex*ex)-((b-y0)*(b-y0))/(2*ey*ey)));
	if (altitude < 0.5) { return 0; }
	else { return altitude; }
}

// Méthode virtuelle permettant de modifier les attributs d'une montagne avec les valeurs passées en arguments
void Montagne:: set_montagne(double x, double y, double h, double ox, double oy) 
{
	x0 = x;
	y0 = y;
	H = h;
	ex = ox;
	ey = oy;
}

// Méthode permettant d'afficher les attributs d'une montagne
/*void Montagne :: affiche_para(ostream& sortie) const

{
	sortie << " une montagne : " << endl;
	sortie << type << " de paramètre : " << endl;
	sortie << " centre de la montagne (" << x0 << "," << y0 << ");" << endl;
	sortie << " hauteur maximale : " << H << endl;
	sortie << " étalement en x : " << ex << endl;
	sortie << " étalement en y : " << ey << endl;

	
	
}*/

std::ostream& operator<<(ostream& sortie, Montagne& montagne) 
{
	sortie << " une montagne : " << endl;
	sortie << " centre de la montagne (" << montagne.get_x0() << "," << montagne.get_y0() << ");" << endl;
	sortie << " hauteur maximale : " << montagne.get_H() << endl;
	sortie << " étalement en x : " << montagne.get_ex() << endl;
	sortie << " étalement en y : " << montagne.get_ey() << endl;
	return sortie;
}



// Méthode dessine_sur redéfinie
void Montagne::  dessine_sur(SupportADessin& a_dessiner)
{
	a_dessiner.dessine(*this);
	
}

double Montagne:: get_x0()
{
	return x0;
}
	
double Montagne:: get_y0()
{
	return y0;
}
	
double Montagne:: get_H()
{
	return H;
}
	
double Montagne:: get_ex()
{
	return ex;
}
	
double Montagne:: get_ey()
{
	return ey;
}

// Méthode donnant aux attributs de la i-ème montagne simple de la chaîne les valeurs passées en arguments
void ChaineDeMontagnes:: set_montagne(double x, double y, double h, double ox, double oy, const unsigned int &indice) 
{
	montagnes_simples[indice].set_montagne(x, y, h, ox, oy);
}

// Méthode remplaçant la i-ème sous-chaîne de la chaîne par celle passée en argument 
void ChaineDeMontagnes:: set_montagne(ChaineDeMontagnes chaine, const unsigned int &indice) 
{
	montagnes_simples[indice] = chaine;
}

// Méthode virtuelle qui retourne le maximum des altitudes des montagnes simples et des sous-chaînes qui composent la chaîne 
double ChaineDeMontagnes:: altitude(double a, double b) const 
{
	double retour;
	if ((nombre_montagnes == 0) && (nombre_chaines == 0)) // Cas où il n'y a pas de montagne ni de sous-chaîne
	{
		retour = 0;
	}
	else
	{
		if (montagnes_simples.size() == 0) // Si il n'y a pas de montagnes simples, on travaille uniquement sur les sous-chaînes 
		{
			retour = chaines_simples[0].altitude(a, b); 
			for (size_t j(0); j < chaines_simples.size(); ++j)
			{
				if (chaines_simples[j].altitude(a, b) > retour)
				{
					retour = chaines_simples[j].altitude(a, b); // Calcul du maximum des altitudes des sous-chaînes 
				}
			}
		}
		else if (chaines_simples.size() == 0) // Si il n'y a pas de sous-chaînes, on travaille uniquement sur les montagnes simples 
		{
			retour = montagnes_simples[0].altitude(a, b); 
			for (size_t i(0); i < montagnes_simples.size(); ++i)
			{
				if (montagnes_simples[i].altitude(a, b) > retour)
				{
					retour = montagnes_simples[i].altitude(a, b); // Calcul du maximum des altitudes des montagnes simples 
				}
			}
		}
		else // Cas où il y a des montagnes simples et des sous-chaînes dans la chaîne 
		{
			
			if (montagnes_simples[0].altitude(a, b) > chaines_simples[0].altitude(a, b)) 
			{
				retour = montagnes_simples[0].altitude(a, b);
			}
			else
			{
				retour = chaines_simples[0].altitude(a, b);
			}

			for (size_t i(0); i < montagnes_simples.size(); ++i)
			{
				if (montagnes_simples[i].altitude(a, b) > retour)
				{
					retour = montagnes_simples[i].altitude(a, b); 
				}
			}

			for (size_t j(0); j < chaines_simples.size(); ++j)
			{
				if (chaines_simples[j].altitude(a, b) > retour)
				{
					retour = chaines_simples[j].altitude(a, b); //Calcul du maximum des altitudes dans les deux tableaux 
				}
			}
		}
		
	}
	return retour;
}

// Retourne le nombre de montagnes simples qui composent la chaîne 
int ChaineDeMontagnes:: get_nbre_montagnes() 
{
	return nombre_montagnes;
}

// Retourne le nombre de sous-chaînes qui composent la chaîne 
int ChaineDeMontagnes:: get_nbre_chaines() 
{
	return nombre_chaines;
}

