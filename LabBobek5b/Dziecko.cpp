#include <iostream>
#include <string.h>
#include "Dziecko.h"
using namespace std;

Dziecko::Dziecko(string imi, string naz, int wie, string szk){
  imie=imi;
  nazwisko=naz;
  wiek=wie;
  szkola=szk;
};
Rodzic::Rodzic(string im, string na, int w, string im_d, string na_d, int w_d, string sz_d):dziecko(im_d, na_d, w_d, sz_d){
  imie=im;
  nazwisko=na;
  wiek=w;
};
void Rodzic::przepiszDoInnejSzkoly(string nazwa){
  dziecko.szkola=nazwa; 
};
