#pragma once 
#include <iostream>
#include <string>



class Card{
public:

    // REQUIRES: nothing
    // MODIFIES: creates blank card object with default parameters 
    // EFFECTS: nothing
    Card();

    // REQUIRES: nothing
    // MODIFIES: creates card object with parameters, converts int type to correct string using ENUM
    // EFFECTS: nothing
    Card(int s, int n, int v);

    std::string suit;
    std::string name;
    int value;


    // REQUIRES: int for suit
    // MODIFIES: nothing
    // EFFECTS: returns an int for a suit, using ENUM
    std::string suitToString (int suit);

    // REQUIRES: int for name
    // MODIFIES: nothing
    // EFFECTS: changes int to name using ENUM
    std::string nameToString(int name);
  
};



// 52 Card objects with different values and suits
class Deck {

public:

    // REQUIRES: nothing
    // MODIFIES: creates a card object, makes a full 52 card deck
    // EFFECTS: appends each card into deck, making a full deck vector
    Deck() {

    for (int cardSuit = 0; cardSuit < 4; cardSuit++)
    {
        for (int rank = 1; rank < 14; rank++)
        {
            int countVal = rank;
            if (countVal > 10) {
                countVal = 10;
            }

            Card c(cardSuit, rank, countVal);
            deckOfCards.push_back(c);
        }
    }
    }

    std::vector<Card> deckOfCards;
    

};

