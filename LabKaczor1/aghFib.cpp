#include <iostream>
#include "aghFib.h"
#include "aghException.h"

using namespace std;

int aghFib::operator[](int index)
{
   if (index < 0)
      throw aghException(0, "Index żądanej liczby ciagu Fibonacciego nie może być mniejszy od 0", __FILE__, __LINE__);
   if (index == 0) 
      return 0;
   int pierwszy = 0, drugi = 1;
   for (int i = 0; i < index - 1; i++)
   {
      swap(pierwszy,drugi);
      drugi += pierwszy;
   };
   return drugi;   
}
