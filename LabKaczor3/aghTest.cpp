#include <iostream>
#include "aghTest.h"

using namespace std;

aghTest::aghTest(){}
aghTest::aghTest(aghGenerator* _wskGenerator, int _iloscLiczb)
{
   if (_iloscLiczb < 100)
      throw aghException(0, "Za mała ilosc liczb do poprawnego przeprowdzenia jakiegokolwiek testu", __FILE__, __LINE__);
   if (_wskGenerator == NULL)
      throw aghException(0, "Podany wskaźnik na generator nie wskazuje na żaden generator", __FILE__, __LINE__);
   wskGenerator = _wskGenerator;
   iloscLiczb = _iloscLiczb;
}
aghTest::~aghTest(){}
void aghTest::ustawGenerator(aghGenerator* _wskGenerator)
{
   if (_wskGenerator == NULL)
      throw aghException(0, "Podany wskaźnik na generator nie wskazuje na żaden generator", __FILE__, __LINE__);
   wskGenerator = _wskGenerator;
}
void aghTest::ustawIloscLiczb(int _iloscLiczb)
{ 
   if (_iloscLiczb < 100)
      throw aghException(0, "Za mała ilosc liczb do poprawnego przeprowdzenia jakiegokolwiek testu", __FILE__, __LINE__);
   iloscLiczb = _iloscLiczb;
}
void aghTest::wypiszNazwe(ostream& strumien)
{
   strumien << endl << endl << nazwaTest;
}





