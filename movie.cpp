#include <sstream>
#include <iomanip>
#include "movie.h"
using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
  Product(category, name, price, qty)
{
  genre_ = genre;
  rating_ = rating;
}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
  
  std::set<std::string> one(parseStringToWords(name_));
  std::set<std::string> genres(parseStringToWords(genre_));
  set<std::string> ans(setUnion(one, genres));
  
  return ans;
}
std::string Movie::displayString() const
{

    std::stringstream ss;
    ss << name_ + "\n";
    
    ss << "Genre: " + genre_ + " Rating: " + rating_ + "\n";
    
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.\n";
    
    return ss.str();
}
void Movie::dump(std::ostream& os) const
{

  Product::dump(os);
  os << genre_ << endl;
  os << rating_ << endl;

}