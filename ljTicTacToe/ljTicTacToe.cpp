/*
  Lucas Johnson
  9/14/23
  Makes a playable game a TicTacToe for two people
 */
#include <iostream>
#include <cstring>
using namespace std;


//Set up the constants to be used later.
const int EMPTY = 2;
const int X_MOVE = 1;
const int O_MOVE = 0;

//Function declarations
void printBoard(int board[3][3], int row);
void createBoard(int board[3][3], int row);
void takeTurn(int board[3][3], int player);
bool isValidMove(int board[3][3], int row, int col);
void placePlayer(int board[3][3], int player, int row, int col);
bool checkWin(int board[3][3], int player);
bool check_tie(int board[3][3], int player, int row);

//Since we can't have any global variables, all of my "global" variables are stored in main (Board, player, wins, etc)
int main(){
  int board[3][3];
  int row = 3;
  bool game_running = true;
  bool battling = true;
  int player = 1;
  int o_wins = 0;
  int x_wins = 0;

  //This function runs to initialize the game before entering another while loop, where players actually take turns
  while(game_running){
    createBoard(board, row);
    cout << "Welcome to TicTacToe!" << endl;
    while(battling){
      //Here each turn is taken with the take_turn() function
      printBoard(board, row);
      if(player == 1){
	cout << "X Turn" << endl;

      } else {
	cout << "O Turn" << endl;
      }
      takeTurn(board, player);
      printBoard(board, row);
      
      //checkWin/Tie checks for wins and ties
      if(checkWin(board, player)){
	if(player == 1){
	  x_wins++;
	  cout << "Player X won! They now have "<< x_wins << " and player O has " << o_wins << ". Would you like to play again? (y/n)" << endl;
	} else {
	  o_wins++;
	    cout << "Player O won! They now have " << o_wins << " and player O has " << o_wins << ". Would you like to play again? (y/n)" << endl; 
	}//Break out of inner while loop if their is a winner
	battling = false;
      } else if (check_tie(board, player, row)){
	cout << "Its a tie! Good Game. Player X has won " << x_wins << " times and. Would you like to play again? (y/n)" << endl;
	battling = false;
      }
      //Regardless of a win/loss, the current player is switched. This still works, because if a player wins and wants to play again, the current player is automatically set to X.
      if(player == 1){
	player = 0;
      }
      else{
	player = 1;
      }
  }
    //Now out of inner while loop. Determines if players want to play again.
    char yorn = 'a';
    cin >> yorn;
    //If the player wants to play again, player is set to X and the inner loop is reset.
    //The code then resets the board and enters the turn-taking stage before repeating.
   if (yorn == 'y'){
      battling = true;
      player = 1;
      continue;
    } else if (yorn == 'n'){
      game_running = false;
    }
  

}
}
//Fills in the board array with blank pieces
void createBoard(int board[3][3], int row){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < row; j++){
      board[i][j] = EMPTY;
    } 
  }
}
//Prints the board
void printBoard(int board[3][3], int row){
  cout << "  1  2  3" << endl;
  for(int i = 0; i < row; i++){
    int in1 = i+1;
    cout << in1 << " ";
    for(int j = 0; j < row; j++){
      //determines the correct thing to print into each spot using the constant variables
      if(board[i][j] == EMPTY){
	cout << "-" << "  ";
      } else if (board[i][j] == X_MOVE){
	cout << "X" << "  ";
      } else {
	cout << "O" << "  ";
	
      }

    }
    cout << endl;
  }
}

//Asks the user for a valid move as long as they haven't inputted a valid one
void takeTurn(int board[3][3],int player){
  bool moveMade = false;
  while (moveMade == false){
    int row = 0;
    int col = 0;
    cout << endl;
    cout << "Please enter a valid row ";
    cin >> row;
    cout << endl;

    cout << "Please enter a valid col ";
    cin >> col;
    cout << endl;
    //Uses isValidMove to check if the space is empty. If it is, placePlayer function puts the player down in the correct space
    if(isValidMove(board, row-1, col-1)  == true){
      placePlayer(board, player, row-1, col-1);
      moveMade = true;

    } else {
      cout << "Please input a valid input dummy." << endl;
    }
    
  }
}
//Checks if the move is valid
bool isValidMove(int board[3][3], int row, int col){
  if(row < 3 && col < 3){
    if(board[row][col] == EMPTY){
      return true;

    }
    else {
      return false;
    }

  }
  return false;

}
//Acutally places the player
void placePlayer(int board[3][3], int player, int row, int col){
  board[row][col] = player;
}
//Goes through every winning situation to determine if the inputted player has won
bool checkWin(int board[3][3], int player){
  if (board[0][0] == player and board[0][1] == player and board[0][2] == player){
        return true;
  } else if (board[1][0] == player and board[1][1] == player and board[1][2] == player){
        return true;
  } else if (board[2][0] == player and board[2][1] == player and board[2][2] == player){
        return true;
  } else if (board[0][0] == player and board[1][0] == player and board[2][0] == player){
        return true;
  } else if (board[0][1] == player and board[1][1] == player and board[2][1] == player){
        return true;
  } else if (board[0][2] == player and board[1][2] == player and board[2][2] == player){
        return true;
  } else if (board[0][0] == player and board[1][1] == player and board[2][2] == player){
        return true;
  } else if (board[0][2] == player and board[1][1] == player and board[2][0] == player){
        return true;
  }
  return false;

}
//Goes through the board to check if a tie had occurred
bool check_tie(int board[3][3], int player, int row){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < row; j++){
      if(board[i][j] == EMPTY){
	return false;

      }
    }
  }
  if(checkWin(board, player)){
    return false;
  }
  else{
    return true;
  }


}
