#include <iostream>
#include "DTab.h"
using namespace std;

DTab::DTab(const DTab &lol){
  this->last=lol.last;
  this->length=lol.length;
  this->tab = new double[lol.length];
  for(int i=0; i<lol.length; i++){
    this->tab[i]=lol.tab[i];
  };             
  cout << "Pracuje konstruktor kopiujacy" << endl;
};
void DTab::resize(int newSize){
  int i=0, j=0;
  
  if (length!=0){
    double *buff = new double[length]; 
    for(; j<length; j++)
      buff[j]=tab[j];  
    delete [] tab;
    tab = new double[newSize]; 
    for(; i<length; i++)
      tab[i]=buff[i];
    for(;i<newSize; i++)
      tab[i]=0;
    length=newSize;
    delete [] buff;
  }
  else{
    length=newSize;
    tab = new double[length];
    for(int i=0; i<length;i++) 
      tab[i]=0;
  }
};
DTab::DTab(){
  length=0;
  resize(10);
};
DTab::DTab(int initLength){
  length=0;
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
DTab DTab::wypelniona(int wypelnienie){
  for(int i=0; i<length; i++)
   tab[i]=wypelnienie;
  return *this;   
};
