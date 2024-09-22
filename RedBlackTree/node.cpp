/*
  Lucas Johnson
  4/3/2024
  CPP file for node class
 */

//imports
#include "node.h"


//Constructor for node class
node::node(int val, int col) {
  //Assign node's data/color based on construction parameter
  val1 = val;
  color = col;
  //Set the next node to null (will need to set node later)
  nextNodeL = NULL;
  nextNodeR = NULL;
  parent = NULL;
}

//Getter function for Node's held value
int node::getVal() {
  return val1;
}

//Setter function for Node's next node (left or right) or parent or color
void node::setLeftNext(node* newNext) {
  nextNodeL = newNext;
}

void node::setRightNext(node* newNext) {
  nextNodeR = newNext;
}

void node::setParent(node* newParent){
  parent = newParent;
}

void node::setColor(int col){
  color = col;
}
//Getter function for Node's next node (left or irght) or parent or color
node* node::getLeftNext() {
  return nextNodeL;
}
node* node::getRightNext() {
  return nextNodeR;
}
node* node::getParent(){
  return parent;
}

int node::getColor(){
  return color;
}
//Setter, used only in delete function for shifting values
void node::setVal(int val){
  val1 = val;
}
