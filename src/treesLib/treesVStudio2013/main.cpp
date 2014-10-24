#include <Training/trees/trees.hpp>

#include <iostream>
#include <string>

int main (){
  std::cout << "Hello World" << std::endl;
  trees::printTest();

  std::unique_ptr<trees::Node<std::string, trees::BinaryTreePolicy> > node(new trees::Node<std::string, trees::BinaryTreePolicy>("1"));
  node->add("2");
  node->add("3");
  node->add("4");
  node->add("5");
  node->add("6", false);
  node->add("7", false);
  node->add("8");
  node->add("9");
  trees::PreOrder(node.get());
  std::cout << std::endl;
  trees::InOrder(node.get());
  std::cout << std::endl;
  trees::PostOrder(node.get());
  std::cout << std::endl << std::endl;

  std::unique_ptr<trees::Node<int, trees::BinarySearchTreePolicy> > bstNode(new trees::Node<int, trees::BinarySearchTreePolicy>(8));
  bstNode->add(3);
  bstNode->add(10);
  bstNode->add(1);
  bstNode->add(6);
  bstNode->add(14);
  bstNode->add(4);
  bstNode->add(7);
  bstNode->add(13);
  trees::PreOrder(bstNode.get());
  std::cout << std::endl;
  trees::InOrder(bstNode.get());
  std::cout << std::endl;
  trees::PostOrder(bstNode.get());
  std::cout << std::endl << std::endl;

  std::unique_ptr<trees::Node<std::string, trees::BinarySearchTreePolicy> > bstNode2(new trees::Node<std::string, trees::BinarySearchTreePolicy>("8"));
  bstNode2->add("3");
  bstNode2->add("10");
  bstNode2->add("1");
  bstNode2->add("6");
  bstNode2->add("14");
  bstNode2->add("4");
  bstNode2->add("7");
  bstNode2->add("13");
  trees::PreOrder(bstNode2.get());
  std::cout << std::endl;
  trees::InOrder(bstNode2.get());
  std::cout << std::endl;
  trees::PostOrder(bstNode2.get());
  std::cout << std::endl << std::endl;


  return (0);
}