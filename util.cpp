#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}


std::set<std::string> parseStringToWords(string rawWords)
{
  std::set<std::string> myWords;

  int twoStopCount = 0;
  int firstGoodI = 0;

  for(int i = 0; i < rawWords.length(); i++)
  {
    char ch = rawWords[i];
    //this if is supposed catch ch at a non digit, letter, or space
    if((ch < 48) || (ch > 57 && ch < 65) || (ch > 90 && ch < 97) || (ch > 122))
    {
      if(twoStopCount >= 2)
      {
        std::string add = rawWords.substr (firstGoodI,twoStopCount);
        add = trim(add);
        add = convToLower(add);
        myWords.insert(add);
      }

      if(rawWords[i + 1] == 32)
      {
        firstGoodI = i + 2;
      }
      else
      {
        firstGoodI = i + 1;
      }
      twoStopCount = 0;
    }
    else
    {
      twoStopCount++;
    }
  }

  if(twoStopCount >= 2)
  {
    std::string add = rawWords.substr (firstGoodI,twoStopCount);
    add = trim(add);
    add = convToLower(add);
    myWords.insert(add);
  }

  return myWords;
}

std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
