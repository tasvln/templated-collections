/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-10-01

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_ORDEREDCOLLECTION_H
#define SDDS_ORDEREDCOLLECTION_H

#include <iostream>
#include "Collection.h"

namespace sdds {
  template <typename T>
  class OrderedCollection : public Collection<T, 72> {
  public:
    // operator+=(): add an item to the collection and sort the collection
    bool operator+=(const T& item) {
      T temp;
      bool result = false;

      // add the item to the collection if the collection is not full
      if (this->size() < this->capacity()) {
        // call the base class operator+= to add the item to the array
        result = Collection<T, 72>::operator+=(item);
        
        // sort m_items in ascending order with bubble sort
        for (size_t i = 0; i < this->size() - 1; i++) {
          for (size_t j = 0; j < this->size() - i - 1; j++) {
            if ((*this)[j] > (*this)[j + 1]) {
              temp = (*this)[j];
              (*this)[j] = (*this)[j + 1];
              (*this)[j + 1] = temp;
            }
          }
        }
      }

      return result;
    }
  };
}

#endif