/*
  Lucas Johnson
  12/11/23
  CPP File for LinkedList Project
  Used: Chat GPT 3.5
  With This Prompt: how to make it so a c++ float is always printed up to two decimal places
 */
#include<iostream>
#include <iomanip>
#include <cstring>
#include "student.h"
#include "node.h"
using namespace std;


//Various functions, one for input and one for each keyword
char* getInput();
void add(node* &mainNode, node* &newNode, node* &current, node* &previous);
void print(node* current);
void del(int id, node* &mainNode, node* &current, node* &previous);
void quit(node* &mainNode, node* &current, node* &previous);
void average(int &counter, float &total, node* &current);

int main(){
  //Sets up the head node and the loop for the program to run in
  bool gameRun = true;
  node* mainNode = NULL;
  while(gameRun){
    //Gets input, then determines keyword to work with
    char* keyword = new char[11];
    strcpy(keyword, getInput());

    //First gets basic facts for student obj, then runs add function
    if((strcmp(keyword, "ADD")) == 0){
      int id;
      cout << "please provide the student id, six digits." << endl;
      cin >> id;
      cin.get();

      float gpa;
      cout << "please provide a gpa between 1-4" << endl;
      cin >> gpa;
      cin.get();

      char* name = new char[31];
      cout << "please provide the students name, or less than 30 characters of it" << endl;
      cin.getline(name, 30);
      
      //creates current/previous to go through the chain and new node to be inserted
      student* stu = new student(id, gpa, name);
      node* newNode = new node(stu);
      node* current = mainNode;
      node* previous = mainNode;
      add(mainNode, newNode, current, previous);
    }
    else if((strcmp(keyword, "PRINT")) == 0){
      node* current = mainNode;
      print(current);

    }
    else if ((strcmp(keyword, "DELETE")) == 0){
      //Determines the ID to delete, then runs delete function with current/prev
      int id;
      cout << "Id to delete?" << endl;
      cin >> id;
      cin.get();

      node* current = mainNode;
      node* previous = mainNode;
      del(id, mainNode, current, previous);

    }
    else if ((strcmp(keyword, "QUIT")) == 0){
      //Deletes the chain
      node* current = mainNode;
      node* previous = mainNode;
      quit(mainNode, current, previous);
      gameRun = false;

    }
    else if((strcmp(keyword, "AVERAGE")) == 0){
      //Uses total for total GPA, then divides that total by the number of gpas.
      float total = 0;
      int counter = 0;
      node* current = mainNode;
      average(counter, total, current);
      cout << "Average of all GPAs: " << total << endl;

    }


  }
}


char* getInput(){
  //Gets input, checking for faulty input. The good input is returned to be strcpyied into another char ptr in main
  cout << "Please input the keyword ADD, PRINT, DELETE, QUIT, AVERAGE, all caps"<< endl;
  bool badInput = true;
  while(badInput){
    char* input = new char[11];
    cin.getline(input, 10);

    if(((strcmp(input, "ADD")) == 0) || ((strcmp(input, "PRINT")) == 0) || ((strcmp(input, "DELETE")) == 0) || ((strcmp(input, "QUIT")) == 0) || ((strcmp(input, "AVERAGE")) == 0)){
      return input;
    }
    else{
      cout << "Invalid input, try again" << endl;
    }
  }
}



void add(node* &mainNode, node* &newNode, node* &current, node* &previous){
  //Hell
  //Pretty much check for the main node first, otherwise use recursion to determine where to place it.
  //Specifically, checks the id of current and compares w/ new node. When current is greater, we know
  //to insert the new node BEFORE it. Use previous and current to connect appropriately. End cases are
  //also accounted for.

  if(mainNode == NULL){
    mainNode = newNode;
    return;
    }
  else{
   
    int id1 = current->getStudent()->getId();
    int id2 = newNode->getStudent()->getId();
   
    if(id1 < id2 && current->getNode() != NULL){
      node* temp = current;
      previous = temp;
      current = current->getNode();
      add(mainNode, newNode, current, previous);
      return;
     }
     else{
       bool doMiddlePlace = false;
       if(id2 < id1){
	 doMiddlePlace = true;
       }
       if(current != mainNode && doMiddlePlace == true){
	 cout << "1" << endl;
	 newNode->setNode(current);
	 previous->setNode(newNode);
       }
       else if(current == mainNode && doMiddlePlace == true){
	 cout << "2" << endl;
	 node* temp = mainNode;
	 mainNode = newNode;
	 newNode->setNode(temp);
       }
       else if(doMiddlePlace == false){
	 cout << "3" << endl;
	 current->setNode(newNode);
       }
       return;
     }
    }
 }

void print(node* current){
  //Runs thru the chain with recursion, printing till current hits NULL (the end of the chain)
  if(current == NULL){
    return;
  }
  else{
    cout << fixed << setprecision(2);
    cout << "Name: " << current->getStudent()->getName() << ", Id: " << current->getStudent()->getId() << ", GPA: " << current->getStudent()->getGpa() << endl;
    current = current->getNode();
    print(current);
  }


}

void del(int id, node* &mainNode, node* &current, node* &previous){
  //More hell
  if(mainNode == NULL){
    cout << "Dummy you can't delete from an empty list" << endl;
    return;
  }
  //If id == mainNode id, then delete node in main node but make sure to move the chain down one notch.
  if(id == mainNode->getStudent()->getId()){
    node* temp = mainNode;
    if(mainNode->getNode() != NULL){
      mainNode = mainNode->getNode();
    }
    else{
      mainNode = NULL;
    }
    delete temp;
  }
  else{
    //Runs all the way down till we get a match
    if(current->getNode() != NULL && current->getStudent()->getId() < id){
      node* temp = current;
      previous = current;
      current = current->getNode();
      del(id, mainNode, current, previous);
    }
    else{
      //delete match, tie loose ends
      if(id == current->getStudent()->getId()){
	current = current->getNode();
	delete previous->getNode();
	previous->setNode(current);
	return;
      }
      //for end case
      else{
	delete current;
	previous->setNode(NULL);
	return;
      }
    }
  }
}

void quit(node* &mainNode, node* &current, node* &previous){
  //Think of a fisher, which is main node. Fisher casts rod (current/prev) till it reaches the
  //end of the chain. Once their, current sets itself to previous, deletes curr->getNode() then is
  //"Reeled in" back to main node, the fisher. Repeat till you get main node, whereas main node
  //deletes itself.
  if(mainNode == NULL){
    return;
  }
  else {
    if(current->getNode() != NULL){
      previous = current;
      current = current->getNode();
      quit(mainNode, current, previous);
    }
    else if (current != mainNode){
      current = previous;
      delete current->getNode();
      current->setNode(NULL);
      current = mainNode;
      previous = mainNode;
      quit(mainNode, current, previous);
    }
    else {
      mainNode = NULL;
      delete current;
      return;

    }
    

  }


}

void average(int &counter, float &total, node* &current){
  //Runs thru, adding up the gpa of all students before dividing by current. Print out total in main.
  if(current == NULL){
    return;
  }
  else{
    total += current->getStudent()->getGpa();
    counter++;
    if(current->getNode() != NULL){
      current = current->getNode();
      average(counter, total, current);
    }
    else{
      total /= counter;
      return;
    }

  }

}
