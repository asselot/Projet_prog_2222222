#prama once 
#include <iostream>
#include "Boite3D.h"
#include "CubeAir.h"
#include "Dessinable.h"
#include "SupportADessin.h"

class Ciel : public Boite3D<CubedAir> Dessinable

{
	friend class CubedAir;
	public:
	virtual void dessine_sur(SupportADessin a_dessiner)
	
	Ciel(const ChampsPotentiels& champ) : Boite3D(champ.Nx, champ.Ny, champ.Nz, champ.pas) {}
	
	
	
};
