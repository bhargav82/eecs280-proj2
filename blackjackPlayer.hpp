#pragma once
#include <string>
#include "card.hpp"
#include "shoe.hpp"

// use this class to create a user and dealer
// table needs to use get shoeOfCards()
class Table : public Shoe{

public:

    Card* tableShoe = NULL;
    std::string userName;
    std::vector<Card> userHand;

    Table();

    std::vector<Card> dealerHand;

    virtual void toStr() = 0;

};

class User : public Table
{
public:

    User();

    void toStr() override;

private:
    int chips = 1000;

    
};

class Dealer : public Table
{

};