/*
  Lucas Johnson
  10/23/23
  Main File that runs all code and associated classes.
  Program itself allows the search, addition, and removal of media files and its children.
 */

//Includes
#include <iostream>
#include <cstring>
#include <vector>
#include "vid_games.h"
#include "music.h"
#include "movie.h"
using namespace std;

//List of functions
char* get_input();
void add_func(vector<media*> &v);
void search_func(vector<media*> &v);
void del_func(vector<media*> &v);

int main(){
  //Reused from my studentList project, essentially a while loop that gets input and runs until the user inputs QUIT
  char* to_do = new char[11];
  bool program = true;
  vector<media*> helpMe;


  while(program){
    strcpy(to_do, get_input());
    //Uses strcmp to determine what keyword was used. Appropriate
    //functio is run from their.
    if((strcmp(to_do, "ADD")) == 0){
      add_func(helpMe);

    }
    else if((strcmp(to_do, "SEARCH")) == 0){
      search_func(helpMe);

    }
    else if((strcmp(to_do, "DELETE")) == 0){
      del_func(helpMe);
    }
    else {
      //Breaks the loop by changing program variable
      //Uses iterator to run through vector and delete all pointers.
      //Class destructors delete appropriate items on the heap
      program = false;
      for(vector<media*>::iterator it = helpMe.begin(); it != helpMe.end(); it++){
	delete (*it);
      }
    }

  }
  
  
}

//Gets input, checks to make sure its a keyword, and shoots it to main
char* get_input(){
  char* input = new char[11];
  bool valid_input = false;
  while(valid_input == false){
    cout << "Please choose to either add, search, or delete media with the keywords ADD, SEARCH, or DELETE. Or quit with the keyword QUIT" << endl;
    cin.get(input, 10);
    cin.ignore(10, '\n');
    cout << endl;
    if((strcmp(input, "ADD")) != 0 && (strcmp(input, "SEARCH")) != 0 && (strcmp(input, "DELETE")) != 0 && (strcmp(input, "QUIT")) != 0){
      cout << "Please enter a valid input." << endl;
      continue;
    }
    valid_input = true;
  }
  return input;


}

//Determines the type of media before requesting the proper information and
//creating a new object of the correct class
//Finally, adds this child object to the vector (which stores the parent)
void add_func(vector<media*> &v){
  char input[21];
  cout << "Please input the type of media you'd like to add (MUSIC, GAME, MOVIE)" << endl;
  cout << "Please only input up to 20 characters for all inputs" << endl;
  cin.get(input, 20);
  cin.ignore(20, '\n');
  cout << endl;
  if((strcmp(input, "MUSIC")) == 0){
    char* title = new char[21];
    char* artist = new char[21];
    int year;
    int duration;
    char* publisher = new char[21];
    char titl[21];
    char artis[21];
    char publish[21];

    cout << "Please input the song's title (20 characters max)" << endl;
    cin.get(titl, 20);
    cin.get();
    strcpy(title, titl);
    cout << endl;

    cout<< "Please input the artist (20 characters max)" << endl;
    cin.get(artis, 20);
    cin.get();
    strcpy(artist, artis);
    cout << endl;

    cout << "Please input a release year" << endl;
    cin >> year;
    cin.get();
    cout << endl;

    cout << "Please input the song's duration in seconds" << endl;
    cin >> duration;
    cin.get();
    cout << endl;

    cout << "Please input the song's publisher (20 characters max)" << endl;
    cin.get(publish, 20);
    cin.get();
    strcpy(publisher, publish);
    cout << endl;

    music* song = new music(title, artist, year, duration, publisher);
    v.push_back(song);

  }
  else if ((strcmp(input, "GAME")) == 0){
      char* title = new char[21];
      int year;
      char* publisher = new char[21];
      float rating;
      char titl[21];
      char publish[21];

      cout << "Please input the game's title" << endl;
      cin.get(titl, 20);
      cin.get();
      strcpy(title, titl);
      cout << endl;

      cout << "Please input the game's publisher" << endl;
      cin.get(publish, 20);
      cin.get();
      strcpy(publisher, publish);
      cout << endl;

      cout << "Please input the game's release year" << endl;
      cin >> year;
      cin.get();
      cout << endl;

      cout << "What is the game's rating? (0-5)" << endl;
      cin >> rating;
      cin.get();
      cout << endl;

      vid_games* game = new vid_games(title, year, publisher, rating);
      v.push_back(game);


  } else if ((strcmp(input, "MOVIE")) == 0){
	char* title = new char[21];
	char* director = new char[21];
	int year;
	int duration;
	float rating;
	char titl[21];
	char directo[21];

	cout << "Please input the film's title" << endl;
	cin.get(titl, 20);
	cin.get();
	strcpy(title, titl);
	cout << endl;

	cout << "Please input the film's director" << endl;
	cin.get(directo, 20);
	cin.get();
	strcpy(director, directo);
	cout << endl;

	cout << "Please input the films duration in minutes" << endl;
	cin >> duration;
	cin.get();
	cout << endl;

	cout << "Please input the films release year" << endl;
	cin >> year;
	cin.get();
	cout << endl;

	cout << "Please input the films rating (0-5)" << endl;
	cin >> rating;
	cin.get();
	cout << endl;

	movie* movi = new movie(title, director, year, duration, rating);
	v.push_back(movi);


      } else {
    //Default response
	cout << "Sorry, that wasn't a valid option" << endl;

      }


}
//Gets the name(title) of the media and looks through the vector.
//Creates a vector of all matches to the title and prints out the vector.
void search_func (vector<media*> &v){
      char* input = new char[21];
      char inpu[21];
      vector<media*> v2;
      cout << "Please input the title (exactly) of the piece of media you want to look for" << endl;
      cin.get(inpu, 20);
      cin.get();
      strcpy(input, inpu);
      cout << endl;

      for(vector<media*>::iterator it = v.begin(); it != v.end(); it++){
	if((strcmp(input, (*it)->getTitle())) == 0){
	  v2.push_back(*it);
	}

      }
      if(v2.size() == 0){
	//If there are no hits
	cout << "Sorry, we found no matches based on your input" << endl; 

      } else
	{
	  cout << "List of matches: " << endl;
	  for(vector<media*>::iterator it = v2.begin(); it != v2.end(); it++){
	    cout << "Title: " << (*it)->getTitle() << ", Year released: " << (*it)->getYear() << endl;
	  }
	}

      


    }

//Takes user input for the title of the media that should be deleted
//Runs through and checks if the title is in the vector. If it is, the user must confirm and the obj will be deleted.
void del_func(vector<media*> &v){
  char* input = new char[21];
  char inpu[21];
  cout << "Please input the title of the media you want to delete" << endl;
  cin.getline(inpu, 20);
  strcpy(input, inpu);
  cout << endl;

  for(vector<media*>::iterator it = v.begin(); it != v.end(); it++){
    if((strcmp(input, (*it)->getTitle())) == 0){
      cout << "Are you sure you want to delete " << (*it)->getTitle() << "? (y/n)" << endl;
      char newInput[3];
      cin.getline(newInput, 2);
      if((strcmp(newInput, "y")) == 0){
	delete *it;
        v.erase(it);
        cout << "Media has been deleted!" << endl;
        return;
    }

  }

}
}
