#include <sstream>
#include <iomanip>
#include "clothing.h"
using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) :
  Product(category, name, price, qty)
{
  size_ = size;
  brand_ = brand;
}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const
{
    
    set<std::string> names(parseStringToWords(name_));
    set<std::string> brands(parseStringToWords(brand_));
    set<std::string> ans(setUnion(names, brands));

    return ans;
}
std::string Clothing::displayString() const
{
    std::stringstream ss;
    
    ss << name_ + "\n";
    
    ss << "Size: " + size_ + " Brand: " + brand_ +  "\n";
    
    ss << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.\n";
    
    return ss.str();
}
void Clothing::dump(std::ostream& os) const
{
  Product::dump(os);
  os << size_ << endl;
  os << brand_ << endl;

}