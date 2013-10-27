#include <iostream>
#include <math.h>
#include "Zespolona.h"

using namespace std;

Zespolona::Zespolona(double a, double b){
  real=a;
  imaginary=b;
};
void Zespolona::add(Zespolona a, Zespolona b){
  real=a.real+b.real;
  imaginary=a.imaginary+b.imaginary;
};
void Zespolona::sub(Zespolona a, Zespolona b){
  real=a.real-b.real;
  imaginary=a.imaginary-b.imaginary;
};
void Zespolona::mul(Zespolona a, Zespolona b){
  real=a.real*b.real-a.imaginary*b.imaginary;
  imaginary=a.real*b.imaginary+a.imaginary*b.real;
};     
void Zespolona::div(Zespolona a, Zespolona b){
  real=(a.real*b.real+a.imaginary*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
  imaginary=(-a.real*b.imaginary+a.imaginary*b.real)/(b.real*b.real+b.imaginary*b.imaginary);
};
void Zespolona::pow(Zespolona a){
  real=a.real*a.real-a.imaginary*a.imaginary;
  imaginary=2*a.real*a.imaginary;
};  
void Zespolona::Wypisz(){
  cout << real << " + " << imaginary << "sqrt(-1)" << endl;
};
const Zespolona operator+(const Zespolona &a, const Zespolona &b){
  Zespolona c;
  c.real=a.real+b.real;
  c.imaginary=a.imaginary+b.imaginary;
  return c;       
};
const Zespolona operator-(const Zespolona &a, const Zespolona &b){
  Zespolona c;
  c.real=a.real-b.real;
  c.imaginary=a.imaginary-b.imaginary;
  return c;    
};
const Zespolona operator+=(Zespolona &a, const Zespolona &b){
  a.real=a.real+b.real;
  a.imaginary=a.imaginary+b.imaginary;
  return a;     
};
const Zespolona operator-=(Zespolona &a, const Zespolona &b){
  a.real=a.real-b.real;
  a.imaginary=a.imaginary-b.imaginary;
  return a;
};
const Zespolona operator*(const Zespolona &a, const Zespolona &b){
  Zespolona c;
  c.real=a.real*b.real-a.imaginary*b.imaginary;
  c.imaginary=a.real*b.imaginary+a.imaginary*b.real;
  return c;      
};
const Zespolona operator/(const Zespolona &a, const Zespolona &b){
  Zespolona c;
  c.real=(a.real*b.real+a.imaginary*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
  c.imaginary=(-a.real*b.imaginary+a.imaginary*b.real)/(b.real*b.real+b.imaginary*b.imaginary);
  return c;      
};
bool operator==(const Zespolona &a, const Zespolona &b){
  return ((a.real==b.real)&&(a.imaginary==b.imaginary));       
};
bool operator!=(const Zespolona &a, const Zespolona &b){
  return !((a.real==b.real)&&(a.imaginary==b.imaginary));       
};
bool operator<(const Zespolona &a, const Zespolona &b){
  double modul1, modul2;
  modul1 = sqrt(pow(a.real,2)+pow(a.imaginary,2));
  modul2 = sqrt(pow(b.real,2)+pow(b.imaginary,2));
  if (modul1 < modul2) return true;
  else return false;
}
bool operator>(const Zespolona &a, const Zespolona &b){
  double modul1, modul2;
  modul1 = sqrt(pow(a.real,2)+pow(a.imaginary,2));
  modul2 = sqrt(pow(b.real,2)+pow(b.imaginary,2));
  if (modul1 > modul2) return true;
  else return false;
}
