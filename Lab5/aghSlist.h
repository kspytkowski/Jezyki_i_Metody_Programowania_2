/**
* \file aghSlist.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghSlist
*/

#ifndef AGHSLIST_H
#define AGHSLIST_H

#include "aghContainer.h"
#include "aghSWezel.h"
#include "aghException.h"

/**
* \class aghSlist
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 30.05.2013
* \brief Definicja klasy szablonowej aghSlist
*/
template <class W>
class aghSlist : public aghContainer<W>
{
   private:
      int ilosc; ///< Ilosc obiektow
      aghSWezel<W>* glowa; ///< Wskażnik na głowę listy
      aghSWezel<W>* ogon; ///< Wskażnik na ogon listy
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghSlist(void);
      /// \brief Konstruktor kopiujący klasy
      ///
      /// \param model - Model pojemnika
      aghSlist(const aghSlist<W>& model);
      /// \brief Konstruktor kopiujący klasy (przyjmujący stałą referencje do klasy bazowej)
      ///
      /// \param model - Model pojemnika
      aghSlist(const aghContainer<W>& model);
      /// \brief Destruktor klasy
      ~aghSlist(void);
      /// \brief Przeładowany operator=
      ///
      /// \param model - Model pojemnika
      /// \return Referencja do this
      aghSlist<W>& operator=(const aghSlist<W>& model);
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
aghSlist<W>::aghSlist(void) : aghContainer<W>()
{
   ilosc = 0;
   glowa = NULL;
   ogon = NULL;
}
template<class W>
aghSlist<W>::aghSlist(const aghSlist<W>& model) : aghContainer<W>()
{ 
   /* Stara wersja konstruktora kopiujacego:*/
   /* ilosc = model.ilosc;
   aghSWezel<W>* goniec = model.glowa;
   if (model.glowa != NULL)
   {
      glowa = new aghSWezel<W>;
      aghSWezel<W>* goniec2 = glowa;
      while (goniec != NULL)
      {
         goniec2->wartosc = goniec->wartosc;
         if (goniec->nastepny != NULL)
         {
            goniec2->nastepny = new aghSWezel<W>;
            goniec2 = goniec2->nastepny;
         }
         else
            goniec2->nastepny = NULL;
         goniec = goniec->nastepny;
      }
   }
   else
      glowa = NULL;*/
   glowa = NULL;
   ilosc = 0;
   for (int i = 0; i < model.size(); i++)
      insert(i, model.at(i));
} 
template<class W>
aghSlist<W>::aghSlist(const aghContainer<W>& model): aghContainer<W>()
{ 
   /* Stara wersja konstruktora kopiujacego:*/
   /* ilosc = (dynamic_cast<const aghSlist<W>&>(model)).ilosc;
   aghSWezel<W>* goniec = (dynamic_cast<const aghSlist<W>&>(model)).glowa;
   if ((dynamic_cast<const aghSlist<W>&>(model)).glowa != NULL)
   {
      glowa = new aghSWezel<W>;
      aghSWezel<W>* goniec2 = glowa;
      while (goniec != NULL)
      {
         goniec2->wartosc = goniec->wartosc;
         if (goniec->nastepny != NULL)
         {
            goniec2->nastepny = new aghSWezel<W>;
            goniec2 = goniec2->nastepny;
         }
         else
           goniec2->nastepny = NULL;
         goniec = goniec->nastepny;
      }
   }
   else
      glowa = NULL;*/
   glowa = NULL;
   ilosc = 0;
   for (int i = 0; i < model.size(); i++)
      insert(i, model.at(i));
} 
template<class W>
aghSlist<W>::~aghSlist(void)
{
   aghSWezel<W>* goniec;
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
aghSlist<W>& aghSlist<W>::operator=(const aghSlist<W>& model)
{
   (*this).aghContainer<W>::operator=(model); 
   return *this;
}
template<class W>
bool aghSlist<W>::insert(int index, W const& element)
{
   if ((index < 0) || (index > size()))
      return false;
   aghSWezel<W>* nowy = new aghSWezel<W>();   
   if (nowy == NULL)
      throw aghException(0, "Nie udało sie przydzielić wystarczającej ilości pamięci", __FILE__, __LINE__);
   nowy->wartosc = element;
   if (index != 0) 
   {
      aghSWezel<W>* goniec;
      for (goniec = glowa; index > 1; index--)
         goniec = goniec->nastepny;
      nowy->nastepny = goniec->nastepny;
      goniec->nastepny = nowy;   
      if (goniec == ogon)
         ogon = nowy;
   }
   else
   {
      nowy->nastepny = glowa;
      glowa = nowy;
      if (!ogon) ogon = glowa;
   }
   ilosc++;
   return true;
}
template<class W>
W& aghSlist<W>::at(int index) const
{
   if (index < 0 || index > size() - 1)
      throw aghException(0, "Niepoprawny index odwolania do elemntu", __FILE__, __LINE__);
   aghSWezel<W>* goniec;
   goniec = glowa;
   while(index > 0)
   {
      goniec = goniec->nastepny;
      index--;
   }
   return goniec->wartosc;
}
template<class W>
int aghSlist<W>::size(void) const
{
   return ilosc;
}
template<class W>
bool aghSlist<W>::remove(int index)
{
   if ((index < 0) || (index > size() - 1))
      return false;
   aghSWezel<W>* goniec;
   if (index == 0) 
   {
      if (glowa != NULL)
      {
         goniec = glowa;
         glowa = glowa->nastepny;
         if (glowa == NULL) 
            ogon = NULL;
         delete goniec;
      }
   }
   else
   {
      aghSWezel<W>* goniec2;
      for (goniec = glowa; index > 1; index--)
         goniec = goniec->nastepny;   
      goniec2 = goniec;
      goniec = goniec->nastepny;
      goniec2->nastepny = goniec->nastepny;
      if (goniec2->nastepny == NULL) 
         ogon = goniec2;
      delete goniec;   
   }
   ilosc--;
   return true;
}

#endif
