#ifndef KWADRAT_H_
#define KWADRAT_H_
#include <iostream>
#include <math.h>

using namespace std;

class Kwadrat {
private:
	Punkt a, b, c, d;
public:
	Kwadrat(Punkt e, Punkt f, Punkt g, Punkt h);
	void obwod();
	void pole();
};

#endif /* KWADRAT_H_ */
