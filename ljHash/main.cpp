#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "node.h"
#include <fstream>
#include <cstdlib>
#include <time.h>
/*                                           
  Lucas Johnson                                    
  2/5/24                                           
  Creates a Table ADT that is able to get/input different values with keys. Uses chaining to sort collisions.
 */


using namespace std;



//All functions                                                              
char* valid_input();
node* add_func(int id=0, char* name = NULL, float gpa = 0.0);
void del_func(node** list, int size);
void prnt_func(node** list, int size);
bool hash_sadge(node* &thing, node** list, int &size);
node** rehash(node** list, int &size, bool &rehashCheck);
char* getFullName(vector<char*> first, vector<char*> last);
void fullADD(int id, char* name, float gpa, int &size, node** &list);

int main(){
  //Initial size/list created. Use a double pointer, meaning a pointer to an array of pointers
  srand(time(NULL));
  int size = 100;
  node** da_list = new node*[size];
  for(int i = 0; i< size; i++){
    da_list[i] = NULL;
  }
  //Get values from each file, see folder for specifics.
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

  fstream newFile;
  newFile.open("lastNames");
  vector<char*> lastN;
  char* input1 = new char[20];
  while(newFile >> input1){
    char* temp1 = new char[20];
    strcpy(temp1, input1);
    lastN.push_back(temp1);
  }
  newFile.close();
  //Sets the initial id for the RAND function
  int id = 100000;


  
  bool programRunning = true;
  //Create input cstring, as well as loop that runs while program is active                        
  char* to_do = new char[11];
  while(programRunning){

    //Gets user input, overwriting to_do each time it does.
    strcpy(to_do, valid_input());
    //determines the users input, runs appropriate function                                                                                                   //Determines what to do                                              
    if((strcmp(to_do, "ADD")) == 0){
      //Runs the add_func() to get the node* to add
      node* thingy = add_func();
      //Checks if we need to rehash after we hash the value in
      bool rehash1 = hash_sadge(thingy, da_list, size);
      //If we do need to rehash, this loop keeps running as long as we need to
      //keep rehashing
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
    } else if((strcmp(to_do, "RAND")) == 0){
      //Gets input, then continuously creates and adds students, rehashing/sorting as it goes
      int input = 0;
      cout << "How many students you want (under 500 por favor)" << endl;
      cin >> input;
      cin.get();
      for(int i = 0; i < input; i++){
	float gpa = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/4));
	char* fullName = getFullName(firstN, lastN);
	id++;
	fullADD(id, fullName, gpa, size, da_list);
      }
    }
  }
}
//Gets correct input
char* valid_input(){
  cout << endl;
  char* input = new char[11];
  bool good_input = false;
  while(good_input == false){
    cout << "Please input what you would like to do (ADD, PRINT, DELETE, RAND, QUIT). There is a character limit of 10." << endl;
    cin.get(input, 20);
    cin.get();
    if((strcmp(input, "ADD") != 0) && (strcmp(input,"DELETE") != 0) && (strcmp(input,"PRINT") != 0) && (strcmp(input, "QUIT") != 0) && (strcmp(input, "RAND") != 0)){
      cout << "Please select a valid input" << endl;
      continue;
    }
    else{
      good_input = true;
    }


  }
  return input;
}


//Add function simply creates and returns the node to be used for hashing
node* add_func(int id1, char* name0, float gpa1){
  if(id1 != 0){
    student* stu1 = new student(id1, gpa1, name0);
    node* nod1 = new node(stu1);
    return nod1;
  }
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
//Runs through every index and node to determine the correct node to delete
void del_func(node** da_list, int size){
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
	    return;
	  }
	  else if(current->getNode() != NULL){
	    cout << "Deleting node middle of list" << endl;
	    node* temp = current->getNode();
	    previous->setNode(temp);
	    delete current;
	    return;
	  }
	  else{
	    cout << "Delete at end of list" << endl;
	    delete current;
	    previous->setNode(NULL);
	    return;
	  }
	}
	else if(current->getNode() == NULL && current->getStudent()->getId() != find_id){
	  break;
	}
	else{
	  if(current != da_list[i]){
	    previous = previous->getNode();
	  }
	  current = current->getNode();
	}
      }
      break;
    }
  }
  cout << "Sorry, we couldn't find that student in our directory." << endl;
}
//Prints out each student and their additional information.
void prnt_func(node** da_list, int size){
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



//Get's the id, determines it proper index by % size, runs through the list. Once the correct spot is found, check for head node/chain. Add accordingly.
bool hash_sadge(node* &thing, node** alist, int &size){
  int id = thing->getStudent()->getId();
 

  int sum = id % size;

  if(alist[sum] == NULL){
    alist[sum] = thing;
  }
  else{
    node* current = alist[sum];
    bool notEnd = true;
    int position = 1;
    while(notEnd){
      if(current->getNode() != NULL && position < 3){
	current = current->getNode();
	position++;
      }
      else{
	current->setNode(thing);
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
//The reason I need therapy
//Makes a new list, five times the size of the previous. Hashes all previous values into this new list.
//Set "global" list equal to this new temp list
node** rehash(node** da_list, int &size, bool &rehashCheck){
  size *= 5;
  int temporarySize = size / 5;
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
	previous->setNode(NULL);
	bool check = hash_sadge(getLast, temp, size);
	if(check == true){
	  rehashCheck = true;
	}
	break;
	}
  }
}
  node** temp1 = da_list;
  delete temp1;
  return temp;
  }


//Generates a random name from the two vectors of names
char* getFullName(vector<char*> first, vector<char*> last){
  int firstI = rand() % 50;
  int lastI = rand() % 50;

  char* full = new char[50];
  int i = 0;
  for(; i < strlen(first[firstI]); i++){
    full[i] = (first[firstI])[i];
  }
  full[i++] = ' ';

  int j = 0;
  int combined = strlen(first[firstI]) + strlen(last[lastI]) + 1;
  for(; i < combined; i++){
    full[i] = (last[lastI])[j];
    j++;

  }
  full[combined] = '\0';

  return full;

}
//Pretty much just my above add if statement in a function. Run for every student.
void fullADD(int id, char* name, float gpa, int &size, node** &da_list){
  node* thingy = add_func(id, name, gpa);
  bool rehash1 = hash_sadge(thingy, da_list, size);
  if(rehash1){
    bool checker = false;
    da_list = rehash(da_list, size, checker);
  }
}
