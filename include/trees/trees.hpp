#ifndef __TREES__HPP__
#define __TREES__HPP__

#include <memory>
#include <utility>
#include <string>
#include <iostream>
#include <sstream>
#include <functional>

namespace trees 
{
void printTest();

template<class T, class NodeType>
class BinaryTreePolicy {
public:
  bool add(T element, NodeType &parent, bool direction=true){
    if (parent.left == nullptr) {
      parent.left.reset(new NodeType(element));
    } 
    else if(parent.right == nullptr) {
      parent.right.reset(new NodeType(element));
    } else {
      if (direction){
        parent.left->add(element);
      } else {
        parent.right->add(element);
      }
    }
    return true;
  }
};

template<class T, class NodeType >
class BinarySearchTreePolicy {
public:
  bool add(T element, NodeType &parent, bool direction = true){
    if (element == parent.data)
      return false;
    std::less< T > comp;
    if (comp(element, parent.data)) {
      if (parent.left == nullptr){
        parent.left.reset(new NodeType(element));
        return true;
      } else {
        return parent.left->add(element);
      }
    }
    else if (comp(parent.data, element)){
      if (parent.right == nullptr){
        parent.right.reset(new NodeType(element));
        return true;
      } else {
        return parent.right->add(element);
      }
    }
    return false;
  }
};

template<class T, template <typename, typename> class Policy >
class Node {
  typename Policy<T, Node<T, Policy> > policy;

public:
  Node(T element) : data(std::move(element)) {}
  bool add(T element, bool direction = true){
    return policy.add(std::move(element), *this, direction);
  }
  T data;
  std::unique_ptr<Node<T,Policy> > left;
  std::unique_ptr<Node<T, Policy> > right;
};

template<class T>
class Print{
public:
  Print(T const &rhs){
    std::stringstream ss("");
    ss << rhs;
    std::cout << ss.str() << ",";
  }
};

template< class T,
  template <typename, typename>  class Y,
  typename Function = Print<typename T> >
void PreOrder(Node<T, Y> *node){
  if (node == nullptr) 
    return;
  Function fn(node->data);
  PreOrder(node->left.get());
  PreOrder(node->right.get());
}

template< class T, 
          template <typename, typename>  class Y, 
          typename Function = Print<typename T> >
void InOrder(Node<T, Y> *node){
  if (node == nullptr)
    return;
  InOrder(node->left.get());
  Function fn(node->data);
  InOrder(node->right.get());
}

template< class T,
  template <typename, typename>  class Y,
  typename Function = Print<typename T> >
void PostOrder(Node<T, Y> *node){
  if (node == nullptr)
    return;
  PostOrder(node->left.get());
  PostOrder(node->right.get());
  Function fn(node->data);
}

}

#endif