#include "courbe.h"

#include <math.h>

Courbe::Courbe()
{
}

Courbe::Courbe(std::vector<float> coeffs)
{
    _coeffs = coeffs;
}

float Courbe::getValue(float x)
{
    float sum = 0;
    // Cas où coefficients non renseignés
    if(_coeffs.size() == 0)
    {
        std::cout << "Erreur : Pas de coefficients spécifiés" << std::endl;
    }
    else
    {
        for(int i=0; i<_coeffs.size(); i++)
        {
            sum += _coeffs[i]*pow(x,i);
        }
    }

    return(sum);
}

void Courbe::setCoeffs(std::vector<float> coeffs)
{
    _coeffs = coeffs;
}

void Courbe::setCoeff(float coeff, int i)
{
    if(i>=_coeffs.size())
    {
        _coeffs.resize(i+1);
    }
    _coeffs[i] = coeff;
}

std::vector<float> Courbe::getCoeffs()
{
    return(_coeffs);
}

float Courbe::dichotomie(float value)
{
    if(value < 0. || value > 1.)
    {
        std::cout << "Erreur : la valeur doit etre comprise entre 0 et 1." << std::endl;
        return(0);
    }
    else
    {
        float mil;
        float db = 0.;
        float fin = 255.;

        while (fin - db > 1.)
        {
            mil = (fin + db)/2.;
            if (value < getValue(mil))
            {
                fin = mil;
            }
            else
            {
                db = mil;
            }
        }

        return(1.0*(fin + db)/(2.*255.));
    }
}

void Courbe::operator=(Courbe courbe)
{
    _coeffs.clear();
    _coeffs = courbe.getCoeffs();
}
