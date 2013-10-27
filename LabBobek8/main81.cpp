#include <iostream>
#include <string.h>
#include "Umowa.h"
#include "Pracownik.h"

using namespace std;

int main(){
  UmowaDzielo dzielo(4000);
  UmowaPraca praca(4000);
  Pracownik siostra("Anna","Spytkowska","00000000000",&dzielo);
  Pracownik ja("Krzysztof","Spytkowski","11111111111",&praca);

  cout << "Umowa o dzielo:" << endl;
  cout << siostra << endl;
  cout << "Umowa o prace:" << endl;
  cout << ja << endl;
  return 0;
}
