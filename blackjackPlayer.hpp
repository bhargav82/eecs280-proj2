#pragma once
#include <string>
#include "card.hpp"
#include "shoe.hpp"
#include "hand.hpp"

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
        
        // structure that hold card, allows for addCard and resetCard after each hand 
        Hand handOfCards;

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