#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>



template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> ans;

  for(typename std::set<T>::iterator it1 = s1.begin(); it1 != s1.end(); ++it1)
  {
    typename std::set<T>::iterator it2 = s2.find(*it1);
      
    if(it2 != s2.end())
    {
      ans.insert(*it1);
    }
  }
  return ans;
  
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> ans;
   for(typename std::set<T>::iterator it1 = s1.begin(); it1 != s1.end(); ++it1)
   {
     ans.insert(*it1);
   }
   for(typename std::set<T>::iterator it2 = s2.begin(); it2 != s2.end(); ++it2)
   {
     ans.insert(*it2);
   }
   return ans;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
