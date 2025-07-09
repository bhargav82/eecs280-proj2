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


int User::getChips()
{
    return chips;
}



// should pass in wager amount (positive if won - negative if lost)
void User::addOrRemoveChips(int wagerAmount ){
    chips += wagerAmount;

}



int User::getScore() {
    return userScore;
}

void User::setScore() {
    userScore = count();
}

void User::toStr()
{
    std::cout << "Your hand:" << std::endl;
    for (Card& c : hand)
    {
        std::cout << "| " << c.name << " of " << c.suit << " | " << std::endl;

        printCard(c);
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}



void blackjackPlayer::printCard(Card& card)
{
    char value = 'c';
    std::string suit = "";

    if(card.value == 1)
    {
        value = 'A';
    }
    else if(card.value < 10)
    {
        value = '0' + card.value;
    }
    else if (card.name == "Ten") {
        value = 'T';
    }
    else if (card.name == "King")
    {
        value = 'K';
    }
        else if (card.name == "Jack")
    {
        value = 'J';
    }
        else if (card.name == "Queen")
    {
        value = 'Q';
    } 
    if(card.suit == "Clubs")
    {
        suit = "♣";
    }
    else if(card.suit == "Diamonds")
    {
        suit = "♦";
    }
        else if(card.suit == "Hearts")
    {
        suit = "♥";
    }
            else if(card.suit == "Spades")
    {
        suit = "♠";
    }

    std::cout<< "_______\n|" << suit << "    |\n|     |\n|  " << value << "  |\n|     |\n|    " << suit << "|\n──────";
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
    std::cout << "Dealer's hand: |";
    for (Card& c : hand)
    {
        std::cout << c.name << " of " << c.suit << " | ";
        printCard(c);
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

