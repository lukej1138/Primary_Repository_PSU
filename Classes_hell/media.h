#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class media {
 public:
  media(int newyear, char* newtitle);
  char* getTitle();
  int getYear();

 protected:
  char* title;
  int year;
  


};
#endif
