#include <iostream>
#include <math.h>
#include "Punkt.h"
using namespace std;

int main(void) {
	Punkt p, p5;
	Punkt p2(12, 34);
	Punkt p3(13, 35);
	Punkt *ptrP = new Punkt(3, 4);
	p2.wyswietl();
	cout << ptrP->distance(p2) << endl;
	delete ptrP;
	cout << endl << "NOWA PROBA" << endl;
	cout << Distance(p2, p3) << endl;
	cout << "Przypisanie podczas deklaracji:";
	Punkt p4 = p2;
	cout << "Przypisanie poza deklaracja:";
	p5 = p2;
	cout << endl;

	return 0;
}
