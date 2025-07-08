#pragma once
#include "game.hpp"
#include "table.hpp"
#include "card.hpp"



class Blackjack : public Game{
public:
    void shuffle();
    void deal();
    bool hitOrStand();
    bool dealMoreCards();
    bool busted();
    bool hasSeventeen();
    bool playerIsWinner();

private:
    


};


//int User::count();

