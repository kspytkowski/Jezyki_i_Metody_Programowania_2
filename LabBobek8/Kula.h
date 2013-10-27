#ifndef KULA_H
#define KULA_H
#include "Kolo.h"
 
using namespace std;

class Kula : public Kolo{
  private:
    double z;
  public:
    Kula(double _x = 0, double _y = 0, double _z = 0, double _r = 0);
    Kula(const Kula &k);
    ~Kula();
    double pole();    
};

#endif
