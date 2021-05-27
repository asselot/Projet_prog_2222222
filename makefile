CC = $(CXX)
all : testMontagne testVecteur2D testPotentiel testLaplace testNuages testMontagne2 

Vecteur2D.o : Vecteur2D.cc Vecteur2D.h

testVecteur2D.o : testVecteur2D.cc Vecteur2D.h 

testVecteur2D : testVecteur2D.o Vecteur2D.o 

SupportADessin.o : SupportADessin.h Montagne.h Ciel.h Systeme.h

Montagne.o : Montagne.h Montagne.cc Dessinable.h SupportADessin.h ChampsPotentiels.h

Dessinable.o : Dessinable.h SupportADessin.h

Systeme.o : Systeme.h Systeme.cc Montagne.h Ciel.h ChampsPotentiels.h

Boite3D.o : Boite3D.h Boite3D.cc

CubedAir.o : CubedAir.h CubedAir.cc Boite3D.h ChampsPotentiels.h Ciel.h

Potentiel.o : Potentiel.h Potentiel.cc ChampsPotentiels.h Vecteur2D.h

testMontagne.o : testMontagne.cc Montagne.h 

testMontagne : testMontagne.o Montagne.o

testMontagne2.o : testMontagne2.cc Montagne.h 

testMontagne2 : testMontagne2.o Montagne.o

constantes.o: constantes.cc constantes.h

TextViewer.o : TextViewer.h TextViewer.cc SupportADessin.h

Ciel.o : Ciel.h Ciel.cc Boite3D.h CubedAir.h Dessinable.h SupportADessin.h ChampsPotentiels.h 

ChampsPotentiels.o: Vecteur2D.h Montagne.h ChampsPotentiels.cc ChampsPotentiels.h Boite3D.h Potentiel.h 

testPotentiel.o : testPotentiel.cc Montagne.h Vecteur2D.h ChampsPotentiels.h Potentiel.h

testPotentiel : testPotentiel.o Montagne.o Vecteur2D.o ChampsPotentiels.o constantes.o Potentiel.o

testLaplace.o : testLaplace.cc Montagne.h Vecteur2D.h ChampsPotentiels.h 

testLaplace : testLaplace.o Montagne.o Vecteur2D.o ChampsPotentiels.o constantes.o

testNuages.o : testNuages.cc Montagne.h Vecteur2D.h ChampsPotentiels.h Potentiel.h

testNuages : testNuages.o Montagne.o Vecteur2D.o ChampsPotentiels.o constantes.o Potentiel.o
