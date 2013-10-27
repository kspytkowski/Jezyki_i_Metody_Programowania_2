#include <iostream>
#include <string.h>
using namespace std;
class Dziecko {
private:
	string imie;
	string nazwisko;
	int wiek;
	string szkola;
public:
	Dziecko(string imi, string naz, int wie, string szk);
	friend class Rodzic;
};
