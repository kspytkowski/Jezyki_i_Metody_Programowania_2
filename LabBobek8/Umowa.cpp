#include <iostream>
#include <string.h> ///???????????????????
#include "Umowa.h"

using namespace std;

Umowa::Umowa(double pensja){
  wynagrodzenieBrutto = pensja;
};

double Umowa::pobierzBrutto(){
  return wynagrodzenieBrutto;
};

double UmowaDzielo::pobierzNetto(){
  return 0.8*pobierzBrutto();
};

double UmowaPraca::pobierzNetto(){
  return 0.6*pobierzBrutto();
};
