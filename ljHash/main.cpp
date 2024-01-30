#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "node.h"
/*                                           
  Lucas Johnson                                    
  9/20/23                                           
  Creates a program that stores inputted students, as well as prints/deletes them.                                              
 */


using namespace std;


//Struct used when making a student                                                                                                                                                              
//All functions                                                              
char* valid_input();
node* add_func();
void del_func(node* list[], int size);
void prnt_func(node* list[], int size);
bool hash_sadge(node* &thing, node* list[], int &size);
bool rehash(node* list[], int &size);

int main(){
  int size = 100;
  node* da_list[size];

  for(int i = 0; i< size; i++){
    da_list[i] = NULL;
  }
  bool programRunning = true;
  //Create input cstring, as well as loop that runs while program is active                        
  char* to_do = new char[11];
  while(programRunning){
    //calls valid input to get user input, copying it/overwriting to_do                                                                                                                                     
    strcpy(to_do, valid_input());
    //determines the users input, runs appropriate function                                                                                                                                                 
    if((strcmp(to_do, "ADD")) == 0){
      node* thingy = add_func();
      bool rehash1 = hash_sadge(thingy, da_list, size);
      if(rehash1){
	while(true){
	  bool checker = rehash(da_list, size);
	  if(checker == false){
	    break;
	  }
	}
      }
    }
    else if((strcmp(to_do, "DELETE")) == 0){
      del_func(da_list, size);

    } else if((strcmp(to_do, "PRINT")) == 0){
      prnt_func(da_list, size);

    } else if((strcmp(to_do, "QUIT")) == 0){
      programRunning = false;
    }
  }
}

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
node* add_func(){
  char* name1 = new char[41];
  int id = 0;
  float gpa = 0.0;
  cout << "What is the students name? (40 characters max)" << endl;
  cin.get(name1, 20);
  cin.get();

  cout << "Student ID? (6 digits)" << endl;
  cin >> id;
  cin.get();
  cout << endl;

  cout << "GPA? (0.0 -> 4.0)" << endl;
  cin >> gpa;
  cin.get();
  cout << endl;

  student* stu = new student(id, gpa, name1);
  node* nod = new node(stu);

  cout << "New student " << stu->getName() << " created." << endl;
  return nod;
  

}
void del_func(node* da_list[], int size){
  int find_id = 0;
  cout << "What's the id of the student you want to delete?" << endl;
  cin >> find_id;
  cin.get();
  for(int i = 0; i < size; i++){
    if(find_id == da_list[i]->getStudent()->getId()){
      node* temp = da_list[i];
      da_list[i] = da_list[i]->getNode();
      delete temp;
      cout << "Successfully deleted student" << endl;
      return;
    }
  }
  cout << "Sorry, we couldn't find that student in our directory." << endl;
}
//Prints out each student and their additional information.
void prnt_func(node* da_list[], int size){
  for(int i = 0; i < size; i++){
    if(da_list[i] != NULL){
      //GET THRU NODES
      bool notDone = true;
      node* current = da_list[i];
      while(notDone){
	cout << current->getStudent()->getName() << ", " << current->getStudent()->getId() << ", " << setprecision(2) << current->getStudent()->getGpa() << endl;
	if(current->getNode() == NULL){
	  notDone = false;
	}
	else{
	  current = current->getNode();
	}

      }
    }
  }
}




bool hash_sadge(node* &thing, node* alist[], int &size){
  int sum = thing->getStudent()->getId();
 
  cout << size << endl;

  sum = sum % (size);
  cout << sum << endl;

  if(alist[sum] == NULL){
    alist[sum] = thing;
  }
  else{
    node* current = alist[sum];
    bool notEnd = true;
    int position = 1;
    while(notEnd){
      cout << "current position " << position << endl;
      if(current->getNode() != NULL && position < 3){
	current = current->getNode();
	position++;
      }
      else{
	cout << "here" << endl;
	current->setNode(thing);
	cout << "here2" << endl;
	cout << position << endl;
	if(position == 3){
	  return true;
	}
	else{
	  return false;

	}
	

      }   

      }

    }


  
  //get ascii num
  //check if spot isn't empty
  //if is, fill
  //if not AND haven't added twice, add
  //else rehash
}

bool rehash(node* da_list[], int &size){
  size *= 2;
  node* temp[size];

  for(int i = 0; i < size; i++){
    temp[i] = NULL;
  }
  bool needRehash = false;
  //Use recursion, loop thru og list, using for loop to get ascii val, then put into new list.
  for(int i = 0; i < size; i++){
    if(da_list[i] != NULL){
      while(true){
	node* getLast = da_list[i];
	node* previous = da_list[i];
	while(true){
	  if(getLast->getNode() != NULL){
	    if(getLast != da_list[i]){
	      previous = previous->getNode();
	    }
	    getLast = getLast->getNode();
	  }
	  else{
	    break;
	  }
	}
	bool check = hash_sadge(getLast, temp, size);
	cout << "right before previous" << endl;
	previous->setNode(NULL);
	getLast->setNode(NULL);
	cout << "WE GOT OUT" << endl;
	if(check == true){
	  cout << "we are rehashing" << endl;
	  needRehash = true;
	}
	if(previous == da_list[i]){
	  cout << "Got in prev" << endl;
	  check = hash_sadge(previous, temp, size);
	  if(check){
	    needRehash = true;
	  }
	  break;
	}
  }
}
  }
  if(needRehash){
    return true;
  }
  return false;
}



  
  
  
  
  
