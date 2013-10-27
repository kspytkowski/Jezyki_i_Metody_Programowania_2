#include <iostream>
#include "aghChiKwadrat.h"

using namespace std;

aghChiKwadrat::aghChiKwadrat()
{
   nazwaTest = "Test ChiKwadrat: ";
}
aghChiKwadrat::aghChiKwadrat(aghGenerator* _wskGenerator, int _iloscLiczb, int _liczbaPrzedzialow) : aghTest(_wskGenerator, _iloscLiczb)
{
   nazwaTest = "Test ChiKwadrat: ";
   if (_iloscLiczb < sqrt(_liczbaPrzedzialow) * 10)
      throw aghException(0, "Liczba przedziałów nie spełnia zalezności iloscLiczb < sqrt(liczbaPrzedzialow)*10", __FILE__, __LINE__);
   liczbaPrzedzialow = _liczbaPrzedzialow;
}
void aghChiKwadrat::ustawLiczbaPrzedzialow(int _liczbaPrzedzialow)
{
   liczbaPrzedzialow = _liczbaPrzedzialow;
}
void aghChiKwadrat::testuj()
{
   tablicaCzestotliwosci = new int[wskGenerator->wezKoniec() - wskGenerator->wezPoczatek()];
   for (int z = 0; z < wskGenerator->wezKoniec() - wskGenerator->wezPoczatek(); z++)
      tablicaCzestotliwosci[z] = 0;
   int liczba;
   for(int i = 0; i < iloscLiczb; i++)
   {
      liczba = wskGenerator->losujLiczbe();
      tablicaCzestotliwosci[liczba] += 1;
   }
   wartoscKrytyczna = 0.;
   for (int j = 0; j < liczbaPrzedzialow; j++)
      wartoscKrytyczna = wartoscKrytyczna + ((static_cast<double>(iloscLiczb) / static_cast<double>(liczbaPrzedzialow)) - tablicaCzestotliwosci[j]) * ((static_cast<double>(iloscLiczb) / static_cast<double>(liczbaPrzedzialow)) - tablicaCzestotliwosci[j]);
   wartoscKrytyczna = wartoscKrytyczna / (static_cast<double>(iloscLiczb) / static_cast<double>(liczbaPrzedzialow));
   delete [] tablicaCzestotliwosci;
}
void aghChiKwadrat::wypisz(ostream& strumien)
{ 
   strumien << "Wyliczona wartosc krytyczna: " << wartoscKrytyczna;
}
