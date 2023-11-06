#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

class room {
 public:
  room(char* name, map<int, char*>* rmItems, int id, map<char*, int>* exits, char* rmdescription);
  void printItems(map<int, char*>* items);

  int getId();

  void printExits(map<char*, int>* exits, vector<room*> rooms);

  char* getRmdescription();

  void setItems(char* item, int doodad, map<int, char*>* items, int location);

  void setExits(map<char*, int>* mp);

  char* getName();

  ~room();

  map<int, char*>* rmItems;
  map<char*, int>* exits;
  char* rmdescription;
  int id;
  char* name;
};
#endif
