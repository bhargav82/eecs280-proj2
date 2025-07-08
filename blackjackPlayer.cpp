#include "blackjackPlayer.hpp"

// will push back to the hand, can  change based on who is playing
void blackjackPlayer::addCard(Card& c)
{
    hand.push_back(c);
}

int blackjackPlayer::count() {
    int handValue = 0;
    bool hasAce = false;

    for (size_t i = 0; i < hand.size(); i++) 
    {
        if (hand[i].name == "Ace") 
        {
            hasAce = true;
            
        }
        handValue += hand[i].value;
    }

    if (hasAce && handValue < 12) 
    {
        handValue += 10;
        
    }

    return handValue;
}


User::User()
{
    chips = 1000;
    userScore = 0;
}



int User::getScore() {
    return userScore;
}


void User::setScore() {
    userScore = count();
}

void User::toStr()
{
    std::cout << "Your hand: " << std::endl;
    std::cout << "-----------" << std::endl;
    for (Card& c : hand)
    {
        std::cout << c.name << " of " << c.suit << std::endl;
    }
}




Dealer::Dealer() {
    dealerScore = 0;
}

int Dealer::getScore() {
    return dealerScore;
}

void Dealer::setScore() {
    dealerScore = count();
}


// make sure its only 1
void Dealer::toStr()
{
    std::cout << "Dealer's hand: " << std::endl;
    std::cout << "----------------" << std::endl;
    for (Card& c : hand)
    {
        std::cout << c.name << " of " << c.suit << std::endl;
    }
}

