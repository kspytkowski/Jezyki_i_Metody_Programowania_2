#include <iostream>
#include <math.h>

using namespace std;

class Punkt{
  private:
    float x,y;
  public:
    Punkt(float, float);
    float getX(){ return x;};
    float getY(){ return y;};
};
Punkt::Punkt(float a=0, float b=0){
  x=a;
  y=b;   
};

class Kwadrat{
  private:
    Punkt a,b,c,d;
  public:
    Kwadrat(Punkt e,Punkt f,Punkt g,Punkt h);
    void obwod();
    void pole();
};
Kwadrat::Kwadrat(Punkt e,Punkt f,Punkt g,Punkt h){
  a=e;
  b=f;
  c=g;
  d=h;
};
void Kwadrat::obwod(){
  cout << "Obwod kwadratu wynosi:";
  cout << 4*sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2)) << endl;   
};
void Kwadrat::pole(){
  cout << "Pole kwadratu wynosi:";
  cout << pow(sqrt(pow(a.getX()-b.getX(),2)+pow(a.getY()-b.getY(),2)),2) << endl;   
};

int main(){
  Punkt pierwszy(1,5), drugi(1,8), trzeci(4,5), czwarty(4,8);
  Kwadrat figura(pierwszy, drugi, trzeci, czwarty);
  figura.obwod();
  figura.pole();
  
  return 0;  
}
