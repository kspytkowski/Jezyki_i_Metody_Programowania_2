#include <iostream>
#include "aghSrednia.h"

using namespace std;

aghSrednia::aghSrednia()
{
   nazwaTest = "Test Srednia: ";
}
aghSrednia::aghSrednia(aghGenerator* _wskGenerator, int _iloscLiczb) : aghTest(_wskGenerator, _iloscLiczb)
{
   nazwaTest = "Test Srednia: ";
}
void aghSrednia::testuj()
{

   int aktualnaLiczba;
   wynikSredniej = 0.;
   for(int i = 0; i < iloscLiczb; i++)
   {
      aktualnaLiczba = wskGenerator->losujLiczbe();
      wynikSredniej += (aktualnaLiczba - wynikSredniej) / (i + 1);
   }
}
void aghSrednia::wypisz(ostream& strumien)
{ 
   strumien << "Wyliczona srednia arytmetyczna: " << wynikSredniej;
}
