#ifndef __LINKEDLIST__HPP__
#define __LINKEDLIST__HPP__

#include <memory>

namespace linkedlist
{
template<class T>
class Node {
public:
  Node(){}
  Node(T const &pData) : data(pData) {}

  std::unique_ptr<Node<T> > next = nullptr;
  T data;
};


template<class T>
class List {
public:
  typedef Node<T>* iterator;
  List() : _size(0) {}
  List(T const &root);
  void push_back(T const &root);
  void erase(T const& value, int const &amount=-1);
  void removeDuplicates();
  iterator begin() { return _root.get(); }
  
private:
  std::unique_ptr<Node<T> > _root;
  std::size_t _size;
};

}

#include <Training\linkedlist\linkedlistImpl.hpp>

#endif