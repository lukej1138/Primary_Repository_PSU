/*Lucas Johnson
  10/23/23
  Parent Media header file
*/
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class media {
 public:
  //Media constructor for universal fields. Used w/every child constructor
  media(int newyear, char* newtitle);
  //Getters
  virtual char* getTitle();
  virtual int getYear();
  //Destructor for media. It's called with every child destructor.
  virtual ~media();
 protected:
  //Fields
  char* title;
  int year;
  


};
#endif
