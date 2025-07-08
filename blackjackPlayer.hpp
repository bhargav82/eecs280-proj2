#pragma once
#include <string>
#include "card.hpp"
#include "shoe.hpp"

class blackjackPlayer 
{
    public:
        virtual void toStr() = 0;
        void addCard (Card& c);
        virtual int count();

        bool isBust();

    protected:                                          
        std::vector<Card> hand;                                               // becomes public later, dealer and user will have their own hand

};


class User : public blackjackPlayer
{
public:

    User();
    void toStr() override; 
    int getScore();   
    void setScore(); 

private:
    int chips;
    int userScore;
    std::string userName;
    
};


class Dealer : public blackjackPlayer
{
public:
    Dealer();

    void toStr() override;
    int getScore();
    void setScore();


private:
    int dealerScore;
    
};