#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
/*Lucas Johnson
  9/6/2023
  Determines if a giving input is a palindrome
 */
//At the start we define a string for input, new input, and reverse input. We   then go through input and pull out all characters, adding them to newInput. We then make the character lowercase.
int main(){
  char input[81];
  cout << "Gib Value" << endl;
  cin.get(input,81);
  cin.get();
  char newInput[81];
  char reverseInput[81];
  int firstCounter = 0;
  for(int i = 0; i < strlen(input); i++){
    if(isalpha(input[i])){
      newInput[firstCounter] = input[i];
      newInput[firstCounter] = tolower(newInput[firstCounter]);
      firstCounter++;
    }
  }
  //Here we add a nullcharacter to the end of newInput
  newInput[firstCounter] = '\0';

  //Then we take newInput, use a reverse loop and go through it backwards, adding all the characters to reverseInput
  int counter = 0;
  for(int i = strlen(newInput) - 1; i >= 0; i--){
    reverseInput[counter] = newInput[i];
    counter++;
  }
  //Add null character
  reverseInput[counter] = '\0';
  
  //Finally we compare newInput and reverseInput to determine if we have a palindrome.
  if(strcmp(reverseInput, newInput) == 0){
      cout<< "Palindrome" << endl;

  } else {
      cout << "Not a palindrome" << endl;

    }


}
