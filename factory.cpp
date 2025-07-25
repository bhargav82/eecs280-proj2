#include "factory.hpp"
#include "consoledraw.hpp"
#include "guess.hpp"
#include "tictactoe.hpp"
#include "hangman.hpp"
#include "blackjack.hpp"

using namespace std;

// This is a "factory" function.
// It is used for creating new game objects dynamically
Game* pickGame()
{
	// we will return a pointer to a Game*
	Game* result = NULL;

	// we need to get the user's choice of game
	int choice = -1;
	while( -1 == choice )
	{
		resetScreen();

		cout
			<< "We have the following options available:" << endl
			<< "0: Quit" << endl
			<< "1: Tic Tac Toe - a classic" << endl
			<< "2: Guess! - guess the number between 1 and 100" << endl
			<< "3: Hangman! - guess the word" << endl
			<< "4: Blackjack! - aim for 21" << endl;
		
		cout << "Enter your choice here: ";
		cin >> choice;

		switch( choice )
		{
			case 0:
				break;
			case 1:
				result = new TicTacToe();
				break;
			case 2:
				result = new Guess();
				break;
			case 3:
				result = new Hangman();
				break;
			case 4:
				result = new Blackjack();
				break;
			default:
				cout << "choice not recognized! choose again!" << endl;
				choice = -1;
				break;
		}
	}

	return result;
}
