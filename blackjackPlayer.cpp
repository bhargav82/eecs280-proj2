#include "blackjackPlayer.hpp"
#include "consoledraw.hpp"



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
    handOfCards.addCard(c);
    
}

int blackjackPlayer::count() {
    int handValue = 0;
    bool hasAce = false;

    for (size_t i = 0; i < handOfCards.getSize(); i++) 
    {
        
        if (handOfCards.atIndex(i).name == "Ace") 
        {
            hasAce = true;
            
        }
        handValue += handOfCards.atIndex(i).value;
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

void User::setChips(int wagerVal) {
    chips = chips + wagerVal;
}


int blackjackPlayer::getScore(){
    return score;
}

void blackjackPlayer::setScore(){
    score = count();
}




void User::toStr()
{
    std::cout << "Your hand: ";
    for (int i = 0; i < handOfCards.getSize(); i++)
    {
        std::cout << "| " << handOfCards.atIndex(i).name << " of " << handOfCards.atIndex(i).suit << " |";
    }
    
    std::cout << std::endl << std::endl;


    for (int i = 0; i < handOfCards.getSize(); i++)
    {
        Card c = handOfCards.atIndex(i);
        printCard(c);
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}



Dealer::Dealer() {
    
}



// make sure its only 1
void Dealer::toStr()
{
    std::cout << "Dealer's hand: ";
    for (int i = 0; i < handOfCards.getSize(); i++)
    {
        std::cout << "| " << handOfCards.atIndex(i).name << " of " << handOfCards.atIndex(i).suit << " |";
    }
    
    std::cout << std::endl << std::endl;


    for (int i = 0; i < handOfCards.getSize(); i++)
    {
        Card c = handOfCards.atIndex(i);
        printCard(c);
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
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

    if(suit == "♣" || "♠")
    {
    std::cout<< "\n_______\n|" << suit << "    |\n|     |\n|  " << value << "  |\n|     |\n|    " << suit << "|\n───────";
    }
    else if(suit == "♦" || "♥")
    {
    std::cout<< "\n_______\n|" << suit << "    |\n|     |\n|  " << value << "  |\n|     |\n|    " << suit << "|\n───────";
    }
}