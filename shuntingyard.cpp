#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void pushStack(Node* &stackHead, int value, int precedence);
Node* popStack(Node* &stackHead);
Node* peekStack(Node* stackhead);
void enqueueQueue(Node* &queueHead, Node* newNode);
Node* dequeueQueue(Node* &queueHead);
void readQueue(Node* queueHead);
void infixToPostfix(char* expression, Node* &stackHead, Node* &queueHead);

int main() { 
  Node* stackHead = NULL;
  Node* queueHead = NULL;
  char input[20];
  char expression[20];

  cout << "Welcome to Shunting Yard!" << endl;
  
  // Standard repeating message sequence using bool and while loop.
  bool active = true;
  while(active == true) {
    cout << "Please input your expression in infix notation: " << endl;
    cin.get(expression, 20);
    cin.clear();
    cin.ignore(10000, '\n');
    infixToPostfix(expression, stackHead, queueHead);
    cout << "\nWhich notation would you like to output? Your options are \"INFIX,\" \"PREFIX,\" and \"POSTFIX.\" You may also \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    
    if(strcmp(input, "PREFIX") == 0) {

    } else if(strcmp(input, "POSTFIX") == 0) {
      
    } else if(strcmp(input, "INFIX") == 0) {

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
    cout << "There's nothing in the stack." << endl;
  } else {
    Node* tempNode = stackHead;
    stackHead = stackHead->getNext();
    tempNode->setNext(NULL);
    return tempNode;
  }
}

Node* peekStack(Node* stackHead) {
 if(stackHead == NULL) {
  cout << "There's nothing in the stack." << endl; 
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
    cout << "There's nothing in the queue." << endl;
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
      pushStack(stackHead, -1, 1);
    } else if(expression[i] == '-') {
      pushStack(stackHead, -2, 1);      
    } else if(expression[i] == '*') {
      pushStack(stackHead, -3, 2);      
    } else if(expression[i] == '/') {
      pushStack(stackHead, -4, 2);      
    } else if(expression[i] == '^') {
      pushStack(stackHead, -5, 3);      
    } else if(expression[i] == '(') {
      pushStack(stackHead, -6, 4);      
    } else if(expression[i] == ')') {
      while(peekStack(stackHead)->getValue() != -6) {
        enqueueQueue(queueHead, popStack(stackHead)); 
      }
      popStack(stackHead);
    } else if (expression[i] != ' ') {
      int value = expression[i] - 48;
      Node* newNode = new Node(value);
      newNode->setPrecedence(0);
      enqueueQueue(queueHead, newNode);
    }
  }
  while(stackHead != NULL) {
    enqueueQueue(queueHead, popStack(stackHead));
  }
  readQueue(queueHead);
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

/*createTree(Node* treeHead, char* expression) {
  
}

printInfixTree(Node* treehead) {
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
