/*Lucas Johnson
  10/23/23
  Movie cpp file
*/
#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;
//Constructor
movie::movie(char* title, char* director, int year, int duration, float rating) : media(year, title){
  direct = new char[21];
  strcpy(direct, director);
  durate = duration;
  rate = rating;
}
//Getters
char* movie::getDirector(){
  return direct;
}

int movie::getDuration(){
  return durate;
}

float movie::getRating(){
  return rate;
}

//Destructor
movie::~movie(){
  delete[] direct;

}
