#include <iostream>
#include <string.h>
#include "Dziecko.h"
using namespace std;

int main(void){
    Rodzic tata("Andrzej", "Noga", 40, "Bartek", "Noga", 10, "Podstawowka");
    tata.wypisz();
    tata.przepiszDoInnejSzkoly("Gimnazjum");
    tata.wypisz();

    return 0;
}
