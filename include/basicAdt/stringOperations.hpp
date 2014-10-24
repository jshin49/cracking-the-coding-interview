#ifndef STRINGOPERATIONS__HPP__
#define STRINGOPERATIONS__HPP__

#include <string>

#include <boost/tuple/tuple.hpp>
#include <boost/iterator/zip_iterator.hpp>
#include <boost/range/iterator_range.hpp>

template<class... Conts>
auto zip_range(Conts&... conts)
  -> decltype(boost::make_iterator_range(
  boost::make_zip_iterator(boost::make_tuple(conts.begin()...)),
  boost::make_zip_iterator(boost::make_tuple(conts.end()...))))
{
  return {boost::make_zip_iterator(boost::make_tuple(conts.begin()...)),
          boost::make_zip_iterator(boost::make_tuple(conts.end()...))};
}

namespace basicAdt {

/*!
 *  Implement an algorithm to determine if a string
 *  has all unique characters. What if you can not use
 *  additional data structures
 */
bool AllUnique(std::string const &rhs);


/*!
 * Write code to reverse a C Style String
 */
void Reverse(char *str);

/*!
 * Design an algorithm and write code to remove the duplicate
 * characters in a string without using any additional buffer
 */
void RemoveDuplicate(std::string &rhs);

/*!
 * Given two strings, write a method to decide if one is a permutation of the other.
 */
bool IsPermutation(std::string const &lhs, std::string const &rhs);

/*!
* Write a method to replace all spaces in a string with'%20'. You may assume that
* the string has sufficient space at the end of the string to hold the additional
* characters, and that you are given the "true" length of the string.
*/
void encodeSpacesStringNoFindNoInsert(std::string &rhs);
void encodeSpacesStringFind(std::string &rhs);

/*! Implement a method to perform basic string compression using the counts
 * of repeated characters. For example, the string aabcccccaaa would become
 * a2blc5a3. If the "compressed" string would not become smaller than the orig-
 * inal string, your method should return the original string.
 */
std::string compressWord(std::string const &rhs);

/*!Assume you have a method isSubstring which checks if one word is a
 * substring of another. Given two strings, si and s2, write code to check if s2 is
 * a rotation of s1 using only one call to isSubstring (e.g.,"waterbottle"is a rota-
 * tion of "erbottlewat"
*/
class IsRotation {
  bool isSubstring(std::string const &lhs, std::string const &rhs);
public:
  bool check(std::string const &lhs, std::string const &rhs);
};
}

#endif