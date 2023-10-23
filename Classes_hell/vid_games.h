/*Lucas Johnson
  10/23/23
  Videogame class header
*/
#ifndef VID_GAMES_H
#define VID_GAMES_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class vid_games : public media {
 public:
  //Video_game destructor which sets up fields for use by objects
  vid_games(char* title, int year, char* pub, float rating);
  //Getters
  virtual char* getPublisher();
  virtual float getRating();
  //Destructor for appropriate cstrings
  virtual ~vid_games();
 protected:
  //Specific fields (to the child)
  char* publisher;
  float rating;


};

#endif
