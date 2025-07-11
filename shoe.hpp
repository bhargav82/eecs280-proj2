#pragma once 
#include <vector>
#include <iostream>
#include "card.hpp"

#define DECK_SIZE 52


class Shoe {
public:

    // REQUIRES: nothing
    // MODIFIES: creates shoe data structure, takes in 3 decks,
    // EFFECTS: nothihg
    Shoe();

    // REQUIRES: nothing
    // MODIFIES: deletes array
    // EFFECTS: nothihg
    ~Shoe();
    
    // REQUIRES: nothing
    // MODIFIES: calls getTop, gets top card and "removes" from Shoe
    // EFFECTS: returns card to deal to player or dealer
    Card playCard();

    // REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: returns top card of shoe, if possible
    Card getTop();


    // REQUIRES: nothing
    // MODIFIES: iterates through cards and prits them out    
    // EFFECTS: nothing
    void toStr();

    // REQUIRES: nothing
    // MODIFIES: shoeOfCards
    // EFFECTS: shuffles the deck
    void shuffle();

    // REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: returns pointer to array of shoe of cards
    Card* getShoe();
    
    // REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: returns the capacity
    int getCapacity();

    // REQUIRES: 
    // MODIFIES: resets capacity to max_cap, since cards were never deleted, they are still in array memory
    // EFFECTS: allows one array to hold shoe, call when capacity < 50% in blackjack game
    void resetShoe();



private:
    static const int MAX_CAP = 156;
    Card shoeOfCards[MAX_CAP];
    int capacity = MAX_CAP;
};