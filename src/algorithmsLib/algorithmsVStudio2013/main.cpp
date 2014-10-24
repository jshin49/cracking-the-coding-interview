#include <Training/algorithms/algorithms.hpp>

#include <iostream>

int main (){
  std::cout << "Hello World" << std::endl;
  algorithms::printTest();

  algorithms::Manacher manach("civicradarrevivermalayalammadamnoon");
  std::cout << manach.LongestPalindromicSubString() << std::endl;
  return (0);
}