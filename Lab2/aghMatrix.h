/**
* \file aghMatrix.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 10.05.2013
* \version 1.0
* \brief Plik zawiera deklaracje klasy szablonowej aghMatrix
*/

#ifndef AGHMATRIX_H
#define AGHMATRIX_H

#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include "aghMatrix.h"
#include "aghException.h"

using namespace std;

/**
* \class aghMatrix
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 10.05.2013
* \brief Definicja klasy szablonowej aghMatrix
*/
template <class T>
class aghMatrix
{ 
   private:
      int rows; ///< Liczba wierszy tablicy
      int cols; ///< Liczba kolumn tablicy
      T** table; ///< Tablica dwuwymiarowa
      /// \brief Funkcja alokująca pamięć
      ///
      /// \param newRows - Nowa liczba wierszy
      /// \param newCols - Nowa liczba kolumn
      void resize(int newRows, int newCols);
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghMatrix();
      /// \brief Konstruktor parametrowy klasy
      ///
      /// \param _rows - Liczba wierszy
      /// \param _cols - Liczba kolumn
      aghMatrix(int _rows, int _cols);
      /// \brief Konstruktor kopiujący klasy
      /// 
      /// \param model - Model macierzy
      aghMatrix(const aghMatrix& model);
      /// \brief Destruktor klasy
      ~aghMatrix();
      /// \brief Funkcja wstawia we wskazane miejsce w macierzy zadaną daną 
      ///
      /// \param _rows - Współrzedna (wiersz)
      /// \param _cols - Współrzędna (kolumna)
      /// \param dana - Zadana dana
      void setItem(int _rows, int _cols, T dana);
      /// \brief Funkcja wstawia do macierzy dane pochodzące z innej macierzy 
      ///
      /// \param wsk_table - wskaźnik na macierz z danymi
      void setItems(T *wsk_table);
      /// \brief Funkcja wstawia do macierzy zadane dane 
      ///
      /// \param _rows - liczba wierszy
      /// \param _cols - liczba kolumn
      /// \param ... - Zadane dane
      void setItems(int _rows, int _cols, ...);
      /// \brief Przeładowany operator= przypisujący macierzy wartości innej macierzy
      ///
      /// \param model - Macierz, ktora należy przypisac innej macierzy
      /// \return Referencja do nowopowstałej macierzy
      aghMatrix<T>& operator=(const aghMatrix<T>& model);
      /// \brief Przeładowany operator+ sumujący dwie macierze według algorytmu sumowania macierzy
      ///
      /// \param component - Macierz będąca jednym ze składników
      /// \return Nowopowstała macierz
      aghMatrix<T> operator+(const aghMatrix<T>& component);
      /// \brief Przeładowany operator* mnożący dwie macierze według algorytmu mnozenia macierzy
      ///
      /// \param component - Macierz będąca jednym z czynników
      /// \return Nowopowstała macierz
      aghMatrix<T> operator*(const aghMatrix<T>& component);
      /// \brief Przeładowany operator== porównujący dwie macierze
      ///
      /// \param component - Macierz do porównania
      /// \return Wartość logiczna porównania
      bool operator==(const aghMatrix<T>& component);
      /// \brief Przeładowany operator!= porównujący dwie macierze
      ///
      /// \param component - Macierz do porównania
      /// \return Wartość logiczna porównania
      bool operator!=(const aghMatrix<T>& component);
      /// \brief Przeładowany operator() 
      ///
      /// \param _rows - wiersz
      /// \param _cols - kolumna
      /// \return Wartość macierzy pod wskazanymi współrzędnymi
      T operator()(int _rows, int _cols);
};
template <class T>
void aghMatrix<T>::resize(int newRows, int newCols)
{
   T** bufor = new T*[newRows];
   for (int i = 0; i < newRows; i++)
   {
      bufor[i] = new T[newCols];
   }
   if (table != NULL)
   {
      for (int i = 0; i < rows; i++)
      {
         delete [] table[i];
      }
      delete [] table;
   }
   table = bufor;
   rows = newRows;
   cols = newCols;
}
/// \brief Funkcja alokująca pamięć (specjalizowana dla char*)
///
/// \param newRows - Nowa liczba wierszy
/// \param newCols - Nowa liczba kolumn
template <>
void aghMatrix<char*>::resize(int newRows, int newCols)
{
   char*** bufor = new char**[newRows];
   for (int k = 0; k < newRows; k++)
   {
      bufor[k] = new char*[newCols];
   }
   if (table != NULL)
   {
      for (int i = 0; i < rows; i++)
      {
         delete [] table[i];
      }
      delete [] table;
   }
   table = bufor;
   rows = newRows;
   cols = newCols;
}
template <class T>
aghMatrix<T>::aghMatrix()
{
   rows = 0;
   cols = 0;
   table = NULL;
}
template <class T>
aghMatrix<T>::aghMatrix(int _rows, int _cols)
{
   rows = _rows;
   cols = _cols;
   table = NULL;
   resize(_rows, _cols);
}
/// \brief Konstruktor parametrowy klasy (specjalizowany dla char*)
///
/// \param _rows - Liczba wierszy
/// \param _cols - Liczba kolumn
template <>
aghMatrix<char*>::aghMatrix(int _rows, int _cols)
{
   rows = _rows;
   cols = _cols;
   table = NULL;
   resize(_rows, _cols);
}
template <class T>
aghMatrix<T>::aghMatrix(const aghMatrix<T>& model)
{
   table = NULL;
   resize(model.rows, model.cols);
   for (int i = 0; i < model.rows; i++)
   {
      for (int j = 0; j < model.cols; j++)
      {
         table[i][j] = model.table[i][j];
      }
   }    
}
/// \brief Konstruktor kopiujący klasy (specjalizowany dla char*)
/// 
/// \param model - Model macierzy
template <>
aghMatrix<char*>::aghMatrix(const aghMatrix<char*>& model)
{
   resize(model.rows, model.cols);
   for (int i = 0; i < model.rows; i++)
   {
      for (int j = 0; j < model.cols; j++)
      {
         table[i][j] = new char[strlen(model.table[i][j]) + 1];
         strcpy(table[i][j], model.table[i][j]);
      }
   }
}
template <class T>
aghMatrix<T>::~aghMatrix()
{
   if (table != NULL)
   {
      for (int i = 0; i < rows; i++)
      {
         delete [] table[i];
      }
      delete [] table;
   }
   table = NULL;
   rows = 0;
   cols = 0;
}
/// \brief Destruktor klasy (specjalizowany dla char*)
template <>
aghMatrix<char*>::~aghMatrix()
{
   if (table != NULL)
   {
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < cols; j++)
         { 
            delete [] table[i][j];
         }
         delete [] table[i];
      }
      delete [] table;
   }
   table = NULL;
   rows = 0;
   cols = 0;
}
template <class T>
void aghMatrix<T>::setItem(int _rows, int _cols, T dana)
{
   table[_rows][_cols] = dana;
}
/// \brief Funkcja wstawia we wskazane miejsce w macierzy zadaną daną (specjalizowana dla char*)
///
/// \param _rows - Współrzedna (wiersz)
/// \param _cols - Współrzędna (kolumna)
/// \param dana - Zadana dana
template <>
void aghMatrix<char*>::setItem(int _rows, int _cols, char* dana)
{
   if (table[_rows][_cols] != NULL)
      delete [] table[_rows][_cols];
   table[_rows][_cols] = new char[strlen(dana) + 1];
   strcpy(table[_rows][_cols], dana);
}
template <class T>
void aghMatrix<T>::setItems(T* wsk_table)
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         table[i][j] = *wsk_table;
         wsk_table++;
      }
   }
}
/// \brief Funkcja wstawia do macierzy dane pochodzące z innej macierzy (specjalizowana dla char*)
///
/// \param wsk_table - wskaźnik na macierz z danymi
template <>
void aghMatrix<char*>::setItems(char** wsk_table)
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         table[i][j] = new char[strlen(*wsk_table) + 1];
         strcpy(table[i][j], *wsk_table);
         wsk_table++;
      }
   }
}
template <class T>
void aghMatrix<T>::setItems(int _rows, int _cols, ...)
{
   resize(_rows, _cols);
   va_list items;
   va_start(items, _cols);
   for (int i = 0; i < _rows; i++)
   {
      for (int j = 0; j < _cols; j++)
      {
         table[i][j] = va_arg(items, T);
      }
   }
   va_end(items);
}
/// \brief Funkcja wstawia do macierzy zadane dane (specjalizowana dla char)
///
/// \param _rows - liczba wierszy
/// \param _cols - liczba kolumn
/// \param ... - Zadane dane
template <>
void aghMatrix<char>::setItems(int _rows, int _cols, ...)
{
   resize(_rows, _cols);
   va_list items;
   va_start(items, _cols);
   for (int i = 0; i < _rows; i++)
   {
      for (int j = 0; j < _cols; j++)
      {
         table[i][j] = va_arg(items, int);
      }
   }
   va_end(items);
}
/// \brief Funkcja wstawia do macierzy zadane dane (specjalizowana dla char*)
///
/// \param _rows - liczba wierszy
/// \param _cols - liczba kolumn
/// \param ... - Zadane dane
template <>
void aghMatrix<char*>::setItems(int _rows, int _cols, ...)
{
   resize(_rows, _cols);
   va_list item;
   va_start(item, _cols);
   for (int k = 0; k < _rows; k++)
   {
      for (int z = 0; z < _cols; z++)
      {
         table[k][z] = new char[strlen(va_arg(item,char*)) + 1];
      }
   }
   va_end(item);
   va_list items;
   va_start(items, _cols);
   for (int i = 0; i < _rows; i++)
   {
      for (int j = 0; j < _cols; j++)
      {
         strcpy(table[i][j], va_arg(items, char*));
      }
   }
   va_end(items);
}
template <class T>
aghMatrix<T>& aghMatrix<T>::operator=(const aghMatrix<T>& model)
{
   if (this == &model) 
      return *this;
   if (table != NULL)
   {
      for (int i = 0; i < rows; i++)
      {
         delete [] table[i];
      }
      delete [] table;
   }
   table = NULL;
   resize(model.rows, model.cols);
   if (table != NULL)
   {
      for (int i = 0; i < model.rows; i++)
      {
         for (int j = 0; j < model.cols; j++)
         {
            table[i][j] = model.table[i][j];
         }
      }
   }
   return *this;
}
/// \brief Przeładowany operator= przypisujący macierzy wartości innej macierzy (specjalizowany dla char*)
///
/// \param model - Macierz, ktorą należy przypisac innej macierzy
/// \return Referencja do nowopowstałej macierzy
template <>
aghMatrix<char*>& aghMatrix<char*>::operator=(const aghMatrix<char*>& model)
{
   if (this == &model) 
      return *this;
   if (table != NULL)
   {
      for (int i = 0; i < rows; i++)
      {
         for (int j = 0; j < cols; j++)
         { 
            delete [] table[i][j];
         }
         delete [] table[i];
      }
      delete [] table;
   }
   table = NULL;
   resize(model.rows, model.cols);
   for (int i = 0; i < model.rows; i++)
   {
      for (int j = 0; j < model.cols; j++)
      {
         table[i][j] = new char[strlen(model.table[i][j]) + 1];
         strcpy(table[i][j], model.table[i][j]);
      }
   }
   return *this;
}
template <class T>
aghMatrix<T> aghMatrix<T>::operator+(const aghMatrix<T>& component)
{
   if ((rows != component.rows) || (cols != component.cols))
      throw aghException(0, "Nie mozna dodawac macierzy o roznych wymiarach", __FILE__, __LINE__);
   aghMatrix<T> result(rows, cols);
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         result.table[i][j] = table[i][j] + component.table[i][j];
      }
   }      
   return result;   
}
/// \brief Przeładowany operator+ sumujący dwie macierze według algorytmu sumowania macierzy (specjalizowany dla char)
///
/// \param component - Macierz będąca jednym ze składników
/// \return Nowopowstała macierz
template<>
aghMatrix<char> aghMatrix<char>::operator+(const aghMatrix<char>& component)
{
   if ((rows != component.rows) || (cols != component.cols))
      throw aghException(0, "Nie mozna dodawac macierzy o roznych wymiarach", __FILE__, __LINE__);
   aghMatrix<char> result(rows, cols);  
   int help;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         help = table[i][j] + component.table[i][j] - 2 * 'a';
         if (help > 'z' - 'a') 
            help = help % ('z' - 'a' + 1);
         result.table[i][j] = (help + 'a');
      }
   }    
   return result; 
}
/// \brief Przeładowany operator+ sumujący dwie macierze według algorytmu sumowania macierzy (specjalizowany dla char*)
///
/// \param component - Macierz będąca jednym ze składników
/// \return Nowopowstała macierz
template<>
aghMatrix<char*> aghMatrix<char*>::operator+(const aghMatrix<char*>& component)
{
   if ((rows != component.rows) || (cols != component.cols))
      throw aghException(0, "Nie mozna dodawac macierzy o roznych wymiarach", __FILE__, __LINE__);
   aghMatrix<char*> result(rows, cols);
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         char* help = new char[strlen(table[i][j]) + strlen(component.table[i][j]) + 1];
         char* help2 = new char[strlen(table[i][j]) + strlen(component.table[i][j]) + 1];
         for (unsigned int z = 0; z < strlen(table[i][j]) + strlen(component.table[i][j]) + 1; z++) 
            help2[z] = '\0';
         strcpy(help, table[i][j]);
         strcat(help, component.table[i][j]);
         for (unsigned int k = 0; k < strlen(help); k++)
         {
            for (unsigned int m = 0; m < strlen(help); m++)
            {
               if (help2[m] == help[k]) 
                  break;
               if (help2[m] == '\0') 
               {
                  help2[m] = help[k];
                  break;
               }
            }
         }
         result.table[i][j] = new char[strlen(help2) + 1];
         strcpy(result.table[i][j], help2);
         delete [] help;
         delete [] help2;
      }
   }    
   return result; 
}
template <class T>
aghMatrix<T> aghMatrix<T>::operator*(const aghMatrix<T>& component)
{
   if (cols != component.rows)
      throw aghException(0, "Nie mozna mnozyc macierzy gdy liczba kolumn pierwszej jest inna niz liczba wierszy drugiej", __FILE__, __LINE__);
   aghMatrix<T> result(rows, component.cols);
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < component.cols; j++)
      {
         result.table[i][j] = 0;
         for (int m = 0; m < cols; m++)
         {
            result.table[i][j] = result.table[i][j] + table[i][m] * component.table[m][j];
         }
      }
   }
   return result;   
}
/// \brief Przeładowany operator* mnożący dwie macierze według algorytmu mnozenia macierzy (specjalizowany dla char)
///
/// \param component - Macierz będąca jednym z czynników
/// \return Nowopowstała macierz
template <>
aghMatrix<char> aghMatrix<char>::operator*(const aghMatrix<char>& component)
{
   if (cols != component.rows)
      throw aghException(0, "Nie mozna mnozyc macierzy gdy liczba kolumn pierwszej jest inna niz liczba wierszy drugiej", __FILE__, __LINE__);
   int help;
   aghMatrix<char> result(rows, component.cols);
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < component.cols; j++)
      {
         help = 0;
         result.table[i][j] = 0;      
         for (int m = 0; m < cols; m++)
         {
            result.table[i][j] = result.table[i][j] + table[i][m] * component.table[m][j];
            help = help + (table[i][m] - 'a')*(component.table[m][j] - 'a');
         }
         if (help > 'z' - 'a') 
            help = help % ('z' - 'a' + 1);
         result.table[i][j] = help + 'a';
      }
   }
   return result;   
}
/// \brief Przeładowany operator* mnożący dwie macierze według algorytmu mnozenia macierzy (specjalizowany dla char*)
///
/// \param component - Macierz będąca jednym z czynników
/// \return Nowopowstała macierz
template <>
aghMatrix<char*> aghMatrix<char*>::operator*(const aghMatrix<char*>& component)
{
   if (cols != component.rows)
      throw aghException(0, "Nie mozna mnozyc macierzy gdy liczba kolumn pierwszej jest inna niz liczba wierszy drugiej", __FILE__, __LINE__);
   aghMatrix<char*> result(rows, component.cols);
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < component.cols; j++)
      {
         result.table[i][j] = new char[50];
         result.table[i][j][0] = '\0';
         for (int m = 0; m < cols; m++)
         {
            char help[40] = {'\0'}; 
            int z = 0;
            for (unsigned int t = 0; t < strlen(table[i][m]); t++)
            {
               if (component.table[m][j][t] == '\0') 
                  break;
               else
                  for (unsigned int v = 0; v < strlen(component.table[m][j]); v++)
                  {
                     if (table[i][m][t] == component.table[m][j][v])
                     {
                        help[z] = table[i][m][t];
                        z++;
                     }
                  }
            }
            help[z] = '\0';
            char* help2 = new char[strlen(result.table[i][j]) + strlen(help) + 1];
            char* help3 = new char[strlen(result.table[i][j]) + strlen(help) + 1];
            help3[0] = '\0';
            strcpy(help2, result.table[i][j]);
            strcat(help2, help);
            for (unsigned int k = 0; k < strlen(help2); k++)
            {
               for (unsigned int m = 0; m < strlen(help2); m++)
               {
                  if (help3[m] == help2[k]) 
                     break;
                  if (help3[m] == '\0') 
                  {
                     help3[m] = help2[k];
                     help3[m+1] = '\0';
                     break;
                  }
               }
            }
            delete [] result.table[i][j]; 
            result.table[i][j] = new char[strlen(help3) + 1];
            strcpy(result.table[i][j], help3);
            delete [] help2;
            delete [] help3;
         }
      }
   }
   return result;   
}
template <class T>
bool aghMatrix<T>::operator==(const aghMatrix<T>& component)
{
   if ((rows != component.rows) || (cols != component.cols)) 
      return false;
   bool flag = true;
   for (int i = 0; i < rows; i++)
   {
      for (int k = 0; k < cols; k++)
      {
         if (table[i][k] != component.table[i][k])
         {
            flag = false;
            break;
         }
      }
      if (flag == false) 
         break;
   }   
   return flag;
}
/// \brief Przeładowany operator== porównujący dwie macierze (specjalizowany dla char*)
///
/// \param component - Macierz do porównania
/// \return Wartość logiczna porównania
template <>
bool aghMatrix<char*>::operator==(const aghMatrix<char*>& component)
{  
   if ((rows != component.rows) || (cols != component.cols)) 
      return false; 
   bool flag = true;   
   for (int i = 0; i < rows; i++)
   {
      for (int k = 0; k < cols; k++)
      {
         if (strcmp(table[i][k], component.table[i][k]) != 0)
         {
            flag = false;
            break;
         }
      }
      if (flag == false) 
         break;
   }
   return flag;
}
template <class T>
bool aghMatrix<T>::operator!=(const aghMatrix<T>& component)
{
   if ((rows != component.rows) || (cols != component.cols)) 
      return true;
   bool flag = true;
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         if (table[i][j] != component.table[i][j])
         {
            flag = false; 
            break;
         }
      }
      if (flag == false) 
         break;
   }
   return !flag;
}
template <class T>
T aghMatrix<T>::operator()(int _rows, int _cols)
{
   if ((_rows > rows) || (_cols > cols))
      throw aghException(0, "Podany indeks jest poza zakresem tablicy", __FILE__, __LINE__);
   if ((_rows < 0) || (_cols < 0))
      throw aghException(0, "Indeks tablicy nie moze byc mniejszy od zera", __FILE__, __LINE__);
   return table[_rows][_cols];
}

#endif
