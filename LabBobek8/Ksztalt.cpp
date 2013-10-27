#include <iostream>
#include <list>
#include <time.h>
#include <cstdlib>
#include "Ksztalt.h"

void Trojkat::rysuj(){
  cout << "   *   " << endl;
  cout << "  ***  " << endl;
  cout << " ***** " << endl;
  cout << endl;
};

void Kwadrat::rysuj(){
  cout << " ***** " << endl;
  cout << " ***** " << endl;
  cout << " ***** " << endl;
  cout << endl;
};

void Kolo::rysuj(){
  cout << "  ***  " << endl;
  cout << " ***** " << endl;
  cout << "  ***  " << endl;
  cout << endl;
};

