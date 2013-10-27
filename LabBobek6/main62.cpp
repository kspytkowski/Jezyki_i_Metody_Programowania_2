#include <iostream>
#include "Zespolona.h"

using namespace std;

int main(){
   Zespolona pierwsza(1,2), druga(3,4), trzecia;

   trzecia=pierwsza+druga+pierwsza;
   trzecia.Wypisz();
   trzecia=pierwsza-druga;
   trzecia.Wypisz();
   pierwsza+=druga;
   pierwsza.Wypisz();
   pierwsza-=druga;
   pierwsza.Wypisz();
   trzecia=pierwsza*druga;
   trzecia.Wypisz();
   trzecia=pierwsza/druga;
   trzecia.Wypisz();
   if (pierwsza == druga) cout << "rowne";
   if (pierwsza != druga) cout << "nierowne";
   if (pierwsza > druga) cout << "pierwsza ma modul wiekszy niz druga";
   if (pierwsza < druga) cout << "pierwsza ma modul mniejszy niz druga";

   return 0;
}
