/**
* \file aghFib.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 01.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghFib
*/

#ifndef AGHFIB_H
#define AGHFIB_H

/**
* \class aghFib
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 01.05.2013
* \brief Klasa aghFib służy do wyznaczania liczb ciągu Fibonacciego
*/
class aghFib
{
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghFib(){};
      /// \brief Konstruktor kopiujący klasy
      aghFib(const aghFib& model){}; 
      /// \brief Destruktor klasy
      ~aghFib(){};
      /// \brief Przeładowany operator[]
      ///
      /// \param index - Index poszukiwanej liczby ciągu Fibonacciego
      /// \return Liczba ciągu Fibonacciego o zadanym indexie
      int operator[](int index);
};

#endif
