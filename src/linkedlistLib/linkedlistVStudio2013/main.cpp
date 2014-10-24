#include <Training/linkedlist/linkedlist.hpp>

#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
  linkedlist::List<std::string> list;
  list.push_back("10");
  list.push_back("10");
  list.push_back("5");
  list.push_back("10");
  list.push_back("10");
  list.push_back("7");
  list.push_back("10");
  list.push_back("15");
  list.push_back("10");
  list.push_back("10");

  list.erase("10");
  for (auto it = list.begin(); it != nullptr; it = it->next.get()) {
    std::cout << it->data << std::endl;
  }
  
  return 0;
}