#include <iostream>
#include <math.h>
#include "Kolo.h"
#include "Kula.h"

using namespace std;

int main(void){
  Kula k(0,0,0,10);

  cout << k.Kolo::pole() << endl;
  return 0;
}
