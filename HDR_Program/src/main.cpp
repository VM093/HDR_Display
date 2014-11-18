#include "Includes.h"

#include "Linearisation.h"
#include "courbe.h"

main()
{
    std::cout << "Hello Robert !" << std::endl;+

    std::vector<float> coeffs;
    coeffs.push_back(2.6242393e-03);
    coeffs.push_back(3.4504178e-04);
    coeffs.push_back(-1.6646242e-07);
    coeffs.push_back(1.2630876e-07);
    coeffs.push_back(-2.5823518e-10);
    coeffs.push_back(-7.4170105e-14);

    Courbe courbe(coeffs);
    //std::cout << courbe.getValue(0.5) << std::endl;
    //std::cout << courbe.dichotomie(1.) << std::endl;

    Linearisation lin(courbe);
    lin.processPixel(3,2);

    return 0;
}
