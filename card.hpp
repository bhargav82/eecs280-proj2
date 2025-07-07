
#include <iostream>
#include <string>


enum intToSuit {
    Spades = 0,
    Clubs = 1,
    Hearts = 2,
    Diamonds = 3,
};

std::string suitToString (int suit) {
    switch(suit)
    {
        case Spades:  return "Spades";
        case Clubs:  return "Clubs";
        case Hearts:  return "Hearts";
        case Diamonds:  return "Diamonds";

        default : return "N/A";

       

    }
}


class Card{

public:

    std::string suit;
    int value;

    Card(int s, int v) : suit(suitToString(s)), value(v) {};
  
};



class Deck {

    // 52 Card objects with different values and suits

    public: 
    std::vector<Card> deckOfCards;

    Deck() {

    for (int cardSuit = 0; cardSuit < 4; cardSuit++)
    {
        for (int rank = 1; rank < 14; rank++)
        {
            Card c(cardSuit, rank);
            deckOfCards.push_back(c);
        }
    }
    }

};

