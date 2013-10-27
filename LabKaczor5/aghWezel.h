/**
* \file aghSWezel.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghSWezel
*/

#ifndef AGHSWEZEL_H
#define AGHSWEZEL_H

#include "aghException.h"

/**
* \class aghSWezel
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \brief Definicja klasy aghSWezel
*/
template <class X>
class aghSWezel
{
   public:
      X wartosc; ///< Wartość
      aghSWezel* nastepny; ///< Wskaźnik na następny węzeł
      /// \brief Konstruktor bezparametrowy klasy
      aghSWezel(void); 
};
template <class X>
aghSWezel<X>::aghSWezel(void) : wartosc(X()), nastepny(NULL){}

#endif
