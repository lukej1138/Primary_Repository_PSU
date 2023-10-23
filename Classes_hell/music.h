/*Lucas Johnson
  10/23/23
  Header for music clas
*/
//Header for header
#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music : public media {
 public:
  //Constructor which takes 5 arguments and assigns them to 5 fields
  //Note that for title and year, the parent function is called.
  music(char* title, char* artist, int year, int duration, char* publisher);
  //Getters for various fields specific for the class
  //Title/year getters are given to children from media.h
  virtual char* getArtist();
  virtual int getDuration();
  virtual char* getPublisher();
  //Destructor for cstrings.
  virtual ~music();
  //Variables
 protected:
  char* arti;
  int durate;
  char* publisher;

};
#endif
