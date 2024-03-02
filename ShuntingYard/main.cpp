#include <iostream>
#include "node.h"
#include <cstring>
//Errors: Get thru stack, but stack gets empty and thingy has something to throw on; 

void enqueue(node* &queueHead, node* thingyMaBob);
void dequeue(node* &queueHead, node* &current, node* previous);
void push(node* &stackHead, node* thing);
node* pop(node* &stackHead);
void parseInput(char* input, char arr[]);
void ShuntingDaYard(node* &queuehead, node* stackhead, char arr[]);
int assignValue(char thingy);
node* peek(node* &stackHead, node* current);
void stackprint(node* stackhead);
void queueprint(node* queuehead);
void buildTree(node* &queueHead, node* &treeHead);
void printIn(node* treeHead);
void printPost(node* treeHead);
void printPre(node* treeHead);
using namespace std;

int main(){
  node* queueHead = NULL;
  node* stackHead = NULL;
  node* treeHead = NULL;
  bool gameRunnin = true;
  char* input = new char[101];
  cout << "Please provide a math equation, less than 100 characters" << endl;
  cin.get(input, 100);
  cin.get();
  char arr[100];
  parseInput(input, arr);
  ShuntingDaYard(queueHead, stackHead, arr);
  buildTree(queueHead, treeHead);
  while(gameRunnin){
    cout << "Would you like infix, postfix, or prefix (type exactly)? Type 'quit' to quit" << endl;
    char* input1 = new char[31];
    cin.get(input1, 30);
    cin.get();
    if((strcmp(input1, "infix")) == 0){
      printIn(treeHead);
      cout << endl;
    }
    else if((strcmp(input1, "postfix")) == 0){
      printPost(treeHead);
      cout << endl;
    }
    else if((strcmp(input1, "prefix")) == 0){
      printPre(treeHead);
      cout << endl;
    }
    else{
      gameRunnin = false;
    }

  }
}

void enqueue(node* &queueHead, node* thingy){
  if(queueHead == NULL){
    queueHead = thingy;
    return;
  }
  node* temp = queueHead;
  queueHead = thingy;
  queueHead->setCenterNext(temp);
}

void dequeue(node* &queueHead, node* &current, node* previous){
  if(current->getCenterNext() == NULL){
    if(current == queueHead){
      queueHead = NULL;
      return;
    }
    previous->setCenterNext(NULL);
    return;
  }
  else{
    if(current != queueHead){
      previous = previous->getCenterNext();
    }
    current = current->getCenterNext();
    dequeue(queueHead, current, previous);
  }
}

node* pop(node* &stackHead){
  node* temp = stackHead;
  if(stackHead->getCenterNext() != NULL){
    stackHead = stackHead->getCenterNext();
  }
  else{
    stackHead = NULL;
  }
  temp->setCenterNext(NULL);
  return temp;
}

void push(node* &stackHead, node* thingy){
  if(stackHead == NULL){
    stackHead = thingy;
    return;
  }
  node* temp = stackHead;
  stackHead = thingy;
  stackHead->setCenterNext(temp);

}

void parseInput(char* input, char arr[]){
  for(int i = 0; i < strlen(input)+1; i++){
    arr[i] = input[i];
    if(arr[i] == '\0'){
      break;
    }
  }
}


node* peek(node* &stackHead, node* current){
  if(current->getCenterNext() == NULL){
    return current;
  }
  else{
    current = current->getCenterNext();
    pop(stackHead);
  }
}

void ShuntingDaYard(node* &queuehead, node* stackhead, char arr[]){
  for(int i = 0; i < 100; i++){
    if(arr[i] == '\0'){
      break;
    }
    node* thingy = new node(arr[i]);
    if(isdigit(arr[i])){
      enqueue(queuehead, thingy);
    }
    else if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i]  == '/' || arr[i] == '^'){
      if(stackhead == NULL){
	push(stackhead, thingy);
      }
      else{
	
	while(((stackhead->getVal()) == '+' || (stackhead->getVal()) == '-' || (stackhead->getVal()) == '*' || (stackhead->getVal()) == '/' || (stackhead->getVal()) == '^')  && ((assignValue(stackhead->getVal()) > assignValue(arr[i])) || (assignValue(stackhead->getVal()) == assignValue(arr[i]) && arr[i] != '^'))){
        enqueue(queuehead, pop(stackhead));
	if(stackhead == NULL){
	  break;
	}
	}
	push(stackhead, thingy);
      }
    }else if(arr[i] == '('){
      push(stackhead, thingy);
    }else if(arr[i] == ')'){
      while(stackhead->getVal() != '('){
	if(stackhead == NULL){
	  break;
	}
	enqueue(queuehead, pop(stackhead));
      }
      if(stackhead->getVal() == '('){
	delete pop(stackhead);
      }
      if(stackhead == NULL){
	continue;
      }
      if(stackhead->getVal() == '+' || stackhead->getVal() == '-' || stackhead->getVal() == '*' || stackhead->getVal() == '/' || stackhead->getVal() == '^'){
          enqueue(queuehead, pop(stackhead));
        }
    }
  }
    while(stackhead != NULL){
      if(stackhead->getVal() != '('){
	enqueue(queuehead, pop(stackhead));
      }
      else{
	cout << "mismatched parenthesis" << endl;
	break;
      }
    }
}
int assignValue(char thingy){
  if(thingy == '+' || thingy == '-'){
    return 10;
  }
  else if(thingy == '*' || thingy == '/'){
    return 20;
  }
  else if(thingy == '^'){
    return 30;
  }
}
void stackprint(node* stackHead){
  if(stackHead == NULL){
    cout << "Stack is empty" << endl;
  }
  else{
    cout << stackHead->getVal();
    if(stackHead->getCenterNext() != NULL){
      stackprint(stackHead->getCenterNext());
    }
    cout << endl;
    return;
  }
}
void queueprint(node* queueHead){
  if(queueHead == NULL){
    cout << "Queue is empty" <<	endl;
  }
  else{
    cout << queueHead->getVal();
    if(queueHead->getCenterNext() != NULL){
      queueprint(queueHead->getCenterNext());
    }
    return;
  }
}

void buildTree(node* &queueHead, node* &treeHead){
  while(queueHead != NULL){
    node* thing = queueHead;
    node* previous = queueHead;
    dequeue(queueHead, thing, previous);
    if(isdigit(thing->getVal()) == 1){
      push(treeHead, thing);
    }
    else if(thing->getVal() == '+' || thing->getVal() == '-' || thing->getVal() == '*' || thing->getVal() == '/' || thing->getVal() == '^'){
      node* right = pop(treeHead);
      node* left = pop(treeHead);
      push(treeHead, thing);
      thing->setRightNext(right);
      thing->setLeftNext(left);
  }
    else{
      continue;
    }
}
}

void printIn(node* treeHead){
  if(treeHead->getLeftNext() != NULL){
    printIn(treeHead->getLeftNext());
  }
  cout << treeHead->getVal();
  if(treeHead->getRightNext() != NULL){
    printIn(treeHead->getRightNext());
  }
  return;
}

void printPost(node* treeHead){
  if(treeHead->getLeftNext() != NULL){
    printPost(treeHead->getLeftNext());
  }
  if(treeHead->getRightNext() != NULL){
    printPost(treeHead->getRightNext());
  }
  cout << treeHead->getVal();
  return;
}
void printPre(node* treeHead){
  cout << treeHead->getVal();
  if(treeHead->getLeftNext() != NULL){
    printPre(treeHead->getLeftNext());
  }
  if(treeHead->getRightNext() != NULL){
    printPre(treeHead->getRightNext());
  }
  return;
}
