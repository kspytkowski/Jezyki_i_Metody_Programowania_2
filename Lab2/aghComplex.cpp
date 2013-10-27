#include <iostream>
#include "aghComplex.h"

using namespace std;

aghComplex::aghComplex(double _real, double _imaginary)
{
   real = _real;
   imaginary = _imaginary;
}
aghComplex::aghComplex(const aghComplex& model)
{
   real = model.real;
   imaginary = model.imaginary;
}
aghComplex aghComplex::operator+(const aghComplex& component)
{
   aghComplex result;
   result.real = component.real + real;
   result.imaginary = component.imaginary + imaginary;
   return result;
}
aghComplex aghComplex::operator*(const aghComplex& component)
{
   aghComplex result;
   result.real = real*component.real - imaginary*component.imaginary;
   result.imaginary = component.imaginary*real + imaginary*component.real;
   return result;
}
bool aghComplex::operator==(const aghComplex& component)
{
   if ((real == component.real) && (imaginary == component.imaginary))
      return true;
   else
      return false;
}
bool aghComplex::operator!=(const aghComplex& component)
{
   if ((real != component.real) || (imaginary != component.imaginary))
      return true;
   else
      return false;
}
aghComplex& aghComplex::operator=(const aghComplex& model)
{
   if (this == &model) return *this;
   real = model.real;
   imaginary = model.imaginary;
   return *this;
}
