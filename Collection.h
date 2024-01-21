/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-09-30

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include "Book.h"

namespace sdds {
  template <typename T, unsigned C>
  class Collection {
    T m_items[C]{};
    size_t m_size{};
    static T m_smallestItem;
    static T m_largestItem;

  protected:
    // setSmallestItem() and setLargestItem() to set the smallest and largest items in the collection
    void setSmallestItem(const T& item) {
      if (item < m_smallestItem) {
        m_smallestItem = item;
      }
    }

    void setLargestItem(const T& item) {
      if (item > m_largestItem) {
        m_largestItem = item;
      }
    }
  public:
    // static member functions
    static T getSmallestItem();

    static T getLargestItem();

    // size(): to return the number of items in the collection
    size_t size() const {
      return m_size;
    }

    // capacity(): to return the capacity of the collection
    unsigned capacity() const {
      return C;
    }

    // operator+=(): to add an item to the collection
    bool operator+=(const T& item) {
      bool result = false;

      // add the item to the collection if the collection is not full
      if (size() < capacity()) {
        setSmallestItem(item);
        setLargestItem(item);

        // add the item to the collection
        m_items[m_size++] = item;

        result = true;
      }

      return result;
    }
    
    std::ostream& print(std::ostream& os) const {
      os << '[';
      
      for (size_t i = 0; i < size(); i++) {
        os << m_items[i];
        if (i < size() - 1) {
          os << ',';
        }
      }
      os << ']' << std::endl;

      return os;
    }

    // operator[](): to return the item at the index received as parameter
    T& operator[](size_t index) {
      return m_items[index];
    }

    // incrSize(): to increment the size of the collection
    void incrSize() {
      m_size++;
    }
  };

  // static data members
  template <typename T, unsigned C>
  T Collection<T, C>::m_smallestItem = 9999;

  template <typename T, unsigned C>
  T Collection<T, C>::m_largestItem = -9999;

  template <typename T, unsigned C>
  T Collection<T, C>::getSmallestItem() {
    return m_smallestItem;
  }

  template <typename T, unsigned C>
  T Collection<T, C>::getLargestItem() {
    return m_largestItem;
  }

  // Template Specializations
	template <>
	Book Collection<Book, 10>::m_smallestItem = Book("", 1, 1000);

	template <>
	Book Collection<Book, 10>::m_largestItem = Book("", 1000, 1);

  template <>
  std::ostream& Collection<Book, 10>::print(std::ostream& os) const {
    os << "| ---------------------------------------------------------------------------|" << std::endl;
    for (auto i = 0u; i < size(); i++) {
      os << "| " << m_items[i] << " |" << std::endl;
    }
    os << "| ---------------------------------------------------------------------------|" << std::endl;
    return os;
  }

  template <>
  Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

  template <>
  Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

  template <>
  std::ostream& Collection<Book, 72>::print(std::ostream& os) const {
    os << "| ---------------------------------------------------------------------------|" << std::endl;
    for (auto i = 0u; i < size(); i++) {
      os << "| " << m_items[i] << " |" << std::endl;
    }
    os << "| ---------------------------------------------------------------------------|" << std::endl;
    return os;
  }
}

#endif