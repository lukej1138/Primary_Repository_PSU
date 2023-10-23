/*Lucas Johnson
  10/23/23
  video game cpp file
*/
#include <iostream>
#include <cstring>
#include "vid_games.h"
using namespace std;
//Constructor
vid_games::vid_games(char* title, int year, char* pub, float rating):media(year, title){
  publisher  = new char[21];
  strcpy(publisher, pub);
  this->rating = rating;
}
//Getters
char* vid_games::getPublisher(){
  return publisher;
}

float vid_games::getRating(){
  return rating;

}
//Destructor
vid_games::~vid_games(){
  delete[] publisher;

}
