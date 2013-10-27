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
    ~DTab();
    void add(double element); 
    double get(int index); 
    void set(double element, int index); 
    void print();
};
void DTab::resize(int newSize){
  int i=0, j=0;
  
  if (newSize!=10){
    double *buff = new double[length]; 
    for(; j<length; j++)
      buff[j]=tab[j];  
    delete [] tab;
    tab = new double[newSize]; 
    for(; i<length; i++)
      tab[i]=buff[i];
    length=newSize;
    delete [] buff;
  }
  else{
    length=10;
    tab = new double[length];
    for(int i=0; i<length;i++) 
      tab[i]=0;
  }
};
DTab::DTab(){
  tab=NULL;
  resize(10);
};
DTab::DTab(int initLength){
  tab=NULL;
  resize(initLength);
};
DTab::~DTab(){
  delete [] tab;
};
void DTab::add(double element){
  if (tab[length-1]==0) tab[length-1]=element;
  else{
    resize(length+1);
    tab[length-1]=element;
  }  
};
double DTab::get(int index){
  return tab[index];
}; 
void DTab::set(double element, int index){
  tab[index]=element;
}; 
void DTab::print(){
  for(int i=0; i<length; i++)
  cout << tab[i] << " ";
  cout << endl;    
};
       
int main(){
  double szukana;
  DTab ala(0);
   
 /* ala.print();
  ala.add(3.6);
  ala.print();
  ala.add(4.9);
  ala.print();
  ala.add(4.9);
  ala.print();
  szukana=ala.get(6);
  cout << szukana << endl;
  ala.set(3.999,3);
  ala.print();
   */
  return 0;
}
