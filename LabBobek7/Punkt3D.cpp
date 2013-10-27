#include <iostream>
#include <math.h>
#include "Punkt3D.h"

using namespace std;

Punkt3D::Punkt3D():Punkt(0,0),z(0){
  cout << "Konstruktor bezparametrowy Punktu 3D" << endl;
};       

Punkt3D::Punkt3D(double _x, double _y, double _z):Punkt(_x,_y){
  cout << "Konstruktor parametrowy Punktu 3D" << endl;
  z = _z;
}; 

Punkt3D::Punkt3D(const Punkt3D &p):Punkt(p.x,p.y){
  cout << "Konstruktor kopiujacy Punktu 3D" << endl;
  z = p.z;
};                       

Punkt3D::~Punkt3D(){
  cout << "Destruktor 3D! Nic nie robie, bo nie musze zwalniać pamięci!";
  cout << endl;                    
};

double Punkt3D::distance(Punkt3D inny){
  return sqrt(pow(x-inny.x,2)+pow(y-inny.y,2)+pow(z-inny.z,2));       
}
