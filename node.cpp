#include "node.h"
#include <iostream>

using namespace std;

Node::Node(int myValue) {
  next = NULL;
  value = myValue;
}

Node::~Node() {
  next = NULL;
  delete value;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node* Node::getNext() {
  return next;
}

int Node::getValue() {
  return value;
}
