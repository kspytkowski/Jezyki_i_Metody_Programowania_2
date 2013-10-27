/**
* \file aghWbudowany.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghWbudowany
*/

#ifndef AGHWBUDOWANY_H
#define AGHWBUDOWANY_H

#include "aghGenerator.h"

/**
* \class aghWbudowany
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy aghWbudowany
*/
class aghWbudowany : public aghGenerator
{
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghWbudowany();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _poczatekZakres - Poczatek zakresu losowanych liczb
      /// \param _koniecZakres - Koniec zakresu losowanych liczb
      /// \param _ziarno - Ziarno
      aghWbudowany(int _poczatekZakres, int _koniecZakres, int _ziarno);
      /// \brief Wirtualna funkcja ustawaijąca ziarno
      ///
      /// \param _ziarno - Ziarno
      virtual void ustawZiarno(int _ziarno);
      // \brief Wirtualna funkcja losująca liczbę
      ///
      /// \return Wylosowana liczba
      virtual int losujLiczbe();
};

#endif
