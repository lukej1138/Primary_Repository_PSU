#include "room.h"
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

//Make all uppercase
//Get input. Split into two words. Determine keyword and secondary word.

char* getInput();
void setrmItems(map<int,char*>* &mp, int id, char* item);
void setMapExitsUp(map<char*, int>* &mp, room* north, room* south, room* east, room* west);



int main(){
  map<int, char*>* rmItems1 = new map<int, char*>();
  setrmItems(rmItems1, 0, nullptr);
  char* name1 = new char[21];
  strcpy(name1, "castle entrance");
  char* rmdescription1 = new char[801];
  strcpy(rmdescription1, "You start your adventure at the entrance of a mighty castle, riddled with mysteries. Past the drawbridge (lowered) is a mudroom.");
  room* castleEntrance = new room(name1, rmItems1, 1, nullptr, rmdescription1);
  cout << castleEntrance->getId() << endl;
  castleEntrance->printItems(rmItems1);


  
}

//Sets up map to be given as a field for the room
void setrmItems(map<int,char*>* &mp, int id, char* item){
  for(int i = 1; i < 6; i++){
    if(i != id){
      mp->insert(pair<int, char*>(i, nullptr));
      continue;
    }
    mp->insert(pair<int, char*>(id, item));

  }
}
//sets up the exits (not a setter)
void setMapExitsUp(map<char*, int>* &mp, room* north=nullptr, room* south=nullptr, room* east=nullptr, room* west=nullptr){
  for(int counter = 1; counter < 5; counter++){
    if(counter == 1 && north !=nullptr){
      char* north1 = new char[21];
      strcpy(north1, "north");
      mp->insert(pair<char*,int>(north1, north->getId()));
    }
    else if(counter == 2 && south != nullptr){
      char* south1 = new char[21];
      strcpy(south1, "south");
      mp->insert(pair<char*,int>(south1, south->getId()));
    }
    else if(counter == 3 && east!=nullptr){
      char* east1 = new char[21];
      strcpy(east1, "east");
      mp->insert(pair<char*,int>(east1, east->getId()));
    }
    else if(counter == 4 && west!=nullptr){
      char* west1 = new char[21];
      strcpy(west1, "west");
      mp->insert(pair<char*, int>(west1, west->getId()));

    }

    
  
  
  
  
  
  
  
  
  
   
   
   
   
   
  
  
  
  
  
  
  
  
  
  
  
  
  
  




  }

}
  
  

