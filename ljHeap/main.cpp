#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
/*
  Lucas Johnson
  2/13/24
  Makes a max heap (binary tree)
 */

//For add:
//1.Add to end
//2. Recursively check if parent is larger or your at the root stop.

//Delete
//1. Swap the root and last one
//2. Recursively check if children are bigger. If so, swap with biggest child. Check again till all is right.

//Functions
void add_function(int arr[], int moverI);
void del_function(int arr[]);
int getToEnd(int arr[]);
char* valid_input();
int getParent(int arr[], int childIndex);
void print(int index, int count, int end, int arr[]);
void del_function(int arr[], int babyI);
void delALL_function(int arr[]);

int main(){
  //Set up list; -1 means no value
  int da_list[101];
  for(int i = 0; i < 101; i++){
    da_list[i] = -1;
  }
  
  bool programRunnin = true;
  char* to_do = new char[20];
  //Get's value then determines what to do.
  while(programRunnin){
    strcpy(to_do, valid_input());
    if(strcmp(to_do, "ADD") == 0){
      char input[10];
      cout << "type file or cmd, file for file upload or cmd for manual" << endl;
      cin.get(input, 9);
      cin.get();
      //Adds one value at a time
      if(strcmp(input, "cmd") == 0){
	int size = 0;
	cout << "How many inputs do you have?" << endl;
	cin >> size;
	int input = 0;
	for(int i = 0; i < size; i++){
	  cout << "Input a number" << endl;
	  cin >> input;
	  cin.get();
	  int endI = getToEnd(da_list);
	  da_list[endI+1] = input;
	  add_function(da_list, endI+1);
	}
      }
      //Reads in from Numbers.rtf to automatically fill the tree
      else if(strcmp(input, "file") == 0){
	fstream fin;
	fin.open("Numbers.rtf");
	int input1 = 0;
	int i = 1;
	while(fin >> input1){
	  int temp = input1;
	  int endI = getToEnd(da_list);
          da_list[endI+1] = temp;
          add_function(da_list, endI+1);
	  i++;
	}
	fin.close();
      }
    } else if(strcmp(to_do, "QUIT") == 0){
      //Ends program
      programRunnin = false;
    } else if(strcmp(to_do, "PRINT") == 0){
      //Prints
      int count = 0;
      int endI = getToEnd(da_list);
      int index = 1;
      print(index, count, endI+1, da_list);
    }
    else if(strcmp(to_do, "DELETE") == 0){
      //Deletes the head, reorganizes the list.
      int endI = getToEnd(da_list);
      da_list[1] = da_list[endI];
      da_list[endI] = -1;
      del_function(da_list, 1);
      
    }
    else if(strcmp(to_do, "DELALL") == 0){
      //Deletes everything in the list
      delALL_function(da_list);
    }
  }
}

//Get's input from a user, checks if it is an accepted command, then returns to main.
char* valid_input(){
  cout << endl;
  char* input = new char[11];
  bool good_input = false;
  while(good_input == false){
    cout << "Please input what you would like to do (ADD, PRINT, DELETE, DELALL, QUIT). There is a character limit of 10." << endl;
    cin.get(input, 10);
    cin.get();
    if((strcmp(input, "ADD") != 0) && (strcmp(input,"DELETE") != 0) && (strcmp(input,"PRINT") != 0) && (strcmp(input, "QUIT") != 0) && (strcmp(input, "DELALL") !=0)){
      cout << "Please select a valid input" << endl;
      continue;
    }
    else{
      good_input = true;
    }


  }
  return input;
}

//A function that automatically gets to the end of the array, or the rightmost value in the binary tree
int getToEnd(int arr[]){
  int lastDigit = 0;
  for(int i = 0; i < 101; i++){
    if(arr[1] == -1){
      return 0;
    }
    else if(arr[i+1] == -1 || i == 100){
      lastDigit = i;
      return lastDigit;
    }

  }

}
void add_function(int arr[], int moverI){
  if(moverI == 1){
    return;
  }
  int pI = getParent(arr, moverI);

  if(arr[pI] < arr[moverI]){
    int temp = arr[pI];
    arr[pI] = arr[moverI];
    arr[moverI] = temp;
    if(pI != 1){
      add_function(arr ,pI);
    }
    else{
      return;
    }
  }
  return;
}
//Returns the parent of a child value
int getParent(int arr[], int childIndex){
  return floor(childIndex / 2);
}

//A recursive function that gets to the last value, prints it, goes to the parent, prints the parent, and so on. Repeats on teh left side after finished with the right.
void print(int index, int count, int endI, int arr[]){
  if((index*2)+1 < endI){
    print((index*2)+1, count+1, endI, arr);
  }
  for(int i = 0; i < count; i++){
    cout << "   ";
  }
  if(arr[index] != -1){
    cout << arr[index]<< endl;
  }
  if((index*2) < endI){
    print((index*2), count+1, endI, arr);
  }
}

//A recursive function that, after replacing the head with babyI, moves BabyI back down the array, replacing BabyI with it's biggest child till babyI is back at the bottom (or until it's bigger than its children)
void del_function(int arr[], int babyI){
  if(babyI > 100 || babyI*2 > 100 || (babyI*2)+1 > 100){
    return;
  }
  if(arr[babyI] < arr[babyI*2] && arr[babyI*2] >= arr[(babyI*2)+1]){
    int temp = arr[babyI];
    arr[babyI] = arr[babyI*2];
    arr[babyI*2] = temp;
    del_function(arr, babyI*2);
  }
  else if(arr[babyI*2] < arr[(babyI*2)+1] && arr[babyI] < arr[(babyI*2)+1]){
    int temp = arr[babyI];
    arr[babyI] = arr[(babyI*2)+1];
    arr[(babyI*2)+1] = temp;
    del_function(arr, (babyI*2)+1);
  }
  else if(arr[babyI] > arr[babyI*2] && arr[babyI] > arr[(babyI*2)+1]){
    return;
  } 
}

//Runs through the list and calls the delete function until the array is empty.
void delALL_function(int arr[]){
  int og = getToEnd(arr);
  for(int i = 1; i < og+1; i++){
    int endI = getToEnd(arr);
    cout << arr[1] << endl;
    arr[1] = arr[endI];
    arr[endI] = -1;
    del_function(arr, 1);
    int count = 0;
  }
}
