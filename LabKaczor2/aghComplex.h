/**
* \file aghComplex.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 10.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy aghComplex
*/

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H

/**
* \class aghComplex
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 10.05.2013
* \brief Definicja klasy aghComplex
*/
class aghComplex
{
   private:
      double real; ///< Część rzeczywista liczby zespolonej
      double imaginary; ///< Część urojona liczby zespolonej
   public:
      /// \brief Konstruktor domyślny klasy
      ///
      /// \param _real - Część rzeczywista liczby zespolonej
      /// \param _imaginary - Część urojona liczby zespolonej
      aghComplex(double _real = 0, double _imaginary = 0);
      /// \brief Konstruktor kopiujący klasy
      ///
      /// \param model - Model liczby zespolonej
      aghComplex(const aghComplex& model);  
      /// \brief Destruktor klasy
      ~aghComplex(){}
      /// \brief Przeładowany operator+
      ///
      /// \param component - Liczba zespolona będąca składnikiem do zsumowania
      /// \return Liczba zespolona będąca sumą dwóch zadanych liczb
      aghComplex operator+(const aghComplex& component);
      /// \brief Przeładowany operator*
      ///
      /// \param component - Liczba zespolona będąca czynnikiem do wymnożenia
      /// \return Liczba zespolona będąca iloczynem dwóch zadanych liczb
      aghComplex operator*(const aghComplex& component);
      /// \brief Przeładowany operator==
      ///
      /// \param component - Liczba zespolona będąca składnikiem do porównania
      /// \return Wartość logiczna będąca wynikiem porównania liczb
      bool operator==(const aghComplex& component);  
      /// \brief Przeładowany operator!=
      ///
      /// \param component - Liczba zespolona będąca składnikiem do porównania
      /// \return Wartość logiczna będąca wynikiem porównania liczb 
      bool operator!=(const aghComplex& component);
      /// \brief Przeładowany operator=
      ///
      /// \param model - Referencja do liczby zespolonej będącej modelem służacym do konstrukcji jej kopii
      /// \return Referencja do nowoskonstruowanej liczby zespolonej
      aghComplex& operator=(const aghComplex& model);
};

#endif
