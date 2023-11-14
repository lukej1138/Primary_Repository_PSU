/*
  Lucas Johnson
  11/14/23
  Header file for room class
 */

//Header guard
#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

class room {
 public:
  //Constructor
  room(char* name, map<int, char*>* rmItems, int id, map<char*, int>* exits, char* rmdescription);
  void printItems();

  //getters, printers, and setters
  int getId();

  void printExits(vector<room*> rooms);

  char* getRmdescription();

  //Used for adding/removing items in a room AFTER the room is created (so like dropping/getting items in room)
  void setItems(char* item, int doodad, map<int, char*>* items, int location);

  //Sets the exits like normal
  void setExits(map<char*, int>* mp);

  char* getName();

  //destructor
  ~room();

  //More Getters
  map<char*, int>* getExits();

  map<int, char*>* getItems();

  //Fields for each constructor
  map<int, char*>* rmItems;
  map<char*, int>* exits;
  char* rmdescription;
  int id;
  char* name;
};
#endif
