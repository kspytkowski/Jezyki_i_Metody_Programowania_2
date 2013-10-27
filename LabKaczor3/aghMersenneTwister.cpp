#include <iostream>
#include "aghMersenneTwister.h"

using namespace std;

void aghMersenneTwister::generujLiczby()
{
   int y;
   for (int i = 0; i < 624; i++)
   {
      y = (0x80000000 & (MT[i] + (0x7FFFFFFF & (MT[i + 1] % 624))));
      MT[i] = MT[(i + 397) % 624] ^ (y >> 1);
      if ((y % 2) == 1)
         MT[i] = MT[i] ^ 0x9908b0df;
   }
}
aghMersenneTwister::aghMersenneTwister()
{
   nazwaGenerator = "Generator Mersenne Twister: ";
   index = 0;
}
aghMersenneTwister::aghMersenneTwister(int _poczatekZakres, int _koniecZakres, int _ziarno) : aghGenerator(_poczatekZakres, _koniecZakres, _ziarno)
{
   nazwaGenerator = "Generator Mersenne Twister: ";
   index = 0; 
   MT[0] = _ziarno;
   for (int i = 0; i < 624; i++)
       MT[i] = 0x6c078965 * (MT[i - 1] ^ MT[i - 1] >> 30) + i;   
}
void aghMersenneTwister::ustawZiarno(int _ziarno)
{
   ziarno = _ziarno;
   MT[0] = _ziarno;
   for (int i = 0; i < 624; i++)
       MT[i] = 0x6c078965 * (MT[i - 1] ^ MT[i - 1] >> 30) + i;   
}
int aghMersenneTwister::losujLiczbe()
{
   if (index == 0) 
      generujLiczby();
   int y = MT[index];
   y ^= y >> 11;
   y ^= y << 7 & 0x9d2c5680;
   y ^= y << 15 & 0xefc60000;
   y ^= y >> 18;  
   index = (index + 1) % 624;
   return poczatekZakres + y % koniecZakres; 
}
