#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

class movie : public media {
 public:
  movie(char* title, char* director, int year, int duration, float rating);
  virtual char* getDirector();
  virtual int getDuration();
  virtual float getRating();
  virtual ~movie();
 protected:
  char* direct;
  int durate;
  float rate;


};





#endif
