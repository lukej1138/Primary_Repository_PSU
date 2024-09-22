#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;

student::student(int id, float gpa, char* name){
  n = new char[31];
  strcpy(n, name);
  i = id;
  g = gpa;
}

student::~student(){
  delete[] this->n;
}

float student::getGpa(){
  return g;
}

int student::getId(){
  return i;
}

char* student::getName(){
  return n;
}
