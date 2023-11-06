/*
  Lucas Johnson
  10/23/23
  Header file for movie child class
*/
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

class movie : public media {
 public:
  //Constructor for movie with appropriate fields. Again title and year
  //are universal fields, so the media constructor is called for these
  movie(char* title, char* director, int year, int duration, float rating);
  //getters
  virtual char* getDirector();
  virtual int getDuration();
  virtual float getRating();
  //destructor
  virtual ~movie();
 protected:
  //Specific fields.
  char* direct;
  int durate;
  float rate;


};





#endif
