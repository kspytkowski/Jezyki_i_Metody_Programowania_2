#include <iostream>
#include "aghBlumBlumShub.h"

using namespace std;

bool aghBlumBlumShub::czyJestPierwsza(int liczba)
{
   if (liczba < 2) return false;
   bool rezultat = true;
   for(int i = 2;i <= sqrt(liczba); i++)
   {		
	   if(liczba % i == 0)
      {
         rezultat = false; 
         break;
      }
   }	
   return rezultat;
}
aghBlumBlumShub::aghBlumBlumShub()
{
   nazwaGenerator = "Generator BlumBlumShub: ";
}
aghBlumBlumShub::aghBlumBlumShub(int _poczatekZakres, int _koniecZakres, int _ziarno, int _pierwszaP, int _pierwszaQ) : aghGenerator(_poczatekZakres, _koniecZakres, _ziarno)
{
   nazwaGenerator = "Generator BlumBlumShub: ";
   if ((czyJestPierwsza(_pierwszaQ) == false) || (czyJestPierwsza(_pierwszaP) == false))
      throw aghException(0, "Błędnie podana liczba pierwsza", __FILE__, __LINE__);
   pierwszaP = _pierwszaP;
   pierwszaQ = _pierwszaQ;
   poprzednik = ziarno; 
}      
void aghBlumBlumShub::ustawZiarno(int _ziarno)
{ 
   ziarno = poprzednik = _ziarno;
}
void aghBlumBlumShub::ustawPierwszaP(int _pierwszaP)
{ 
   if (czyJestPierwsza(_pierwszaP) == false)
      throw aghException(0, "Błędnie podana liczba pierwsza", __FILE__, __LINE__);
   pierwszaP = _pierwszaP;
}
void aghBlumBlumShub::ustawPierwszaQ(int _pierwszaQ)
{ 
   if (czyJestPierwsza(_pierwszaQ) == false)
      throw aghException(0, "Błędnie podana liczba pierwsza", __FILE__, __LINE__);
   pierwszaQ = _pierwszaQ;
}
int aghBlumBlumShub::losujLiczbe()
{
   poprzednik = (poprzednik * poprzednik) % (pierwszaP * pierwszaQ);
   return poczatekZakres + poprzednik % koniecZakres;
}
