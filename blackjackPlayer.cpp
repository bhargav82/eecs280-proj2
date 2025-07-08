#include "blackjackPlayer.hpp"



Table::Table()
{
    this->shuffle();                                                    // shuffles shoe of cards

    this->player.getCardFromShoe();
    this->player.getCardFromShoe();
    
    

}


User::User()
{
    chips = 1000;
    
}

void User::getCardFromShoe() {
    
    Card newCard;
    this->userHand.push_back(newCard);
}

void User::toStr()
{
    for (Card c : this->userHand)
    {
        std::cout << c.name << " of " << c.suit << ", Value: " << c.value << std::endl;
    }
}

