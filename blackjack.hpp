#pragma once
#include "game.hpp"
#include "table.hpp"
#include "card.hpp"



class Blackjack : public Game{
public:
    // virtual function we need to implement
    void drawBoard() override;
	void getInput() override;
	/* returns true if in top 10 */
	bool addScore( HighScore* newScore ) override;
	int play(const Player&) override;
	void resetGame() override;



	void getWager();

    Blackjack();

	Table blackjackTable;
    
	void printBlackjackMenu();
	int wager = 0;

    ~Blackjack();

private:

};




