#include <iostream>
#include <string.h>
#include "List.h"
using namespace std;

int main(){
    List lista;
    Node a("pies"),b("krowa"),c("mysz"),d=a,e("kura"),f(a),g("kot");
    
    b.data="zyrafa";
    f.zmien("kon");
    lista.push(a);
    lista.push(b);
    lista.push(c);
    lista.push(d);
    lista.push(e);
    lista.push(f);
    lista.push(g);
    lista.print(lista.getHead());
    lista.find(2);
    lista.find(7);
    lista.pop();
    lista.pop();
    lista.print(lista.getHead());
    lista.~List();

    return 0;
}
