/*
  Lucas Johnson
  Red Black Tree Main Function
  4/3/2024
 */
//1 = RED;
//0 = BLACK;
#include <iostream>
#include <cstring>
#include "node.h"
#include <fstream>
using namespace std;
//Function prototypes
void printTree(node* head, int count);
node* addTree(node* &head, node* thingy);
char* valid_input();
void add2Tree(node* &root, node* &head, node* thingy);
//bool searchTree(node* head, int thingy);
//void delTree(node* head, node* previous, int thingy);
//node* delTree2(node* head, node* previous, int initialHead);
bool findChildSide(node* Gparent, node* head);
void Case3(node* &root, node* &Gparent, node* &uncle, node* &head);
void leftRotation(node* &head, node* &thingy);
void rightRotation(node* &head, node* &thingy);
int main(){
  //Head node, basic "global" variables declared
  //Set up while loop for game
  node* head = NULL;
  bool programRunnin = true;
  char* to_do = new char[20];
  while(programRunnin){
    strcpy(to_do, valid_input());
    //Uses string (read in above) to determine what to do (specific command)
    if(strcmp(to_do, "ADD") == 0){
      char input[10];
      cout << "type file or cmd, file for file upload or cmd for manual" << endl;
      cin.get(input, 9);
      cin.get();
      //Adds one value at a time                                             
      if(strcmp(input, "cmd") == 0){
        int size = 0;
        cout << "How many inputs do you have?" << endl;
        cin >> size;
        int input = 0;
        for(int i = 0; i < size; i++){
          cout << "Input a number" << endl;
          cin >> input;
          cin.get();
	  node* thingy = new node(input, 1);
          node* parent = addTree(head, thingy);
	  add2Tree(head, parent, thingy);
        }
      }
      //Reads in from Numbers.rtf to automatically fill the tree              
      else if(strcmp(input, "file") == 0){
        fstream fin;
        fin.open("Numbers.rtf");
        int input1 = 0;
        while(fin >> input1){
          int temp = input1;
	  node* thingy = new node(temp, 1);
          node* parent = addTree(head, thingy);
	  add2Tree(head, parent, thingy);
        }
        fin.close();
      }
    } else if(strcmp(to_do, "QUIT") == 0){
      programRunnin = false;
    } else if(strcmp(to_do, "PRINT") == 0){
      int count = 0;
      printTree(head, count);
    }
  }

}

//Uses Stack print function, modified to read out the tree.
void printTree(node* head, int count){
  if(head->getRightNext() != NULL){
    printTree(head->getRightNext(), count+1);
  }
  for(int i = 0; i < count; i++){
    cout << '\t';
  }
  if(head->getColor() == 0){
    cout << 'B';
  }
  else{
    cout << 'R';
  }
  cout << head->getVal() << endl;

  if(head->getLeftNext() != NULL){
    printTree(head->getLeftNext(), count+1);
  }
}

//Go left/right by comparing the current "Head" with node being added. Keep going until at the end. Returns the head node to be used for rebalancing in following function.
node* addTree(node* &head, node* thingy){
  if(head == NULL){
    head = thingy;
    thingy->setParent(NULL);
    return head;
  }
  if(thingy->getVal() < head->getVal()){
    if(head->getLeftNext() != NULL){
      node* temp1 = head->getLeftNext();
      return addTree(temp1, thingy);
    }else{
     head->setLeftNext(thingy);
     thingy->setParent(head);
     return head;
    }
  }else{
    if(head->getRightNext() != NULL){
      node* temp2 = head->getRightNext();
      return addTree(temp2, thingy);
    }else{
      head->setRightNext(thingy);
      thingy->setParent(head);
      return head;
    }
  }
}

  

  

//Function that checks for valid input, making sure a valid keyword is inputted by the user
char* valid_input(){
  cout << endl;
  char* input = new char[11];
  bool good_input = false;
  while(good_input == false){
    cout << "Please input what you would like to do (ADD, PRINT, QUIT (SEARCH AND DELETE COMING SOON!)). There is a character limit of 10." << endl;
    cin.get(input, 10);
    cin.get();
    if((strcmp(input, "ADD") != 0) && (strcmp(input,"DELETE") != 0) && (strcmp(input,"PRINT") != 0) && (strcmp(input, "QUIT") != 0) && (strcmp(input, "SEARCH") !=0)){
      cout << "Please select a valid input" << endl;
      continue;
    }
    else{
      good_input = true;
    }


  }
  return input;
}

  //True = right, false = left
