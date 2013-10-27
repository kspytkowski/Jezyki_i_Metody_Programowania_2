#include <iostream>
#include <string.h>
using namespace std;

class Node{
  public:
    char *data;
    Node* next;
    Node(char *data2);
    void zmien(const char *nowe){
      strcpy(data, nowe);
    };
    Node(const Node &ref);
};
class List{
  private:
    Node *head;
    int amount;
  public:
    List();   
    ~List();  
    List(const List &kopia);
    Node *getHead(){ return head;};
    void push(Node temp);
    void pop();
    void find(int number);
    void print(Node *temp);
};
