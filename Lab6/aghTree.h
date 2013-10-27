/**
* \file aghTree.h
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 14.06.2013
* \version 1.0
* \brief Plik zawiera definicje klasy szablonowej aghTree
*/

#ifndef AGHTREE_H
#define AGHTREE_H

#include "aghContainer.h"
#include "aghException.h"
#include "aghWezel.h"

/**
* \class aghTree
* \author Izabela Śmietana & Krzysztof Spytkowski
* \date 14.06.2013
* \brief Definicja szablonowej klasy aghTree
*/
template <class W>
class aghTree : public aghContainer<W>
{
   private:
      int amount; ///< Ilosc obiektow
      aghWezel<W>* root; ///< Wskaźnik na korzeń drzewa
   public:
      /// \brief Konstruktor bezparametrowy klasy
      aghTree();     
      /// \brief Konstruktor kopiujący klasy
      ///
      /// \param model - Model pojemnika
      aghTree(const aghTree<W>& model);
      /// \brief Konstruktor kopiujący klasy (przyjmujący stałą referencje do klasy bazowej)
      ///
      /// \param model - Model pojemnika
      aghTree(const aghContainer<W>& model);
      /// \brief Destruktor klasy
      ~aghTree();
      /// \brief Funkcja przeszukująca drzewo inorder
      ///
      /// \param index - index poszukiwanego węzła
      /// \return Wskaźnik do węzła
      aghWezel<W>* inOrder(int index) const;
      /// \brief Funkcja szukająca węzła o minimalnym kluczu
      ///
      /// \param helper - początkowy węzeł
      /// \return Wskaźnik do węzła
      aghWezel<W>* minimumKey(aghWezel<W>* helper);
      /// \brief Funkcja szukająca następnika węzła
      ///
      /// \param helper - początkowy węzeł
      /// \return Wskaźnik do węzła
      aghWezel<W>* findSuccesor(aghWezel<W>* helper);
      /// \brief Przeładowany operator=
      ///
      /// \param model - Model pojemnika
      /// \return Referencja do this
      aghTree<W>& operator=(const aghTree<W>& model);
      /// \brief Czystko wirtualna funkcja wstawiająca element do drzewa
      ///
      /// \param index - Parametr ignorowany
      /// \param element - Nowy element
      /// \return Wrtość logiczna będącą miarą powodzenia operacji
      virtual bool insert(int index, W const& element);
      /// \brief Czystko wirtualna funkcja zwracająca wartość danego elementu w drzewie
      ///
      /// \param index - Index poszukiwanego elementu drzewa
      /// \return Poszukiwana wartość
      virtual W& at(int index) const;
      /// \brief Czystko wirtualna funkcja zwracająca ilosc elementow w drzewie
      ///
      /// \return Ilosc elementow w drzewie
      virtual int size(void) const;
      /// \brief Czystko wirtualna funkcja usuwająca element z drzewa
      ///
      /// \param index - Index elementu do usunięcia
      /// \return Wrtość logiczna będącą miarą powodzenia operacji
      virtual bool remove(int);
};
template<class W>
aghTree<W>::aghTree() : aghContainer<W>()
{
   amount = 0;
   root = NULL;
}
template<class W>
aghTree<W>::aghTree(const aghTree<W>& model) : aghContainer<W>(model)
{
   amount = 0;
   root = NULL;
   for(int i = 0; i < model.size(); i++)
      insert(0, model.at(i));
}
template<class W>
aghTree<W>::aghTree(const aghContainer<W>& model) : aghContainer<W>(model)
{
   amount = 0;
   root = NULL;
   for(int i = 0; i < model.size(); i++)
      insert(0, model.at(i));
}
template<class W>
aghTree<W>::~aghTree()
{  
   while (size() != 0)
      remove(0);
   root = NULL;
}
template<class W>
aghTree<W>& aghTree<W>::operator=(const aghTree<W>& model)
{
   (*this).aghContainer<W>::operator=(model); 
   return *this;
}
template<class W>
bool aghTree<W>::insert(int index, W const& element)
{
   aghWezel<W>* InsertNode = new aghWezel<W>();
   InsertNode->key = element;
   aghWezel<W>* helper2 = NULL;
   aghWezel<W>* helper = root;
   while (helper != NULL) 
   {
      helper2 = helper;
      if (InsertNode->key < helper->key)
         helper = helper->left;
      else
         helper = helper->right;
   }
   InsertNode->parent = helper2;
   if (helper2 == NULL) 
      root = InsertNode;
   else
      if (InsertNode->key < helper2->key)
         helper2->left = InsertNode;
      else
         helper2->right = InsertNode;
   amount++;
   return true;
}
template<class W>
aghWezel<W>* aghTree<W>::inOrder(int index) const {
   aghWezel<W>* current = root;
   aghWezel<W>* previous = NULL;
   int flag = -1;
   while (current) 
   {
      if (previous == current->parent)
      {
         previous = current;
         if (current->left) 
            current = current->left;
         else 
         {
            flag++;
            if (index == flag) 
               return current;
            if (current->right)
               current = current->right;
            else
               current = current->parent;
         }
      } 
      else if (previous == current->left) 
      { 
         previous = current;
         flag++;
         if (index == flag) 
            return current;
         if (current->right)
            current = current->right;
         else
            current = current->parent;
      } 
      else if (previous == current->right) 
      {
         previous = current;
         current = current->parent;
      }
   }
   return current;
}
template<class W>
W& aghTree<W>::at(int index) const
{
   if ((index < 0) || (index > size() - 1)) 
      throw aghException(0, "Podany index jest poza rozmiarem drzewa", __FILE__, __LINE__);
   return inOrder(index)->key;
}
template<class W>
int aghTree<W>::size(void) const
{
   return amount;
}
template<class W>
aghWezel<W>* aghTree<W>::minimumKey(aghWezel<W>* helper)
{
   while(helper->left != NULL) helper = helper->left;
   return helper;
}
template<class W>
aghWezel<W>* aghTree<W>::findSuccesor(aghWezel<W>* helper)
{
   if (helper->right != NULL) 
      return minimumKey(helper->right);
   aghWezel<W>* helper2 = helper->parent;
   while((helper2 != NULL) && (helper2->left != helper)) 
   {
      helper = helper2;
      helper2 = helper2->parent;
   }
   return helper2;
}
template<class W>
bool aghTree<W>::remove(int index)
{
   aghWezel<W>* helper, *helper2, *helper3;
   helper = inOrder(index);
   if ((helper->left == NULL) || (helper->right == NULL))
      helper2 = helper;
   else
      helper2 = findSuccesor(helper);
   if (helper2->left != NULL) 
      helper3 = helper2->left;
   else 
      helper3 = helper2->right;
   if (helper3 != NULL) 
      helper3->parent = helper2->parent;
   if (helper2->parent == NULL) 
      root = helper3;
   else if (helper2 == helper2->parent->left) 
      helper2->parent->left = helper3;
   else 
      helper2->parent->right = helper3;
   if (helper2 != helper) 
      helper->key = helper2->key;
   delete helper2;
   amount--;
   return true;
}

#endif
