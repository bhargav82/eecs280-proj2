#pragma once
#include "game.hpp"
#include "card.hpp"
#include "blackjackPlayer.hpp"
#include "hand.hpp"



class Blackjack : public Game{
public:

	// Blackjack constructor and destructor
	Blackjack();
	~Blackjack();

    // virtual function we need to implement
    void drawBoard() override;
	void getInput() override;
	/* returns true if in top 10 */
	bool addScore( HighScore* newScore ) override;
	int play(const Player&) override;
	int singlePlay(const Player&);
	void resetGame() override;

	// Blackjack functionality
	void dealCardToPlayer();
	void dealCardToDealer();
	void getWager();
	void printBlackjackMenu();
	void playerHit();
	void dealerHit();
	void printWinner(char letter);
	char checkWinner();
	

	// Blackjack variables and instances of other classes
	int wager = 0;
	bool userHitChoice = true;
	bool userBust = false;
	bool userPlayAgain = true;
	User player;
    Dealer dealer;
    Shoe shoeOfCardsOnTable; 

};




