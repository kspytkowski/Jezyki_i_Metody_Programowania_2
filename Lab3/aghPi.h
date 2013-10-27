/**
* \file aghPi.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghPi
*/

#ifndef AGHPI_H
#define AGHPI_H

#include "aghTest.h"

/**
* \class aghPi
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy aghPi
*/
class aghPi : public aghTest
{
   private:
      double x; ///< Współrzędna x-owa punktu
      double y; ///< Współrzędna y-owa punktu
      int punktyWewnatrz; ///< Ilość punktów wewnątrz koła
      int punktyZewnatrz; ///< Ilość punktów na zewnątrz koła
      double nowePi; ///< Wyliczona wartość liczby pi
   public:
      static const double pi; ///< Wzorcowa wartość liczby pi
      /// \brief Konstruktor bezparametrowy klasy
      aghPi();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _wskGenerator - Wskaźnik na generator
      /// \param _iloscLiczb - Ilośc liczb do wylosowania
      aghPi(aghGenerator* _wskGenerator, int _iloscLiczb);
      /// \brief Wirtualna funkcja testująca generator
      virtual void testuj();
      /// \brief Wirtualna funkcja wypisująca na zadany strumien wynik testu
      ///
      /// \param strumien - Strumien, na który należy wypisać wynik testu (domyślnie cout)
      virtual void wypisz(ostream& strumien = cout);
};

#endif
