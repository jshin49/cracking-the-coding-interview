#ifndef __LINKEDLISTIMPL__HPP__
#define __LINKEDLISTIMPL__HPP__

#include <map>

namespace linkedlist
{

template<class T>
List<T>::List(T const &root) : _size(1) {
  _root.reset(new Node<T>(root));
}

template<class T>
void List<T>::push_back(T const &val) {
  if (_root == nullptr) {
    _root.reset(new Node<T>(val));
    _size++;
  }
  else {
    auto current = begin();
    while (current->next != nullptr) {
      current = current->next.get();
    }
    current->next.reset(new Node<T>(val));
    _size++;
  }
}

template<class T>
void List<T>::erase(T const& value, int const &amount) {
  int count{ 0 };
  if (_root == nullptr) return;
  iterator current = begin(), previous = nullptr;
  while (current != nullptr) {
    if (count == amount) return;
    if (current->data != value){
      previous = current;
    }
    else {
      if (previous == nullptr){
        _root = std::move(_root->next);
        current = begin();
      } else {
        previous->next = std::move(current->next);
        current = previous;
      }
      _size--; count++;
    }
    if (previous != nullptr)
      current = current->next.get();
  }
}

template<class T>
void List<T>::removeDuplicates(){
  if (_root == nullptr) return;
  typename std::map<T, bool> elements;
  iterator current = begin(), previous{ nullptr };
  while (current != nullptr) {
    if (elements.find(current->data) == elements.end()){
      elements[current->data] = true;
      previous = current;
    }
    else {
      previous->next = std::move(current->next);
      _size--;
      current = previous;
    }
    current = current->next.get();
  }
}

}

#endif