bool findChildSide(node* Gparent, node* head){
  if(Gparent->getRightNext() == head){
    return true;
  }
  return false;
}

//For when uncle is red and parent is read. Recolors such that Gparent is red, head/uncle become black. Rerun's all checks on Gparent again.
void Case3(node* &root, node* &Gparent, node* &uncle, node* &head){
  head->setColor(0);
  uncle->setColor(0);
  if(Gparent->getParent() != NULL){
    Gparent->setColor(1);
    node* tempG = Gparent;
    Gparent = Gparent->getParent();
    head = tempG;
    bool checkSide = findChildSide(Gparent, head);
    if(checkSide){
      //Head is Right
      uncle = Gparent->getLeftNext();
    }
    else{
      //Head is Left
      uncle = Gparent->getRightNext();
    }
    add2Tree(root, Gparent, head);    
  }
}
//Following function to addTree. Determines case and executes proper measures.
void add2Tree(node* &root, node* &head, node* thingy){
  //Case one and two.
  if(head == thingy){
    thingy->setColor(0);
    return;
  }
  if(thingy->getParent()->getColor() == 0){
    return;
  }
  //Case 3, 4, 5;
  if(head->getParent() != NULL){
    node* Gparent = head->getParent();
    bool checkSide = findChildSide(Gparent, head);
    node* uncle = NULL;
    if(checkSide){
      //Head is Right
      uncle = Gparent->getLeftNext();
    }else{
      //Head is Left
      uncle = Gparent->getRightNext();
    }
    if(uncle != NULL && uncle->getColor() == 1 && head->getColor() == 1){
      Case3(root, Gparent, uncle, head);
    }
    if(uncle == NULL || uncle->getColor() == 0 && head->getColor() == 1){
      if(Gparent->getLeftNext() == head && head->getRightNext() == thingy){
	//Left right case 4
	leftRotation(head, thingy);
	if(head->getParent() == NULL){
	  root = head;
	}
	node* tempP = head;
        head = Gparent;
        thingy = tempP;
        rightRotation(head, thingy);
	if(head->getParent() == NULL){
          root = head;
        }
        head->setColor(0);
        thingy->setColor(1);
      	
      }
      else if(Gparent->getRightNext() == head && head->getLeftNext() == thingy){
	//Right left case 4
	rightRotation(head, thingy);
	if(head->getParent() == NULL){
          root = head;
        }
        node* tempP = head;
        head = Gparent;
        thingy = tempP;
        leftRotation(head, thingy);
	if(head->getParent() == NULL){
          root = head;
        }
        head->setColor(0);
        thingy->setColor(1);
      }
      else if(Gparent->getRightNext() == head && head->getRightNext() == thingy){
	//Right Right case 5
	node* tempP = head;
	head = Gparent;
	thingy = tempP;
	leftRotation(head, thingy);
	if(head->getParent() == NULL){
          root = head;
        }
	head->setColor(0);
        thingy->setColor(1);
      }
      else if(Gparent->getLeftNext() == head && head->getLeftNext() == thingy){
        //Left Left case 5
	node* tempP = head;
        head = Gparent;
        thingy = tempP;
	rightRotation(head, thingy);
	if(head->getParent() == NULL){
          root = head;
        }
        head->setColor(0);
	thingy->setColor(1);
	return;
      }

    }
  }
}
//Performs a left rotation;
void leftRotation(node* &head, node* &thingy){
  node* thingyLeft = thingy->getLeftNext();
  node* tempP = head;
  head = thingy;
  thingy = tempP;
  head->setParent(thingy->getParent());
  head->setLeftNext(thingy);
  thingy->setRightNext(thingyLeft);
  if(thingy->getParent() != NULL){
    if(findChildSide(thingy->getParent(), thingy)){
      thingy->getParent()->setRightNext(head);
    }else{
      thingy->getParent()->setLeftNext(head);
    }
  }
  thingy->setParent(head);
  if(thingyLeft != NULL){
    thingyLeft->setParent(thingy);
  }
}
//Performs a right rotation
void rightRotation(node* &head, node* &thingy){
  node* thingyRight = thingy->getRightNext();
  node* tempP =	head;
  head = thingy;
  thingy = tempP;

  head->setParent(thingy->getParent());
  head->setRightNext(thingy);
  if(thingy->getParent() != NULL){
    if(findChildSide(thingy->getParent(), thingy)){
      thingy->getParent()->setRightNext(head);
    }else{
      thingy->getParent()->setLeftNext(head);
    }
  }
  
  thingy->setParent(head);
  thingy->setLeftNext(thingyRight);
  if(thingyRight != NULL){
    thingyRight->setParent(thingy);
  }
}


