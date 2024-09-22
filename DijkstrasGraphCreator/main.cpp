/*
  Lucas Johnson
  05/16/2024
  Main File for Graph Creator
 */


//Functions and includes
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
char* valid_input();
bool label_search(char label, char labelList[]);
bool edge_search(int edge, int adj_table[][20]);
void addLabel(char label, char labelList[], int adjTable[][20]);
void remLabel(char label, char labelList[], int adjTable[][20]);
void addEdge(int edge, int labelI1, int labelI2, int adjTable[][20]);
void remEdge(int labelI1, int labelI2,  int adjTable[][20]);
int findEdge(char label, char labelList[]);
//void print(char labelList[], int adjTable[][20]);
void d_dudeAlgorithm(char start, int adjTable[][20], char labelList[], int distances[], char previous[]);
bool unvisite(int i, char labelList[], char unvisited[]);
//Main function that runs and determines action to take
int main(){

  //Creates adj table/label list and fills it with correct info. 
  bool programRunnin = true;
  char* to_do = new char[20];
  int adjTable[20][20];
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      adjTable[i][j] = -1;
    }
  }
  char labelList[20];
  for(int i = 0; i < 20; i++){
    labelList[i] = '\0';
  }
  while(programRunnin){
    strcpy(to_do, valid_input());
    if(strcmp(to_do, "LABEL") == 0){
      //Takes a label, determines if user wants to add or remove it. If they
      //want to remove it, the program checks to make sure it exists
      char label;
      cout << "Please give label" << endl;
      cin >> label;
      cin.get();
      cout << "would you like to add or remove (a/r)" << endl;
      char addRem;
      cin >> addRem;
      cin.get();
      if(addRem == 'a'){
	addLabel(label, labelList, adjTable);
      }
      else if(addRem == 'r'){
	if(label_search(label, labelList)){
	  remLabel(label, labelList, adjTable);
	}
	else{
	  cout << "That label does not exist" << endl;
	}
      }
    }
    else if(strcmp(to_do, "EDGE") == 0){
      //Using columns as the source and rows as the destination,
      //the adjacency matrix adds an edge between two provided labels or removes it
      //The program makes sure that the edge exists before removing
      cout << "Please provide the source label (column)" << endl;
      char first;
      cin >> first;
      cin.get();
      int firstI = findEdge(first, labelList);

      cout << "Please provide destination label (row)" << endl;
      char second;
      cin >> second;
      cin.get();
      int secondI = findEdge(second, labelList);

      if(secondI == -2 || firstI == -2){
	cout << "one of the labels does not exist" << endl;
	continue;
      }
      else if (secondI == firstI){
	cout << "Sorry, you can't modify the edge of a label pointing to itself" << endl;
	continue;

      }
      
      cout << "would you like to add or remove (a/r)" << endl;
      char addRem;
      cin >> addRem;
      cin.get();
      if(addRem == 'a'){
	int edge;
	//Provide weight edge before function is run
	cout << "please provide edge weight" << endl;
	cin >> edge;
	cin.get();
	addEdge(edge, secondI, firstI, adjTable);
      }
      else if(addRem == 'r'){
	if(edge_search(adjTable[secondI][firstI], adjTable)){
	  remEdge(secondI, firstI, adjTable);
	}
	else{
	  cout << "Edge doesn't exist" << endl;
	}
      }
    }
    else if(strcmp(to_do, "QUIT") == 0){
      programRunnin = false;
    }
    //Uses Djikstra's algorithm to determine the shortest path between two given nodes
    //This path as well as its total weight is printed, otherwise the user is informed
    //that no such path exists
    else if(strcmp(to_do, "SHORT") == 0){
      char start;
      cout << "please give us a start character" << endl;
      cin >> start;
      cin.get();
      //Distances array and previous array are filled first
      //When user gives an end character, then the data is used to determine a path to the end node
      int distancesFromStart[20];
      char previous[20];
      d_dudeAlgorithm(start, adjTable, labelList, distancesFromStart, previous);
      char finish;
      cout << "Please give us end character" << endl;
      cin >> finish;
      cin.get();
      
      for(int i = 0; i < 20; i++){
	if(labelList[i] == finish){
	  if(distancesFromStart[i] == 1000){
	    cout << "No path exists" << endl;
	  }
	  else{
	    cout << "Length of Path" << " : " << distancesFromStart[i] << endl;
	    char current = finish;
	    while(true){
	      cout << current << "<-";
	      if(current == start){
		break;
	      }
	      for(int j = 0; j < 20; j++){
		if(labelList[j] == current){
		  current = previous[j];
		  break;
		}
	      }
	      }
	    cout << endl;
	  }
	}
      }

    }
  }
}
//Searches thru labelList array to check if a label is present
bool label_search(char label, char labelList[]){
  for(int i = 0; i < 20; i++){
    if(label == labelList[i]){
      return true;
    }
  }
  return false;
}

