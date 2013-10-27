#ifndef KOLO_H
#define KOLO_H
 
using namespace std;

class Kolo{
  protected:
    double x, y, r;
  public:
    Kolo(double _x = 0, double _y = 0, double _r = 0);
    Kolo(const Kolo&);
    ~Kolo();
    double pole();    
};

#endif


