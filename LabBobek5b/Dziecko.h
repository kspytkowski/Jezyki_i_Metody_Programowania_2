#include <iostream>
#include <string.h>
using namespace std;

class Dziecko{
  private:
    string imie;
    string nazwisko;
    int wiek;
    string szkola;  
  public:
    Dziecko(string imi, string naz, int wie, string szk);       
    friend class Rodzic;
};
class Rodzic{
  private:
    string imie;
    string nazwisko;
    int wiek;
    Dziecko dziecko;      
  public:
    Rodzic(string im, string na, int w, string im_d, string na_d, int w_d, string sz_d);
    void przepiszDoInnejSzkoly(string nazwa);
    void wypisz(){
      cout << dziecko.szkola << endl;
    };
};
