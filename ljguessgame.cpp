#include <iostream>
#include <cstdlib>
/*Lucas Johnson
  9/6/2023
  Asks a user to guess a number between 1 - 100
 */
//No global variables, ever
//No strings
//You should include iostream, not stdio. Also use new/delete instead of malloc/free
using namespace std;
int main(){
  //set variables for while loops and the final input (y/n)
  srand(time(NULL));
  bool wannaplay = true;
  bool guessing = true;
  char end_input;
  //runs while user still is playing the game, determining the random number, setting up input/number of guesses.
  while(wannaplay == true){
    int answer = rand() % 100;
    int guess = 0;
    int input = 0;
    //runs while user is guessing the number, stating if they guessed too high, low, or just right
    while(guessing){
      cout << "Guess the number: ";
      cin >> input;
      cout << endl;
      if(input > answer){
	cout << "Too high! Try Again." << endl;
	guess++;
      } else if(input < answer){
	cout << "Too low! Try Again." << endl;
	guess++;
	//the final else statement adds to the number of guesses and breaks out of the loop
      } else {
	guess++;
	guessing = false;
      }
      
    }
    //End prompt of code, determining if the program should be reset or to kill it.
    cout << "Thats the number!" << endl;
    cout << "It took you " << guess << " tries to find the number!" << endl;
    cout << "Do you want to play again (y/n)?" << endl;
    cin >> end_input;
    cout << endl;
    if(end_input == 'n'){
      wannaplay = false;
    } else {
      guessing = true;

    }

  }
  return 0;

}
