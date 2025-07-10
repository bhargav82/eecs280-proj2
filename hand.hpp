#pragma once
#include "card.hpp"

// similar implemetation to vector
class Hand
{

public:

    Hand();
    ~Hand();

    void addCard(Card &c);
    void clearHand();

    int getSize();
    int getCapacity();

    void resize();
    
    Card atIndex(int index);


private:
    
    int size;
    int capacity;

    Card* cardsOfHand;



};