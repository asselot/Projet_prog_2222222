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
void initialisation(ChaineDeMontagnes& chaine)
{
	
	string reponse(oui); // Réponse de l'utilisateur
	
do
 {
	cout << " Voulez-vous ajouter une montagne supplémentaire à la chaine ? oui/non << endl;
	cout << " Attention au lag " << endl;
	
	cin >> reponse;
	
		do 
			{
				if ( cin.fail() ) 
					{ 
		
						cout  << " Répondez  oui ou non - attention à la syntaxe - " << end; // Insulte modeste sur l'utilisateur
						cout << "Opération annulé " << endl;
		
						cin.clear();
		
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		
				} else  
	
					{
		
						cout << endl;
		
					}
		
		} while ( not cin.fail()); // Tant que le cin n'est pas valable on recommence
	

	if ( reponse == "oui" ) { Ajouter_montagne(chaine); }	// Si la réponse est oui on ajoute une montagne	
		
	else { cout << endl;} 
		
	
	
 } while ( reponse == "oui"); // Tant que l'utilisateur veut des montagnes on en rajoute dans la chaine
	
	
}

// Ajoute une montagne à la chaine
void Ajout_montagne(ChaineDeMontagnes& chaine)

{
	Montagne m ( Creation_montagne());
	
	chaine.set_montagne(m);
	
}

void condition (double& x)

{
	if ( x < -30) { x = -29; }
	if ( x > = 30) { x = 29; }
}

// Créer une chaine de montagne à partir d'une montagne
ChaineDeMontagne Premiere_montagne()
{
  cout << " Ajouter une première montagne - pour initialiser la chaine - " << endl;
	
	// Déclare et initialise une montagne
	Montagne M(Creation_montagne());
	
	// Déclare et initialise une chaine grâce à la première montagne
	ChaineDeMontagne chaine(M);
	
	return chaine;
}

Montagne Creation_montagne()
{
	// Demande tous les paramètres de la montagne
	
	cout " Entrez les pramètres de la montagne : " << endl;
	cout << " Le centre coord_x : " ;
	double x;
	cin >> x;
	condition (x);  // Vérifie des conditions pour les paramètres de la montagne --> à l'intérieur de la boîte
	
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
	
        // Créer la montagne à partir des paramètres reçus
	Montagne m (x, y, h, ex, ey);
	
	return m;
	
}

int main(int argc, char* argv[])
{


  QApplication a(argc, argv);

  ChaineDeMontagne dessin (Premiere_montagne());
  initialisation (dessin);

  ChampsPotentiels ch (30, 30, 30, 1, dessin);

  GLWidget w(ch, dessin);

  w.show();
  return a.exec();

  return 0;
}
