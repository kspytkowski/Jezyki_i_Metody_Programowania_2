/**
* \file aghChiKwadrat.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghChiKwadrat
*/

#ifndef AGHCHIKWADRAT_H
#define AGHCHIKWADRAT_H

#include <cmath>
#include "aghTest.h"

/**
* \class aghChiKwadrat
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy aghChiKwadrat
*/
class aghChiKwadrat : public aghTest
{
   private:
      int liczbaPrzedzialow; ///< Liczba przedzialow
      int* tablicaCzestotliwosci; ///< Tablica częstości wystapień danych liczb
      double wartoscKrytyczna; ///< Wyliczona wartość krytyczna
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghChiKwadrat();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _wskGenerator - Wskaźnik na generator
      /// \param _iloscLiczb - Ilośc liczb do wylosowania
      /// \param _liczbaPrzedzialow - Liczba przedzialow
      aghChiKwadrat(aghGenerator* _wskGenerator, int _iloscLiczb, int _liczbaPrzedzialow);
      /// \brief Funkcja ustawiająca liczbę przedzialow
      void ustawLiczbaPrzedzialow(int _liczbaPrzedzialow);
      /// \brief Wirtualna funkcja testująca generator
      virtual void testuj();
      /// \brief Wirtualna funkcja wypisująca na zadany strumien wynik testu
      ///
      /// \param strumien - Strumien, na który należy wypisać wynik testu (domyślnie cout)
      virtual void wypisz(ostream& strumien = cout);
};

#endif
