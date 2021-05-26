#include <iostream>
#include "Dessinable.h"
#include "SupportADessin.h"

// Constructeurs des classes Dessinable et SupportADessin

Dessinable :: Dessinable(SupportADessin& a_dessiner) : support(&a_dessiner) {}

SupportADessin :: SupportADessin() {} // Ne fait rien car aucun attribut

