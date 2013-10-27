#include <iostream>
#include <math.h>
#include "Punkt.h"
using namespace std;

Punkt::Punkt():x(0),y(0){
  cout << "Konstruktor bezparametrowy" << endl;
}; 
Punkt::Punkt(double _x, double _y){
  cout << "Konstruktor parametrowy" << endl;
  x = _x;
  y = _y;
}; 
Punkt::Punkt(const Punkt &ref){
  this->x = ref.x;
  this->y = ref.y;
  cout << "Konstruktor kopiujący" << endl;         
};
Punkt::~Punkt(){
  cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
  cout << endl;
}; 
double Punkt::distance(Punkt inny){
  return sqrt(pow(x-inny.x,2)+pow(y-inny.y,2));
}; 
void Punkt::wyswietl(){
  cout << "(" << x << ";" << y << ")";
};
double Distance(Punkt pierwszy, Punkt drugi){
  // return sqrt(pow(pierwszy.x-drugi.x,2)+pow(pierwszy.y-drugi.y,2));            
  // bezposrednia proba dostepu do skladnikow wywoluje blad kompilacji
  return sqrt(pow(pierwszy.getX()-drugi.getX(),2)+pow(pierwszy.getY()-drugi.getY(),2));
};
istream& operator>>(istream & input, Punkt& p){
   input.ignore();    
   input >> p.x;
   input.ignore();    
   input >> p.y;
   input.ignore();    
   return input;      
};
ostream& operator<<(ostream & output, Punkt& p){
  output << "(" << p.x << "," << p.y << ")" << endl;
  return output;       
};
