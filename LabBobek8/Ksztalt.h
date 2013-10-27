#ifndef KSZTALT_H
#define KSZTALT_H

#include <iostream>

using namespace std;

class Ksztalt{
  public:
    virtual void rysuj() = 0;
};

class Trojkat : public Ksztalt{
  public:
    virtual void rysuj();
};

class Kwadrat : public Ksztalt{
  public:
    virtual void rysuj();
};

class Kolo : public Ksztalt{
  public:
    virtual void rysuj();
};

#endif
