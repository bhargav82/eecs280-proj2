#pragma once
#include "card.hpp"

// similar implemetation to vector
class Hand
{

public:

    // REQUIRES: nothing
    // MODIFIES: creates a new array with size 2, should live for entirety of game, don't reset after each single play
    // EFFECTS: nothing
    Hand();

    // REQUIRES: nothing
    // MODIFIES: deletes hand array, delete only once game is over, want to keep same hand for each player during game duration 
    // EFFECTS: nothing
    ~Hand();


    // REQUIRES: Card object, get topCard of shoe
    // MODIFIES: if there is space add the card, resize the array and add the card in new space   
    // EFFECTS: nothing
    void addCard(Card &c);

    // REQUIRES: nothing
    // MODIFIES: keep the same array unless the array grows too big -> then reset capacity, delete old array, make new array, 
    // EFFECTS: nothing
    void clearHand();

    // REQUIRES: nothing
    // MODIFIES: nothing    
    // EFFECTS: number of cards in hand
    int getSize();

    // REQUIRES: nothing
    // MODIFIES: nothing    
    // EFFECTS: size of hand structure, should stay relatively small
    int getCapacity();

    // REQUIRES: nothing
    // MODIFIES: make new array with doubled capacity, copy over all old cards from old array, then delete old array and reassign variable to new array    
    // EFFECTS: nothing
    void resize();
    
    // REQUIRES: nothing
    // MODIFIES: nothing    
    // EFFECTS: returns card at the index, similar to [] or .at() for vectors
    Card atIndex(int index);


private:
    
    int size;
    int capacity;

    Card* cardsOfHand;


};