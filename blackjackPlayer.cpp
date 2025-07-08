#include "blackjackPlayer.hpp"



Table::Table()
{
    this->shuffle();                                                    // shuffles shoe of cards
    tableShoe = this->getShoe();                                        // stores shoe in table shoe (IDK IF THIS IS NECESSARY)

}


User::User()
{
    Card newCard = this->playCard();
    this->userHand.push_back(newCard);
    
}

void User::toStr()
{
    for (Card c : this->userHand)
    {
        std::cout << c.name << " of " << c.suit << ", Value: " << c.value << std::endl;
    }
}

