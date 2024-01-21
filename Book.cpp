/*
  Name: Temitope Oladimeji Samuel Adebayo
  Date: 2023-09-30

  I have done all the coding by myself and only copied the code that my professor provided 
  to complete my workshops and assignments.
*/

#include <iomanip>
#include "Book.h"

using namespace std;

namespace sdds {
  // three arguments constructor
  Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) {
    m_title = title;
    m_numChapters = nChapters;
    m_numPages = nPages;
  }

  // isEmpty(): to verify if the Book is valid
  bool Book::isEmpty() const {
    return m_title.empty() || m_numChapters == 0 || m_numPages == 0;
  }

  // operator < and > overloads to compare the average number of pages per chapter
  bool Book::operator<(const Book& book) const {
    // compare the average number of pages per chapter
    return (double)m_numPages / m_numChapters < (double)book.m_numPages / book.m_numChapters;
  }

  bool Book::operator>(const Book& book) const {
    // compare the average number of pages per chapter
    return (double)m_numPages / m_numChapters > (double)book.m_numPages / book.m_numChapters;
  }

  // print(): to print the Book information
  std::ostream& Book::print(std::ostream& os) const {
    // set the width of the output
    size_t bookRightWidth = 56;
    size_t bookLeftWidth = 15;

    // calculate the average number of pages per chapter
    double average = (double)m_numPages / m_numChapters;

    // print the Book information
    if (!isEmpty()) {
      os << right << setw(bookRightWidth) << (m_title + ',' + to_string(m_numChapters) + ',' + to_string(m_numPages));
      os << " | " << left << std::setw(bookLeftWidth) << ('(' + std::to_string(average) + ')');

    } else {
      os << "| Invalid book data";
    }

    return os;
  }

  std::ostream& operator<<(std::ostream& os, const Book& bk) {
    bk.print(os);
    return os;
  }
}