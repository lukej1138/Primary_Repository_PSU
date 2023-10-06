#include <iostream>
#include <cstring>

using namespace std;

int main(){
  char input[81];
  cout << "Gib input" << endl;
  cin.get(input, 80);
  cin.get();
  int counter = 0;
  for(int i = 0; i < strlen(input); i++){
    if(input[i] == '('){
      counter++;

    }
    else if(input[i] == ')'){
      counter--;

    }
  }
  if(counter == 0){
    int counter = 0;
    bool it_broke = false;
    for(int i = 0; i < strlen(input); i++){
      if(input[i] == '('){
	counter++;

      } else if(input[i] == ')'){
	counter--;
      }

      if(counter < 0){
	it_broke = true;
	break;
	

      }

    }
    cout << counter << endl;
    cout << it_broke << endl;
    if(it_broke == true || counter !=0){
      cout << "Parenthesis not connecting" << endl;

    }
    else{
      cout << "All parenthesis present and matching" << endl;

    }

    


  } else{
    cout << "Number of parenthesis not equal, therefore no match" << endl;

  }


}
