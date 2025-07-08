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

