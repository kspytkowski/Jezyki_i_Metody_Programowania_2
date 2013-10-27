#ifndef PRACOWNIK_H
#define PRACOWNIK_H

#include <iostream>
#include <string.h> ///???????????????????
#include "Umowa.h"

using namespace std;

class Pracownik{
  private:
    string imie,nazwisko,pesel;  
    Umowa* umowa;
  public:
    Pracownik(string i, string n, string p, Umowa* u):
    imie(i),nazwisko(n),pesel(p),umowa(u){};
    Pracownik(const Pracownik&);
    ~Pracownik(){};
    double pobierzPensje();
    friend ostream& operator<<(ostream&,Pracownik&);
};

#endif
