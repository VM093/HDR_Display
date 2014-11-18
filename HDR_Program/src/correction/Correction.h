#ifndef CORRECTION_H
#define CORRECTION_H

class Correction
{
public :
    Correction();
    virtual void processPixel(int x, int y) = 0;
private:

protected:

};

#endif CORRECTION_H
