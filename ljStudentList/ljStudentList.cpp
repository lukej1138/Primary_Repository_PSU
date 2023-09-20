#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
/*
  Lucas Johnson
  9/20/23
  Creates a program that stores inputted students, as well as prints/deletes them.
 */


using namespace std;


//Struct used when making a student
struct Student_stuff {
  char first_name[21];
  char last_name[21];
  int id;
  float GPA;

};

//All functions
char* valid_input();
void add_func(vector<Student_stuff*> &list);
void del_func(vector<Student_stuff*> &list);
void prnt_func(vector<Student_stuff*> &list);

int main(){
  //First we create a new vector of student pointers
  vector<Student_stuff*> da_list;
  bool programRunning = true;
  //Create input cstring, as well as loop that runs while program is active
  char* to_do = new char[11];
  while(programRunning){
    //calls valid input to get user input, copying it/overwriting to_do
    strcpy(to_do, valid_input());
    //determines the users input, runs appropriate function
    if((strcmp(to_do, "ADD")) == 0){
      add_func(da_list);
    }
    else if((strcmp(to_do, "DELETE")) == 0){
      del_func(da_list);

    } else if((strcmp(to_do, "PRINT")) == 0){
      prnt_func(da_list);

    } else if((strcmp(to_do, "QUIT")) == 0){
      programRunning = false;

    }

  }
  


}

//makes input pointer cstring, uses while loop to get proper user input.
//When proper input is attained, returns it to be used later.
char* valid_input(){
  cout << endl;
  char* input = new char[11];
  bool good_input = false;
  while(good_input == false){
    cout << "Please input what you would like to do (ADD, PRINT, DELETE, QUIT). There is a character limit of 10." << endl;
    cin.get(input, 20);
    cin.get();
    if((strcmp(input, "ADD") != 0) && (strcmp(input,"DELETE") != 0) && (strcmp(input,"PRINT") != 0) && (strcmp(input, "QUIT") != 0)){
      cout << "Please select a valid input" << endl;
      continue;
    }
    else{
      good_input = true;
    }
    

  }
  return input;
}

//When user chooses to add a player, this function asks them for all essential elements to make a new student struct variable
//Once created, the student variable is stored in the vector made in main. 
void add_func(vector<Student_stuff*> &list){
  char* name1 = new char[21];
  char* name2 = new char[21];
  int id = 0;
  float gpa = 0.0;
  cout << "What is the students first name? (20 characters max)" << endl;
  cin.get(name1, 20);
  cin.get();
  Student_stuff* student1 = new Student_stuff();
  strcpy(student1->first_name, name1);

  cout << "Last name? (20 char max)" << endl;
  cin.get(name2, 20);
  cin.get();
  strcpy(student1->last_name, name2);

  cout << "Student ID? (6 digits)" << endl;
  cin >> id;
  cin.get();
  cout << endl;
  student1->id = id;

  cout << "GPA? (0.0 -> 4.0)" << endl;
  cin >> gpa;
  cin.get();
  cout << endl;
  student1 -> GPA = gpa;
  list.push_back(student1);

  cout << "New student " << student1->first_name << " created." << endl;
  


}

//Determines the id of the student the code wants to delete, uses iterator to go through vector and determine if that student exists. If it does, the pointer is deleted and erased
//from the vector.
void del_func(vector<Student_stuff*> &list){
  int find_id = 0;
  cout << "What's the id of the student you want to delete?" << endl;
  cin >> find_id;
  cin.get();
  for(vector<Student_stuff*>::iterator it = list.begin(); it != list.end(); it++){
    if(find_id == (*it)->id){
      delete *it;
      list.erase(it);
      cout << "Successfully deleted student" << endl;
      return;

    }

  }
  cout << "Sorry, we couldn't find that student in our directory." << endl;


}
//Prints out each student and their additional information.
void prnt_func(vector<Student_stuff*> &list){
  for(vector<Student_stuff*>::iterator it = list.begin(); it != list.end(); it++){
    cout << (*it)->first_name << " " << (*it)->last_name << ", " << (*it)->id << ", " << setprecision(2) << (*it)->GPA << endl;

  }

}
