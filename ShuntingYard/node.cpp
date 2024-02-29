//imports
#include "node.h"

//Constructor for node class
node::node(char val) {
  //Assign node's student based on construction parameter
  val1 = val;

  //Set the next node to null (will need to set node later)
  nextNodeL = NULL;
  nextNodeR = NULL;
  nextNodeC = NULL;
}

//Destructor for node class
node::~node() {
  nextNodeL = NULL;
  nextNodeR = NULL;
  nextNodeC = NULL;
}

//Getter function for Node's held student
char node::getVal() {
  return val1;
}

//Setter function for Node's next node link
void node::setLeftNext(node* newNext) {
  nextNodeL = newNext;
}
void node::setCenterNext(node* newNext) {
  nextNodeC = newNext;
}
void node::setRightNext(node* newNext) {
  nextNodeR = newNext;
}

//Getter function for Node's next node link
node* node::getLeftNext() {
  return nextNodeL;
}
node* node::getRightNext() {
  return nextNodeR;
}
node* node::getCenterNext() {
  return nextNodeC;
}
