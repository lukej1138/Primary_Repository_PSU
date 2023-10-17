#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

class vid_games : public media {
 public:
  vid_games(char* title, int year, char* pub, float rating);
  virtual char* getPublisher();
  virtual float getRating();
  virtual ~vid_games();
 protected:
  char* publisher;
  float rating;


};
