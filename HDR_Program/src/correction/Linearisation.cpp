#include "Linearisation.h"

#include <iostream>

Linearisation::Linearisation()
{
}

Linearisation::Linearisation(Courbe courbe)
{
    _courbe = courbe;
}

void Linearisation::setCourbe(Courbe courbe)
{
    _courbe = courbe;
}

void Linearisation::processPixel(int x, int y)
{
    float valWanted = 0.8;
    float valObtained = _courbe.dichotomie(valWanted);
    std::cout << "Valeur souhaitée : " << valWanted << std::endl;
    std::cout << "Valeur obtenue : " << valObtained << std::endl;
    std::cout << "Affichage : " << _courbe.getValue(valObtained*255.) << std::endl;
    //std::cout << _courbe.getValue(0.5) << std::endl;
}
