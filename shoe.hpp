#pragma once 
#include <vector>
#include <iostream>
#include "card.hpp"

#define DECK_SIZE 52


class Shoe {
public:

    // REQUIRES: nothing
    // MODIFIES: creates shoe data structure, takes in 3 decks, allows for removing from front
    // EFFECTS: nothihg
    Shoe();

    // REQUIRES: nothing
    // MODIFIES: deletes array
    // EFFECTS: nothihg
    ~Shoe();
    
    // REQUIRES: nothing
    // MODIFIES: finds top card, removes from Shoe
    // EFFECTS: returns card to deal to player or dealer
    Card playCard();

    // REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: returns top of card, if possible
    Card getTop();


    // REQUIRES: nothing
    // MODIFIES: iterates through     // EFFECTS: nothing
    void toStr();

    // REQUIRES: nothing
    // MODIFIES: shoeOfCards
    // EFFECTS: shuffles the deck
    void shuffle();

    Card* getShoe();


private:
    static const int MAX_CAP = 156;
    Card shoeOfCards[MAX_CAP];
    int capacity = MAX_CAP;
};