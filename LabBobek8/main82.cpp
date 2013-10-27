#include <iostream>
#include <list>
#include <cstdlib>
#include "Ksztalt.h"

using namespace std;

int main(){
  list<Ksztalt*> lista;
  list<Ksztalt*>::iterator it;
  
  for(int i=0; i<10; i++){
    switch(rand()%3){
      case 0:
        lista.push_front(new Trojkat);
        break;
      case 1:
        lista.push_front(new Kwadrat);
        break;
      case 2:
        lista.push_front(new Kolo);
        break;
    };
  };
  for(it=lista.begin(); it!=lista.end(); it++){
    (*it)->rysuj();
  };
  return 0;
}
