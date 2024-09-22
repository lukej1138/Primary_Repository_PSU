/*
  LJCoolJ (lucasJohnson)
  11/14/23
  Main File for Zuul Game
  Note: I use a map w/ an id and char* for my items. Mr. G confirmed
  that I could do this, even tho it isn't a struct/class. 
 */


#include "room.h"
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;



//Make sure to delete all pointers when done with them.
char* getInput();
void setrmItems(map<int,char*>* &mp, int id, char* item);
void setMapExitsUp(map<char*, int>* &mp, room* north, room* south, room* east, room* west);
void basicInfo(room* r, vector<room*> board, map<int, char*>* inventory);
void getInput(char* ogStr, char* cmd, char* location);

int main(){
  //The holy vector of rooms
  vector<room*> board;

  //Room Declarations. Setting up name, descriptions, items, and finally the room object itself
  //Room 1
  map<int, char*>* rmItems1 = new map<int, char*>();
  setrmItems(rmItems1, 0, nullptr);
  char* name1 = new char[21];
  strcpy(name1, "castle entrance");
  char* rmdescription1 = new char[401];
  strcpy(rmdescription1, "You start your adventure at the entrance of a mighty castle, riddled with mysteries. Past the drawbridge (lowered) is a mudroom.");
  room* castleEntrance = new room(name1, rmItems1, 1, nullptr, rmdescription1);
  board.push_back(castleEntrance);

  //Room 2
  map<int,char*>* rmItems2 = new map<int,char*>();
  setrmItems(rmItems2, 0, nullptr);
  char* name2 = new char[21];
  strcpy(name2, "mudroom");
  char* rmdescription2 = new char[401];
  strcpy(rmdescription2, "This is a mudroom, filled with boots and whatnot. Lots of armor too. But you can't have any of that because i'm lazy. Mwahaha. Anyways, eastwards is what appears to be a bigger armory, and south seems to be a sick ward.");
  room* mudRoom = new room(name2, rmItems2, 2, nullptr, rmdescription2);
  board.push_back(mudRoom);
  
  //Room 3
  map<int,char*>* rmItems3 = new map<int,char*>();
  char* rustyHelmet = new char[21];
  strcpy(rustyHelmet, "A Dope Rusty Helmet");
  setrmItems(rmItems3, 1, rustyHelmet);
  char* name3 = new char[21];
  strcpy(name3, "Armory");
  char* rmdescription3 = new char[401];
  strcpy(rmdescription3, "You enter a cool looking armory, weapons and armor all rotting away.");
  room* armory = new room(name3, rmItems3, 3, nullptr, rmdescription3);
  board.push_back(armory);

  //Room 4
  map<int, char*>* rmItems4 = new map<int, char*>();
  setrmItems(rmItems4, 0, nullptr);
  char* name4 = new char[21];
  strcpy(name4, "Soldier Quarters");
  char* rmdescription4 = new char[401];
  strcpy(rmdescription4, "You enter an old, decrepit sleeping quarters for soldiers. Nothing much in here though.");
  room* soldierQuarter = new room(name4, rmItems4, 4, nullptr, rmdescription4);
  board.push_back(soldierQuarter);

  //Room 5
  map<int, char*>* rmItems5 = new map<int, char*>();
  char* knife = new char[21];
  strcpy(knife, "A butcher knife");
  setrmItems(rmItems5, 2, knife);
  char* name5 = new char[21];
  strcpy(name5, "kitchen");
  char* rmdescription5 = new char[401];
  strcpy(rmdescription5, "An old kitchen. Seems pretty old and rustic, but has a good vibe. Hopefully no one died here.");
  room* kitchen = new room(name5, rmItems5, 5, nullptr, rmdescription5);
  board.push_back(kitchen);

  //Room 6
  map<int, char*>* rmItems6 = new map<int, char*>();
  setrmItems(rmItems6, 0, nullptr);
  char* name6 = new char[21];
  strcpy(name6, "Sick Ward");
  char* rmdescription6 = new char[401];
  strcpy(rmdescription6, "You enter what appears to be an abandoned infirmary. Nothing of importance here");
  room* sickWard = new room(name6, rmItems6, 6, nullptr, rmdescription6);
  board.push_back(sickWard);
  
  //Room 7
  map<int, char*>* rmItems7 = new map<int, char*>();
  char* scrolls = new char[21];
  strcpy(scrolls, "Burned Dragon Scrolls");
  setrmItems(rmItems7, 3, scrolls);
  char* name7 = new char[21];
  strcpy(name7, "Throne Room");
  char* rmdescription7 = new char[401];
  strcpy(rmdescription7, "You enter a massive room filled with gold. A dragon sits in the middle, sleeping soundly. Scrolls cover the ground.");
  room* throneRoom = new room(name7, rmItems7, 7, nullptr, rmdescription7);
  board.push_back(throneRoom);
  
  //Room 8
  map<int, char*>* rmItems8 = new map<int, char*>();
  setrmItems(rmItems8, 0, nullptr);
  char* name8 = new char[21];
  strcpy(name8, "Servant Quarters");
  char* rmdescription8 = new char[401];
  strcpy(rmdescription8, "You enter the sleeping quarters of the servants. Very tidy place, but nothing of value here");
  room* servantQuarters = new room(name8, rmItems8, 8, nullptr, rmdescription8);
  board.push_back(servantQuarters);

  //Room 9
  map<int, char*>* rmItems9 = new map<int, char*>();
  char* name9 = new char[21];
  strcpy(name9, "Dining Room");
  char* can = new char[21];
  strcpy(can, "Old Can");
  setrmItems(rmItems9, 4, can);
  char* rmdescription9 = new char[401];
  strcpy(rmdescription9, "You enter a dining room. Its... just a pretty cool dining room, that's about it.");
  room* diningRoom = new room(name9, rmItems9, 9, nullptr, rmdescription9);
  board.push_back(diningRoom);
  
  //Room 10
  map<int, char*>* rmItems10 = new map<int, char*>();
  char* tome = new char[21];
  strcpy(tome, "A Wizard's Tome");
  setrmItems(rmItems10, 5, tome);
  char* name10 = new char[21];
  strcpy(name10, "Wizard's Lair");
  char* rmdescription10 = new char[601];
  strcpy(rmdescription10, "You enter a spiraling wizard tower. Books and scrolls line the walls, and a large blue orb sits in the middle of the entire room. You try and touch it, but nothing happens. You can't move it either.");
  room* wizardLair = new room(name10, rmItems10, 10, nullptr, rmdescription10);
  board.push_back(wizardLair);
  
  //Room 11
  map<int, char*>* rmItems11 = new map<int, char*>();
  setrmItems(rmItems11, 0, nullptr);
  char* name11 = new char[21];
  strcpy(name11, "Cannon Room");
  char* rmdescription11 = new char[401];
  strcpy(rmdescription11, "A room filled with cannons, cannonballs, and other ordinance");
  room* cannonRoom = new room(name11, rmItems11, 11, nullptr, rmdescription11);
  board.push_back(cannonRoom);
  
  //Room 12
  map<int, char*>* rmItems12 = new map<int, char*>();
  setrmItems(rmItems12, 0, nullptr);
  char* name12 = new char[21];
  strcpy(name12, "Dungeon");
  char* rmdescription12 = new char[401];
  strcpy(rmdescription12, "An old, run-down dungeon. Nothing of note here, except a few corpes. Gross.");
  room* dungeon = new room(name12, rmItems12, 12, nullptr, rmdescription12);
  board.push_back(dungeon);

  //Room 13
  map<int, char*>* rmItems13 = new map<int, char*>();
  setrmItems(rmItems13, 0, nullptr);
  char* name13 = new char[21];
  strcpy(name13, "Kings Chambers");
  char* rmdescription13 = new char[401];
  strcpy(rmdescription13, "A royal chamber, fit for a king. Pretty cool bed you can bounce on.");
  room* kingBed = new room(name13, rmItems13, 13, nullptr, rmdescription13);
  board.push_back(kingBed);

  //Room 14
  map<int, char*>* rmItems14 = new map<int, char*>();
  setrmItems(rmItems14, 0, nullptr);
  char* name14 = new char[21];
  strcpy(name14, "bathroom");
  char* rmdescription14 = new char[401];
  strcpy(rmdescription14, "A pretty olden-style bathroom. Diamond studded toilet, golden tp rolls, the works.");
  room* bathroom = new room(name14, rmItems14, 14, nullptr, rmdescription14);
  board.push_back(bathroom);

  //Room 15
  map<int, char*>* rmItems15 = new map<int, char*>();
  setrmItems(rmItems15, 0, nullptr);
  char* name15 = new char[21];
  strcpy(name15, "escape tunnel");
  char* rmdescription15 = new char[300];
  strcpy(rmdescription14, "You enter a room with a big door in front of you, but it seems to be sealed off. Maybe if you got more items, it would open...");
  room* escape = new room(name15, rmItems15, 15, nullptr, rmdescription15);
  board.push_back(escape);


  //Set Exits
  map<char*, int>* exits1 = new map<char*,int>();
  setMapExitsUp(exits1, nullptr, nullptr, mudRoom, nullptr);
  castleEntrance->setExits(exits1);

  map<char*,int>* exits2 = new map<char*, int>();
  setMapExitsUp(exits2, nullptr, sickWard, armory, castleEntrance);
  mudRoom->setExits(exits2);

  map<char*,int>* exits3 = new map<char*, int>();
  setMapExitsUp(exits3, nullptr, nullptr, soldierQuarter, mudRoom);
  armory->setExits(exits3);

  map<char*, int>* exits4 = new map<char*, int>();
  setMapExitsUp(exits4, nullptr, nullptr, kitchen, armory);
  soldierQuarter->setExits(exits4);

  map<char*, int>* exits5 = new map<char*,int>();
  setMapExitsUp(exits5, nullptr, servantQuarters, nullptr, soldierQuarter);
  kitchen->setExits(exits5);

  map<char*, int>* exits6 = new map<char*,int>();
  setMapExitsUp(exits6, mudRoom, diningRoom, throneRoom, nullptr);
  sickWard->setExits(exits6);

  map<char*, int>* exits7 = new map<char*,int>();
  setMapExitsUp(exits7, nullptr, wizardLair, servantQuarters, sickWard);
  throneRoom->setExits(exits7);

  map<char*,int>* exits8 = new map<char*, int>();
  setMapExitsUp(exits8, kitchen, cannonRoom, nullptr, throneRoom);
  servantQuarters->setExits(exits8);

  map<char*, int>* exits9 = new map<char*, int>();
  setMapExitsUp(exits9, sickWard, dungeon, wizardLair, nullptr);
  diningRoom->setExits(exits9);

  map<char*,int>* exits10 = new map<char*, int>();
  setMapExitsUp(exits10, throneRoom, nullptr, cannonRoom, diningRoom);
  wizardLair->setExits(exits10);

  map<char*, int>* exits11 = new map<char*,int>();
  setMapExitsUp(exits11, servantQuarters, nullptr, nullptr, wizardLair);
  cannonRoom->setExits(exits11);

  map<char*, int>* exits12 = new map<char*,int>();
  setMapExitsUp(exits12, diningRoom, nullptr, kingBed, nullptr);
  dungeon->setExits(exits12);

  map<char*, int>* exits13 = new map<char*,int>();
  setMapExitsUp(exits13, nullptr, nullptr, bathroom, dungeon);
  kingBed->setExits(exits13);

  map<char*,int>* exits14 = new map<char*,int>();
  setMapExitsUp(exits14, nullptr, nullptr, escape, kingBed);
  bathroom->setExits(exits14);

  map<char*,int>* exits15 = new map<char*,int>();
  setMapExitsUp(exits15, nullptr, nullptr, nullptr, bathroom);
  escape->setExits(exits15);
    
  //Running the game
  //Sets up basic variables to be used later on
  bool gameRunning = true;
  room* currentRoom = castleEntrance;
  char* cmd = new char[21];
  char* location = new char[31];

  //Set up inventory, similar to setting up exits/items in each room.
  char* ogStr = new char[31];
  map<int, char*>* inventory = new map<int, char*>();
  for(int i = 1; i < 6; i++){
    char* newSpace = new char[21];
    strcpy(newSpace, " ");
    inventory->insert(pair<int, char*>(i, newSpace)); 
  }


  
  while(gameRunning){
    //Prints basic info and gets input
    basicInfo(currentRoom, board, inventory);
    getInput(ogStr, cmd, location);

    //Determines correct command and goes from there.
    if((strcmp(cmd, "GO")) == 0){
      //First determines the id of the exit the player wants to go to.
      int currId = 0;
      for(map<char*, int>::iterator it = (currentRoom->getExits())->begin(); it != (currentRoom->getExits())->end(); it++){
	if((strcmp(location, it->first)) == 0){
	  currId = (it->second);
	}
      }

      //Runs through board until it finds the room the player wants to go to (using Id)
      int counter = 0;
      bool foundRoom = false;
      for(vector<room*>::iterator it = board.begin(); it != board.end(); it++){
	if(currId == board[counter]->getId()){
	  //Sets that room to the current one
	  currentRoom = board[counter];
	  foundRoom = true;
	  break;
	}
	counter++;
      }
      //In case no room was found.
      if(foundRoom == false){
	cout << "Please choose an actual room" << endl;

      }

      //Win condition. Determines if the players inventory is full/they are in dungeon. If both conditions are met, a little congrats is printed, the game stop running, and the room pointers
      //are deleted
      bool allFull = true;
      for(map<int, char*>::iterator it = inventory->begin(); it != inventory->end(); it++){
	if((strcmp(it->second, " ")) == 0){
	  allFull = false;
	  break;
	}
      }
      if(allFull == true && (currentRoom->getId()) == (escape->getId())){
	cout << "Congrats, you got all the items and made it to the end!!" << endl;
	cout << "Thanks for exploring my dungeon! :D" << endl;
	gameRunning = false;

	for(vector<room*>::iterator it = board.begin(); it != board.end(); it++){
	  delete *it;
	}

      }

      
    }
    else if((strcmp(cmd, "GET")) == 0){
      bool found = false;
      int foundId = 0;
      char* foundItem = new char[21];
      //looks for the item in the currentRoom's map of items. If it finds it, it'll set the id and item name to outside variables.
      for(map<int, char*>::iterator it = (currentRoom->getItems())->begin(); it != (currentRoom->getItems())->end(); it++){
	if((strcmp(it->second, location)) == 0){
	  foundId = it->first;
	  strcpy(foundItem, it->second);
	  break;
	}
      }
      //Gets the item found in the previous loop into the inventory
      for(map<int, char*>::iterator it1 = inventory->begin(); it1 != inventory->end(); it1++){
	if(it1->first == foundId){
            strcpy(it1->second, foundItem);
	    //Removes the item from the rooms "floor"
	    currentRoom->setItems(foundItem, 0, currentRoom->getItems(), foundId);
	    found = true;
	    break;
	  }
        }
      //In case no such item exists in the room.
      if(found == false){
        cout << "Sorry, their is no such item in this room." << endl;
      }
    }

    //Reverse of GET
    else if ((strcmp(cmd, "DROP")) == 0){
      int foundId = 0;
      char* foundItem = new char[21];
      bool itWorked = false;
      //Looks through inventory, finds the appropriate item, removes it, adds it to inventory
      for(map<int, char*>::iterator it = inventory->begin(); it != inventory->end(); it++){
	if((strcmp(it->second, location)) == 0){
	  foundId = it->first;
	  strcpy(foundItem, it->second);
	  strcpy(it->second, " ");
	  currentRoom->setItems(foundItem, 1, currentRoom->getItems(), foundId);
	  itWorked = true;
	  break;
	}
      }
      //In case no item was found
      if(itWorked == false){
	cout << "Sorry, we couldn't find that item in your inventory" << endl;

      }

    }
    //Quits out of the game and runs the destructor
    else if((strcmp(cmd, "QUIT")) == 0){
      gameRunning = false;
      for(vector<room*>::iterator it = board.begin(); it != board.end(); it++){
	delete *it;
      }
    }
  }
}

