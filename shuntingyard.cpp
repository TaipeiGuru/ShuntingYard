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

void pushStack(Node* newNode) {
 
}

Node* popStack() {
 
}

void peekStack() {
 
}

enqueueQueue(Node* newNode) {
 
}

Node* dequeueQueue() {
 
}

infixToPostfix(char* expression, Node* stackHead) {
  char output[20];
  int arraySize = sizeof(expression)/sizeof(expression[0]);
  for(int i = 0; i < arraySize; i++) {
    if(expression[i] == " ") {
      i++; 
    } else if(expression[i] == "+" || expression[i] == "-" || expression[i] == "/" || expression[i] == "*" || expression[i] == "^" || expression[i] == "(" || expression[i] == ")") {
      
    }
  }
  
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
