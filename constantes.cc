#include "constantes.h"

//Fichier contenant toutes les constantes physiques qui sont nécessaires dans certaines classes

	extern const double Physique::g(9.81);                                // Accélération gravitationnelle
        extern const double Physique::vinfini(20.0)                            // Vitesse aux bords
	extern const double Physique::Tinfini(284.5);                         // Température aux bords
	extern const double Physique::Pinfini(101325);                        // Pression de l'air au bord
	extern const double Physique::Pref(101325);                           // Pression de référence
	extern const double Physique::tau(8.10e-3);                           // Taux d'humidité
	extern const double Physique::Meau(0.0180153);                        // Masse molaire eau
	extern const double Physique::Mair_sec(0.02896);                      // Masse molaire air sec
	extern const double Physique::R(8.3144621);                           // Constante des gaz parfait
	extern const double Physique::hinfini((7/2)*(R/Mair_sec)*Tinfini);    // Enthalpie aux bords
	extern const double Physique::cte(0.5*vinfini*vinfini + hinfini);     // Constante de Bernouilli
