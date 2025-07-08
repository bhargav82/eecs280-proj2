#pragma once
#include <string>
#include "card.hpp"
#include "shoe.hpp"

// use this class to create a user and dealer
// table needs to use get shoeOfCards()
class Table : public Shoe{

public:
    Table();

    virtual void getCardFromShoe() = 0;
    //virtual int getScore() = 0;
    virtual void toStr() = 0;

    User player;
    Dealer dealer;

};

class User : public Table
{
public:

    User();

    void toStr() override;
    void getCardFromShoe() override;
    //int getScore() override;
    std::vector<Card> userHand;

private:
    int chips;
    std::string userName;
    
};

class Dealer : public Table
{
public:
    //int getScore() override;
    //void getCardFromShoe() override;
    void toStr() override;
    Dealer();

private: 
    std::vector<Card> dealerHand;
};