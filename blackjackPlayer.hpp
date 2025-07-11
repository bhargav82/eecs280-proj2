#pragma once
#include <string>
#include "card.hpp"
#include "shoe.hpp"
#include "hand.hpp"

class blackjackPlayer 
{
    public:

        // REQUIRES: nothing
        // MODIFIES: nothing
        // EFFECTS: forces each player and dealer to print their cards
        virtual void toStr() = 0;
        
        // REQUIRES: new Card to add
        // MODIFIES: whoever the player currently is (player or dealer), their handOfCards structure will add a card
        // EFFECTS: nothing
        void addCard (Card& c);
        
        // REQUIRES: nothing
        // MODIFIES: nothing
        // EFFECTS: counts how many points the hand has, acounting for Ace duality (11 or 1)        
        virtual int count();
        
        // REQUIRES: a card
        // MODIFIES: nothing
        // EFFECTS: prints the card as a draw card      
        void printCard(Card& card);

        // REQUIRES: nothing
        // MODIFIES: nothing
        // EFFECTS: returns score of whoever the player current is, since both user and dealer inherit this fucniton
        int getScore(); 
   
        // REQUIRES: nothing
        // MODIFIES: nothing
        // EFFECTS: nakes the player/dealer score equals to count
        void setScore(); 

        // REQUIRES: nothing
        // MODIFIES: nothing
        // EFFECTS: if either player has blackjack -> true if so, false otherwise
        bool scoreEqualsBlackjack();    
        


        int score = 0;                  
        
        // structure that hold card, allows for addCard and resetCard after each hand 
        Hand handOfCards;

};

class User : public blackjackPlayer
{
public:


    // REQUIRES: nothing
    // MODIFIES: sets user chips to 1000, only happens once a new game starts with a new user
    // EFFECTS: nothing 
    User();

    // REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: prints correct version of player hand    
    void toStr() override; 
  

    // REQUIRES: new wager
    // MODIFIES: nothing
    // EFFECTS: adds wager to chips, is set to negative if user losese
    void setChips(int wagerVal);

     // REQUIRES: nothing
    // MODIFIES: nothing
    // EFFECTS: current chip counter
    int getChips();

    
        
private:
    int chips;
    std::string userName;
    
};


class Dealer : public blackjackPlayer
{
    
public:

    // REQUIRES: nothing
    // MODIFIES: just creates dealer object
    // EFFECTS: nothing
    Dealer();

    // REQUIRES: nothing
    // MODIFIES: prints the correct version of the dealer hand
    // EFFECTS: nothing 
    void toStr() override;

    
    
};