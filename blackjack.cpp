#include "blackjack.hpp"
#include <chrono>
#include <thread>


// initialize a new table, should only be one table when the game starts, even for multiple games
Blackjack::Blackjack() : Game()
{
                      
}

void Blackjack::getInput() {

}
// REQUIRES: nothing
// MODIFIES: cout
// EFFECTS: prints a menu explaining some of the basic rules of Blackjack, should only be called once, not when the retry game
void Blackjack::printBlackjackMenu()
{
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Welcome to Blackjack! Here are the rules of the game." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "~ At the beginning of each hand, you will be asked" << std::endl;
    std::cout << "    to provide a wager of points. This will be " << std::endl;
    std::cout << "  how your score is evaluated on the leaderboard." << std::endl << std::endl;
    std::cout << "~ Your objective is to get as close to a score of 21" << std::endl;
    std::cout << "  as possible without going over by drawing cards." << std::endl << std::endl;
    std::cout << "~ The dealer and the player will both start with two " << std::endl;
    std::cout << "  cards. After the player decides to stand, the" << std::endl;
    std::cout << "    dealer will attempt to beat the player."   << std::endl << std::endl;
    std::cout << "~ The dealer will hit on 16 and stand on 17. If" << std::endl;
    std::cout << "  the dealer goes over 21, the player will win."         << std::endl << std::endl;
    std::cout << "          ** Good luck, and have fun!! **           " << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}

void Blackjack::getWager() {
    std::cout << "$$$ Enter your wager (number of chips) $$$ : ";
    std::string tempWager = "";
    bool invalidInput = true;
    while (invalidInput)
    {   
        
        std::getline(std::cin, tempWager);
        
        try 
        {
            
            wager = std::stoi(tempWager);
            invalidInput = false;
        }
        catch (std::invalid_argument &error)
        {
            std::cout << "Please enter a number: ";
        }
    }

    return;
}

void Blackjack::drawBoard()
{
    std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
    std::cout << "<>  Dealing two cards to both you and the dealer  <>" << std::endl;
    std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl << std::endl;


    std::cout << "################################" << std::endl;
    std::cout << "Your current chips balance: " << blackjackTable.player.getChips() << std::endl;
    std::cout << "################################" << std::endl << std::endl;
}
// SHOULD REALLY BE BLACKJACK::PLAY

int Blackjack::play(const Player&)
{
    Table t1;

    this->printBlackjackMenu();                                                       // only call this once

    this->drawBoard();

    int wager = 0;
    this->getWager();

    t1.player.setScore();
    t1.dealer.setScore();
    
    
    t1.player.toStr();
    std::cout << std::endl;
    t1.dealer.toStr();
    std::cout << std::endl;

    std::cout << "Your current score: " << t1.player.getScore() << std::endl;
    std::cout << "Dealer's current score: " << t1.dealer.getScore() << std::endl << std::endl;
    
    return 0;
}


int main()
{
    // Takes in three unshuffled decks, shuffles them, and puts them in one shoe
    Table t1;
   

    //std::string tempWager;
    int wager = 0;
    //this->getWager(wager);
    
    
    t1.dealer.setScore();
    t1.player.setScore();
    
    
    t1.player.toStr();
    std::cout << std::endl;
    t1.dealer.toStr();
    std::cout << std::endl;
    
    
    std::cout << "Your current score: " << t1.player.getScore() << std::endl;
    std::cout << "Dealer's current score: " << t1.dealer.getScore() << std::endl << std::endl;
    
    bool userHitChoice = true;
    bool userBust = false;
    while (userHitChoice && (t1.player.getScore() < 21)) {
        userHitChoice = t1.hitOrStand();

        if (userHitChoice) {
            t1.dealCardToPlayer();
            t1.player.setScore();
            std::cout << std::endl;
            t1.player.toStr();
            if (t1.player.getScore() > 21) {
                std::cout << "You bust with a score of " << t1.player.getScore() << "!" << std::endl;
                userBust = true;
            }
            else {
                std::cout << std::endl;
                std::cout << "Your current score: " << t1.player.getScore() << std::endl << std::endl;
            }
        }
    }

    while (t1.dealer.getScore() < 17 && !userBust) 
    {
        std::cout << "Dealer hits!" << std::endl;
        t1.dealCardToDealer();
        t1.dealer.setScore();
        std::cout << std::endl;
        t1.dealer.toStr();
        if (t1.dealer.getScore() > 21) {
            std::cout << "Dealer bust with a score of " << t1.dealer.getScore() << "!" << std::endl;
        }
        else {
            std::cout << std::endl;
            std::cout << "Dealer's current score: " << t1.dealer.getScore() << std::endl << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }

    return 0;
}



bool Blackjack::addScore( HighScore* newScore )
{
    return false;
}


void Blackjack::resetGame()
{
    
}

Blackjack::~Blackjack(){

}