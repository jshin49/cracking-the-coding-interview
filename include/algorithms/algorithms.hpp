#ifndef __ALGORITHMS__HPP__
#define __ALGORITHMS__HPP__

#include <vector>
#include <string>

namespace algorithms 
{
void printTest();

class Manacher{
public:
  Manacher(std::string const&rhs);
  std::string PreProcess(std::string const &rhs);
  std::string LongestPalindromicSubString();
  std::string LongestPalindromicSubString(int const &i);

private:
  std::vector<int> longestPalindromicString;
  std::string transformedString;
  std::string originalString;
};

}


#endif