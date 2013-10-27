#include <iostream>
#include <list>
#include "Marsjanin.h"
using namespace std;

void Marsjanin::atakuj(){
  cout << "Jest nas: " << liczbaMarsjan << ", wiec atakujemy!" << endl;
};
void Marsjanin::ukryjSie(){
  cout << "Jest nas: " << liczbaMarsjan << ", wiec ukrywamy sie..." << endl;     
};
int Marsjanin::liczbaMarsjan = 0;
