#include "blackjack.hpp"

void printBlackjackMenu(){
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
    std::cout << "----------------------------------------------------" << std::endl << std::endl;
}


int count()
{
    int handValue = 0
    
    for(size_t i = 0; i < userHand; i++)
    {
        if(userHand[i].name == "Ace" && handValue > 10)
        {

        }
    }
}