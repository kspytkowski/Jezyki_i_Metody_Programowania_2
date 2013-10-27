#ifndef AGHSLIST_H
#define AGHSLIST_H

#include "aghContainer.h"
#include "aghException.h"

template <class W>
class aghSlist : public aghContainer<W>
{
   public://private:
      int amount; // ilosc wartoscow
      struct wezel
      {
         W wartosc;
         wezel* nastepny;
         wezel() : wartosc(W()), nastepny(NULL){}
      };
      struct wezel* glowa;
      struct wezel* ogon;
   public:
      aghSlist();//
      ~aghSlist();//
      aghSlist(const aghSlist<W>& model);//
      aghSlist(const aghContainer<W>& model);//
      aghSlist<W>& operator=(const aghSlist<W>& model);
      aghSlist<W>& operator=(const aghContainer<W>& model);
      virtual bool insert(int, W const&);
      virtual W& at(int) const;
      virtual int size(void) const;
      virtual bool remove(int);
};
template<class W>
bool aghSlist<W>::insert(int index, W const& element)
{
   if (index < 0)
      throw aghException(0, "Pozycja do wstawienia elementu do listy nie może być mniejsza od 0", __FILE__, __LINE__);
   if (index > size())
      throw aghException(0, "Pozycja do wstawienia elementu do listy nie może być wieksza od pozycji ostatniego elementu w liscie", __FILE__, __LINE__);
   struct wezel* lol = new struct wezel();
   lol->wartosc = element;

   if (index != 0) 
   {
      struct wezel* goniec;
      for (goniec = glowa; index > 1; index--)
         goniec = goniec->nastepny;
      lol->nastepny = goniec->nastepny;
      goniec->nastepny = lol;   
      if (goniec == ogon)
         ogon = lol;
   }
   else
   {
      lol->nastepny = glowa;
      glowa = lol;
      if (!ogon) ogon = glowa;
   }
   amount++;
}
template<class W>
W& aghSlist<W>::at(int index) const
{
   if (index < 0 || index > amount)
      throw aghException(0, "Niepoprawny index odwolania do elemntu", __FILE__, __LINE__);
   struct wezel* zlo;
   zlo = glowa;
   while(index > 0)
{
   zlo = zlo->nastepny;
index--;
}
   return zlo->wartosc;
}
template<class W>
int aghSlist<W>::size(void) const
{
   return amount;
}
template<class W>
bool aghSlist<W>::remove(int index)
{
//jezeli pusta lista to wyjatek!
// znow wyjatki jak nie mozna usuwac czegos poza zakresem
struct wezel* goniec;

if (index == 0) 
{
   if (glowa != NULL)
   {
      goniec = glowa;
      glowa = glowa->nastepny;
      if (glowa == NULL) ogon = NULL;
      delete goniec;
   }
}
else
{
   struct wezel* goniec2;
   for (goniec = glowa; index > 1; index--)
         goniec = goniec->nastepny;   
         goniec2 = goniec;
         goniec = goniec->nastepny;
         goniec2->nastepny = goniec->nastepny;
      if (goniec2->nastepny == NULL) ogon = goniec2;
      delete goniec;

   
}
amount--;
/*  if (index == 0)
 {
      delete glowa;
      glowa = ogon = NULL;
cout << 2;
amount--;
 }
else
{
cout << 1;
   struct wezel* zlo;
   struct wezel* zlo2;
   zlo = glowa;
   zlo2 = glowa;
   while(index > 1)
   {
      zlo = zlo->nastepny;
      index--;
   }
   zlo2= zlo->nastepny;
   zlo->nastepny=zlo2->nastepny;
   delete zlo2;
amount--;
}*/
}
template<class W>
aghSlist<W>::aghSlist()
{
   amount = 0;
   glowa = NULL;
   ogon = NULL;
}
template<class W>
aghSlist<W>::~aghSlist()
{
   wezel* pomocnik;
   while(glowa != NULL)
   {
      pomocnik = glowa->nastepny;      
      delete glowa;
      glowa = pomocnik;
   }
   amount = 0; 
}
template<class W>
aghSlist<W>::aghSlist(const aghSlist<W>& model)// : aghContainer<W>()
{ 
   amount = model.amount;

  wezel* actual = model.glowa;
  if (model.glowa != NULL)
  {
    glowa = new wezel;
    wezel* actual2 = glowa;
    while (actual != NULL)
    {
      actual2->wartosc = actual->wartosc;
      if (actual->nastepny != NULL)
      {
        actual2->nastepny = new wezel;
        actual2 = actual2->nastepny;
      }
      else
        actual2->nastepny = NULL;
      actual = actual->nastepny;
    }
  }
  else
    glowa = NULL;
} 
   


template<class W>
aghSlist<W>::aghSlist(const aghContainer<W>& model)
{ 
   amount = ((aghSlist&)model).amount;

  wezel* actual = ((aghSlist&)model).glowa;
  if (((aghSlist&)model).glowa != NULL)
  {
    glowa = new wezel;
    wezel* actual2 = glowa;
    while (actual != NULL)
    {
      actual2->wartosc = actual->wartosc;
      if (actual->nastepny != NULL)
      {
        actual2->nastepny = new wezel;
        actual2 = actual2->nastepny;
      }
      else
        actual2->nastepny = NULL;
      actual = actual->nastepny;
    }
  }
  else
    glowa = NULL;
} 
template<class W>
aghSlist<W>& aghSlist<W>::operator=(const aghSlist<W>& model)
{
   if (this == &model)
      return *this;
   wezel* pomocnik;
   while(glowa != NULL)
   {
      pomocnik = glowa->nastepny;      
      delete glowa;
      glowa = pomocnik;
   }
   amount = 0; 

   amount = model.amount;

  wezel* actual = model.glowa;
  if (model.glowa != NULL)
  {
    glowa = new wezel;
    wezel* actual2 = glowa;
    while (actual != NULL)
    {
      actual2->wartosc = actual->wartosc;
      if (actual->nastepny != NULL)
      {
        actual2->nastepny = new wezel;
        actual2 = actual2->nastepny;
      }
      else
        actual2->nastepny = NULL;
      actual = actual->nastepny;
    }
  }
  else
    glowa = NULL;
   return *this;
}
template<class W>
aghSlist<W>& aghSlist<W>::operator=(const aghContainer<W>& model)
{
   if (this == &((aghSlist&)model))
      return *((aghSlist*)this);
   wezel* pomocnik;
   while(glowa != NULL)
   {
      pomocnik = glowa->nastepny;      
      delete glowa;
      glowa = pomocnik;
   }
   amount = 0; 

   amount = ((aghSlist&)model).amount;

  wezel* actual = ((aghSlist&)model).glowa;
  if (((aghSlist&)model).glowa != NULL)
  {
    glowa = new wezel;
    wezel* actual2 = glowa;
    while (actual != NULL)
    {
      actual2->wartosc = actual->wartosc;
      if (actual->nastepny != NULL)
      {
        actual2->nastepny = new wezel;
        actual2 = actual2->nastepny;
      }
      else
        actual2->nastepny = NULL;
      actual = actual->nastepny;
    }
  }
  else
    glowa = NULL;
   return *((aghSlist*)this);
}

#endif
