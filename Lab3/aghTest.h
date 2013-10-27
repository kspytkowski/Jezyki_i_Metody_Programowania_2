/**
* \file aghTest.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy abstrakcyjnej aghTest
*/

#ifndef AGHTEST_H
#define AGHTEST_H

#include <iostream>
#include "aghGenerator.h"

using namespace std;

/**
* \class aghTest
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy abstrakcyjnej aghTest
*/
class aghTest
{
   protected:
      aghGenerator* wskGenerator; ///< Wskaźnik na generator
      int iloscLiczb; ///< Ilośc liczb do wylosowania
      const char* nazwaTest; ///< Nazwa testu
   public:      
      /// \brief Konstruktor bezparametrowy klasy
      aghTest();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _wskGenerator - Wskaźnik na generator
      /// \param _iloscLiczb - Ilośc liczb do wylosowania
      aghTest(aghGenerator* _wskGenerator, int _iloscLiczb);
      /// \brief Wirtualny destruktor klasy
      virtual ~aghTest();
      /// \brief Funkcja ustawaijąca wskaźnik na generator
      ///
      /// \param _wskGenerator - Wskaźnik na generator
      void ustawGenerator(aghGenerator* _wskGenerator);
      /// \brief Funkcja ustawaijąca ilośc liczb do wylosowania
      ///
      /// \param _iloscLiczb - Ilośc liczb do wylosowania
      void ustawIloscLiczb(int _iloscLiczb);
      /// \brief Czysto wirtualna funkcja testująca generator
      virtual void testuj() = 0;
      /// \brief Funkcja wypisująca na zadany strumien nazwe testu
      ///
      /// \param strumien - Strumien, na który należy wypisać nazwe testu (domyślnie cout)
      void wypiszNazwe(ostream& strumien = cout);
      /// \brief Czysto wirtualna funkcja wypisująca na zadany strumien wynik testu
      ///
      /// \param strumien - Strumien, na który należy wypisać wynik testu (domyślnie cout)
      virtual void wypisz(ostream& strumien = cout) = 0;
};

#endif
