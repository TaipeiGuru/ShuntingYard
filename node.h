#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node {
 public:
  Node(int myValue);
  ~Node();
  int getValue();
  void setNext(Node* newnext);
  Node* getNext();
  Node* getLeft();
  Node* getRight();
  void setRight(Node* right);
  void setLeft(Node* left);
  void setPrecedence(int value);
  int getPrecedence();
 private:
  Node* next;
  Node* rightChild;
  Node* leftChild;
  int value;
  int precedence;
};
#endif
