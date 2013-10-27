#include <iostream>
#include "aghPi.h"

using namespace std;

const double aghPi::pi = 3.14159;

aghPi::aghPi()
{
   nazwaTest = "Test Pi:";
   punktyWewnatrz = 0;  
   punktyZewnatrz = 0; 
}
aghPi::aghPi(aghGenerator* _wskGenerator, int _iloscLiczb) : aghTest(_wskGenerator, _iloscLiczb)
{
   nazwaTest = "Test Pi";
   punktyWewnatrz = 0;
   punktyZewnatrz = 0;
}
void aghPi::testuj()
{
   while (punktyWewnatrz < iloscLiczb)
   {
      x = static_cast<double>(wskGenerator->losujLiczbe() - wskGenerator->wezPoczatek()) / static_cast<double>(wskGenerator->wezKoniec() - wskGenerator->wezPoczatek());
      y = static_cast<double>(wskGenerator->losujLiczbe() - wskGenerator->wezPoczatek()) / static_cast<double>(wskGenerator->wezKoniec() - wskGenerator->wezPoczatek());
      punktyWewnatrz = punktyWewnatrz + 1;
      if (x * x + y * y <= 1)
         punktyZewnatrz = punktyZewnatrz + 1;
   }
   nowePi = 4.0 * static_cast<double>(punktyZewnatrz) / static_cast<double>(punktyWewnatrz);
   punktyWewnatrz = 0;
   punktyZewnatrz = 0;
}
void aghPi::wypisz(ostream& strumien)
{ 
   strumien << "Wyliczona wartość liczby Pi: " << nowePi;
}

