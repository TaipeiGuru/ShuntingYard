#include <iostream>
#include <cstring>

using namespace std;

void pushStack(Node* newNode);
Node* popStack();
void peekStack();
enqueueQueue();
dequeueQueue();

Node* stackHead = NULL;
Node* queueHead = NULL;

int main() { 
  char input[20];

  cout << "Welcome to Shunting Yard!" << endl;
  
  // Standard repeating message sequence using bool and while loop.
  bool active = true;
  while(active == true) {
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
