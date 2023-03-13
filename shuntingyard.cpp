#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

void pushStack(Node* newNode);
Node* popStack();
void peekStack();
enqueueQueue(Node* queueHead, Node* newNode);
dequeueQueue();

int main() { 
  Node* stackHead = NULL;
  Node* treeHead = NULL;
  char input[20];
  char expression[20];

  cout << "Welcome to Shunting Yard!" << endl;
  
  // Standard repeating message sequence using bool and while loop.
  bool active = true;
  while(active == true) {
    cout << "Please input your expression in infix notation: " << endl;
    cin >> expression;
    cin.clear();
    cin.ignore(10000, '\n');
    infixToPostfix(expression, stackHead);
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

void pushStack(Node* &stackhead, int value, int precedence) {
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
  Node* tempNode = stackHead;
  stackHead = stackHead->getNext();
  tempNode->setNext(NULL);
  return tempNode;
}

Node* peekStack(Node* stackHead) {
 
}

void enqueueQueue(Node* &queueHead, Node* newNode) {
  if(newNode->getNext() == NULL) {
    newNode->setNext(newNode);
  } else {
    enqueueQueue(queueHead->getNext(), newNode);  
  }
}

Node* dequeueQueue(Node* &queueHead) {
  
}

infixToPostfix(char* expression, Node* &stackHead, Node* &queueHead) {
  int arraySize = sizeof(expression)/sizeof(expression[0]);
  for(int i = 0; i < arraySize; i++) {
    if(expression[i] == ' ') {
      i++; 
    } else if(expression[i] == '+') {
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
      while(peekStack()->getValue() != -6) {
        enqueueQueue(queueHead, popStack(stackHead)); 
      }
      popStack(stackHead);
    } else {
      Node* newNode = new Node((int)expression[i]);
      newNode->setPrecedence(0);
      enqueueQueue(queueHead, newNode);
    }
    
  }
  
  
  || expression[i] == "-" || expression[i] == "/" || expression[i] == "*" || expression[i] == "^" || expression[i] == "(" || expression[i] == ")") {
}

createTree(Node* treeHead, char* expression) {
  
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
