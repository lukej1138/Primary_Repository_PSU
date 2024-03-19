/*
  Lucas Johnson
  Binar Expression Tree Main Function
  3/18/23
 */
#include <iostream>
#include <cstring>
#include "node.h"
#include <fstream>
using namespace std;
//Function prototypes
void printTree(node* head, int count);
void addTree(node* &head, node* thingy);
char* valid_input();
bool searchTree(node* head, int thingy);
void delTree(node* head, node* previous, int thingy);
node* delTree2(node* head, node* previous, int initialHead);


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
	  node* thingy = new node(input);
          addTree(head, thingy);
        }
      }
      //Reads in from Numbers.rtf to automatically fill the tree              
      else if(strcmp(input, "file") == 0){
        fstream fin;
        fin.open("Numbers.rtf");
        int input1 = 0;
        while(fin >> input1){
          int temp = input1;
	  node* thingy = new node(temp);
          addTree(head, thingy);
        }
        fin.close();
      }
    } else if(strcmp(to_do, "QUIT") == 0){
      programRunnin = false;
    } else if(strcmp(to_do, "PRINT") == 0){
      int count = 0;
      printTree(head, count);
    } else if(strcmp(to_do, "SEARCH") == 0){
      cout << "What value would you like to search for?" << endl;
      int thingy = 0;
      cin >> thingy;
      cin.get();
      bool exists = searchTree(head, thingy);
      if(exists == true){
	cout << "That number is in the tree!" << endl;
      }
      else{
	cout << "Sorry, that number does not exist." << endl;
      }
    } else if (strcmp(to_do, "DELETE") == 0){
      int input = 0;
      cout << "Give us a number to look for" << endl;
      cin >> input;
      cin.get();
      node* previous = head;
      delTree(head, previous, input);
      cout << "WE DID IT!!!" << endl;

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
  cout << head->getVal() << endl;

  if(head->getLeftNext() != NULL){
    printTree(head->getLeftNext(), count+1);
  }
}

//Go left/right by comparing the current "Head" with node being added. Keep going until at the end
void addTree(node* &head, node* thingy){
  if(head == NULL){
    head = thingy;
    return;
  }

  if(thingy->getVal() < head->getVal()){
    if(head->getLeftNext() != NULL){
      node* temp1 = head->getLeftNext();
      addTree(temp1, thingy);
    }else{
     head->setLeftNext(thingy);
    }
  }else{
    if(head->getRightNext() != NULL){
      node* temp2 = head->getRightNext();
      addTree(temp2, thingy);
    }else{
      head->setRightNext(thingy);
    }
  }
}
//Function that checks for valid input, making sure a valid keyword is inputted by the user
char* valid_input(){
  cout << endl;
  char* input = new char[11];
  bool good_input = false;
  while(good_input == false){
    cout << "Please input what you would like to do (ADD, PRINT, DELETE, SEARCH,  QUIT). There is a character limit of 10." << endl;
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

//goes to the left/right of each node depending on the node's data's relation to the passed in data. If we get to the end of the tree, then the number doesn't exist.
bool searchTree(node* head, int thingy){
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

}
//Nightmare fuel
//Uses the above tree to access to the node that we want to remove
//Determines the number of children. Searches for successor (accidentally
//called predecessor in code, whoopsies) if their are two children, if their is just one replaces with that child. 
void delTree(node* head, node* previous, int thingy){
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
    cout << "Found a match" << endl;
    cout << "Current Head: " << head->getVal() << endl;
    if(head->getLeftNext() != NULL && head->getRightNext() != NULL){
      node* temp = previous;
      previous = head;
      node* predecessor = delTree2(head->getRightNext(), previous, head->getVal());
      previous = temp;
      cout << "Predecessor Found " << predecessor->getVal() << endl;
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
      cout << "HERE" << endl;
      cout << "previous: " << previous->getVal() << endl;
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
//Recursively runs thru tree to find a predecessor to be used in the main delete
node* delTree2(node* head, node* previous, int initialHead){
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
