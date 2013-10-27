#include "aghGenerator.h"
#include "aghWbudowany.h"
#include "aghBlumBlumShub.h" 
#include "aghMersenneTwister.h"
#include "aghTest.h"
#include "aghSrednia.h"
#include "aghPi.h"
#include "aghChiKwadrat.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   aghGenerator* generator[3] = {new aghWbudowany(), new aghBlumBlumShub(), new aghMersenneTwister()};
   aghTest* test[3] = {new aghSrednia(), new aghPi(), new aghChiKwadrat()};
   ofstream plik("TestyGeneratorow.txt");

   try
   {
      for(int i = 0; i < 3; i++)
      {
         generator[i]->wypiszNazwe(plik);
         generator[i]->ustawPoczatek(0);
         generator[i]->ustawKoniec(1000);
         generator[i]->ustawZiarno(25);
         if (i == 1)
         {
            (static_cast<aghBlumBlumShub*>(generator[i]))->ustawPierwszaP(307);
            (static_cast<aghBlumBlumShub*>(generator[i]))->ustawPierwszaQ(311);
         }   
         for(int j = 0; j < 10; j++)
            generator[i]->wypiszLiczbe(plik);
      }
  
      for(int k = 0; k < 3; k++)
      {
         test[k]-> wypiszNazwe(plik);
         test[k]->ustawIloscLiczb(1000);
         for(int i = 0; i < 3; i++)
         {
            test[k]->ustawGenerator(generator[i]);
            generator[i]->wypiszNazwe(plik);
            if (k == 2)
               (static_cast<aghChiKwadrat*>(test[k]))->ustawLiczbaPrzedzialow(20);
            test[k]->testuj();
            test[k]->wypisz(plik);
         }
      }
   }
   catch(aghException& e)
   {
      cout << e << endl;
   }
   catch(...)
   {
      cout << "\nNierozpoznany błąd\n";
   }

   plik.close();

   for(int i = 0; i < 3; i++)
      delete generator[i];
   
   for(int k = 0; k < 3; k++)
      delete test[k];

   return 0;
}

