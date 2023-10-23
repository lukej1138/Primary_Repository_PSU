/*Lucas Johnson
  10/23/23
  Media cpp file (parent)
 */
#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;
//Constructor
media::media(int newyear, char* newtitle){
  year = newyear;
  title = new char[21];
  strcpy(title, newtitle);

}
//getters
char* media::getTitle(){
  return title;
}

int media::getYear(){
  return year;

};
//Destructor
media::~media(){
  delete[] title;

}
