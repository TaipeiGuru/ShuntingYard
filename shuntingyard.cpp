#include <iostream>
#include <cstring>
#include <ctype.h>
#include "node.h"

using namespace std;

void pushStack(Node* &stackHead, int value, int precedence);
Node* popStack(Node* &stackHead);
Node* peekStack(Node* stackhead);
void enqueueQueue(Node* &queueHead, Node* newNode);
Node* dequeueQueue(Node* &queueHead);
void readQueue(Node* queueHead);
void infixToPostfix(char* expression, Node* &stackHead, Node* &queueHead);
void createTree(Node* &treeStackHead, Node* queueHead);

int main() { 
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  Node* treeStackHead = NULL;
  char input[20];
  char expression[50];

  cout << "Welcome to Shunting Yard!" << endl;
  
  // Standard repeating message sequence using bool and while loop.
  bool active = true;
  while(active == true) {
    cout << "Please input your expression in infix notation: " << endl;
    cin.get(expression, 50);
    cin.clear();
    cin.ignore(10000, '\n');
    infixToPostfix(expression, stackHead, queueHead);
    cout << "\nWhich notation would you like to output? Your options are \"INFIX,\" \"PREFIX,\" and \"POSTFIX.\" You may also \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    
    if(strcmp(input, "PREFIX") == 0) {
      printPrefix(treeStackHead);
    } else if(strcmp(input, "POSTFIX") == 0) {
      printPostfix(treeStackHead);
    } else if(strcmp(input, "INFIX") == 0) {
      printInfix(treeStackHead);
    } else if(strcmp(input, "QUIT") == 0) {
      active = false; 
    } else {
      cout << "Sorry, invalid input." << endl; 
    }
  }
  return 0;
}

void pushStack(Node* &stackHead, int value, int precedence) {
  if(stackHead == NULL) {
    stackHead = new Node(value);
    stackHead->setPrecedence(precedence);
  } else {
    Node* tempNode = new Node(value);
    tempNode->setPrecedence(precedence);
    tempNode->setNext(stackHead);
    stackHead = tempNode;
  }
}

Node* popStack(Node* &stackHead) {
  if(stackHead == NULL) {
    return NULL;
  } else {
    Node* tempNode = stackHead;
    stackHead = stackHead->getNext();
    tempNode->setNext(NULL);
    return tempNode;
  }
}

Node* peekStack(Node* stackHead) {
  if(stackHead == NULL) {
    return NULL;
  } else {
    return stackHead; 
  }
}

void enqueueQueue(Node* &queueHead, Node* newNode) {
  if(queueHead == NULL) {
    queueHead = newNode;
    newNode->setNext(NULL);
  } else {
    if(queueHead->getNext() == NULL) {
      queueHead->setNext(newNode);
    } else {
      Node* tempNode = queueHead->getNext();
      enqueueQueue(tempNode, newNode);
    }
  }
}

Node* dequeueQueue(Node* &queueHead) {
  if(queueHead == NULL) {
    return NULL;
  } else {
    Node* tempNode = queueHead;
    queueHead = queueHead->getNext();
    tempNode->setNext(NULL);
    return tempNode;
  }
}

void infixToPostfix(char* expression, Node* &stackHead, Node* &queueHead) {
  int arraySize = strlen(expression);
  for(int i = 0; i < arraySize; i++) {
    if(expression[i] == '+') {
      while(peekStack(stackHead) != NULL && peekStack(stackHead)->getPrecedence() >= 1 && peekStack(stackHead)->getValue() != -6) {
	enqueueQueue(queueHead, popStack(stackHead));
      }
      pushStack(stackHead, -1, 1);
    } else if(expression[i] == '-') {
      while(peekStack(stackHead) != NULL && peekStack(stackHead)->getPrecedence() >= 1 && peekStack(stackHead)->getValue() != -6) {
	enqueueQueue(queueHead, popStack(stackHead));
      }
      pushStack(stackHead, -2, 1);      
    } else if(expression[i] == '*') {
      while(peekStack(stackHead) != NULL && peekStack(stackHead)->getPrecedence() >= 2 && peekStack(stackHead)->getValue() != -6) {
	enqueueQueue(queueHead, popStack(stackHead));
      }
      pushStack(stackHead, -3, 2);      
    } else if(expression[i] == '/') {
      while(peekStack(stackHead) != NULL && peekStack(stackHead)->getPrecedence() >= 2 && peekStack(stackHead)->getValue() != -6) {
	enqueueQueue(queueHead, popStack(stackHead));
      }
      pushStack(stackHead, -4, 2);      
    } else if(expression[i] == '^') {
      while(peekStack(stackHead) != NULL && peekStack(stackHead)->getPrecedence() >= 3 && peekStack(stackHead)->getValue() != -6) {
	enqueueQueue(queueHead, popStack(stackHead));
      }
      pushStack(stackHead, -5, 3);      
    } else if(expression[i] == '(') {
      pushStack(stackHead, -6, 4);      
    } else if(expression[i] == ')') {
      while(peekStack(stackHead)->getValue() != -6) {
	cout << peekStack(stackHead)->getValue() << endl;
        enqueueQueue(queueHead, popStack(stackHead)); 
      }
      popStack(stackHead);
    } else if (isdigit(expression[i]) == true) {
      int value = expression[i] - 48;
      Node* newNode = new Node(value);
      newNode->setPrecedence(0);
      enqueueQueue(queueHead, newNode);
    }
  }
  while(stackHead != NULL) {
    enqueueQueue(queueHead, popStack(stackHead));
  }
  cout << "Postfix notation: ";
  readQueue(queueHead);
  createTree();
}

void readQueue(Node* queueHead) {
  if(queueHead != NULL) {
    if(queueHead->getValue() == -1) {
      cout << "+"; 
    } else if(queueHead->getValue() == -2) {
      cout << "-"; 
    } else if(queueHead->getValue() == -3) {
      cout << "*"; 
    } else if(queueHead->getValue() == -4) {
      cout << "/"; 
    } else if(queueHead->getValue() == -5) {
      cout << "^"; 
    } else if(queueHead->getValue() == -6) {
      cout << "("; 
    } else if(queueHead->getValue() == -7) {
      cout << ")"; 
    } else {
      cout << queueHead->getValue();
    }
    cout << " ";
    readQueue(queueHead->getNext());
  }
}

void createTree(Node* &treeStackHead, Node* queueHead) {
  Node* tempNode;
  while(queueHead != NULL) {
    tempNode = dequeueQueue(queueHead);
    if(tempNode->getValue() >= 0) {
      pushStack(treeStackHead, tempNode->getValue(), 0);
    } else {
      tempNode->setRightChild(popStack(treeStackHead));
      tempNode->setLeftChild(popStack(treeStackHead));
      pushStack(treeStackHead, tempNode->getValue(), tempNode->getPrecedence());
    }
  }
}

/*printInfix(Node* treeStackHead) {
  if (treeHead != NULL) {
    if (tree token is operator)
       print (open parenthesis)
    end if
    infix (tree left subtree)
    print (tree token)
    infix (tree right subtree)
    if (tree token is operator)
       print (close parenthesis)
    end if
  }
}
*/
