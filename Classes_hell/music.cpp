#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

music::music(char* title, char* artist, int year, int duration, char* publisher):media(year, title){
  arti = new char[21];
  this->publisher = new char[21];
  durate = duration;
  strcpy(arti, artist);
  strcpy(this->publisher, publisher);


}

char* music::getArtist(){
  return arti;
}
int music::getDuration(){
  return durate;
}
char* music::getPublisher(){
  return publisher;
}

music::~music(){
  delete[] arti;
  delete[] publisher;
  delete[] title;

}
