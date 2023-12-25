#include <sstream>
#include <iomanip>
#include "book.h"
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author) :
  Product(category, name, price, qty)
{
  isbn_ = isbn;
  author_ = author;
}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
  
  set<std::string> names(parseStringToWords(name_));
  set<std::string> authors(parseStringToWords(author_));

  set<std::string> ans(setUnion(names, authors));

  ans.insert(isbn_);

  return ans;

}
std::string Book::displayString() const
{
    std::stringstream ss;
    
    ss << name_ + "\n";
    
    ss << "Author: " + author_ + " ISBN: " + isbn_ + "\n";
    
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.\n";
    
    return ss.str();
}
void Book::dump(std::ostream& os) const
{
  Product::dump(os);
  os << isbn_ << endl;
  os << author_ << endl;

}