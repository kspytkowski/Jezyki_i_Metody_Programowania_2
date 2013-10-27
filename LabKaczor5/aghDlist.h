/**
* \file aghDlist.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghDlist
*/

#ifndef AGHDLIST_H
#define AGHDLIST_H

#include "aghContainer.h"
#include "aghDWezel.h"
#include "aghException.h"

/**
* \class aghDlist
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \brief Definicja klasy szablonowej aghDlist
*/
template <class W>
class aghDlist : public aghContainer<W>
{
   private:
      int ilosc; ///< Ilosc obiektow
      aghDWezel<W>* glowa; ///< Wskażnik na głowę listy
      aghDWezel<W>* ogon; ///< Wskażnik na ogon listy
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghDlist(void);
      /// \brief Konstruktor kopiujący klasy
      ///
      /// \param model - Model pojemnika
      aghDlist(const aghDlist<W>& model);
      /// \brief Konstruktor kopiujący klasy (przyjmujący stałą referencje do klasy bazowej)
      ///
      /// \param model - Model pojemnika
      aghDlist(const aghContainer<W>& model);
      /// \brief Destruktor klasy
      ~aghDlist(void);
      /// \brief Przeładowany operator=
      ///
      /// \param model - Model pojemnika
      /// \return Referencja do this
      aghDlist<W>& operator=(const aghDlist<W>& model);
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
aghDlist<W>::aghDlist(void) : aghContainer<W>()
{
   ilosc = 0;
   glowa = NULL;
   ogon = NULL;
}
template<class W>
aghDlist<W>::aghDlist(const aghDlist<W>& model) : aghContainer<W>()
{ 
   /* Stara wersja konstruktora kopiujacego:*/
   /* ilosc = model.ilosc;
   aghDWezel<W>* goniec = model.glowa;
   if (model.glowa != NULL)
   {
      glowa = new aghDWezel<W>;
      aghDWezel<W>* goniec2 = glowa;
      while (goniec != NULL)
      {
         goniec2->wartosc = goniec->wartosc;
         if (goniec->nastepny != NULL)
         {
            goniec2->nastepny = new aghDWezel<W>;
            goniec2->nastepny->poprzedni = goniec2;
            goniec2 = goniec2->nastepny;
         }
         else
            goniec2->nastepny = NULL;
         ogon = goniec2;
         goniec = goniec->nastepny;
      }
   }
   else
   {
      glowa = NULL;
      ogon = NULL;
   }*/
   glowa = NULL;
   ogon = NULL;
   ilosc = 0;
   for (int i = 0; i < model.size(); i++)
      insert(i, model.at(i));
} 
template<class W>
aghDlist<W>::aghDlist(const aghContainer<W>& model): aghContainer<W>()
{ 
   /* Stara wersja konstruktora kopiujacego:*/
   /*ilosc = (dynamic_cast<const aghDlist<W>&>(model)).ilosc;
   aghDWezel<W>* goniec = (dynamic_cast<const aghDlist<W>&>(model)).glowa;
   if ((dynamic_cast<const aghDlist<W>&>(model)).glowa != NULL)
   {
      glowa = new aghDWezel<W>;
      aghDWezel<W>* goniec2 = glowa;
      while (goniec != NULL)
      {
         goniec2->wartosc = goniec->wartosc;
         if (goniec->nastepny != NULL)
         {
            goniec2->nastepny = new aghDWezel<W>;
            goniec2->nastepny->poprzedni = goniec2;
            goniec2 = goniec2->nastepny;
         }
         else
           goniec2->nastepny = NULL;
         ogon = goniec2;
         goniec = goniec->nastepny;
      }
   }
   else
   {
      glowa = NULL;
      ogon = NULL;
   }*/
   glowa = NULL;
   ogon = NULL;
   ilosc = 0;
   for (int i = 0; i < model.size(); i++)
      insert(i, model.at(i));
} 
template<class W>
aghDlist<W>::~aghDlist(void)
{
   aghDWezel<W>* goniec;
   while(glowa != NULL)
   {
      goniec = glowa->nastepny;      
      delete glowa;
      glowa = goniec;
   }
   ogon = NULL;
   ilosc = 0; 
}
template<class W>
aghDlist<W>& aghDlist<W>::operator=(const aghDlist<W>& model)
{
   (*this).aghContainer<W>::operator=(model); 
   return *this;
}
template<class W>
bool aghDlist<W>::insert(int index, W const& element)
{
   if ((index < 0) || (index > size()))
      return false;
   aghDWezel<W>* nowy = new aghDWezel<W>();   
   if (nowy == NULL)
      throw aghException(0, "Nie udało sie przydzielić wystarczającej ilości pamięci", __FILE__, __LINE__);
   nowy->wartosc = element;
   if (index != 0) 
   {
      aghDWezel<W>* goniec;
      for (goniec = glowa; index > 1; index--)
         goniec = goniec->nastepny;
      nowy->nastepny = goniec->nastepny;
      nowy->poprzedni = goniec;
      goniec->nastepny = nowy;   
      if (nowy->nastepny != NULL) 
         nowy->nastepny->poprzedni = nowy;
      else 
         ogon = nowy;
   }
   else
   {
      nowy->nastepny = glowa;
      nowy->poprzedni = NULL;
      if (glowa != NULL) 
         glowa->poprzedni = nowy;
      glowa = nowy;
      if (ogon == NULL) 
         ogon = glowa;
   }
   ilosc++;
   return true;
}
template<class W>
W& aghDlist<W>::at(int index) const
{
   if (index < 0 || index > size() - 1)
      throw aghException(0, "Niepoprawny index odwolania do elemntu", __FILE__, __LINE__);
   aghDWezel<W>* goniec;
   goniec = glowa;
   while(index > 0)
   {
      goniec = goniec->nastepny;
      index--;
   }
   return goniec->wartosc;
}
template<class W>
int aghDlist<W>::size(void) const
{
   return ilosc;
}
template<class W>
bool aghDlist<W>::remove(int index)
{
   if ((index < 0) || (index > size() - 1))
      return false;
   aghDWezel<W>* goniec;
   for (goniec = glowa; index > 0; index--)
         goniec = goniec->nastepny;
   if (goniec->poprzedni != NULL) 
      goniec->poprzedni->nastepny = goniec->nastepny;
   else glowa = goniec->nastepny;
   if (goniec->nastepny != NULL) 
      goniec->nastepny->poprzedni = goniec->poprzedni;
   else ogon = goniec->poprzedni;
   delete goniec;
   ilosc--;
   return true;
}

#endif
