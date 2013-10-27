
#ifndef RODZIC_H_
#define RODZIC_H_
#include <iostream>
#include "Dziecko.h"

using namespace std;
class Rodzic{
  private:
    string imie;
    string nazwisko;
    int wiek;
    Dziecko dziecko;
  public:
    Rodzic(string im, string na, int w, string im_d, string na_d, int w_d, string sz_d);
    void przepiszDoInnejSzkoly(string nazwa);
    void wypisz();
};

#endif
