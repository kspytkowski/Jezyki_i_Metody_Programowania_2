#include <iostream>
#include <math.h>
#include "Kwadrat.h"

using namespace std;
Kwadrat::Kwadrat(Punkt e,Punkt f,Punkt g,Punkt h){
  a=e;
  b=f;
  c=g;
  d=h;
};
void Kwadrat::obwod(){
  cout << "Obwod kwadratu wynosi:";
  cout << 4*sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2)) << endl;   
};
void Kwadrat::pole(){
  cout << "Pole kwadratu wynosi:";
  cout << pow(sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2)),2) << endl;   
};
