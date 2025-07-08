#pragma once
#include "blackjackPlayer.hpp"


// use this class to create a user and dealer
// table needs to use get shoeOfCards()
class Table{
public:
    Table();

    void dealCardToPlayer();
    void dealCardToDealer();

    
    // make objects for both player and dealer -> allows us to choose who to give cards to
    User player;
    Dealer dealer;

    


    private:
    Shoe shoeOfCardsOnTable;                            // creates shoe object, allows us to use Shoe functionality

};