//DO NOT LOOK BEYOND THIS POINT
//goes to the left/right of each node depending on the node's data's relation to the passed in data. If we get to the end of the tree, then the number doesn't exist.
/*bool searchTree(node* head, int thingy){
  if(head == NULL){
    return false;
  }
  if(head->getVal() != thingy){
    if(head->getVal() > thingy){
      return searchTree(head->getLeftNext(), thingy);
    }
    else{
      return searchTree(head->getRightNext(), thingy);
    }
  }
  else{
    return true;
  }

  }*/
//Nightmare fuel
//Uses the above tree to access to the node that we want to remove
//Determines the number of children. Searches for successor (accidentally
//called predecessor in code, whoopsies) if their are two children, if their is just one replaces with that child. 
/*void delTree(node* head, node* previous, int thingy){
  if(head == NULL){
    cout << "The number doesn't exist in the data structure" << endl;
    return;
  }

  if(head->getVal() != thingy){
    if(head->getVal() > thingy){
      previous = head;
      head = head->getLeftNext();
      delTree(head, previous, thingy);
    }
    else{
      previous = head;
      head = head->getRightNext();
      delTree(head, previous, thingy);
    }
  }
  else{
    if(head->getLeftNext() != NULL && head->getRightNext() != NULL){
      node* temp = previous;
      previous = head;
      node* predecessor = delTree2(head->getRightNext(), previous, head->getVal());
      previous = temp;
      head->setVal(predecessor->getVal());
      delete predecessor;
    }
    else if(head->getLeftNext() != NULL){
      if(previous == head){
	previous->setVal(previous->getLeftNext()->getVal());
        node* temp = previous->getLeftNext();
        previous->setLeftNext(NULL);
        delete temp;
        return;
      }
      if(previous->getLeftNext() == head){
	previous->setLeftNext(head->getLeftNext());
	delete head;
	return;
      }
      else{
	previous->setRightNext(head->getLeftNext());
	delete head;
	return;
      }
    }
    else if(head->getRightNext() != NULL){
      if(previous == head){
	previous->setVal(previous->getRightNext()->getVal());
	node* temp = previous->getRightNext();
	previous->setRightNext(NULL);
	delete temp;
	return;
      }
      if(previous->getLeftNext() == head){
        previous->setLeftNext(head->getRightNext());
	delete head;
        return;
      }
      else{
        previous->setRightNext(head->getRightNext());
        delete head;
        return;
      }
    }
    else{
      if(previous == head){
	previous = NULL;
	return;
      }
      if(previous->getLeftNext() == head){
        previous->setLeftNext(NULL);
        delete head;
        return;
      }
      else{
        previous->setRightNext(NULL);
        delete head;
        return;
      }

    }
    //Create deletion function for (case 1, one child on head so just make it become new head and delete old head) or (case 2, two children so use predecessor method of right one then left all the way)
  }

}
*/
//Recursively runs thru tree to find a predecessor to be used in the main delete
/*node* delTree2(node* head, node* previous, int initialHead){
  if(head->getLeftNext() != NULL){
    previous = head;
    return delTree2(head->getLeftNext(), previous, initialHead);
  }
  else{
    if(previous->getVal() == initialHead){
      previous->setRightNext(head->getRightNext());
      return head;
    }
    previous->setLeftNext(head->getRightNext());
    return head;
  }

}
*/
