#ifndef UMOWA_H
#define UMOWA_H

#include <iostream>
#include <string.h> ///???????????????????

using namespace std;

class Umowa{
  protected:
    double wynagrodzenieBrutto;
  public:
    Umowa(double pensja);
    virtual ~Umowa(){};
    virtual double pobierzNetto() = 0;
    double pobierzBrutto();
};

class UmowaDzielo: public Umowa{
  public:
    UmowaDzielo(double pensja):Umowa(pensja){};
    virtual ~UmowaDzielo(){};
    virtual double pobierzNetto();
};

class UmowaPraca: public Umowa{
  public:
    UmowaPraca(double pensja):Umowa(pensja){};
    virtual ~UmowaPraca(){};
    virtual double pobierzNetto();
};

#endif
