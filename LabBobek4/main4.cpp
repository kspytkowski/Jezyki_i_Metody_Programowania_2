#include "Punkt.h"
#include "Zespolona.h"
#include "Kwadrat.h"

int main() {

	Punkt pierwszy(1, 5), drugi(1, 8), trzeci(4, 5), czwarty(4, 8);
	Kwadrat figura(pierwszy, drugi, trzeci, czwarty);

	figura.obwod();
	figura.pole();

	double szukana;
	DTab ala(0);

	ala.print();
	ala.add(3.6);
	ala.print();
	ala.add(4.9);
	ala.print();
	ala.add(4.9);
	ala.print();
	szukana = ala.get(6);
	cout << szukana << endl;
	ala.set(3.999, 3);
	ala.print();

	Zespolona pierwsza(1, 2);
	Zespolona druga(3, 4);
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

