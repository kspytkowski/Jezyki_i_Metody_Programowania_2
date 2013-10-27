#include <iostream>
#include <string.h> ///???????????????????
#include "Pracownik.h"

using namespace std;

Pracownik::Pracownik(const Pracownik &stary){
  imie = stary.imie;
  nazwisko = stary.nazwisko;
  pesel = stary.pesel;
  umowa = stary.umowa;
};

double Pracownik::pobierzPensje(){
  return umowa->pobierzNetto();
};

ostream& operator<<(ostream &wyjscie, Pracownik &ten){
  wyjscie << ten.imie << " " << ten.nazwisko << " zarabia brutto ";
  wyjscie << ten.umowa->pobierzBrutto() << "zl, co w tym przypadku daje ";
  wyjscie << ten.pobierzPensje() << "zl netto";
  return wyjscie;
};
