/*
  Lucas Johnson
  3/19/2024
  CPP file for node class
 */

//imports
#include "node.h"


//Constructor for node class
node::node(int val) {
  //Assign node's student based on construction parameter
  val1 = val;

  //Set the next node to null (will need to set node later)
  nextNodeL = NULL;
  nextNodeR = NULL;
}

//Getter function for Node's held value
int node::getVal() {
  return val1;
}

//Setter function for Node's next node (left or right)
void node::setLeftNext(node* newNext) {
  nextNodeL = newNext;
}

void node::setRightNext(node* newNext) {
  nextNodeR = newNext;
}

//Getter function for Node's next node (left or irght)
node* node::getLeftNext() {
  return nextNodeL;
}
node* node::getRightNext() {
  return nextNodeR;
}
//Setter, used only in delete function for shifting values
void node::setVal(int val){
  val1 = val;
}
