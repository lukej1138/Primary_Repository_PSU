
//Implemention of a header guard for header file
#ifndef NODE_H
#define NODE_H

//imports
#include <iostream>

using namespace std;

//Start of the singly linked list node class for the student class
class node {
 //Public functions for class
 public:
  node(char val);
  ~node();
  char getVal();
  void setLeftNext(node* newNext);
  void setRightNext(node* newNext);
  void setCenterNext(node* newNext);  
  node* getLeftNext();
  node* getRightNext();
  node* getCenterNext();

 //Private variables & pointers for class
 private:
  char val1;
  node* nextNodeL;
  node* nextNodeC;
  node* nextNodeR;
};

#endif
