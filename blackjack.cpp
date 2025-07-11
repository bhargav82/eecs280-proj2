#include "blackjack.hpp"
#include <chrono>
#include <thread>


// Default constructor for Blackjack, inherits from game
Blackjack::Blackjack() : Game()
{
    // When a new game of Blackjack starts, shuffles the deck
    shoeOfCardsOnTable.shuffle();

    // Reads in junk characters from the stream before the user is prompted to enter their wager
    std::cin.clear();     
    std::cin.ignore();              
}
    
void Blackjack::getWager() {
    // Prompts the user for a wager
    std::cout << "$$$ Enter your wager (number of chips) $$$ : ";

    // Attempts to read in the value given and set wager until the user gives a valid wager
    std::string tempWager = "";
    bool invalidInput = true;
    while (invalidInput)
    {   
        
        std::getline(std::cin, tempWager);
        
        try 
        {
            // Attempts to set the given wager amount to an integer
            wager = std::stoi(tempWager);
            invalidInput = false;
        }
        catch (std::invalid_argument &error)
        {
            // If the user gives invalid input, prompts again for a number
            std::cout << "Please enter a number: ";
        }
    }

    std::cout << std::endl;

    return;
}


int Blackjack::play(const Player& p)
{
    // Prints the menu explaining key rules, call once at beginning of game
    this->printBlackjackMenu();                                                       

    // Plays the game of Blackjack each time the user indicates they wish to continue
    while (userPlayAgain){
        // Plays the game of Blackjack once, then resets the game and updates the player's chip balance
        this->singlePlay(p);
        this->resetGame();
        this->player.setChips(this->wager);


        // checks if we need to reset shoe, repopulates and reshuffles if so
        if (this->shoeOfCardsOnTable.getCapacity() < 50)
        {
            this->shoeOfCardsOnTable.resetShoe();
            this->shoeOfCardsOnTable.shuffle();
            
        }
    }

    return 0;
}



int Blackjack::singlePlay(const Player&)
{
    // Deals two cards to both the dealer and the player
    this->dealCardToDealer();
    this->dealCardToPlayer();
    this->dealCardToPlayer();

    // Prints a header announcing that cards were dealt, asks for wager, updates wager
    this->drawBoard();
    this->getWager();

    // Sets the score of the dealer and the player
    this->player.setScore();
    this->dealer.setScore();
    
    // Prints out the score and hands of the dealer and player
    this->player.toStr();
    std::cout << std::endl;
    this->dealer.toStr();
    std::cout << std::endl;

    // Prints a message declaring the current score
    std::cout << "Your current score: " << this->player.getScore() << std::endl;
    std::cout << "Dealer's current score: " << this->dealer.getScore() << std::endl << std::endl;

    // Each time the user decides to hit, draws another card and updates score until they stand or bust
    while (this->userHitChoice && !this->userBust) 
    {
        this->playerHit();
    }

    // Once the user has finished hitting, if they did not bust, the dealer hits up until 17
    while (this->dealer.getScore() < 17 && !userBust) 
    {
        this->dealerHit();
    }

    // Determines the winner of the hand and prints out a short message congratulating the winner
    char winnerChar = 'x';
    winnerChar = this->checkWinner();
    this->printWinner(winnerChar);

    // Asks the user if they would like to play again, takes in their choice
    char playAgainInput = 'x';
    std::cout << "Play again? (y/n): ";
    std::cin >> playAgainInput;
    
    // Asks the user for their choice until they give a valid response
    while (playAgainInput != 'y' && playAgainInput != 'Y' &&
           playAgainInput != 'n' && playAgainInput != 'N') {
        std::cout << "Please enter 'y' or 'n'. Play again? (y/n): ";
        std::cin >> playAgainInput;
    }
    std::cout << std::endl << std::endl;
    
    // Sets the userPlayAgain value to true if the user wants to play again
    userPlayAgain = (playAgainInput == 'Y' || playAgainInput == 'y');
     
    return 0;
}

// Function that handles the player choosing to hit
void Blackjack::playerHit() 
{
    this->getInput();
    if (this->userHitChoice) 
    {
        this->dealCardToPlayer();

        this->player.setScore();
        std::cout << std::endl;
        this->player.toStr();
        
        if (this->player.getScore() > 21) {
            std::cout << "You bust with a score of " << this->player.getScore() << "!" << std::endl;
            this->userBust = true;
        }
        else 
        {
            std::cout << std::endl;
            std::cout << "Your current score: " << this->player.getScore() << std::endl << std::endl;
        }
    }

}

