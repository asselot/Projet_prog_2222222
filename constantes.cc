#include "constantes.h"


	extern const double Physique::g(9.81); // Accélération gravitationnelle 
	extern const double Physique::vinfini(20.0); // Vitesse aux bords de la plaine
	extern const double Physique::Tinfini(284.5); // Température aux bords de la plaine 
	extern const double Physique::Pinfini(101325.0); // Pression aux bords de la plaine 
	extern const double Physique::Pref(101325.0); // Pression de référence 
	extern const double Physique::tau(0.00810); // Taux d'humidité
	extern const double Physique::Meau(0.0180153); // Masse molaire de l'eau
	extern const double Physique::Mair_sec(0.02896); // Masse molaire de l'air sec
	extern const double Physique::R(8.3144621); // Constante des gaz parfaits 
	extern const double Physique::hinfini((7.0/2.0)*(R/Mair_sec)*Tinfini); // Entropie aux bords de la plaine 
	extern const double Physique::cte(0.5*vinfini*vinfini + hinfini); // Constante de Bernouilli
