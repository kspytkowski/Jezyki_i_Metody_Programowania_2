#include <iostream>
#include <list>
#include <stdlib.h>
#include "Marsjanin.h"
using namespace std;

int main(void){
  list<Marsjanin> lista;
  Marsjanin ja;
  
  while(1){
    if(rand()%2==0){
      lista.push_front(ja);
      Marsjanin::liczbaMarsjan++;
    }
    else{
      if (Marsjanin::liczbaMarsjan > 0){ 
        lista.pop_front();
        Marsjanin::liczbaMarsjan--;
      };
    };  
  if (Marsjanin::liczbaMarsjan > 5)
    for(list<Marsjanin>::const_iterator it=lista.begin(); it!=lista.end(); it++) 
      it->atakuj();
  if (Marsjanin::liczbaMarsjan <= 5) 
    for(list<Marsjanin>::const_iterator it=lista.begin(); it!=lista.end(); it++) 
      it->ukryjSie();
    sleep(1);   
  };
    
  return 0;  
}
