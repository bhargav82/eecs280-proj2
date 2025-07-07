// Ask if having these functions defined in the .hpp is okay tomorrow
// Clarify if enum and suitToString/nameToString should be in here
#pragma once 
#include <iostream>
#include <string>



class Card{
public:
    Card() : suit("N/A"), name("N/A"), value(-1) {};
    Card(int s, int n, int v) : suit(suitToString(s)), name(nameToString(n)), value(v) {};

    std::string suit;
    std::string name;
    int value;

    std::string suitToString (int suit);
    std::string nameToString(int name);
  
};

class Deck {
    // 52 Card objects with different values and suits
public:
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

