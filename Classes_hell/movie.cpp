#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

movie::movie(char* title, char* director, int year, int duration, float rating) : media(year, title){
  direct = new char[21];
  strcpy(direct, director);
  durate = duration;
  rate = rating;
}

char* movie::getDirector(){
  return direct;
}

int movie::getDuration(){
  return durate;
}

float movie::getRating(){
  return rate;
}

movie::~movie(){
  delete[] direct;
  delete[] title;
}
