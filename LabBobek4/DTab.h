#include <iostream>
using namespace std;

class DTab{
  private:
    double *tab;
    int length;
    int last; 
    void resize(int newSize); 
  public:
    DTab();
    DTab(int initLength); 
    DTab(const DTab &lol);
    ~DTab();
    void add(double element); 
    double get(int index); 
    void set(double element, int index); 
    void print();
    DTab wypelniona(int wypelnienie);
};
