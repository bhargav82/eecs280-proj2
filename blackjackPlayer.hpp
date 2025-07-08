#pragma once
#include <string>
#include "card.hpp"
#include "shoe.hpp"




class blackjackPlayer 
{
    public:
        virtual void toStr() = 0;
        void addCard (Card& c);

    protected:                                          
        std::vector<Card> hand;                                               // becomes public later, dealer and user will have their own hand

};




class User : public blackjackPlayer
{
public:
    User();
    void toStr() override;


private:
    int chips;
    std::string userName;
    
};





class Dealer : public blackjackPlayer
{
public:
    
    void toStr() override;
    


    
};