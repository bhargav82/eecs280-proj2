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

        void printCard(Card& card);

        int getScore();   
        void setScore(); 
        
        int score = 0;
        bool scoreEqualsBlackjack();                                       
        std::vector<Card> hand;                                               // becomes public later, dealer and user will have their own hand

};

class User : public blackjackPlayer
{
public:

    User();
    void toStr() override; 
  
    void setChips(int wagerVal);
    int getChips();
    

private:
    int chips;
    
    std::string userName;
    
};


class Dealer : public blackjackPlayer
{
public:
    Dealer();

    void toStr() override;
    


private:
    
    
};