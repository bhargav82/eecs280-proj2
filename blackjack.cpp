#include "blackjack.hpp"
#include <chrono>
#include <thread>

// SHOULD REALLY BE BLACKJACK::PLAY
int main()
{
    // Takes in three unshuffled decks, shuffles them, and puts them in one shoe
    Table t1;
    
    // Prints a banner explaining some of the core rules of Blackjack and announcing the deal
    t1.printBlackjackMenu();
    std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
    std::cout << "<>  Dealing two cards to both you and the dealer  <>" << std::endl;
    std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl << std::endl;
    
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

