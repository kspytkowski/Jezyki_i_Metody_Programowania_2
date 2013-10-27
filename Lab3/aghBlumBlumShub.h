/**
* \file aghBlumBlumShub.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghBlumBlumShub
*/

#ifndef AGHBLUMBLUMSHUB_H
#define AGHBLUMBLUMSHUB_H

#include "aghGenerator.h"
#include <cmath>

/**
* \class aghBlumBlumShub
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.05.2013
* \brief Definicja klasy aghBlumBlumShub
*/
class aghBlumBlumShub : public aghGenerator
{
   private:
      int pierwszaP; ///< Liczba pierwsza
      int pierwszaQ; ///< Liczba pierwsza
      long int poprzednik; ///< Poprzednia wylosowana liczba
      /// \brief Funkcja sprawdzająca czy podana liczba jest pierwsza
      ///
      /// \param liczba - Liczba
      /// \return - Wartośc logiczna sprawdzenia
      bool czyJestPierwsza(int liczba);
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghBlumBlumShub();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _poczatekZakres - Poczatek zakresu losowanych liczb
      /// \param _koniecZakres - Koniec zakresu losowanych liczb
      /// \param _ziarno - Ziarno
      /// \param _pierwszaP - Liczba pierwsza
      /// \param _pierwszaQ - Liczba pierwsza
      aghBlumBlumShub(int _poczatekZakres, int _koniecZakres, int _ziarno, int _pierwszaP, int _pierwszaQ);
      /// \brief Wirtualna funkcja ustawaijąca ziarno
      ///
      /// \param _ziarno - Ziarno
      virtual void ustawZiarno(int _ziarno);
      /// \brief Funkcja ustawaijąca liczbe pierwszą
      ///
      /// \param _pierwszaP - Liczba pierwsza
      void ustawPierwszaP(int _pierwszaP);
      /// \brief Funkcja ustawaijąca liczbe pierwszą
      ///
      /// \param _pierwszaQ - Liczba pierwsza
      void ustawPierwszaQ(int _pierwszaQ);
      /// \brief Wirtualna funkcja losująca liczbę
      ///
      /// \return Wylosowana liczba
      virtual int losujLiczbe();
};

#endif