void Blackjack::dealerHit() 
{
    std::cout << "\n\nDealer hits!" << std::endl << std::endl;
    this->dealCardToDealer();
    this->dealer.setScore();
    std::cout << std::endl;
    this->dealer.toStr();
    if (this->dealer.getScore() > 21) {
        std::cout << "Dealer bust with a score of " << this->dealer.getScore() << "!" << std::endl;
    }
    else {
        std::cout << std::endl;
        std::cout << "Dealer's current score: " << this->dealer.getScore() << std::endl << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

bool Blackjack::addScore( HighScore* newScore )
{
    return false;
}


void Blackjack::resetGame()
{
    this->player.score = 0;
    this->dealer.score = 0;

    this->player.handOfCards.clearHand();
    this->dealer.handOfCards.clearHand();

    this->userHitChoice = true;
    this->userBust = false;

}

Blackjack::~Blackjack(){

}


char Blackjack::checkWinner()
{
    if (!userBust && ((this->player.score > this->dealer.score) || (this->dealer.score > 21)))                      // user wins
    {
        return 'u'; 
    }
    
    else if ((this->player.score == this->dealer.score) && !userBust) {                                             // push (tie)
        this->wager = 0;
        return 'p';
       
    }
    else {                                                                                                           // dealer wins
        this->wager = this->wager * -1;
        return 'd';
    }
    
}

void Blackjack::printWinner(char letter)
{
    if (letter == 'u')
    {
        std::cout << "Congrats, Great Hand! You beat the dealer and won " << this->wager * 2 << " chips!!" << std::endl << std::endl;
    }
    else if (letter == 'p')
    {
        std::cout << "Not bad, you tied against the dealer. You will get back your wager of " << this->wager << " chips!" << std::endl << std::endl;
    }
    else {
        std::cout << "The Evil Blackjack Dealer won, you lost " << this->wager << " chips. :(" << std::endl << std::endl;
    }

}


void Blackjack::dealCardToPlayer() {
    Card p = shoeOfCardsOnTable.playCard();
    player.addCard(p);


    return;
}


void Blackjack::dealCardToDealer() {

    Card newCard = shoeOfCardsOnTable.playCard();
    dealer.addCard(newCard);

    return;
}

// REQUIRES: nothing
// MODIFIES: cin
// EFFECTS: takes in choice from user on whether or not they want to hit, returns true if so, false if stand
void Blackjack::getInput() {
    char userChoice = 'q';
    
    while ((userChoice != 's') && (userChoice != 'h') && (userChoice != 'S') && (userChoice != 'H')) {
        std::cout << "Would you like to hit (h) or stand (s)?" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> userChoice;
    }

    this->userHitChoice = (userChoice == 'h' || userChoice == 'H');
    
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
    std::cout << "~ Once you no longer wish to keep drawing cards, " << std::endl;
    std::cout << "  you can choose to 'stand,' which will set your " << std::endl;
    std::cout << "  score for the round to the value of your hand" << std::endl << std::endl;
    std::cout << "~ You will start with two cards drawn, and the " << std::endl;
    std::cout << "  dealer will start with one. After you decide" << std::endl;
    std::cout << "  to stand, the dealer will begin drawing cards." << std::endl << std::endl;
    std::cout << "~ The dealer will hit on 16 and stand on 17. If" << std::endl;
    std::cout << "  the dealer goes over 21, the player will win."         << std::endl;
    std::cout << "  If neither you nor the dealer bust, the hand" << std::endl;
    std::cout << "  with the higher score will win. If you have " << std::endl;
    std::cout << "  the same score, you will regain your wager" << std::endl << std::endl;
    std::cout << "          ** Good luck, and have fun!! **           " << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
}

void Blackjack::drawBoard()
{
    std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
    std::cout << "<>  Dealing two cards to both you and the dealer  <>" << std::endl;
    std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl << std::endl;


    std::cout << "################################" << std::endl;
    std::cout << "Your current chips balance: " << this->player.getChips() << std::endl;
    std::cout << "################################" << std::endl << std::endl;
}
