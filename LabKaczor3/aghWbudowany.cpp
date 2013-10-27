#include <iostream>
#include <cstdlib>
#include "aghWbudowany.h"

using namespace std;

aghWbudowany::aghWbudowany()
{
   nazwaGenerator = "Generator wbudowany - srand(): ";
}
aghWbudowany::aghWbudowany(int _poczatekZakres, int _koniecZakres, int _ziarno) : aghGenerator(_poczatekZakres, _koniecZakres, _ziarno)
{
   nazwaGenerator = "Generator wbudowany - srand(): ";
   ziarno = _ziarno;
   srand(_ziarno);
}
void aghWbudowany::ustawZiarno(int _ziarno)
{
   ziarno = _ziarno;
   srand(_ziarno);
}
int aghWbudowany::losujLiczbe()
{
   return poczatekZakres + rand() % koniecZakres;
}
