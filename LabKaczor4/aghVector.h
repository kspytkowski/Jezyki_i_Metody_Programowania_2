/**
* \file aghVector.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 24.05.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghVector
*/

#ifndef AGHVECTOR_H
#define AGHVECTOR_H

#include "aghContainer.h"
#include "aghException.h"

/**
* \class aghVector
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 24.05.2013
* \brief Definicja abstrakcyjnej klasy aghVector
*/
template <class W>
class aghVector : public aghContainer<W>
{
   private:
      int amount; ///< Ilosc obiektow
      int space; ///< Atualna ilość miejsca dostępnego w tablicy
      W* table; ///< Tablica
      /// \brief Funkcja rozszerzająca tablice
      ///
      /// \param newSize - Nowy rozmiar tablicy
      /// \return Brak wartosći zwracanej
      void increaseSize(int newSize);      
      /// \brief Funkcja zmniejszająca tablice
      ///
      /// \param newSize - Nowy rozmiar tablicy
      /// \return Brak wartosći zwracanej
      void reduceSize(int newSize);
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghVector(void);
      /// \brief Konstruktor kopiujący klasy
      ///
      /// \param model - Model pojemnika
      aghVector(const aghVector<W>& model);
      /// \brief Konstruktor kopiujący klasy (przyjmujący stałą referencje do klasy bazowej)
      ///
      /// \param model - Model pojemnika
      aghVector(const aghContainer<W>& model);
      /// \brief Destruktor klasy
      ~aghVector(void);
      /// \brief Przeładowany operator=
      ///
      /// \param model - Model pojemnika
      /// \return Referencja do this
      aghVector<W>& operator=(const aghVector<W>& model);
      /// \brief Czystko wirtualna funkcja wstawiająca element do pojemnika
      ///
      /// \param index - Index miejsca, gdzie należy wstawić element
      /// \param element - Nowy element
      /// \return Wrtość logiczna będącą miarą powodzenia operacji
      virtual bool insert(int index, W const& element);
      /// \brief Czystko wirtualna funkcja zwracająca wartość danego elementu w pojemniku
      ///
      /// \param index - Index poszukiwanego elementu pojemnika
      /// \return Poszukiwana wartość
      virtual W& at(int index) const;
      /// \brief Czystko wirtualna funkcja zwracająca ilosc elementow w pojemniku
      ///
      /// \return Ilosc elementow w pojemniku
      virtual int size(void) const;
      /// \brief Czystko wirtualna funkcja usuwająca element z pojemnika
      ///
      /// \param index - Index elementu do usunięcia
      /// \return Wrtość logiczna będącą miarą powodzenia operacji
      virtual bool remove(int index);
};
template<class W>
void aghVector<W>::increaseSize(int newSize)
{
   W* bufor = new W[newSize];
   if (bufor == NULL)
      throw aghException(0, "Nie udało sie przydzielić wystarczającej ilości pamięci", __FILE__, __LINE__);
   for (int i = 0; i < size(); i++)
      bufor[i] = table[i];
   delete [] table;
   table = bufor;
   space = newSize;
}
template<class W>
void aghVector<W>::reduceSize(int newSize)
{
   W* bufor = new W[newSize];
   if (bufor == NULL)
      throw aghException(0, "Nie udało sie przydzielić wystarczającej ilości pamięci", __FILE__, __LINE__);
   for (int i = 0; i < newSize; i++)
      bufor[i] = table[i];
   delete [] table;
   table = bufor;
   space = newSize;
}
template<class W>
aghVector<W>::aghVector() : aghContainer<W>()
{
   amount = 0;
   space = 0;
   table = NULL;
}
template<class W>
aghVector<W>::aghVector(const aghVector<W>& model) : aghContainer<W>(model)
{
   table = new W[model.space];
   if (table == NULL)
      throw aghException(0, "Nie udało sie przydzielić wystarczającej ilości pamięci", __FILE__, __LINE__);
   for (int i = 0; i < model.size(); i++)
      table[i] = model.table[i];
   amount = model.amount;
   space = model.space; 
}
template<class W>
aghVector<W>::aghVector(const aghContainer<W>& model) : aghContainer<W>(model)
{
   table = new W[(dynamic_cast<const aghVector<W>&>(model)).space];
   if (table == NULL)
      throw aghException(0, "Nie udało sie przydzielić wystarczającej ilości pamięci", __FILE__, __LINE__);
   for (int i = 0; i < (dynamic_cast<const aghVector<W>&>(model)).size(); i++)
      table[i] = (dynamic_cast<const aghVector<W>&>(model)).table[i];
   amount = (dynamic_cast<const aghVector<W>&>(model)).amount;
   space = (dynamic_cast<const aghVector<W>&>(model)).space; 
}
template<class W>
aghVector<W>::~aghVector()
{ 
   amount = 0; 
   space = 0;
   delete [] table;   
}
template<class W>
aghVector<W>& aghVector<W>::operator=(const aghVector<W>& model)
{
   (*this).aghContainer<W>::operator=(model); 
   return *this;
}
template<class W>
bool aghVector<W>::insert(int index, W const& element)
{
   if (index < 0 || index > size())
      return false;
   if (space == size())
      increaseSize(2 * size() + 1);
   for (int i = size(); i > index; i--)
      table[i] = table[i-1];
   table[index] = element;
   amount++;
   return true;
}
template<class W>
W& aghVector<W>::at(int index) const
{
   if ((index < 0) || (index > size() - 1)) 
      throw aghException(0, "Podany index jest poza rozmiarem tablicy", __FILE__, __LINE__);
   return table[index];
}
template<class W>
int aghVector<W>::size(void) const
{
   return amount;
}
template<class W>
bool aghVector<W>::remove(int index)
{
   if ((index < 0) || (index > size() - 1))
      return false;
   for (int i = index; i < size() - 1; i++)
      table[i] = table[i+1];
   amount--;
   if (space > 2 * size())
      reduceSize(size());
   return true;
}

#endif
