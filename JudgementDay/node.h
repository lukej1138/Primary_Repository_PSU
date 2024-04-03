/*
  Lucas Johnson
  4/3/2024
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
  node(int val, int col);
  //getters and setters for next nodes, parent, color, and value
  int getVal();
  void setLeftNext(node* newNext);
  void setRightNext(node* newNext);
  void setParent(node* newParent);
  void setColor(int col);
  node* getLeftNext();
  node* getRightNext();
  node* getParent();
  int getColor();
  void setVal(int val);

 //Private variables & pointers for class
 private:
  int color;
  int val1;
  node* nextNodeL;
  node* nextNodeR;
  node* parent;
};

#endif
