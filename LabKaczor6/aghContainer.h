/**
* \file aghContainer.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 24.05.2013
* \version 1.0
* \brief Plik zawiera definicje abstrakcyjnej klasy szablonowej aghContainer
*/

#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H

#include <iostream> 
#include "aghException.h"

using namespace std;

/**
* \class aghContainer
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 24.05.2013
* \brief Definicja abstrakcyjnej klasy szablonowej aghContainer
*/
template <class T>
class aghContainer
{
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghContainer(void);
      /// \brief Konstruktor kopiujący klasy
      ///
      /// \param model - Model pojemnika
      aghContainer(const aghContainer<T>& model);
      /// \brief Wirtualny destruktor klasy
      virtual ~aghContainer(void);
      /// \brief Funkcja dodająca element do pojemnika
      ///
      /// \param element - Nowy element
      /// \return Brak wartości zwracanej
      void append(T const& element);
      /// \brief Czystko wirtualna funkcja wstawiająca element do pojemnika
      ///
      /// \param index - Index miejsca, gdzie należy wstawić element
      /// \param element - Nowy element
      /// \return Wrtość logiczna będącą miarą powodzenia operacji
      virtual bool insert(int index, T const& element) = 0;
      /// \brief Funkcja podmieniajaca element w pojemniku
      ///
      /// \param index - Index elementu do podmiany
      /// \param element - Element do podmiany
      /// \return Wrtość logiczna będącą miarą powodzenia operacji
      bool replace(int index, T const& element);
      /// \brief Czystko wirtualna funkcja zwracająca wartość danego elementu w pojemniku
      ///
      /// \param index - Index poszukiwanego elementu pojemnika
      /// \return Poszukiwana wartość
      virtual T& at(int index) const = 0;
      /// \brief Czystko wirtualna funkcja zwracająca ilosc elementow w pojemniku
      ///
      /// \return Ilosc elementow w pojemniku
      virtual int size(void) const = 0;
      /// \brief Czystko wirtualna funkcja usuwająca element z pojemnika
      ///
      /// \param index - Index elementu do usunięcia
      /// \return Wrtość logiczna będącą miarą powodzenia operacji
      virtual bool remove(int index) = 0;
      /// \brief Funkcja usuwająca wszystkie elementy z pojemnika
      ///
      /// \return Brak wartości zwracanej
      void clear(void);
      /// \brief Funkcja sprawdzająca czy pojemnik jest pusty
      ///
      /// \return Wrtość logiczna będąca wynikiem operacji
      bool isEmpty(void);
      /// \brief Funkcja wyszukująca element w pojemniku przez wartość od zadanego momentu
      ///
      /// \param _value - Zadana wartość
      /// \param _from - Index elementu od którego rozpoczyna sie przeszukiwanie
      /// \return Indeks pierwszego elementu o wartości _value. Jeżeli takiego elementu nie ma to zwraca -1
      int indexOf(T const& _value, int _from = 0) const;
      /// \brief Funkcja sprawdzająca czy dany element jest już w pojemnik
      ///
      /// \param _value - Zadana wartość
      /// \param _from - Index elementu od którego rozpoczyna sie przeszukiwanie
      /// \return Wartośc logiczna sprawdzenia
      bool contains(T const& _value, int _from = 0) const;
      /// \brief Przeładowany operator=
      ///
      /// \param model - Model pojemnika
      /// \return Referencja do this
      aghContainer<T>& operator=(const aghContainer<T>& model);
      /// \brief Przeładowany operator== porównujący dwa pojemniki
      ///
      /// \param right - Pojemnik do porównania
      /// \return Wartość logiczna porównania
      bool operator==(aghContainer<T> const& right);
      /// \brief Przeładowany operator!= porównujący dwa pojemniki
      ///
      /// \param right - Pojemnik do porównania
      /// \return Wartość logiczna porównania
      bool operator!=(aghContainer<T> const& right);      
      /// \brief Przeładowany operator[]
      ///
      /// \param n - Index elementu
      /// \return N-ty element w pojemniku
      T& operator[](int n) const;
      /// \brief Przeładowany operator+= dopisujący wszystkie elementy z pojemnika right
      ///
      /// \param right - Pojemnik, z którego pochodzą elementu do dopisania
      /// \return Referencja do this
      aghContainer<T>& operator+=(aghContainer<T> const& right);
      /// \brief Przeładowany operator+= dodający element do pojemnika
      ///
      /// \param element - Element do dopisania
      /// \return Referencja do this      
      aghContainer<T>& operator+=(T const& element);
      /// \brief Przeładowany operator<< dodający element do pojemnika
      ///
      /// \param element - Element do dopisania
      /// \return Referencja do this
      aghContainer<T>& operator<<(T const& element);
      /// \brief Przeładowany operator<< dopisujący wszystkie elementy z pojemnika right
      ///
      /// \param right - Pojemnik, z którego pochodzą elementu do dopisania
      /// \return Referencja do this
      aghContainer<T>& operator<<(aghContainer<T> const& right);
      /// \brief Przeładowany operator<< wypisujący zawartość pojemnika na strumień
      ///
      /// \param strumien - Strumien, na który nleży wypisać zawartośc pojemnika
      /// \param right - Pojemnik, z którego pochodzą elementy do wypisania
      /// \return Referencja do strumienia
      template <class T1>
      friend ostream& operator<<(ostream& strumien, aghContainer<T1> const& right);
};
template <class T>
aghContainer<T>::aghContainer(void){}
template <class T>
aghContainer<T>::aghContainer(const aghContainer<T>& model){}
template <class T>
aghContainer<T>::~aghContainer(void){}
template <class T>
void aghContainer<T>::append(T const& element)
{
   insert(size(), element);
}
template <class T>
bool aghContainer<T>::replace(int index, T const& element)
{
   if ((index < 0) || (index > size())) 
      return false;
   else
   {
      remove(index);
      insert(index, element);
   }
   return true;
}
template <class T>
void aghContainer<T>::clear(void)
{
   while (isEmpty() != true)
      remove(0);
}
template <class T>
bool aghContainer<T>::isEmpty(void)
{
   return (size() == 0);
}
template <class T>
int aghContainer<T>::indexOf(T const& _value, int _from) const
{
   if ((_from < 0) || (_from > size() - 1))
      throw aghException(0, "Błędna wartość poczatku poszukiwań zadanego elementu w pojemniku", __FILE__, __LINE__);
   while((_from < size()) && (_value != at(_from))) 
      _from++;
   if (_from != size()) 
      return _from;
   else
      return -1;
}
template <class T>
bool aghContainer<T>::contains(T const& _value, int _from) const
{
   if ((_from < 0) || (_from > size() - 1))
      throw aghException(0, "Błędna wartość poczatku poszukiwań zadanego elementu w pojemniku", __FILE__, __LINE__);
   while((_from < size()) && (_value != at(_from))) 
      _from++;
   return (_from != size());       
}
template <class T>
aghContainer<T>& aghContainer<T>::operator=(const aghContainer<T>& model)
{
   if (this == &model)
      return *this;
   while (isEmpty() != true)
      remove(0);  
   for(int i = 0; i < model.size(); i++)
      append(model.at(i));
   return *this;
}
template <class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{
   if (size() != right.size())
      return false;
   for (int i = 0; i < size(); i++)
      if (at(i) != right.at(i))
         return false;
   return true;
}
template <class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
   return !(*this == right);
}
template <class T>
T& aghContainer<T>::operator[](int n) const
{
   if ((n < 0) || (n > size() - 1))
      throw aghException(0, "Podany index jest poza rozmiarem pojemnika", __FILE__, __LINE__);
   return at(n);
}
template <class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{
   for (int i = 0; i < right.size(); i++)
      append(right.at(i));
   return *this;
} 
template <class T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element)
{
   append(element);
   return *this;
}
template <class T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element)
{
   append(element);
   return *this;
}
template <class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right)
{
   for (int i = 0; i < right.size(); i++)
      append(right.at(i));
   return *this;
}
template <class T1>
ostream& operator<<(ostream& strumien, aghContainer<T1> const& right)
{
   for (int i = 0; i < right.size(); i++)
      strumien << right.at(i);
   return strumien; 
}

#endif
