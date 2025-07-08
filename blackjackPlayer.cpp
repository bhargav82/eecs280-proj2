#include "blackjackPlayer.hpp"



// will push back to the hand, can  change based on who is playing
void blackjackPlayer::addCard(Card& c)
{
    hand.push_back(c);
}



User::User()
{
    chips = 1000;
    userScore = 0;
}




void User::toStr()
{
    std::cout << "Player's hand: " << std::endl;
    std::cout << "---------------" << std::endl << std::endl;
    for (Card& c : hand)
    {
        std::cout << c.name << " of " << c.suit << ", Value: " << c.value << std::endl;
    }
}


Dealer::Dealer() {
    dealerScore = 0;
}


// make sure its only 1
void Dealer::toStr()
{
    std::cout << "Dealer's hand: " << std::endl;
    std::cout << "---------------" << std::endl;
    for (Card& c : hand)
    {
        std::cout << c.name << " of " << c.suit << ", Value: " << c.value << std::endl;
    }
}

