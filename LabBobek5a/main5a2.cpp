#include <iostream>
#include "DTab.h"
using namespace std;

int main(){
  cout << "NOWE POKOLENIE" << endl;
  DTab ta;
  DTab cos=ta;
  ta.print();
  cos.print();
  cos.add(4);
  ta.print();
  cos.print();
  ta.wypelniona(5);
  ta.print();
  ta.add(7);
  ta.print();
  ta.set(6,2);
  ta.print();
   
  return 0;
}
