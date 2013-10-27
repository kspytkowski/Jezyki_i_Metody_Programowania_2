/**
* \file aghGenerator.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy abstrakcyjnej aghGenerator
*/

#ifndef AGHGENERATOR_H
#define AGHGENERATOR_H

#include <iostream>
#include "aghException.h"

using namespace std;

/**
* \class aghGenerator
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy abstrakcyjnej aghGenerator
*/
class aghGenerator
{
   protected:
      int poczatekZakres; ///< Poczatek zakresu losowanych liczb
      int koniecZakres; ///< Koniec zakresu losowanych liczb
      int ziarno; ///< Ziarno
      const char* nazwaGenerator; ///< Nazwa generatora
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghGenerator();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _poczatekZakres - Poczatek zakresu losowanych liczb
      /// \param _koniecZakres - Koniec zakresu losowanych liczb
      /// \param _ziarno - Ziarno
      aghGenerator(int _poczatekZakres, int _koniecZakres, int _ziarno);
      /// \brief Wirtualny destruktor klasy
      virtual ~aghGenerator();
      /// \brief Funkcja ustawaijąca poczatek zakresu losowanych liczb
      ///
      /// \param _poczatekZakres - Poczatek zakresu losowanych liczb
      void ustawPoczatek(int _poczatekZakres);
      /// \brief Funkcja ustawaijąca koniec zakresu losowanych liczb
      ///
      /// \param _koniecZakres - Koniec zakresu losowanych liczb
      void ustawKoniec(int _koniecZakres);
      /// \brief Wirtualna funkcja ustawaijąca ziarno
      ///
      /// \param _ziarno - Ziarno
      virtual void ustawZiarno(int _ziarno);
      /// \brief Funkcja zwracająca poczatek zakresu losowanych liczb
      ///
      /// \return Początek zakresu losowanych liczb
      int wezPoczatek();      
      /// \brief Funkcja zwracająca koniec zakresu losowanych liczb
      ///
      /// \return Koniec zakresu losowanych liczb
      int wezKoniec();
      /// \brief Funkcja zwracająca Ziarno
      ///
      /// \return Ziarno
      int wezZiarno();      
      /// \brief Czysto wirtualna funkcja losująca liczbę
      ///
      /// \return Wylosowana liczba
      virtual int losujLiczbe() = 0;      
      /// \brief Wirtualna funkcja wypisująca na zadany strumien nazwe generatora
      ///
      /// \param strumien - Strumien, na który należy wypisać nazwe generatora (domyślnie cout)
      virtual void wypiszNazwe(ostream& strumien = cout);
      /// \brief Wirtualna funkcja wypisująca na zadany strumien wylosowaną liczbę
      ///
      /// \param strumien - Strumien, na który należy wypisać wylosowaną liczbę (domyślnie cout)
      virtual void wypiszLiczbe(ostream& strumien = cout);
};

#endif
