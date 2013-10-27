#include <iostream>
#include <math.h>
#include "Kula.h"
 
using namespace std;

Kula::Kula(double _x, double _y, double _z, double _r):Kolo(_x, _y, _r){
  this->z = _z;
};

Kula::Kula(const Kula &k):Kolo(k.x,k.y,k.r){
  z = k.z;               
};

Kula::~Kula(){};

double Kula::pole(){
  return 3.14*4*r*r;       
};
