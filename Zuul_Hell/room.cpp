#include "room.h"
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

room::room(char* name, map<int, char*>* rmItems, int id, map<char*, int>* exits, char* rmdescription) {
  this->rmdescription = new char[801];
  this->rmItems = rmItems;
  this->exits = exits;
  strcpy(this->rmdescription, rmdescription);
  this->id = id;
  this->name = new char[21];
  strcpy(this->name, name);
}

char* room::getName(){
  return this->name;

}
int room::getId(){
  return this->id;

}
void room::printItems(){
  for(map<int,char*>::iterator it = (this->rmItems)->begin(); it != (this->rmItems)->end(); it++){
    cout << it->second << ", ";
  }
  cout << endl;
  
  
}

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

char* room::getRmdescription(){
  return this->rmdescription;
}
void room::setExits(map<char*, int>* mp){
  this->exits = mp;
}

//Finish up by adding the add ability (drop) for rm items
void room::setItems(char* item, int doodad, map<int, char*>* items, int location){
  if(doodad == 0){
    for(map<int, char*>::iterator it = items->begin(); it != items->end(); it++){
      if((strcmp((it)->second, item)) == 0){
	(it)->second = nullptr;
	break;
      }
    }
  } else if (doodad == 1){
    for(map<int, char*>::iterator it = items->begin(); it != items->end(); it++){
      if(location == (it)->first){
	(it)->second = item;
	break;
      }
    }
  }
}
