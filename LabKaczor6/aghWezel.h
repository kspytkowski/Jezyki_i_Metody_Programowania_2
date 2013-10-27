/**
* \file aghWezel.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 14.06.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghWezel
*/

#ifndef AGHWEZEL_H
#define AGHWEZEL_H

/**
* \class aghWezel
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 14.06.2013
* \brief Definicja szablonowej klasy aghWezel
*/
template<class Z>
class aghWezel
{
   public:
      Z key; ///< Wartość klucza
      aghWezel* left; ///< Lewe dziecko
      aghWezel* right; ///< Prawe dziecko
      aghWezel* parent; ///< Rodzic
      /// \brief Konstruktor bezparametrowy klasy
      aghWezel() : key(Z()), left(NULL), right(NULL), parent(NULL){}
};

#endif
