/*
  Lucas Johnson
  3/19/2024
  Header file for node clas
 */


//Implemention of a header guard for header file
#ifndef NODE_H
#define NODE_H

//imports
#include <iostream>

using namespace std;

class node {
 //Public functions for class
 public:
  //constructor
  node(int val);
  //getters and setters for each next node/value
  int getVal();
  void setLeftNext(node* newNext);
  void setRightNext(node* newNext);
  node* getLeftNext();
  node* getRightNext();
  void setVal(int val);

 //Private variables & pointers for class
 private:
  int val1;
  node* nextNodeL;
  node* nextNodeR;
};

#endif
