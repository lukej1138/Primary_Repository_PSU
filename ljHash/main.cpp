#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "node.h"
#include <fstream>
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
node** rehash(node* list[], int &size, bool &rehashCheck);

int main(){
  int size = 100;
  node** da_list = new node*[size];

  for(int i = 0; i< size; i++){
    da_list[i] = NULL;
  }

  fstream fin;
  fin.open("firstNames");

  vector<char*> firstN;

  char* input = new char[20];
  while(fin >> input){
    char* temp = new char[20];
    strcpy(temp, input);
    firstN.push_back(temp);
  }
  fin.close();

  fstream fin1;
  fin1.open("lastNames");
  vector<char*> lastN;
  char* input1 = new char[20];
  while(fin >> input){
    char* temp1 = new char[20];
    strcpy(temp1, input1);
    cout << temp1 << endl;
    lastN.push_back(temp1);
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
	  bool checker = false;
	  da_list = rehash(da_list, size, checker);
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
  int sum = find_id % size;
  for(int i = 0; i < size; i++){
    if(da_list[i] == NULL){
      continue;
    }
    if(sum  == (da_list[i]->getStudent()->getId() % size)){
      node* current = da_list[i];
      node* previous = da_list[i];
      while(true){
	if(current->getStudent()->getId() == find_id){
	  cout << "found ID" << endl;
	  if(current == da_list[i]){
	    cout << "delete head node" << endl;
	    if(current->getNode() != NULL){
	      node* temp = current->getNode();
	      da_list[i] = temp;
	    }
	    else{
	      da_list[i] = NULL;
	    }
	    cout << "Node deleted" << endl;
	    delete current;
	  }
	  else if(current->getNode() != NULL){
	    node* temp = current->getNode();
	    previous->setNode(temp);
	    delete current;
	  }
	  else{
	    delete current;
	  }
	  cout << "Node deleted" << endl;
	  return;
	}
	else{
	  if(current != da_list[i]){
	    previous = previous->getNode();
	  }
	  current = current->getNode();
	}
      }
    }
  }
  cout << "Sorry, we couldn't find that student in our directory." << endl;
}
//Prints out each student and their additional information.
void prnt_func(node* da_list[], int size){
  for(int i = 0; i < size; i++){
    if(da_list[i] != NULL){
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
 
  cout << "Size: " <<  size << endl;

  sum = sum % (size);
  cout << sum << endl;

  cout << "Remainder: " << sum << endl;
  if(alist[sum] == NULL){
    cout << "first spot filled" << endl;
    alist[sum] = thing;
  }
  else{
    node* current = alist[sum];
    bool notEnd = true;
    int position = 1;
    while(notEnd){
      cout << "current position " << position << endl;
      if(current->getNode() != NULL && position < 3){
	cout << "Moving forward one node" << endl;
	current = current->getNode();
	position++;
      }
      else{
	current->setNode(thing);
	cout << current->getStudent()->getName() << "Linked to " << current->getNode()->getStudent()->getName() << endl;
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


  return false;
}

node** rehash(node* da_list[], int &size, bool &rehashCheck){
  int temporarySize = size;
  size *= 2;
  node** temp = new node*[size];

  for(int i = 0; i < size; i++){
    temp[i] = NULL;
  }
  bool needRehash = false;
  //Use recursion, loop thru og list, using for loop to get ascii val, then put into new list.
  for(int i = 0; i < temporarySize; i++){
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
	getLast->setNode(NULL);
	previous->setNode(NULL);
	bool check =
	  hash_sadge(getLast, temp, size);
	if(check == true){
	  rehashCheck = true;
	}
	if(previous == da_list[i]){
	  check = hash_sadge(previous, temp, size);
	  da_list[i] = NULL;
	  if(check){
	    rehashCheck = true;
	  }
	  break;
	}
  }
}
  }
  return temp;
}



  
  
  
  
  
