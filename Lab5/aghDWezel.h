/**
* \file aghDWezel.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghDWezel
*/

#ifndef AGHDWEZEL_H
#define AGHDWEZEL_H

#include "aghException.h"

/**
* \class aghDWezel
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \brief Definicja klasy aghDWezel
*/
template <class X>
class aghDWezel
{
   public:
      X wartosc; ///< Wartość
      aghDWezel<X>* nastepny; ///< Wskaźnik na następny węzeł
      aghDWezel<X>* poprzedni; ///< Wskaźnik na poprzedni węzeł
      /// \brief Konstruktor bezparametrowy klasy
      aghDWezel(void); 
};
template <class X>
aghDWezel<X>::aghDWezel(void) : wartosc(X()), nastepny(NULL), poprzedni(NULL){}

#endif
