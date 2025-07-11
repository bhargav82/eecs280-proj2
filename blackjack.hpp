#pragma once
#include "game.hpp"
#include "card.hpp"
#include "blackjackPlayer.hpp"
#include "hand.hpp"



class Blackjack : public Game{
public:

	// Blackjack constructor and destructor
	
	// REQUIRES: nothing
    // MODIFIES: shuffles shoeOfCard object, and makes sure to remove any junk input before game started
    // EFFECTS: nothing
	Blackjack();

	// REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: nothing
	~Blackjack();
	
	// REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: draws the board
    void drawBoard() override;

	// REQUIRES: nothing
	// MODIFIES: cin
	// EFFECTS: takes in choice from user on whether or not they want to hit, returns true if so, false if stand
	void getInput() override;

	// REQUIRES: a pointer to a HighScore object
	// MODIFIES: top10list
	// EFFECTS: adds a player's score to top10list if they scored well enough
	bool addScore( HighScore* newScore ) override;
	
	// REQUIRES: a Player object representing the user
	// MODIFIES: nothing
	// EFFECTS: plays the game of Blackjack for as long as the user wants
	int play(const Player&) override;
	
	// REQUIRES: a Player object representing the user
	// MODIFIES: nothing
	// EFFECTS: plays a single hand of Blackjack
	int singlePlay(const Player&);
	
	// REQUIRES: nothing
	// MODIFIES: nothing
	// EFFECTS: resets member variables to default state
	void resetGame() override;

	// REQUIRES: nothing
	// MODIFIES: the player
    // EFFECTS: adds a card to the player
	void dealCardToPlayer();
	
	// REQUIRES: nothing
	// MODIFIES: the dealer
    // EFFECTS: adds a card to the dealer
	void dealCardToDealer();

	// REQUIRES: nothing
	// MODIFIES: wager
    // EFFECTS: asks the player to imput the wager amount, checks if it is viable and passes it on as the wager
	void getWager();

	// REQUIRES: nothing
	// MODIFIES: cout
	// EFFECTS: prints a menu explaining some of the basic rules of Blackjack, should only be called once, not when the retry game	
	void printBlackjackMenu();

	// REQUIRES: nothing
	// MODIFIES: userHitChoice
	// EFFECTS: adds cards to the player's hand while they decide to hit
	void playerHit();

	// REQUIRES: nothing
	// MODIFIES: nothing
	// EFFECTS: adds cards to the dealer's hand while dealer score is less than 17
	void dealerHit();


	// REQUIRES: letter of winner has been set
    // MODIFIES: nothing
    // EFFECTS: prints the winner based of whoever wins
	void printWinner(char letter);

	// REQUIRES: nothing
	// MODIFIES: winnerLetter
	// EFFECTS: determines who won and sets the winnerLetter char to an indicative key
	char checkWinner();
	

	// Blackjack variables and instances of other classes to be used in the game
	int wager = 0;
	bool userHitChoice = true;
	bool userBust = false;
	bool userPlayAgain = true;
	User player;
    Dealer dealer;
    Shoe shoeOfCardsOnTable; 

};




