#include <iostream>
using namespace std;

class Zespolona{
  private:
    double real;
    double imaginary;
  public:
    Zespolona(double a=0, double b=0);
    void add(Zespolona, Zespolona);
    void sub(Zespolona, Zespolona);
    void mul(Zespolona, Zespolona);
    void div(Zespolona, Zespolona);
    void pow(Zespolona);
    void Wypisz();
};
Zespolona::Zespolona(double a, double b){
  real=a;
  imaginary=b;
};
void Zespolona::add(Zespolona a, Zespolona b){
  real=a.real+b.real;
  imaginary=a.imaginary+b.imaginary;
};
void Zespolona::sub(Zespolona a, Zespolona b){
  real=a.real-b.real;
  imaginary=a.imaginary-b.imaginary;
};
void Zespolona::mul(Zespolona a, Zespolona b){
  real=a.real*b.real-a.imaginary*b.imaginary;
  imaginary=a.real*b.imaginary+a.imaginary*b.real;
};     
void Zespolona::div(Zespolona a, Zespolona b){
  real=(a.real*b.real+a.imaginary*b.imaginary)/(b.real*b.real+b.imaginary*b.imaginary);
  imaginary=(-a.real*b.imaginary+a.imaginary*b.real)/(b.real*b.real+b.imaginary*b.imaginary);
};
void Zespolona::pow(Zespolona a){
  real=a.real*a.real-a.imaginary*a.imaginary;
  imaginary=2*a.real*a.imaginary;
};  
void Zespolona::Wypisz(){
  cout << real << " + " << imaginary << "sqrt(-1)" << endl;
}; 

int main(){
  Zespolona pierwsza(1,2);
  Zespolona druga(3,4); 
  Zespolona wynik;
  
  wynik.add(pierwsza, druga);
  wynik.Wypisz();
  wynik.sub(pierwsza, druga);
  wynik.Wypisz();
  wynik.mul(pierwsza, druga);
  wynik.Wypisz();
  wynik.div(pierwsza, druga);
  wynik.Wypisz();
  wynik.pow(pierwsza);
  wynik.Wypisz();
    
  return 0;
}
