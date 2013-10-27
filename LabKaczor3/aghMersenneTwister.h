/**
* \file aghMersenneTwister.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghMersenneTwister
*/

#ifndef AGHMERSENNETWISTER_H
#define AGHMERSENNETWISTER_H

#include "aghGenerator.h"

/**
* \class aghMersenneTwister
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy aghMersenneTwister
*/
class aghMersenneTwister : public aghGenerator
{
   private:
      int index; ///< Index tablicy
      int MT[624]; ///< Tablica liczb
      /// \brief Funkcja generująca liczby do tablicy
      void generujLiczby(); 
   public:      
      /// \brief Konstruktor bezparametrowy klasy
      aghMersenneTwister();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _poczatekZakres - Poczatek zakresu losowanych liczb
      /// \param _koniecZakres - Koniec zakresu losowanych liczb
      /// \param _ziarno - Ziarno
      aghMersenneTwister(int _poczatekZakres, int _koniecZakres, int _ziarno);
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

