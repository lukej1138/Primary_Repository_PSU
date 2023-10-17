#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class music : public media {
 public:
  music(char* title, char* artist, int year, int duration, char* publisher);
  virtual char* getArtist();
  virtual int getDuration();
  virtual char* getPublisher();
  virtual ~music();
 protected:
  char* arti;
  int durate;
  char* publisher;

};
#endif
