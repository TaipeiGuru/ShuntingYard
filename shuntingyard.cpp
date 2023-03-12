#include <iostream>
#include <cstring>

using namespace std;

void pushStack(Node* newNode);
Node* popStack();
void peekStack();
enqueueQueue();
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

void pushStack(Node* &newNode, int value) {
  if(newNode == NULL) {
    newNode = new Node(value);
  } else if(newNode->getNext() == NULL) {
    Node* tempNode = new Node(value);
    newNode->setNext(tempNode);
  } else {
    addStudent(newNode->getNext(), value);  
  }
}

Node* popStack() {
 
}

void peekStack() {
 
}

enqueueQueue(Node* newNode) {
 
}

Node* dequeueQueue() {
 
}

infixToPostfix(char* expression, Node* &stackHead) {
  char output[20];
  for(int h = 0; h < 20; h++) {
    output[h] = 'z';  
  }
  int arraySize = sizeof(expression)/sizeof(expression[0]);
  for(int i = 0; i < arraySize; i++) {
    if(expression[i] == ' ') {
      i++; 
    } else if(expression[i] == '+') {
      pushStack(stackHead, -1);
    } else if(expression[i] == '-') {
      pushStack(stackHead, -2);      
    } else if(expression[i] == '*') {
      pushStack(stackHead, -3);      
    } else if(expression[i] == '/') {
      pushStack(stackHead, -4);      
    } else if(expression[i] == '^') {
      pushStack(stackHead, -5);      
    } else if(expression[i] == '(') {
      pushStack(stackHead, -6);      
    } else if(expression[i] == ')') {
      Node* myNode = popStack(stackHead);
      if(myNode->getValue() == -1) {
        
      } else if(myNode->getValue() == -2) {
        
      } else if(myNode->getValue() == -3) {
        
      } else if(myNode->getValue() == -4) {
        
      } else if(myNode->getValue() == -5) {
        
      }
    } else {
      int j = 0;
      while(output[j] == 'z') {
        j++; 
      }
      output[j] = expression[i];
      output[j+1] = ' ';
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
