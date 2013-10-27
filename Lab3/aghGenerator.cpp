#include <iostream>
#include "aghGenerator.h"

using namespace std;

aghGenerator::aghGenerator(){}
aghGenerator::aghGenerator(int _poczatekZakres, int _koniecZakres, int _ziarno)
{
   if (_koniecZakres > _poczatekZakres)
      throw aghException(0, "Poczatek zakresu nie moze byc mniejszy od konca zakresu", __FILE__, __LINE__);
   poczatekZakres = _poczatekZakres;
   koniecZakres = _koniecZakres;
   ziarno = _ziarno;
}
aghGenerator::~aghGenerator(){}
void aghGenerator::ustawPoczatek(int _poczatekZakres)
{
   poczatekZakres = _poczatekZakres;   
}
void aghGenerator::ustawKoniec(int _koniecZakres)
{
   koniecZakres = _koniecZakres;
}
void aghGenerator::ustawZiarno(int _ziarno)
{
   ziarno = _ziarno;
}
int aghGenerator::wezPoczatek()
{ 
   return poczatekZakres;
}
int aghGenerator::wezKoniec()
{ 
   return koniecZakres;
}
int aghGenerator::wezZiarno()
{ 
   return ziarno;
}
void aghGenerator::wypiszNazwe(ostream& strumien)
{ 
   strumien << endl << nazwaGenerator << endl; 
}
void aghGenerator::wypiszLiczbe(ostream& strumien)
{
   strumien << losujLiczbe() << " ";
}
