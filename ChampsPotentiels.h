#pragma once
#include <iostream>
#include <vector>
#include <array>
#include "Vecteur2D.h"
#include "constantes.h"
#include "Boite3D.h"
#include "Potentiel.h"
#include "Montagne.h"



class ChampsPotentiels : public Boite3D
{
	friend class Ciel;
	public:
	ChampsPotentiels(unsigned int nox = 30, unsigned int noy = 30, unsigned int noz = 30, double p = 1) : Boite3D(nox, noy, noz, p) 
	{}

	void initialise(double vi, const Montagne& mont); //il ne reconnait pas le type montagne!!
	
	bool estauxbords(Potentiel pot) const;
	
	void calcule_laplaciens();
	double erreur();
	void iteration( double E = 0.1);
	void resolution ( double seuil = 2.2621843e-5, unsigned int max = 5000, bool verbeuse = false);
	std::array<double, 3> vitesse(unsigned int i, unsigned int j, unsigned int k) const;
	double norme_vitesse(unsigned int pointi, unsigned int pointj, unsigned int pointk);


	std::vector<std::vector<std::vector<Potentiel>>> get_tableaudepotentiels();
	
	//void remettre(Montagne m);
		
	private:
	std::vector<std::vector<std::vector<Potentiel>>> potentiels3D; //mettre des template ici
	 
};





















//on ne oeut pas changer la classe montagne bc une chaine de montagnes est une chaine et une montagne... modifier la classe montane pour qu'elle puisse admettre plein plein de nouveaux pics?
//ou alors mettre la montagne en attribut pointé et créer plein d'attributs petite montagne? ou faire un tableau de pointeurs? jsp si on peut faire ca hahaha
//mais le probleme cest calculer la hauteur comme il le fait sur gnuplot... si on fait un tableau estce que ca fusionnera les montagnes comme on veut ou estce que ca en fera plein de distinctes?
//est ce qu'on peut faire des tableaux de pointeurs? bc un tableau de montagnes c'est pas dur mais ca prend masse de place -> un tableau de pointeurs sur des montagnes?
//creer une nouvelle classe ChaineDeMontagnes qui herite de la classe montagne??






