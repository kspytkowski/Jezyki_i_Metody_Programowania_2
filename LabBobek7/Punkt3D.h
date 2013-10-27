#ifndef PUNKT3D_H
#define PUNKT3D_H
#include "Punkt2D.h"

using namespace std;

class Punkt3D:public Punkt{
  private:
    double z;
  public:
    Punkt3D();
    Punkt3D(double _x, double _y, double _z);
    Punkt3D(const Punkt3D&);
    ~Punkt3D();     
    double distance(Punkt3D);    
};

#endif
