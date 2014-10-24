#include <Training/algorithms/algorithms.hpp>

#include <iostream>
#include <sstream>
#include <algorithm>

namespace algorithms 
{
void printTest() {
  std::cout << "This is the Algorithms library" << std::endl;
}

Manacher::Manacher(std::string const&rhs) : originalString(rhs) {
  this->transformedString = PreProcess(rhs);
  int center = 0, right = 0;
  this->longestPalindromicString.resize(transformedString.size());
  for (int i = 1; i != transformedString.size() - 1; ++i) {
    int mirror = 2 * center - i;
    if (right > i) {
      longestPalindromicString[i] = std::min(right - i, longestPalindromicString[mirror]);
    }

    while (transformedString[i + (1 + longestPalindromicString[i])] == transformedString[i - (1 + longestPalindromicString[i])])
      longestPalindromicString[i]++;

    if (i + longestPalindromicString[i] > right) {
      center = i;
      right = i + longestPalindromicString[i];
    }

  }
}

std::string Manacher::PreProcess(std::string const &rhs){
  std::stringstream ss("");
  ss << '$';
  for (auto it = rhs.begin(); it != rhs.end(); ++it){
    ss << '#' << *it;
  }
  ss << '#' << '@';
  return ss.str();
}

std::string Manacher::LongestPalindromicSubString(){
  int length = 0;   // length of longest palindromic substring
  int center = 0;   // center of longest palindromic substring
  for (int i = 1; i != longestPalindromicString.size() - 1; ++i) {
    if (longestPalindromicString[i] > length) {
      length = longestPalindromicString[i];
      center = i;
    }
  }
 
  return std::string(originalString.begin()+(center - 1 - length) / 2, originalString.begin()+(center - 1 + length) / 2);
}

std::string Manacher::LongestPalindromicSubString(int const &i){
  int li = i + 2;
  int length = longestPalindromicString[li];
  int center = li;
  return std::string(originalString.begin() + (center - 1 - length) / 2, originalString.begin() + (center - 1 + length) / 2);
}

}