bool edge_search(int edge, int adjTable[][20]){
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 20; j++){
      if(edge == adjTable[i][j]){
	return true;
      }
    }
  }
  return false;
}

//Adds a label/sets the value of the label to itself in the adj matrix to 0
void addLabel(char label, char labelList[], int adjTable[][20]){
  for(int i = 0; i < 20; i++){
    if(labelList[i] == '\0'){
      labelList[i] = label;
      adjTable[i][i] = 0;
      return;
    }
  }
  cout << "You already have 20 labels!" << endl;
}


//Removes a label in the labelList as well as all its connections in the adjTable
void remLabel(char label, char labelList[], int adjTable[][20]){
  for(int i = 0; i < 20; i++){
    if(labelList[i] == label){
      labelList[i] = '\0';
      for(int j = 0; j < 20; j++){
	adjTable[j][i] = -1;
	adjTable[i][j] = -1;
      }
      return;
    }
  }
  cout << "Doesn't exist" << endl;
}

//Adds/removes an edge; very straightforward
void addEdge(int edge, int labelI1, int labelI2, int adjTable[][20]){
  adjTable[labelI1][labelI2] = edge;
}

void remEdge(int labelI1, int labelI2, int adjTable[][20]){
  adjTable[labelI1][labelI2] = -1;
}

//Runs through the adjacency table to find if an edge exists between nodes
int findEdge(char label, char labelList[]){
  for(int i = 0; i < 20; i++){
    if(labelList[i] == label){
      return i;
    }
  }
  return -2;
}

/*
void print(char labelList[], int adjTable[][20]){
  cout << "  ";
  for(int i = 0; i < 20; i++){
    if(labelList[i] != '\0'){
      cout << labelList[i] << " ";
    }
    else if(labelList[i+1] != '\0'){
      cout << "  ";
    }
  }
  cout << endl;
  for(int i = 0; i < 20; i++){
    cout << labelList[i] << " ";
    for(int j = 0; j < 20; j++){
      if(adjTable[i][j] != -1){
	cout << adjTable[i][j] << " ";
      }
      else{
	cout << "  ";
      }
    }
    cout << endl;
    if(labelList[i+1] == '\0'){
      return;
    }
  }
}
*/
//Checks for valid input
char* valid_input(){
  cout << endl;
  char* input = new char[11];
  bool good_input = false;
  while(good_input == false){
    cout << "Please input what you would like to do (EDGE, LABEL, QUIT, SHORT. There is a character limit of 10." << endl;
    cin.get(input, 10);
    cin.get();
    if((strcmp(input, "EDGE") != 0) && (strcmp(input,"LABEL") != 0) && (strcmp(input, "QUIT") != 0) && (strcmp(input, "SHORT") !=0)){
      cout << "Please select a valid input" << endl;
      continue;
    }
    else{
      good_input = true;
    }


  }
  return input;
}
//Runs Djikstra's algorithm and determines the shortest distances from the starting node, as well as their previously connected-to labels
void d_dudeAlgorithm(char start, int adjTable[][20], char labelList[], int distancesFromStart[], char previous[]){
  //This sets up all necessary components for actual algorithm
  int toVisit = 0;
  char unvisited[20];
  for(int i = 0; i < 20; i++){
    if(labelList[i] != '\0'){
      toVisit++;
      unvisited[i] = labelList[i];
      previous[i] = '\0';
    }
  }
  int startIndex = 0;
  for(int i = 0; i < 20; i++){
    if(labelList[i] == start){
      distancesFromStart[i] = 0;
      startIndex = i;
    }
    else if(labelList[i] == '\0'){
      distancesFromStart[i] = -1;
    }else{
      distancesFromStart[i] = 1000;

    }
  }
  while(toVisit != 0){

    //First, find vertex with smallest distance from start vertex
    int smallestVertex = 1000;
    int index;
    for(int i = 0; i < 20; i++){
      if(distancesFromStart[i] <= smallestVertex && distancesFromStart[i] != -1 && unvisite(i, labelList,unvisited)){
	smallestVertex = distancesFromStart[i];
	index = i;
      }
    }
    //For current vertex (since distancesFromStart aligns with labelList) check unvisited neighbors
    for(int i = 0; i < 20; i++){
      if(adjTable[i][index] != -1){
	if(distancesFromStart[i] > (adjTable[i][index] + smallestVertex)){
	  distancesFromStart[i] = (adjTable[i][index] + smallestVertex);
	  //cout << labelList[i] << endl;
	  //	  cout << index << " and " << labelList[index];
	  previous[i] = labelList[index];
	}
      }
    }
    unvisited[index] = '\0';
    toVisit--;
  }
   
}

//Little function to check through the unvisited array and see if a label is still unvisited.
bool unvisite(int i, char labelList[], char unvisited[]){
  for(int j = 0; j < 20; j++){
    if(labelList[j] == unvisited[i] && labelList[j] != '\0'){
      return true;
    }
  }
  return false;

}

