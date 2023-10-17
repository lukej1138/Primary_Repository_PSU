#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

media::media(int newyear, char* newtitle){
  year = newyear;
  title = new char[21];
  strcpy(title, newtitle);

}

char* media::getTitle(){
  return title;
}

int media::getYear(){
  return year;

};
