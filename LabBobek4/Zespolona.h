#ifndef ZESPOLONA_H
#define ZESPOLONA_H

class Zespolona{
  private:
    double real;
    double imaginary;
  public:
    Zespolona(double a=0, double b=0);
    void add(Zespolona, Zespolona);
    void sub(Zespolona, Zespolona);
    void mul(Zespolona, Zespolona);
    void div(Zespolona, Zespolona);
    void pow(Zespolona);
    void Wypisz();
    friend const Zespolona operator+(const Zespolona&, const Zespolona&);
    friend const Zespolona operator-(const Zespolona&, const Zespolona&);
    friend const Zespolona operator+=(Zespolona&, const Zespolona&);
    friend const Zespolona operator-=(Zespolona&, const Zespolona&);
    friend const Zespolona operator*(const Zespolona&, const Zespolona&);
    friend const Zespolona operator/(const Zespolona&, const Zespolona&);
    friend bool operator==(const Zespolona&, const Zespolona&);
    friend bool operator!=(const Zespolona&, const Zespolona&);
    friend bool operator<(const Zespolona&, const Zespolona&);
    friend bool operator>(const Zespolona&, const Zespolona&);
};

#endif