//Sets up map to be given as a field for the room
void setrmItems(map<int,char*>* &mp, int id, char* item){
  for(int i = 1; i < 6; i++){
    if(i != id){
      char* space = new char[21];
      strcpy(space, " ");
      //Provides id/space for each item
      mp->insert(pair<int, char*>(i, space));
      continue;
    }
    mp->insert(pair<int, char*>(id, item));

  }
}
//sets up the map of exits as a field for the room(not a setter)
void setMapExitsUp(map<char*, int>* &mp, room* north=nullptr, room* south=nullptr, room* east=nullptr, room* west=nullptr){
  for(int counter = 1; counter < 5; counter++){
    if(counter == 1 && north !=nullptr){
      //Uses ids of passed-in rooms to identify them later on (when we print exits)
      char* north1 = new char[21];
      strcpy(north1, "NORTH");
      mp->insert(pair<char*,int>(north1, north->getId()));
    }
    else if(counter == 2 && south != nullptr){
      char* south1 = new char[21];
      strcpy(south1, "SOUTH");
      mp->insert(pair<char*,int>(south1, south->getId()));
    }
    else if(counter == 3 && east!=nullptr){
      char* east1 = new char[21];
      strcpy(east1, "EAST");
      mp->insert(pair<char*,int>(east1, east->getId()));
    }
    else if(counter == 4 && west!=nullptr){
      char* west1 = new char[21];
      strcpy(west1, "WEST");
      mp->insert(pair<char*, int>(west1, west->getId()));

    }  

  }

}
//Runs when a player enters a room/does an action, providing basic info
void basicInfo(room* r, vector<room*> board, map<int, char*>* inventory){
  cout << "Name of room: " << r->getName() << endl;
  cout << r->getRmdescription() << endl;
  cout << "Current Items in room: ";
  r->printItems();
  cout << endl;
  cout << "Exits: ";
  r->printExits(board);
  cout << endl;

  cout << "Items in inventory: " << endl;
  for(map<int,char*>::iterator it = inventory->begin(); it != inventory->end(); it++){
    cout << it->second << ", ";
  }
  cout << endl;
  cout << endl;
  

}
//Takes in an input, splits words into either a command or a location by finding the first space
void getInput(char* ogStr, char* cmd, char* location){
  cout << "What would you like to do? "<< endl;
  cout << "Please type everything except item names in uppercase, using NORTH, SOUTH, etc. for location and GO/GET/DROP/QUIT for locations and items (or if you want to quit). Please type item names exactly." << endl;
  cin.get(ogStr, 30);
  cin.get();

  char* cmd1 = new char[21];
  char* location1 = new char[31];
  
  int counter1 = 0;
  //Finds the space
  for(int i = 0; i < strlen(ogStr); i++){
    if(ogStr[i] == ' '){
      counter1 = i;
      break;
    }
  }
  //Reads in up to space to get cmd, copies into actual cmd portion at the very end.
  for(int i = 0; i < counter1; i++){
    cmd1[i] = ogStr[i];
  }
  cmd1[counter1+1] = '\0';


  int counter2 = 0;
  //Reads in from space to end of inputted phrase to get item/room
  for(int i = counter1+1; i < strlen(ogStr); i++){
    location1[counter2] = ogStr[i];
    counter2++;
  }
  location1[counter2] = '\0';
  
  strcpy(cmd, cmd1);
  strcpy(location, location1);
  return;


}
