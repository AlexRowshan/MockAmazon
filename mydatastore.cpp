#include "mydatastore.h"
#include "util.h"
using namespace std;

Mydatastore::Mydatastore()
{

}

Mydatastore::~Mydatastore()
{

  for(int i = 0; i < products_.size(); i++)
  {
    delete products_[i];
  }

  for(std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
  {
    delete (it->second);
  }
}

void Mydatastore::addProduct(Product* p)
{
  products_.push_back(p);
  std::set<string> keyAdds = p->keywords();

  for(std::set<string>::iterator it = keyAdds.begin(); it != keyAdds.end(); ++it)
  {
    keywords_[*it].insert(p);
  }
}

void Mydatastore::addUser(User* u)
{
  string name = u->getName();
  users_[name] = u;
}

std::vector<Product*> Mydatastore::search(std::vector<std::string>& terms, int type)
{
  std::vector<Product*> products;
  std::set<Product*> move;
  //cout << "TERM 1:" << terms[0] << " term 2:" << terms[1] << endl;

  /*for(std::map<std::string, std::set<Product*> >::iterator it = keywords_.begin(); it != keywords_.end(); ++it) 
  {
      std::cout << "Term:" << it->first << std::endl;
  }*/


  if(terms.size() == 0)
  {
    return products;
  }
  else
  {
    for(int i = 0; i < terms.size(); i++)
    {
      if(keywords_.find(terms[i]) != keywords_.end())
      {
        //cout << "Found " << endl;
        if(move.size() == 0)
        {
          move = keywords_[terms[i]];
        }
        if(type == 1)
        {
          move = setUnion(move, keywords_[terms[i]]);
        }
        else
        {
          move = setIntersection(move, keywords_[terms[i]]);
        }
      }
      else
      {
        //cout << "Term not found " << endl;
      }
    }
  }
    for(std::set<Product*>::iterator it = move.begin(); it != move.end(); ++it)
    {
      products.push_back(*it);
    }
  
  return products;
}

void Mydatastore::dump(std::ostream& ofile)
{
  ofile << "<products>" << endl;
  for(int i = 0; i < products_.size(); i++)
  {
    products_[i]->dump(ofile);
  }

  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  for(std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
  {
    (it->second)->dump(ofile);
  }
  ofile << "</users>" << endl;
}

void Mydatastore::addCart(std::string username, Product* p)
{

  if(users_.find(username) == users_.end())
  {
    cout << "Invalid request" << endl;
  }
  else
  {
    cart_[username].push_back(p);
  }
}

void Mydatastore::viewCart(std::string username)
{
  if(users_.find(username) == users_.end())
  {
    cout << "Invalid request" << endl;
  }
  else
  {
    for(int i = 0; i < cart_[username].size(); i++)
    {
      cout << "Item " << (i + 1) << endl;
      cout << (cart_[username][i])->displayString() << endl;
      cout << endl;
    }
  }
}

void Mydatastore::buyCart(std::string username)
{
  vector<Product*> temp;
  if(users_.find(username) == users_.end())
  {
    cout << "Invalid username" << endl;
  }
  else
  {
    for(int i = 0; i < cart_[username].size(); i++)
    {
      if(((cart_[username][i])->getQty() > 0) && ((users_[username])->getBalance() >= cart_[username][i]->getPrice()))
      {
        cart_[username][i]->subtractQty(1);
        (users_[username])->deductAmount(cart_[username][i]->getPrice());

      }
      else {
          temp.push_back(cart_[username][i]);
      }
    }
  }
  if (temp.size() > 0){
    cart_[username] = temp;
    
  }
  else {
    cart_.erase(username);
  }
}

bool Mydatastore::isValidUser(std::string username)
{
  std::map<std::string, User*>::iterator it = users_.find(username);
  if(it != users_.end())
  {
   return true;
  }
  return false;
}