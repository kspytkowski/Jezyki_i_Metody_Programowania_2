/**
* \file aghsuma.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 01.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje szablonu funkcji suma
*/

#ifndef AGHSUMA_H
#define AGHSUMA_H

#include <iostream>
#include <cstring>
#include "aghException.h"

using namespace std;

/// \brief Funkcja sumuje wszystkie elementy w tablicy
///
/// \param tablica - Tablica danych do zsumowania
/// \param dlugoscTablicy - Długość tablicy
/// \return Suma wszystkich elementow tablicy
template <class T>
double suma(T tablica, int dlugoscTablicy)
{
   if (dlugoscTablicy < 0)
      throw aghException(0, "Długośc tablicy przekazanej do zsumowania nie może być mniejsza od 0", __FILE__, __LINE__);
   double wynik = 0;
   for (int i = 0; i < dlugoscTablicy; i++)
   {
      wynik = wynik + tablica[i];
      cout << tablica[i];
      if (i < dlugoscTablicy-1)
         cout << " + "; 
   };
   cout << " = " << wynik << endl;
   return wynik;
}
/// \brief Funkcja (specjalizowana) sumuje (skleja) wszystkie stringi w tablicy w jeden ciąg oraz wyświetla go wraz z podaniem jego długości
///
/// \param tablica - Tablica stringów do zsumowania (sklejenia)
/// \param dlugoscTablicy - Ilość stringów
/// \return Długość powstałego stringa
double suma(char** tablica, int dlugoscTablicy)
{
   if (dlugoscTablicy < 0)
      throw aghException(0, "Długośc tablicy przekazanej do zsumowania (sklejenia wyrazów) nie może być mniejsza od 0", __FILE__, __LINE__);
   int dlugoscSlow = 0;
   for (int i = 0; i < dlugoscTablicy; i++)
   {
      dlugoscSlow = dlugoscSlow + strlen(tablica[i]);
      cout << tablica[i];
      if (i < dlugoscTablicy - 1)
         cout << " + ";
   };
   char* wynik = new char[dlugoscSlow];
   for (int j = 0; j < dlugoscTablicy; j++)
   {
      strcat(wynik,tablica[j]);
   };
   cout << " = " << wynik << "(" << strlen(wynik) << ")" << endl;
   return strlen(wynik);
}

#endif
