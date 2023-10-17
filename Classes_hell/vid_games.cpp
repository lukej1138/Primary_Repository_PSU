#include <iostream>
#include <cstring>
#include "vid_games.h"
using namespace std;

vid_games::vid_games(char* title, int year, char* pub, float rating):media(year, title){
  publisher  = new char[21];
  strcpy(publisher, pub);
  this->rating = rating;
}

char* vid_games::getPublisher(){
  return publisher;
}

float vid_games::getRating(){
  return rating;

}

vid_games::~vid_games(){
  delete[] title;
  delete[] publisher;

}
