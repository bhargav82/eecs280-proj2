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


    protected:                                          
        std::vector<Card> hand;                                               // becomes public later, dealer and user will have their own hand

};

class User : public blackjackPlayer
{
public:

    User();
    void toStr() override; 
  
    int getChips();
    void addOrRemoveChips(int wagerAmount);

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