#include <iostream>
#include <string.h>
#include "List.h"
using namespace std;

Node::Node(char *data2){
  data = new char[100];
  strcpy(data,data2);
  next=NULL;
  cout << "Konstruktor zwykly z domniemanym parametrem" << endl;
};
Node::Node(const Node &ref){
  char *tab = new char[100];
  
  strcpy(tab,ref.data);
  this->data=tab;
  this->next=ref.next;        
  cout << "Konstruktor kopiujacy" << endl;         
};
void List::print(Node *temp){
  int i=0;
    
  while(temp!=NULL){
    cout << "elemenet: " << temp->data << endl;
    temp=temp->next;
    i++;
  };    
  cout << "Liczba elementow w liscie: " << amount << endl;
};
List::List(){
  cout << "Konstruktor listy" << endl;
  head=NULL;
  amount=0;
}
List::List(const List &kopia){

  if(kopia.head != NULL) 
  {
    Node *nowy=new Node;
    head=nowy;
    strcpy(
  
    while (nowy != NULL)
    {
      actual2->content = actual->content;
      if (actual->next != NULL)
      {
        actual2->next = new node;
        actual2 = actual2->next;
      }
      else
        actual2->next = NULL;
      actual = actual->next;
    }
  }
  else head=NULL; 
};
List::~List(){
  Node *temp;
  cout << "Destruktor listy" << endl;
  while(head!=NULL){
  temp=head;
  head=head->next;
  delete temp; 
  };          
};
void List::push(Node temp){
  Node *nowy = new Node(temp);
  
  if (head==NULL){
    head=nowy;
    nowy->next=NULL;
  }
  else{
    nowy->next = head;
    head = nowy;
  };
  amount++;
};
void List::pop(){
  Node *temp;
      
  if(head != NULL){
    temp = head;
    head = head->next;
    delete temp;
    amount--;
  };
};
void List::find(int number){
  Node *temp;
  
  temp = head;
  for(int i=0; i<number-1; i++) temp=temp->next;
  cout << "Element nr " << number << " posiada napis:";
  cout << temp->data << endl;  
};
