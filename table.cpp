#include "table.hpp"

Table::Table() {
    
    shoeOfCardsOnTable.shuffle();
    dealCardToDealer();
    dealCardToDealer();
    dealCardToPlayer();
    dealCardToPlayer();

}

void Table::dealCardToPlayer() {
    Card p = shoeOfCardsOnTable.playCard();
    player.addCard(p);


    return;
}

void Table::dealCardToDealer() {

    Card newCard = shoeOfCardsOnTable.playCard();
    dealer.addCard(newCard);

    return;
}


// REQUIRES: nothing
// MODIFIES: cin
// EFFECTS: takes in choice from user on whether or not they want to hit, returns true if so, false if stand
bool Table::hitOrStand() {
    char userChoice = 'q';
    
    while ((userChoice != 's') && (userChoice != 'h')) {
        std::cout << "Would you like to hit (h) or stand (s)?" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> userChoice;
    }

    if (userChoice == 'h') {
        return true;
    }
    else {
        return false;
    }
}

