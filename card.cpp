#include "card.hpp"



enum intToSuit {
    Spades = 0,
    Clubs = 1,
    Hearts = 2,
    Diamonds = 3,
};

enum intToName {
    Ace = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
};

std::string Card::suitToString (int suit) {
    switch(suit)
    {
        case Spades:  return "Spades";
        case Clubs:  return "Clubs";
        case Hearts:  return "Hearts";
        case Diamonds:  return "Diamonds";

        default : return "N/A";
    }
}

std::string Card::nameToString(int name) {
    switch(name) {
        case Ace: return "Ace";
        case Two: return "Two";
        case Three: return "Three";
        case Four: return "Four";
        case Five: return "Five";
        case Six: return "Six";
        case Seven: return "Seven";
        case Eight: return "Eight";
        case Nine: return "Nine";
        case Ten: return "Ten";
        case Jack: return "Jack";
        case Queen: return "Queen";
        case King: return "King";

        default: return "N/A";
    }
}


