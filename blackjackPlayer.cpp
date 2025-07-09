#include "blackjackPlayer.hpp"




// you need a variable called score that keeps track of whoever has the current hand, 
//look at addCard it works for both players cause it has a variable (hand), hand is used by both

bool blackjackPlayer::scoreEqualsBlackjack()
{
    if(this->score == 21){
        return true; 
    }
    return false;
}


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
    
}


int User::getChips()
{
    return chips;
}



// should pass in wager amount (positive if won - negative if lost)
void User::addOrRemoveChips(int wagerAmount ){
    chips += wagerAmount;

}

int blackjackPlayer::getScore(){
    return score;
}

void blackjackPlayer::setScore(){
    score = count();
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



Dealer::Dealer() {
    
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

    std::cout<< "\n_______\n|" << suit << "    |\n|     |\n|  " << value << "  |\n|     |\n|    " << suit << "|\n──────";
}