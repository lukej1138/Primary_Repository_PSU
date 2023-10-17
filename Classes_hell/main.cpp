#include <iostream>
#include <cstring>
#include <vector>
#include "vid_games.h"
#include "music.h"
#include "movie.h"
//remember children .h files. They themselves should reference the parent.h
//1. Create user input functions like studentlist
//2. Create appropriate other classes (parent media, children Videogames, Music, Movies
//3. Create ADD, SEARCH, DELETE functions. Look over rule of three for delete.
using namespace std;

char* get_input();

int main(){
  //use code from studentList, running a while loop for the duration of
  //program
  //Vector of media (pointers)
  char* to_do = new char[11];
  bool program = true;
  vector<media*> helpMe;

  
  char* help = new char[21];
  strcpy(help, "heeeeelp ");
  movie* video = new movie(help, help, 1990, 160, 6.1232);

  cout << video->getTitle() << endl;
  cout << video->getDuration() << endl;
  // cout << video->getPublisher() << endl;
  cout << video->getYear() << endl;
  
  while(program){
    strcpy(to_do, get_input());
    if((strcmp(to_do, "ADD")) == 0){

    }
    else if((strcmp(to_do, "SEARCH")) == 0){

    }
    else if((strcmp(to_do, "DELETE")) == 0){

    }
    else {
      program = false;
    }

  }
  
  
}

char* get_input(){
  char* input = new char[11];
  bool valid_input = false;
  while(valid_input == false){
    cout << "Please choose to either add, search, or delete media with the keywords ADD, SEARCH, or DELETE. Or quit with the keyword QUIT" << endl;
    cin.get(input, 10);
    cin.get();
    cout << endl;
    if((strcmp(input, "ADD")) != 0 && (strcmp(input, "SEARCH")) != 0 && (strcmp(input, "DELETE")) != 0 && (strcmp(input, "QUIT")) != 0){
      cout << "Please enter a valid input." << endl;
      continue;
    }
    valid_input = true;
  }
  return input;


}
