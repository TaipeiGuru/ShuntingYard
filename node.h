#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node {
 public:
  Node(int value);
  ~Node();
  int getValue();
  void setNext(Node* newnext);
  Node* getNext();
 private:
  Node* next;
  int value;
};
#endif
