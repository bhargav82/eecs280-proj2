#pragma once
#include "card.hpp"

// similar implemetation to vector
class Hand
{

public:

    Hand();
    ~Hand();

    void addCard(Card &c);
    void clearHand(Card &c);

    int getSize();
    int getCapacity();

    void resize();


private:
    
    int size;
    int capacity;

    Card* cardsOfHand;



};