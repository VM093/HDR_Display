#ifndef LINEARISATION_H
#define LINEARISATION_H

#include "Correction.h"
#include "courbe.h"

class Linearisation : public Correction
{
public:
    Linearisation();
    Linearisation(Courbe courbe);
    void setCourbe(Courbe courbe);
    void processPixel(int x, int y);

private:
    Courbe _courbe;
};

#endif // LINEARISATION_H
