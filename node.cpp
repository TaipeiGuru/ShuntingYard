#include "node.h"
#include <iostream>

using namespace std;

Node::Node(int myValue) {
  next = NULL;
  value = myValue;
}

Node::~Node() {
  next = NULL;
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

Node* Node::getRight() {
  return rightChild; 
}

Node* Node::getLeft() {
  return leftChild; 
}

void Node::setRight(Node* right) {
  rightChild = right; 
}

void Node::setLeft(Node* left) {
  leftChild = left; 
}
void Node::setPrecedence(int value) {
  precedence = value;
}
