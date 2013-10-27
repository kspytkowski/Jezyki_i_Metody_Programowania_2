/**
* \file aghSrednia.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghSrednia
*/

#ifndef AGHSREDNIA_H
#define AGHSREDNIA_H

#include "aghTest.h"

/**
* \class aghSrednia
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy aghSrednia
*/
class aghSrednia : public aghTest
{
   private:     
      double wynikSredniej; ///< Wyliczony wynik średniej arytmetycznej
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghSrednia();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _wskGenerator - Wskaźnik na generator
      /// \param _iloscLiczb - Ilośc liczb do wylosowania
      aghSrednia(aghGenerator* _wskGenerator, int _iloscLiczb);
      /// \brief Wirtualna funkcja testująca generator
      virtual void testuj();
      /// \brief Wirtualna funkcja wypisująca na zadany strumien wynik testu
      ///
      /// \param strumien - Strumien, na który należy wypisać wynik testu (domyślnie cout)
      virtual void wypisz(ostream& strumien = cout);
};

#endif
