#pragma once
#include "game.hpp"
#include "table.hpp"
#include "card.hpp"



class Blackjack : public Game{
public:
    void printBlackjackMenu();
    int play();
    bool hitOrStand(Table& t1);

private:
    


};


//int User::count();

