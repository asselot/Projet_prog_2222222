/*#include <QApplication>
#include "glwidget.h"
#include "Boite3D.h"
#include "ChampsPotentiels.h"
#include "Ciel.h"
#include "Systeme.h"
#include "Montagne.h"
#include "SupportADessin.h"
#include "constantes.h"*/

#include <iostream>
#include <string>

class Montagne;
class ChaineDeMontagne;
class ChampsPotentiels;
class GLWidget;


using namespace std;


// Permet d'initialiser autant de montagne dans la chaine
ChaineDeMontagne initialisation(ChaineDeMontagnes& chaine)
{
	
	string reponse(oui);
	
do
 {
	cout << " Voulez-vous ajouter une montagne supplémentaire à la chaine ? oui/non << endl;
	cout << " Attention au lag " << endl;
	
	cin >> reponse;
	
		do 
			{
				if ( cin.fail() ) 
					{ 
		
						cout  << " Répondez  oui ou non - attention à la syntaxe - " << end;
						cout << "Opération annulé " << endl;
		
						cin.clear();
		
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		
				} else  
	
					{
		
						cout << endl;
		
					}
			
		} while ( not cin.fail());
	

	if ( reponse == "oui" ) { Ajouter_montagne(); }		
		
	else { cout << endl;}
		
	
	
 } while ( reponse == "oui");
	
}

// Ajoute une montagne à la chaine
Ajout_montagne(ChaineDeMontagnes& chaine)

{
	cout " Entrez les pramètres de la montagne : " << endl;
	cout << " Le centre coord_x : " ;
	double x;
	cin >> x;
	condition (x); 

	
	
	cout << " Le centre coord_y : " ;
	double y;
	cin >> y;
	condition (y); 
	
	cout << " La hauteur : ;
	double h; 
	cin >> h;
	
	if ( h  <= 0) { h = 1; }
	if ( x > = 27) { x = 27; }
	
	cout << " l'étalement en x : ";
	double ex;
	cin >> ex;
	condition (ex); 
	
	cout << " l'étalement en y : ";
	double ey;
	cin >> ey;
	condition (ey); 
	

	Montagne m ( x, y, h, ex, ey);
	
	chaine.set_montagne(m);
	
}

void condition (double& x)

{
	if ( x < -30) { x = -29; }
	if ( x > = 30) { x = 29; }
}

ChaineDeMontagne Premiere_montagne()
{
  cout << " Ajouter une première montagne - pour initialiser la chaine - " << endl;
	Ajout_montagne();
}

int main(int argc, char* argv[])
{


  QApplication a(argc, argv);

  ChaineDeMontagne dessin1;
  initialisation (dessin1);

  ChampsPotentiels ch (30, 30, 30, 1, dessin1);

  GLWidget w(ch, dessin1);

  w.show();
  return a.exec();

  return 0;
}
