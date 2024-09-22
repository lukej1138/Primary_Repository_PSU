/*
  Lucas Johnson
  11/14/23
  Main file for room class
 */
#include "room.h"
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

//Constructor which assigns all appropriate fields. Use this keyword to make sure we reference the right thing
room::room(char* name, map<int, char*>* rmItems, int id, map<char*, int>* exits, char* rmdescription) {
  this->rmdescription = new char[801];
  this->rmItems = rmItems;
  this->exits = exits;
  strcpy(this->rmdescription, rmdescription);
  this->id = id;
  this->name = new char[21];
  strcpy(this->name, name);
}

//Runs through and deletes each pointer 
room::~room(){
  delete[] this->name;
  delete[] this->rmdescription;
  for(map<int, char*>::iterator it = rmItems->begin(); it!=rmItems->end(); it++){
    delete it->second;
  }
  delete this->rmItems;
  for(map<char*,int>::iterator it = exits->begin();it!=exits->end();it++){
    delete it->first;

  }
  delete this->exits;
  delete this->rmItems;

}

char* room::getName(){
  return this->name;

}
int room::getId(){
  return this->id;

}

//Prints items in map
void room::printItems(){
  for(map<int,char*>::iterator it = rmItems->begin(); it != rmItems->end(); it++){
    cout << it->second << ", ";
  }
  cout << endl;
  
}
//Same thing as printItems but with exits. Needs extra loop to find corresponding room for each id.
void room::printExits(vector<room*> rooms){
  for(map<char*, int>::iterator it = (this->exits)->begin(); it != (this->exits)->end(); it++){
    for(vector<room*>::iterator it1 = rooms.begin(); it1 != rooms.end(); it1++){
      if((*it1)->getId() == it->second){
	cout<<it->first << ": " << (*it1)->getName() << endl;
	break;
      }
    }
  }
}

//Basic getters and setters
char* room::getRmdescription(){
  return this->rmdescription;
}
void room::setExits(map<char*, int>* mp){
  this->exits = mp;
}

map<char*,int>* room::getExits(){
  return this->exits;

}

//Sets the items for the room itself during a DROP/GET command
void room::setItems(char* item, int doodad, map<int, char*>* items, int location){
  if(doodad == 0){
    //Here we delete items
    for(map<int, char*>::iterator it = items->begin(); it != items->end(); it++){
      //Finds the item and deletes it.
      if((strcmp((it)->second, item)) == 0){
	char* newSpace = new char[21];
	strcpy(newSpace, " ");
	strcpy(it->second, newSpace);
	break;
      }
    }
  } else if (doodad == 1){
    //Here we add the items
    for(map<int, char*>::iterator it = items->begin(); it != items->end(); it++){
      //location refers to the id of the item (1-5)
      if(location == (it)->first){
	(it)->second = item;
	break;
      }
    }
  }
}

map<int,char*>* room::getItems(){
  return this->rmItems;
}
