/**
* \file aghIterator.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.06.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghIterator
*/

#ifndef AGHITERATOR_H
#define AGHITERATOR_H

#include <iostream> 
#include "aghContainer.h"
#include "aghException.h"

using namespace std;

/**
* \class aghIterator
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 16.06.2013
* \brief Definicja abstrakcyjnej klasy aghIterator
*/
template <class S>
class aghIterator
{
   private:
      aghContainer<S>* pojemnik; ///< Wskaźnik na pojemnik
      int index; ///< Index elementu
   public:
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _pojemnik - Wskaźnik na pojemnik
      aghIterator(aghContainer<S>* _pojemnik);
      /// \brief Funkcja ustawiająca interator na pierwszy element w pojemniku
      ///
      /// \return Iterator pokazujący na pierwszy element w pojemniku
      aghIterator<S> first();
      /// \brief Funkcja ustawiająca interator na ostatni element w pojemniku
      ///
      /// \return Iterator pokazujący na ostatni element w pojemniku
      aghIterator<S> last();      
      /// \brief Funkcja przesuwająca interator na następny element w pojemniku
      ///
      /// \return Referencja do iteratora
      aghIterator<S>& next();
      /// \brief Funkcja przesuwająca interator na poprzedni element w pojemniku
      ///
      /// \return Referencja do iteratora
      aghIterator<S>& prev();
      /// \brief Funkcja zwracająca aktualnie pokazywany element w pojemniku
      ///
      /// \return Referencja do iteratora
      S& current();
      /// \brief Funkcja przenosząca interator na pierwszy element w pojemniku
      ///
      /// \return Referencja do iteratora
      aghIterator<S>& atFirst();
      /// \brief Funkcja przenosząca interator na ostatni element w pojemniku
      ///
      /// \return Referencja do iteratora
      aghIterator<S>& atLast();
      /// \brief Funkcja zwracająca ilość elementów od aktualnie pokazywanego do ostatniego elementu w pojemniku
      int size();
      /// \brief Pezeładowany operator[]
      ///
      /// \param pozycja - Pozycja elementu znajdującego się o i pozycji dalej względem aktualnego elementu
      /// \return Element znajdujący się o i pozycji dalej względem aktualnego elementu
      S operator[](int pozycja);
      /// \brief Przeładowany operator int
      operator int();
      /// \brief przeładowany operator*
      ///
      /// return Aktualnie pokazywany element
      S& operator*();
      /// \brief Przeładowany operator=
      ///
      /// \param model - Model iteratora
      /// \return Referencja do this
      aghIterator<S>& operator=(const aghIterator<S>& model);
      /// \brief Przeładowany operator+
      ///
      /// \param przesun - Przesuniecie
      /// \return Iterator przesunięty o i elementów dalej
      aghIterator<S> operator+(int przesun);
      /// \brief Przeładowany operator-
      ///
      /// \param przesun - Przesuniecie
      /// \return Iterator przesunięty o i elementów bliżej
      aghIterator<S> operator-(int przesun);
      /// \brief Przesuwa iterator o i elementów dalej
      ///
      /// \param przesun - Przesunięcie
      void operator+=(int przesun);
      /// \brief Przesuwa iterator o i elementów bliżej
      ///
      /// \param przesun - Przesunięcie
      void operator-=(int przesun); 
      /// \brief Przeładowany operator preinkrementacji
      ///
      /// \return Iterator pokazujący na i-ty element
      aghIterator<S>& operator++();
      /// \brief Przeładowany operator predekrementacji
      ///
      /// \return Iterator pokazujący na i-ty element
      aghIterator<S>& operator--();
      /// \brief Przeładowany operator postinkrementacji
      ///
      /// \return Iterator pokazujący na i+1 element
      aghIterator<S> operator++(int);
      /// \brief Przeładowany operator postdekrementacji
      ///
      /// \return Iterator pokazujący na i-1 element
      aghIterator<S> operator--(int);
      /// \brief Przeładowany operator==
      ///
      /// \param prawy - Iterator do porównania
      /// \return Wartość logiczna porówania
      bool operator==(const aghIterator<S>& prawy);
      /// \brief Przeładowany operator!=
      ///
      /// \param prawy - Iterator do porównania
      /// \return Wartość logiczna porówania
      bool operator!=(const aghIterator<S>& prawy);
      /// \brief Przeładowany operator= ustawiający pojemnik na który iterator pokazuje
      ///
      /// \param kontener - Pojemnik
      void operator=(aghContainer<S>* kontener);
};
template <class S>
aghIterator<S>::aghIterator(aghContainer<S>* _pojemnik)
{
   if (_pojemnik == NULL)
      throw aghException(0, "Wskaźnik na pojemnik pokazuje na NULL", __FILE__, __LINE__);
   pojemnik = _pojemnik;
   index = 0;
}
template <class S>
aghIterator<S> aghIterator<S>::first()
{
   aghIterator<S> nowy(pojemnik); 
   nowy.index = 0;
   return nowy;
}
template <class S>
aghIterator<S> aghIterator<S>::last()
{
   aghIterator<S> nowy(pojemnik); 
   nowy.index = pojemnik->size() - 1;
   return nowy;
}
template <class S>
aghIterator<S>& aghIterator<S>::next()
{
   index++;
   return *this;
}
template <class S>
aghIterator<S>& aghIterator<S>::prev()
{
   index--;
   return *this;
}
template <class S>
S& aghIterator<S>::current()
{   
   if ((index < 0) || (index > pojemnik->size() - 1))
      throw aghException(0, "Wyjście poza zakres pojemnika", __FILE__, __LINE__);
   return pojemnik->at(index);
}
template <class S>
aghIterator<S>& aghIterator<S>::atFirst()
{
   index = 0;
   return *this;
}
template <class S>
aghIterator<S>& aghIterator<S>::atLast()
{
   if (pojemnik->size() == 0)
      index = 0;
   else
      index = pojemnik->size() - 1;
   return *this;
}
template <class S>
int aghIterator<S>::size()
{
   return pojemnik->size() - index;
}
template <class S>
S aghIterator<S>::operator[](int pozycja)
{
   if ((index < 0) || (index > pojemnik->size() - 1))
      throw aghException(0, "Wyjście poza zakres pojemnika", __FILE__, __LINE__);
   return pojemnik->at(index + pozycja);
}
template <class S>
aghIterator<S>::operator int()
{
   if ((pojemnik != NULL) && (index < pojemnik->size() - 1) && (index >= 0))
      return 1;
   else
      return 0;
}
template <class S>
S& aghIterator<S>::operator*()
{   
   if ((index < 0) || (index > pojemnik->size() - 1))
      throw aghException(0, "Wyjście poza zakres pojemnika", __FILE__, __LINE__);
   return pojemnik->at(index);
}
template <class S>
aghIterator<S>& aghIterator<S>::operator=(const aghIterator<S>& model)
{
   pojemnik = model.pojemnik;
   index = model.index;
   return *this;
}
template <class S>
aghIterator<S> aghIterator<S>::operator+(int przesun)
{
   aghIterator<S> tymczasowy = *this;
   tymczasowy.index += przesun;
   return tymczasowy;
}
template <class S>
aghIterator<S> aghIterator<S>::operator-(int przesun)
{
   aghIterator<S> tymczasowy = *this;
   tymczasowy.index -= przesun;
   return tymczasowy;
}
template <class S>
void aghIterator<S>::operator+=(int przesun)
{
   index += przesun;
}
template <class S>
void aghIterator<S>::operator-=(int przesun)
{
   index -= przesun;
}
template <class S>
aghIterator<S>& aghIterator<S>::operator++()
{
   index++;
   return *this;
}
template <class S>
aghIterator<S>& aghIterator<S>::operator--()
{
   index--;
   return *this;
}
template <class S>
aghIterator<S> aghIterator<S>::operator++(int)
{
   aghIterator<S> stary = *this;
   ++*this;
   return stary;
}
template <class S>
aghIterator<S> aghIterator<S>::operator--(int)
{
   aghIterator<S> stary = *this;
   --*this;
   return stary;
}
template <class S>
bool aghIterator<S>::operator==(const aghIterator<S>& prawy)
{
   if ((this->pojemnik == prawy.pojemnik) && (this->index == prawy.index))
      return true;
   else 
      return false;
}
template <class S>
bool aghIterator<S>::operator!=(const aghIterator<S>& prawy)
{
   return !(*this == prawy);
}
template <class S>
void aghIterator<S>::operator=(aghContainer<S>* kontener)
{
   pojemnik = kontener;
   index = 0;
}

#endif
