#include <iostream>
#include <math.h>
#include "Punkt2D.h"
#include "Punkt3D.h"

using namespace std;

int main(void){
  Punkt3D pierwszy(18,15,12), drugi(4,5,6);

  cout << endl << pierwszy.distance(drugi) << endl << endl;
  return 0;
}
